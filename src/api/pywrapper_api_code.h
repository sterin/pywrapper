

#ifndef PYTHONWRAPPER_API_CODE__H
#define PYTHONWRAPPER_API_CODE__H

namespace py
{

static inline int Code_Check(PyObject *co)
{
    return safe_noref( PyCode_Check(co) );
}

static inline Py_ssize_t Code_GetNumFree(PyCodeObject* o)
{
    return safe_noref( PyCode_GetNumFree(o) );
}

static inline ref<PyCodeObject> Code_New(int argcount, int nlocals, int stacksize, int flags, PyObject *code, PyObject *consts, PyObject *names, PyObject *varnames, PyObject *freevars, PyObject *cellvars, PyObject *filename, PyObject *name, int firstlineno, PyObject *lnotab)
{
    return safe_ref( PyCode_New(argcount, nlocals, stacksize, flags, code, consts, names, varnames, freevars, cellvars, filename, name, firstlineno, lnotab) );
}

static inline ref<PyCodeObject> Code_NewEmpty(const char *filename, const char *funcname, int firstlineno)
{
    return safe_ref( PyCode_NewEmpty(filename, funcname, firstlineno) );
}

}

#endif // PYTHONWRAPPER_API_API_CODE__H

