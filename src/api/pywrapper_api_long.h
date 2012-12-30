

#ifndef PYTHONWRAPPER_API_LONG__H
#define PYTHONWRAPPER_API_LONG__H

namespace py
{

static inline int Long_Check(PyObject *p)
{
    return safe_noref( PyLong_Check(p) );
}

static inline int Long_CheckExact(PyObject *p)
{
    return safe_noref( PyLong_CheckExact(p) );
}

static inline ref<PyObject> Long_FromLong(long v)
{
    return safe_ref( PyLong_FromLong(v) );
}

static inline ref<PyObject> Long_FromUnsignedLong(unsigned long v)
{
    return safe_ref( PyLong_FromUnsignedLong(v) );
}

static inline ref<PyObject> Long_FromSsize_t(Py_ssize_t v)
{
    return safe_ref( PyLong_FromSsize_t(v) );
}

static inline ref<PyObject> Long_FromSize_t(size_t v)
{
    return safe_ref( PyLong_FromSize_t(v) );
}

static inline ref<PyObject> Long_FromLongLong(PY_LONG_LONG v)
{
    return safe_ref( PyLong_FromLongLong(v) );
}

static inline ref<PyObject> Long_FromUnsignedLongLong(unsigned PY_LONG_LONG v)
{
    return safe_ref( PyLong_FromUnsignedLongLong(v) );
}

static inline ref<PyObject> Long_FromDouble(double v)
{
    return safe_ref( PyLong_FromDouble(v) );
}

static inline ref<PyObject> Long_FromString(char *str, char **pend, int base)
{
    return safe_ref( PyLong_FromString(str, pend, base) );
}

static inline ref<PyObject> Long_FromUnicode(Py_UNICODE *u, Py_ssize_t length, int base)
{
    return safe_ref( PyLong_FromUnicode(u, length, base) );
}

static inline ref<PyObject> Long_FromVoidPtr(void *p)
{
    return safe_ref( PyLong_FromVoidPtr(p) );
}

static inline long Long_AsLong(PyObject *pylong)
{
    return safe_noref( PyLong_AsLong(pylong) );
}

static inline long Long_AsLongAndOverflow(PyObject *pylong, int *overflow)
{
    return safe_noref( PyLong_AsLongAndOverflow(pylong, overflow) );
}

static inline PY_LONG_LONG Long_AsLongLongAndOverflow(PyObject *pylong, int *overflow)
{
    return safe_noref( PyLong_AsLongLongAndOverflow(pylong, overflow) );
}

static inline Py_ssize_t Long_AsSsize_t(PyObject *pylong)
{
    return safe_noref( PyLong_AsSsize_t(pylong) );
}

static inline unsigned long Long_AsUnsignedLong(PyObject *pylong)
{
    return safe_noref( PyLong_AsUnsignedLong(pylong) );
}

static inline PY_LONG_LONG Long_AsLongLong(PyObject *pylong)
{
    return safe_noref( PyLong_AsLongLong(pylong) );
}

static inline unsigned PY_LONG_LONG Long_AsUnsignedLongLong(PyObject *pylong)
{
    return safe_noref( PyLong_AsUnsignedLongLong(pylong) );
}

static inline unsigned long Long_AsUnsignedLongMask(PyObject *io)
{
    return safe_noref( PyLong_AsUnsignedLongMask(io) );
}

static inline unsigned PY_LONG_LONG Long_AsUnsignedLongLongMask(PyObject *io)
{
    return safe_noref( PyLong_AsUnsignedLongLongMask(io) );
}

static inline double Long_AsDouble(PyObject *pylong)
{
    return safe_noref( PyLong_AsDouble(pylong) );
}

static inline void* Long_AsVoidPtr(PyObject *pylong)
{
    return safe_noref( PyLong_AsVoidPtr(pylong) );
}

}

#endif // PYTHONWRAPPER_API_API_LONG__H

