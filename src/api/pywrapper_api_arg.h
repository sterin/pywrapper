

#ifndef PYTHONWRAPPER_API_ARG__H
#define PYTHONWRAPPER_API_ARG__H

namespace py
{

static inline int Arg_VaParse(PyObject *args, const char *format, va_list vargs)
{
    return safe_noref( PyArg_VaParse(args, format, vargs) );
}

static inline int Arg_VaParseTupleAndKeywords(PyObject *args, PyObject *kw, const char *format, char *keywords[], va_list vargs)
{
    return safe_noref( PyArg_VaParseTupleAndKeywords(args, kw, format, keywords, vargs) );
}

static inline ref<PyObject> VaBuildValue(const char *format, va_list vargs)
{
    return safe_ref( Py_VaBuildValue(format, vargs) );
}

}

#endif // PYTHONWRAPPER_API_API_ARG__H

