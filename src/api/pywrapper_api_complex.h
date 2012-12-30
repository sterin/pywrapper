

#ifndef PYTHONWRAPPER_API_COMPLEX__H
#define PYTHONWRAPPER_API_COMPLEX__H

namespace py
{

static inline Py_complex __c_sum(Py_complex left, Py_complex right)
{
    return safe_noref( _Py_c_sum(left, right) );
}

static inline Py_complex __c_diff(Py_complex left, Py_complex right)
{
    return safe_noref( _Py_c_diff(left, right) );
}

static inline Py_complex __c_neg(Py_complex complex)
{
    return safe_noref( _Py_c_neg(complex) );
}

static inline Py_complex __c_prod(Py_complex left, Py_complex right)
{
    return safe_noref( _Py_c_prod(left, right) );
}

static inline Py_complex __c_quot(Py_complex dividend, Py_complex divisor)
{
    return safe_noref( _Py_c_quot(dividend, divisor) );
}

static inline Py_complex __c_pow(Py_complex num, Py_complex exp)
{
    return safe_noref( _Py_c_pow(num, exp) );
}

static inline int Complex_Check(PyObject *p)
{
    return safe_noref( PyComplex_Check(p) );
}

static inline int Complex_CheckExact(PyObject *p)
{
    return safe_noref( PyComplex_CheckExact(p) );
}

static inline ref<PyObject> Complex_FromCComplex(Py_complex v)
{
    return safe_ref( PyComplex_FromCComplex(v) );
}

static inline ref<PyObject> Complex_FromDoubles(double real, double imag)
{
    return safe_ref( PyComplex_FromDoubles(real, imag) );
}

static inline double Complex_RealAsDouble(PyObject *op)
{
    return safe_noref( PyComplex_RealAsDouble(op) );
}

static inline double Complex_ImagAsDouble(PyObject *op)
{
    return safe_noref( PyComplex_ImagAsDouble(op) );
}

static inline Py_complex Complex_AsCComplex(PyObject *op)
{
    return safe_noref( PyComplex_AsCComplex(op) );
}

}

#endif // PYTHONWRAPPER_API_API_COMPLEX__H

