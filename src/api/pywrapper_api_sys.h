

#ifndef PYTHONWRAPPER_API_SYS__H
#define PYTHONWRAPPER_API_SYS__H

namespace py
{

static inline int FdIsInteractive(FILE *fp, const char *filename)
{
    return safe_noref( Py_FdIsInteractive(fp, filename) );
}

static inline void OS_AfterFork()
{
    PyOS_AfterFork();
    exception::check();
}

static inline PyOS_sighandler_t OS_getsig(int i)
{
    return safe_noref( PyOS_getsig(i) );
}

static inline PyOS_sighandler_t OS_setsig(int i, PyOS_sighandler_t h)
{
    return safe_noref( PyOS_setsig(i, h) );
}

static inline borrowed_ref<PyObject> Sys_GetObject(char *name)
{
    return safe_borrowed_ref( PySys_GetObject(name) );
}

static inline FILE* Sys_GetFile(char *name, FILE *def)
{
    return safe_noref( PySys_GetFile(name, def) );
}

static inline int Sys_SetObject(char *name, PyObject *v)
{
    return safe_noref( PySys_SetObject(name, v) );
}

static inline void Sys_ResetWarnOptions()
{
    PySys_ResetWarnOptions();
    exception::check();
}

static inline void Sys_AddWarnOption(char *s)
{
    PySys_AddWarnOption(s);
    exception::check();
}

static inline void Sys_SetPath(char *path)
{
    PySys_SetPath(path);
    exception::check();
}

static inline void FatalError(const char *message)
{
    Py_FatalError(message);
    exception::check();
}

static inline void Exit(int status)
{
    Py_Exit(status);
    exception::check();
}

static inline int AtExit(void (*func) ())
{
    return safe_noref( Py_AtExit(func) );
}

}

#endif // PYTHONWRAPPER_API_API_SYS__H

