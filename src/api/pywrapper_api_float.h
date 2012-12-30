

#ifndef PYTHONWRAPPER_API_FLOAT__H
#define PYTHONWRAPPER_API_FLOAT__H

namespace py
{

static inline int Float_Check(PyObject *p)
{
    return safe_noref( PyFloat_Check(p) );
}

static inline int Float_CheckExact(PyObject *p)
{
    return safe_noref( PyFloat_CheckExact(p) );
}

static inline ref<PyObject> Float_FromString(PyObject *str, char **pend)
{
    return safe_ref( PyFloat_FromString(str, pend) );
}

static inline ref<PyObject> Float_FromDouble(double v)
{
    return safe_ref( PyFloat_FromDouble(v) );
}

static inline double Float_AsDouble(PyObject *pyfloat)
{
    return safe_noref( PyFloat_AsDouble(pyfloat) );
}

static inline double Float_AS_DOUBLE(PyObject *pyfloat)
{
    return safe_noref( PyFloat_AS_DOUBLE(pyfloat) );
}

static inline ref<PyObject> Float_GetInfo(void)
{
    return safe_ref( PyFloat_GetInfo() );
}

static inline double Float_GetMax()
{
    return safe_noref( PyFloat_GetMax() );
}

static inline double Float_GetMin()
{
    return safe_noref( PyFloat_GetMin() );
}

static inline int Float_ClearFreeList()
{
    return safe_noref( PyFloat_ClearFreeList() );
}

static inline void Float_AsString(char *buf, PyFloatObject *v)
{
    PyFloat_AsString(buf, v);
    exception::check();
}

static inline void Float_AsReprString(char *buf, PyFloatObject *v)
{
    PyFloat_AsReprString(buf, v);
    exception::check();
}

}

#endif // PYTHONWRAPPER_API_API_FLOAT__H

