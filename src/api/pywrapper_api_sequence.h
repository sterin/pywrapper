

#ifndef PYTHONWRAPPER_API_SEQUENCE__H
#define PYTHONWRAPPER_API_SEQUENCE__H

namespace py
{

static inline int Sequence_Check(PyObject *o)
{
    return safe_noref( PySequence_Check(o) );
}

static inline Py_ssize_t Sequence_Size(PyObject *o)
{
    return safe_noref( PySequence_Size(o) );
}

static inline ref<PyObject> Sequence_Concat(PyObject *o1, PyObject *o2)
{
    return safe_ref( PySequence_Concat(o1, o2) );
}

static inline ref<PyObject> Sequence_Repeat(PyObject *o, Py_ssize_t count)
{
    return safe_ref( PySequence_Repeat(o, count) );
}

static inline ref<PyObject> Sequence_InPlaceConcat(PyObject *o1, PyObject *o2)
{
    return safe_ref( PySequence_InPlaceConcat(o1, o2) );
}

static inline ref<PyObject> Sequence_InPlaceRepeat(PyObject *o, Py_ssize_t count)
{
    return safe_ref( PySequence_InPlaceRepeat(o, count) );
}

static inline ref<PyObject> Sequence_GetItem(PyObject *o, Py_ssize_t i)
{
    return safe_ref( PySequence_GetItem(o, i) );
}

static inline ref<PyObject> Sequence_GetSlice(PyObject *o, Py_ssize_t i1, Py_ssize_t i2)
{
    return safe_ref( PySequence_GetSlice(o, i1, i2) );
}

static inline int Sequence_SetItem(PyObject *o, Py_ssize_t i, PyObject *v)
{
    return safe_noref( PySequence_SetItem(o, i, v) );
}

static inline int Sequence_DelItem(PyObject *o, Py_ssize_t i)
{
    return safe_noref( PySequence_DelItem(o, i) );
}

static inline int Sequence_SetSlice(PyObject *o, Py_ssize_t i1, Py_ssize_t i2, PyObject *v)
{
    return safe_noref( PySequence_SetSlice(o, i1, i2, v) );
}

static inline int Sequence_DelSlice(PyObject *o, Py_ssize_t i1, Py_ssize_t i2)
{
    return safe_noref( PySequence_DelSlice(o, i1, i2) );
}

static inline Py_ssize_t Sequence_Count(PyObject *o, PyObject *value)
{
    return safe_noref( PySequence_Count(o, value) );
}

static inline int Sequence_Contains(PyObject *o, PyObject *value)
{
    return safe_noref( PySequence_Contains(o, value) );
}

static inline Py_ssize_t Sequence_Index(PyObject *o, PyObject *value)
{
    return safe_noref( PySequence_Index(o, value) );
}

static inline ref<PyObject> Sequence_List(PyObject *o)
{
    return safe_ref( PySequence_List(o) );
}

static inline ref<PyObject> Sequence_Tuple(PyObject *o)
{
    return safe_ref( PySequence_Tuple(o) );
}

static inline ref<PyObject> Sequence_Fast(PyObject *o, const char *m)
{
    return safe_ref( PySequence_Fast(o, m) );
}

static inline borrowed_ref<PyObject> Sequence_Fast_GET_ITEM(PyObject *o, Py_ssize_t i)
{
    return safe_borrowed_ref( PySequence_Fast_GET_ITEM(o, i) );
}

static inline PyObject** Sequence_Fast_ITEMS(PyObject *o)
{
    return safe_noref( PySequence_Fast_ITEMS(o) );
}

static inline ref<PyObject> Sequence_ITEM(PyObject *o, Py_ssize_t i)
{
    return safe_ref( PySequence_ITEM(o, i) );
}

static inline Py_ssize_t Sequence_Fast_GET_SIZE(PyObject *o)
{
    return safe_noref( PySequence_Fast_GET_SIZE(o) );
}

}

#endif // PYTHONWRAPPER_API_API_SEQUENCE__H

