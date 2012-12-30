

#ifndef PYTHONWRAPPER_API_SLICE__H
#define PYTHONWRAPPER_API_SLICE__H

namespace py
{

static inline int Slice_Check(PyObject *ob)
{
    return safe_noref( PySlice_Check(ob) );
}

static inline ref<PyObject> Slice_New(PyObject *start, PyObject *stop, PyObject *step)
{
    return safe_ref( PySlice_New(start, stop, step) );
}

static inline int Slice_GetIndices(PySliceObject *slice, Py_ssize_t length, Py_ssize_t *start, Py_ssize_t *stop, Py_ssize_t *step)
{
    return safe_noref( PySlice_GetIndices(slice, length, start, stop, step) );
}

static inline int Slice_GetIndicesEx(PySliceObject *slice, Py_ssize_t length, Py_ssize_t *start, Py_ssize_t *stop, Py_ssize_t *step, Py_ssize_t *slicelength)
{
    return safe_noref( PySlice_GetIndicesEx(slice, length, start, stop, step, slicelength) );
}

}

#endif // PYTHONWRAPPER_API_API_SLICE__H

