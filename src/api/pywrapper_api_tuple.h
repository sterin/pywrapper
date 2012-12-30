

#ifndef PYTHONWRAPPER_API_TUPLE__H
#define PYTHONWRAPPER_API_TUPLE__H

namespace py
{

static inline int Tuple_Check(PyObject *p)
{
    return safe_noref( PyTuple_Check(p) );
}

static inline int Tuple_CheckExact(PyObject *p)
{
    return safe_noref( PyTuple_CheckExact(p) );
}

static inline ref<PyObject> Tuple_New(Py_ssize_t len)
{
    return safe_ref( PyTuple_New(len) );
}

static inline Py_ssize_t Tuple_Size(PyObject *p)
{
    return safe_noref( PyTuple_Size(p) );
}

static inline Py_ssize_t Tuple_GET_SIZE(PyObject *p)
{
    return safe_noref( PyTuple_GET_SIZE(p) );
}

static inline borrowed_ref<PyObject> Tuple_GetItem(PyObject *p, Py_ssize_t pos)
{
    return safe_borrowed_ref( PyTuple_GetItem(p, pos) );
}

static inline borrowed_ref<PyObject> Tuple_GET_ITEM(PyObject *p, Py_ssize_t pos)
{
    return safe_borrowed_ref( PyTuple_GET_ITEM(p, pos) );
}

static inline ref<PyObject> Tuple_GetSlice(PyObject *p, Py_ssize_t low, Py_ssize_t high)
{
    return safe_ref( PyTuple_GetSlice(p, low, high) );
}

static inline int Tuple_SetItem(PyObject *p, Py_ssize_t pos, stolen_ref<PyObject> o)
{
    return safe_noref( PyTuple_SetItem(p, pos, o.release() ) );
}

static inline void Tuple_SET_ITEM(PyObject *p, Py_ssize_t pos, stolen_ref<PyObject> o)
{
    PyTuple_SET_ITEM(p, pos, o.release() );
    exception::check();
}

static inline int _Tuple_Resize(PyObject **p, Py_ssize_t newsize)
{
    return safe_noref( _PyTuple_Resize(p, newsize) );
}

static inline int Tuple_ClearFreeList()
{
    return safe_noref( PyTuple_ClearFreeList() );
}

}

#endif // PYTHONWRAPPER_API_API_TUPLE__H

