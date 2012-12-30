

#ifndef PYTHONWRAPPER_API_TYPE__H
#define PYTHONWRAPPER_API_TYPE__H

namespace py
{

static inline int Type_Check(PyObject *o)
{
    return safe_noref( PyType_Check(o) );
}

static inline int Type_CheckExact(PyObject *o)
{
    return safe_noref( PyType_CheckExact(o) );
}

static inline unsigned int Type_ClearCache()
{
    return safe_noref( PyType_ClearCache() );
}

static inline void Type_Modified(PyTypeObject *type)
{
    PyType_Modified(type);
    exception::check();
}

static inline int Type_HasFeature(PyTypeObject *o, int feature)
{
    return safe_noref( PyType_HasFeature(o, feature) );
}

static inline int Type_IS_GC(PyTypeObject *o)
{
    return safe_noref( PyType_IS_GC(o) );
}

static inline int Type_IsSubtype(PyTypeObject *a, PyTypeObject *b)
{
    return safe_noref( PyType_IsSubtype(a, b) );
}

static inline ref<PyObject> Type_GenericAlloc(PyTypeObject *type, Py_ssize_t nitems)
{
    return safe_ref( PyType_GenericAlloc(type, nitems) );
}

static inline ref<PyObject> Type_GenericNew(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    return safe_ref( PyType_GenericNew(type, args, kwds) );
}

static inline int Type_Ready(PyTypeObject *type)
{
    return safe_noref( PyType_Ready(type) );
}

}

#endif // PYTHONWRAPPER_API_API_TYPE__H

