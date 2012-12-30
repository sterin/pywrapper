

#ifndef PYTHONWRAPPER_API_BUFFER__H
#define PYTHONWRAPPER_API_BUFFER__H

namespace py
{

static inline int Object_CheckBuffer(PyObject *obj)
{
    return safe_noref( PyObject_CheckBuffer(obj) );
}

static inline int Object_GetBuffer(PyObject *obj, Py_buffer *view, int flags)
{
    return safe_noref( PyObject_GetBuffer(obj, view, flags) );
}

static inline void Buffer_Release(Py_buffer *view)
{
    PyBuffer_Release(view);
    exception::check();
}

static inline Py_ssize_t Buffer_SizeFromFormat(const char * arg0)
{
    return safe_noref( PyBuffer_SizeFromFormat(arg0) );
}

static inline int Buffer_IsContiguous(Py_buffer *view, char fortran)
{
    return safe_noref( PyBuffer_IsContiguous(view, fortran) );
}

static inline void Buffer_FillContiguousStrides(int ndim, Py_ssize_t *shape, Py_ssize_t *strides, Py_ssize_t itemsize, char fortran)
{
    PyBuffer_FillContiguousStrides(ndim, shape, strides, itemsize, fortran);
    exception::check();
}

static inline int Buffer_FillInfo(Py_buffer *view, PyObject *obj, void *buf, Py_ssize_t len, int readonly, int infoflags)
{
    return safe_noref( PyBuffer_FillInfo(view, obj, buf, len, readonly, infoflags) );
}

static inline ref<PyObject> MemoryView_FromObject(PyObject *obj)
{
    return safe_ref( PyMemoryView_FromObject(obj) );
}

static inline ref<PyObject> MemoryView_FromBuffer(Py_buffer *view)
{
    return safe_ref( PyMemoryView_FromBuffer(view) );
}

static inline ref<PyObject> MemoryView_GetContiguous(PyObject *obj, int buffertype, char order)
{
    return safe_ref( PyMemoryView_GetContiguous(obj, buffertype, order) );
}

static inline int MemoryView_Check(PyObject *obj)
{
    return safe_noref( PyMemoryView_Check(obj) );
}

static inline Py_buffer* MemoryView_GET_BUFFER(PyObject *obj)
{
    return safe_noref( PyMemoryView_GET_BUFFER(obj) );
}

static inline int Buffer_Check(PyObject *p)
{
    return safe_noref( PyBuffer_Check(p) );
}

static inline ref<PyObject> Buffer_FromObject(PyObject *base, Py_ssize_t offset, Py_ssize_t size)
{
    return safe_ref( PyBuffer_FromObject(base, offset, size) );
}

static inline ref<PyObject> Buffer_FromReadWriteObject(PyObject *base, Py_ssize_t offset, Py_ssize_t size)
{
    return safe_ref( PyBuffer_FromReadWriteObject(base, offset, size) );
}

static inline ref<PyObject> Buffer_FromMemory(void *ptr, Py_ssize_t size)
{
    return safe_ref( PyBuffer_FromMemory(ptr, size) );
}

static inline ref<PyObject> Buffer_FromReadWriteMemory(void *ptr, Py_ssize_t size)
{
    return safe_ref( PyBuffer_FromReadWriteMemory(ptr, size) );
}

static inline ref<PyObject> Buffer_New(Py_ssize_t size)
{
    return safe_ref( PyBuffer_New(size) );
}

}

#endif // PYTHONWRAPPER_API_API_BUFFER__H

