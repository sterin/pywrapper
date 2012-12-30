

#ifndef PYTHONWRAPPER_API_OBJBUFFER__H
#define PYTHONWRAPPER_API_OBJBUFFER__H

namespace py
{

static inline int Object_AsCharBuffer(PyObject *obj, const char **buffer, Py_ssize_t *buffer_len)
{
    return safe_noref( PyObject_AsCharBuffer(obj, buffer, buffer_len) );
}

static inline int Object_AsReadBuffer(PyObject *obj, const void **buffer, Py_ssize_t *buffer_len)
{
    return safe_noref( PyObject_AsReadBuffer(obj, buffer, buffer_len) );
}

static inline int Object_CheckReadBuffer(PyObject *o)
{
    return safe_noref( PyObject_CheckReadBuffer(o) );
}

static inline int Object_AsWriteBuffer(PyObject *obj, void **buffer, Py_ssize_t *buffer_len)
{
    return safe_noref( PyObject_AsWriteBuffer(obj, buffer, buffer_len) );
}

}

#endif // PYTHONWRAPPER_API_API_OBJBUFFER__H

