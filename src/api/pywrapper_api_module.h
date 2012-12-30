

#ifndef PYTHONWRAPPER_API_MODULE__H
#define PYTHONWRAPPER_API_MODULE__H

namespace py
{

static inline int Module_Check(PyObject *p)
{
    return safe_noref( PyModule_Check(p) );
}

static inline int Module_CheckExact(PyObject *p)
{
    return safe_noref( PyModule_CheckExact(p) );
}

static inline ref<PyObject> Module_New(const char *name)
{
    return safe_ref( PyModule_New(name) );
}

static inline borrowed_ref<PyObject> Module_GetDict(PyObject *module)
{
    return safe_borrowed_ref( PyModule_GetDict(module) );
}

static inline char* Module_GetName(PyObject *module)
{
    return safe_noref( PyModule_GetName(module) );
}

static inline char* Module_GetFilename(PyObject *module)
{
    return safe_noref( PyModule_GetFilename(module) );
}

static inline int Module_AddObject(PyObject *module, const char *name, stolen_ref<PyObject> value)
{
    return safe_noref( PyModule_AddObject(module, name, value.release() ) );
}

static inline int Module_AddIntConstant(PyObject *module, const char *name, long value)
{
    return safe_noref( PyModule_AddIntConstant(module, name, value) );
}

static inline int Module_AddStringConstant(PyObject *module, const char *name, const char *value)
{
    return safe_noref( PyModule_AddStringConstant(module, name, value) );
}

}

#endif // PYTHONWRAPPER_API_API_MODULE__H

