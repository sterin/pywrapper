

#ifndef PYTHONWRAPPER_API_BYTEARRAY__H
#define PYTHONWRAPPER_API_BYTEARRAY__H

namespace py
{

static inline int ByteArray_Check(PyObject *o)
{
    return safe_noref( PyByteArray_Check(o) );
}

static inline int ByteArray_CheckExact(PyObject *o)
{
    return safe_noref( PyByteArray_CheckExact(o) );
}

static inline ref<PyObject> ByteArray_FromObject(PyObject *o)
{
    return safe_ref( PyByteArray_FromObject(o) );
}

static inline ref<PyObject> ByteArray_FromStringAndSize(const char *string, Py_ssize_t len)
{
    return safe_ref( PyByteArray_FromStringAndSize(string, len) );
}

static inline ref<PyObject> ByteArray_Concat(PyObject *a, PyObject *b)
{
    return safe_ref( PyByteArray_Concat(a, b) );
}

static inline Py_ssize_t ByteArray_Size(PyObject *bytearray)
{
    return safe_noref( PyByteArray_Size(bytearray) );
}

static inline char* ByteArray_AsString(PyObject *bytearray)
{
    return safe_noref( PyByteArray_AsString(bytearray) );
}

static inline int ByteArray_Resize(PyObject *bytearray, Py_ssize_t len)
{
    return safe_noref( PyByteArray_Resize(bytearray, len) );
}

static inline char* ByteArray_AS_STRING(PyObject *bytearray)
{
    return safe_noref( PyByteArray_AS_STRING(bytearray) );
}

static inline Py_ssize_t ByteArray_GET_SIZE(PyObject *bytearray)
{
    return safe_noref( PyByteArray_GET_SIZE(bytearray) );
}

}

#endif // PYTHONWRAPPER_API_API_BYTEARRAY__H

