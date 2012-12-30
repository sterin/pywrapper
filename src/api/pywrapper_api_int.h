

#ifndef PYTHONWRAPPER_API_INT__H
#define PYTHONWRAPPER_API_INT__H

namespace py
{

static inline int Int_Check(PyObject *o)
{
    return safe_noref( PyInt_Check(o) );
}

static inline int Int_CheckExact(PyObject *o)
{
    return safe_noref( PyInt_CheckExact(o) );
}

static inline ref<PyObject> Int_FromString(char *str, char **pend, int base)
{
    return safe_ref( PyInt_FromString(str, pend, base) );
}

static inline ref<PyObject> Int_FromLong(long ival)
{
    return safe_ref( PyInt_FromLong(ival) );
}

static inline ref<PyObject> Int_FromSsize_t(Py_ssize_t ival)
{
    return safe_ref( PyInt_FromSsize_t(ival) );
}

static inline ref<PyObject> Int_FromSize_t(size_t ival)
{
    return safe_ref( PyInt_FromSize_t(ival) );
}

static inline long Int_AsLong(PyObject *io)
{
    return safe_noref( PyInt_AsLong(io) );
}

static inline long Int_AS_LONG(PyObject *io)
{
    return safe_noref( PyInt_AS_LONG(io) );
}

static inline unsigned long Int_AsUnsignedLongMask(PyObject *io)
{
    return safe_noref( PyInt_AsUnsignedLongMask(io) );
}

static inline unsigned PY_LONG_LONG Int_AsUnsignedLongLongMask(PyObject *io)
{
    return safe_noref( PyInt_AsUnsignedLongLongMask(io) );
}

static inline Py_ssize_t Int_AsSsize_t(PyObject *io)
{
    return safe_noref( PyInt_AsSsize_t(io) );
}

static inline long Int_GetMax()
{
    return safe_noref( PyInt_GetMax() );
}

static inline int Int_ClearFreeList()
{
    return safe_noref( PyInt_ClearFreeList() );
}

}

#endif // PYTHONWRAPPER_API_API_INT__H

