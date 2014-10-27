#ifndef PYTHONWRAPPER_EMBED__H
#define PYTHONWRAPPER_EMBED__H

namespace py
{

class initialize
{
public:
	initialize(char* name=0, int initsigs = 1)
	{
		if ( name )
		{
			Py_SetProgramName(name);
		}

		Py_InitializeEx(initsigs);
        PyEval_InitThreads();
	}

	~initialize()
	{
		Py_Finalize();
	}

private:
};

class enable_threads
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

class gil_lock
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

class gil_state_ensure
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

class restore_tstate
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

class swap_tstate
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


class thread_state
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

class sub_interpreter
{
public:

    struct thread_scope
    {
        gil_lock _lock;
        thread_state _state;
        swap_tstate _swap;

        thread_scope(PyInterpreterState* interp) :
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

    PyInterpreterState* interp()
    {
        return _ts->interp;
    }

    operator PyInterpreterState*()
    {
        return _ts->interp;
    }

private:

    PyThreadState* _ts;
};


} // namespace py

#endif // PYTHONWRAPPER_EMBED__H
