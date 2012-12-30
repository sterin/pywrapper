

#ifndef PYTHONWRAPPER_API_STRING__H
#define PYTHONWRAPPER_API_STRING__H

namespace py
{

static inline int String_Check(PyObject *o)
{
    return safe_noref( PyString_Check(o) );
}

static inline int String_CheckExact(PyObject *o)
{
    return safe_noref( PyString_CheckExact(o) );
}

static inline ref<PyObject> String_FromString(const char *v)
{
    return safe_ref( PyString_FromString(v) );
}

static inline ref<PyObject> String_FromStringAndSize(const char *v, Py_ssize_t len)
{
    return safe_ref( PyString_FromStringAndSize(v, len) );
}

static inline ref<PyObject> String_FromFormatV(const char *format, va_list vargs)
{
    return safe_ref( PyString_FromFormatV(format, vargs) );
}

static inline Py_ssize_t String_Size(PyObject *string)
{
    return safe_noref( PyString_Size(string) );
}

static inline Py_ssize_t String_GET_SIZE(PyObject *string)
{
    return safe_noref( PyString_GET_SIZE(string) );
}

static inline char* String_AsString(PyObject *string)
{
    return safe_noref( PyString_AsString(string) );
}

static inline char* String_AS_STRING(PyObject *string)
{
    return safe_noref( PyString_AS_STRING(string) );
}

static inline int String_AsStringAndSize(PyObject *obj, char **buffer, Py_ssize_t *length)
{
    return safe_noref( PyString_AsStringAndSize(obj, buffer, length) );
}

static inline void String_Concat(replace_ref<PyObject> string, PyObject *newpart)
{
    PyString_Concat(string, newpart);
    exception::check();
}

static inline void String_ConcatAndDel(replace_ref<PyObject> string, stolen_ref<PyObject> newpart)
{
    PyString_ConcatAndDel(string, newpart.release());
    exception::check();
}

static inline int _String_Resize(PyObject **string, Py_ssize_t newsize)
{
    return safe_noref( _PyString_Resize(string, newsize) );
}

static inline ref<PyObject> String_Format(PyObject *format, PyObject *args)
{
    return safe_ref( PyString_Format(format, args) );
}

static inline void String_InternInPlace(PyObject **string)
{
    PyString_InternInPlace(string);
    exception::check();
}

static inline ref<PyObject> String_InternFromString(const char *v)
{
    return safe_ref( PyString_InternFromString(v) );
}

static inline ref<PyObject> String_Decode(const char *s, Py_ssize_t size, const char *encoding, const char *errors)
{
    return safe_ref( PyString_Decode(s, size, encoding, errors) );
}

static inline ref<PyObject> String_AsDecodedObject(PyObject *str, const char *encoding, const char *errors)
{
    return safe_ref( PyString_AsDecodedObject(str, encoding, errors) );
}

static inline ref<PyObject> String_Encode(const char *s, Py_ssize_t size, const char *encoding, const char *errors)
{
    return safe_ref( PyString_Encode(s, size, encoding, errors) );
}

static inline ref<PyObject> String_AsEncodedObject(PyObject *str, const char *encoding, const char *errors)
{
    return safe_ref( PyString_AsEncodedObject(str, encoding, errors) );
}

}

#endif // PYTHONWRAPPER_API_API_STRING__H

