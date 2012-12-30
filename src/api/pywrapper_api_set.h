

#ifndef PYTHONWRAPPER_API_SET__H
#define PYTHONWRAPPER_API_SET__H

namespace py
{

static inline int Set_Check(PyObject *p)
{
    return safe_noref( PySet_Check(p) );
}

static inline int FrozenSet_Check(PyObject *p)
{
    return safe_noref( PyFrozenSet_Check(p) );
}

static inline int AnySet_Check(PyObject *p)
{
    return safe_noref( PyAnySet_Check(p) );
}

static inline int AnySet_CheckExact(PyObject *p)
{
    return safe_noref( PyAnySet_CheckExact(p) );
}

static inline int FrozenSet_CheckExact(PyObject *p)
{
    return safe_noref( PyFrozenSet_CheckExact(p) );
}

static inline ref<PyObject> Set_New(PyObject *iterable)
{
    return safe_ref( PySet_New(iterable) );
}

static inline ref<PyObject> FrozenSet_New(PyObject *iterable)
{
    return safe_ref( PyFrozenSet_New(iterable) );
}

static inline Py_ssize_t Set_Size(PyObject *anyset)
{
    return safe_noref( PySet_Size(anyset) );
}

static inline Py_ssize_t Set_GET_SIZE(PyObject *anyset)
{
    return safe_noref( PySet_GET_SIZE(anyset) );
}

static inline int Set_Contains(PyObject *anyset, PyObject *key)
{
    return safe_noref( PySet_Contains(anyset, key) );
}

static inline int Set_Add(PyObject *set, PyObject *key)
{
    return safe_noref( PySet_Add(set, key) );
}

static inline int Set_Discard(PyObject *set, PyObject *key)
{
    return safe_noref( PySet_Discard(set, key) );
}

static inline ref<PyObject> Set_Pop(PyObject *set)
{
    return safe_ref( PySet_Pop(set) );
}

static inline int Set_Clear(PyObject *set)
{
    return safe_noref( PySet_Clear(set) );
}

}

#endif // PYTHONWRAPPER_API_API_SET__H

