#ifndef PYTHONWRAPPER_OBJECT__H
#define PYTHONWRAPPER_OBJECT__H

namespace py
{

static inline ref<PyObject> build_args_tuple(const char *format, va_list vargs)
{
    ref<PyObject> p = VaBuildValue(format, vargs);

    if( Tuple_Check(p) )
    {
        return p;
    }

    ref<PyObject> t = Tuple_New(1);
    Tuple_SET_ITEM(t, 0, p);

    return t;
}

static inline ref<PyObject> Tuple_PackV(Py_ssize_t n, va_list vargs)
{
    ref<PyObject> result = Tuple_New(n);

    for(int i=0; i<n ; i++)
    {
        ref<PyObject> o ( va_arg(vargs, PyObject*) );
        Tuple_SET_ITEM(result, i, o);
    }

    return result;
}

static inline ref<PyObject> Tuple_Pack(Py_ssize_t n, ...)
{
    utils::va_list_wrapper vargs;
    va_start(vargs, n);

    return Tuple_PackV(n, vargs);
}

static inline int Arg_ParseTuple(PyObject *args, const char *format, ...)
{
    utils::va_list_wrapper vargs;
    va_start(vargs, format);

    return Arg_VaParse(args, format, vargs);
}

static inline int Arg_ParseTupleAndKeywords(PyObject *args, PyObject *kw, const char *format, char *keywords[], ...)
{
	utils::va_list_wrapper vargs;
	va_start(vargs, keywords);

    return Arg_VaParseTupleAndKeywords(args, kw, format, keywords, vargs);
}

static inline ref<PyObject> BuildValue(const char *format, ...)
{
	utils::va_list_wrapper vargs;
	va_start(vargs, format);

    return VaBuildValue(format, vargs);
}

static inline ref<PyObject> Object_CallFunctionV(PyObject *callable,  char* format, va_list vargs)
{
    return Object_Call(callable, build_args_tuple(format, vargs), 0);
}

static inline ref<PyObject> Object_CallFunction(PyObject *callable,  char *format,  ...)
{
    utils::va_list_wrapper vargs;
    va_start(vargs, format);

    return Object_CallFunctionV(callable, format, vargs);
}

static inline ref<PyObject> Object_CallMethodV(PyObject *o, char *name, char *format, va_list vargs)
{
    if( !o || ! name )
    {
        throw exception::format(PyExc_SystemError, "null argument to internal routine");
    }

    ref<PyObject> func = Object_GetAttrString(o, name);

    if ( ! func )
    {
        throw exception( PyExc_AttributeError, name);
    }

    return Object_CallFunctionV(func, format, vargs);
}

static inline ref<PyObject> Object_CallMethod(PyObject *o, char *name, char *format, ...)
{
    utils::va_list_wrapper vargs;
    va_start(vargs, format);

    return Object_CallMethodV(o, name, format, vargs);
}

static inline ref<PyObject> objargs_mktuple(va_list va)
{
    utils::va_list_wrapper countva(va);

    int n;

    for(n=0; va_arg(countva.get(), PyObject*) ; ++n )
    {
    }

    ref<PyObject> result = Tuple_New(n);

    for( int i=0; i<n ; i++ )
    {
        ref<PyObject> o( va_arg(va, PyObject*) );
        Tuple_SET_ITEM(result, i, o);
    }

    return result;
}

static inline ref<PyObject> Object_CallFunctionObjArgsV(PyObject *callable, va_list vargs)
{
    return Object_CallObject(callable, objargs_mktuple(vargs));
}

static inline ref<PyObject> Object_CallFunctionObjArgs(PyObject *callable, ...)
{
    utils::va_list_wrapper vargs;
    va_start(vargs, callable);

    return Object_CallFunctionObjArgsV(callable, vargs);
}

static inline ref<PyObject> Object_CallMethodObjArgsV(PyObject *o,  PyObject *name, va_list vargs)
{
    if( !o || ! name )
    {
        throw exception::format(PyExc_SystemError, "null argument to internal routine");
    }

    ref<PyObject> func = Object_GetAttr(o, name);

    if ( ! func )
    {
        throw exception( PyExc_AttributeError, name);
    }

    ref<PyObject> args = objargs_mktuple(vargs);

    return Object_Call( func, args, 0);
}

static inline ref<PyObject> Object_CallMethodObjArgs(PyObject *o,  PyObject *name,  ...)
{
    utils::va_list_wrapper args;
    va_start(args, name);

    return Object_CallMethodObjArgsV(o, name, args) ;
}


static inline Py_ssize_t Object_Size(PyObject *o)
{
    return safe_noref( PyObject_Size(o) );
}


static inline ref<PyObject> Unicode_FromFormat(const char *format, ...)
{
    utils::va_list_wrapper vargs;
    va_start(vargs, format);

    return safe_ref(PyUnicode_FromFormatV(format, vargs));
}

} // namespace py

#endif // PYTHONWRAPPER_OBJECT__H
