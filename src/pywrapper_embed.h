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

} // namespace py

#endif // PYTHONWRAPPER_EMBED__H
