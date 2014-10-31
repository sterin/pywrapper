#ifndef PYTHONWRAPPER_THREAD__H
#define PYTHONWRAPPER_THREAD__H

#include "pywrapper_callbacks.h"

#include <thread>
#include <tuple>

namespace py
{

class gil_lock :
    utils::noncopyable
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

class restore_tstate :
    utils::noncopyable
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
    utils::noncopyable
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

template<typename C, typename... T>
void F(C&& _C, T... _T)
{
    _C(std::forward<T>(_T)...);
}

class thread_state :
    utils::noncopyable
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
    utils::noncopyable
{
public:

    struct thread_scope :
        utils::noncopyable
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

    // based on http://stackoverflow.com/a/7858971/99279
    // all because earlier version of g++ cannot unpack in a lambda
    template <typename C, typename ...A>
    class delay_call
    {

        template<int ...>
        struct int_seq
        {
        };

        template<int N, int ...S>
        struct gen_seq :
            gen_seq<N-1, N-1, S...>
        {
        };

        template<int ...S>
        struct gen_seq<0, S...>
        {
            typedef int_seq<S...> type;
        };

    public:

        delay_call(PyInterpreterState* interp, C&& c, A&&... a) :
            _interp(interp),
            _c(std::forward<C>(c)),
            _a(std::forward<A>(a)...)
        {

        }

        void operator()()
        {
            sub_interpreter::thread_scope scope(_interp);

            try
            {
                call(typename gen_seq<sizeof...(A)>::type());
            }
            catch(exception &e)
            {
                Err_PrintEx(1);
            }
        }

    private:

        template<int ...S>
        void call(int_seq<S...>)
        {
            std::forward<C>(_c)(std::forward<A>(std::get<S>(_a))...);
        }

        PyInterpreterState* _interp;
        C&& _c;
        std::tuple<A&&...> _a;
    };

    template<typename C, typename... A>
    static delay_call<C,A...> delay(PyInterpreterState* interp, C&& c, A&&... a)
    {
        return delay_call<C,A...>(interp, std::forward<C>(c), std::forward<A>(a)...);
    }

    template<typename callable_type, typename... arg_types>
    std::thread make_thread(callable_type&& callable, arg_types&&... args)
    {
//        auto f = [&, this]()
//        {
//            sub_interpreter::thread_scope scope(interp());
//
//            try
//            {
//                callable(std::forward<arg_types>(args)...);
//            }
//            catch(exception &e)
//            {
//                Err_PrintEx(1);
//            }
//        };
//

        return std::thread(delay(interp(), callable, args...));
    }

private:
    PyThreadState* _ts;
};

} // namespace py

#endif // PYTHONWRAPPER_THREAD__H
