#ifndef PYTHONWRAPPER_THREAD__H
#define PYTHONWRAPPER_THREAD__H

#include "pywrapper_callbacks.h"

#include <thread>

namespace py
{

struct noncopyable
{
    noncopyable() = default;
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;
};

class enable_threads :
    noncopyable
{
public:
    enable_threads() :
        _state(PyEval_SaveThread())
    {
    }

    ~enable_threads()
    {
        disable();
    }

    void disable()
    {
        if( _state )
        {
            PyEval_RestoreThread(_state);
            _state = 0;
        }
    }

    PyThreadState* state()
    {
        return _state;
    }

private:
    PyThreadState* _state;
};

class gil_lock :
    noncopyable
{
public:
    gil_lock()
    {
        PyEval_AcquireLock();
        _held = true;
    }

    ~gil_lock()
    {
        release();
    }

    void release()
    {
        if( _held)
        {
            PyEval_ReleaseLock();
            _held = false;
        }
    }

private:

    bool _held;
};

class gil_state_ensure :
    noncopyable
{
public:
    gil_state_ensure() :
        _state(PyGILState_Ensure()),
        _held(true)
    {

    }

    ~gil_state_ensure()
    {
        release();
    }

    void release()
    {
        if(_held)
        {
            PyGILState_Release(_state);
            _held = false;
        }
    }

private:

    PyGILState_STATE _state;
    bool _held;
};

class restore_tstate :
    noncopyable
{
public:
    restore_tstate()
    {
        _ts = PyThreadState_Get();
    }

    ~restore_tstate()
    {
        PyThreadState_Swap(_ts);
    }

private:
    PyThreadState* _ts;
};

class swap_tstate :
    noncopyable
{
public:
    swap_tstate(PyThreadState* ts)
    {
        _ts = PyThreadState_Swap(ts);
    }

    ~swap_tstate()
    {
        PyThreadState_Swap(_ts);
    }

private:
    PyThreadState* _ts;
};

class thread_state :
    noncopyable
{
public:

    thread_state(PyInterpreterState* interp)
    {
        _ts = PyThreadState_New(interp);
    }

    ~thread_state()
    {
        if( _ts )
        {
            PyThreadState_Clear(_ts);
            PyThreadState_Delete(_ts);

            _ts = nullptr;
        }
    }

    operator PyThreadState*()
    {
        return _ts;
    }

private:
    PyThreadState* _ts;
};

class sub_interpreter :
    noncopyable
{
public:

    struct thread_scope :
        noncopyable
    {
        gil_lock _lock;
        thread_state _state;
        swap_tstate _swap;

        thread_scope(const sub_interpreter& interp) :
            thread_scope(interp.interp())
        {
        }

        thread_scope(PyInterpreterState *interp) :
            _state(interp),
            _swap(_state)
        {
        }
    };

    sub_interpreter()
    {
        restore_tstate restore;

        _ts = Py_NewInterpreter();
    }

    ~sub_interpreter()
    {
        if( _ts )
        {
            swap_tstate sts(_ts);

            Py_EndInterpreter(_ts);
        }
    }

    PyInterpreterState* interp() const
    {
        return _ts->interp;
    }

    operator PyInterpreterState*() const
    {
        return _ts->interp;
    }

    template<typename callable_type, typename... arg_types>
    std::thread make_thread(callable_type&& callable, arg_types&&... args)
    {
        auto f = [&, this]()
        {
            sub_interpreter::thread_scope scope(interp());

            try
            {
                callable(std::forward<arg_types>(args)...);
            }
            catch(exception &e)
            {
                Err_PrintEx(1);
            }
        };

        return std::thread(f);
    }

private:
    PyThreadState* _ts;
};

} // namespace py

#endif // PYTHONWRAPPER_THREAD__H
