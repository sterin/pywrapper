

#ifndef PYTHONWRAPPER_API_CLASS__H
#define PYTHONWRAPPER_API_CLASS__H

namespace py
{

static inline int Class_Check(PyObject *o)
{
    return safe_noref( PyClass_Check(o) );
}

static inline int Class_IsSubclass(PyObject *klass, PyObject *base)
{
    return safe_noref( PyClass_IsSubclass(klass, base) );
}

static inline int Instance_Check(PyObject *obj)
{
    return safe_noref( PyInstance_Check(obj) );
}

static inline ref<PyObject> Instance_New(PyObject *class_, PyObject *arg, PyObject *kw)
{
    return safe_ref( PyInstance_New(class_, arg, kw) );
}

static inline ref<PyObject> Instance_NewRaw(PyObject *class_, PyObject *dict)
{
    return safe_ref( PyInstance_NewRaw(class_, dict) );
}

}

#endif // PYTHONWRAPPER_API_API_CLASS__H

