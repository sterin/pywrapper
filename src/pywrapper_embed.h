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

class enable_threads :
    utils::noncopyable
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

class gil_state_ensure :
    utils::noncopyable
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

} // namespace py

#endif // PYTHONWRAPPER_EMBED__H
