

#ifndef PYTHONWRAPPER_API_FUNCTION__H
#define PYTHONWRAPPER_API_FUNCTION__H

namespace py
{

static inline int Function_Check(PyObject *o)
{
    return safe_noref( PyFunction_Check(o) );
}

static inline ref<PyObject> Function_New(PyObject *code, PyObject *globals)
{
    return safe_ref( PyFunction_New(code, globals) );
}

static inline borrowed_ref<PyObject> Function_GetCode(PyObject *op)
{
    return safe_borrowed_ref( PyFunction_GetCode(op) );
}

static inline borrowed_ref<PyObject> Function_GetGlobals(PyObject *op)
{
    return safe_borrowed_ref( PyFunction_GetGlobals(op) );
}

static inline borrowed_ref<PyObject> Function_GetModule(PyObject *op)
{
    return safe_borrowed_ref( PyFunction_GetModule(op) );
}

static inline borrowed_ref<PyObject> Function_GetDefaults(PyObject *op)
{
    return safe_borrowed_ref( PyFunction_GetDefaults(op) );
}

static inline int Function_SetDefaults(PyObject *op, PyObject *defaults)
{
    return safe_noref( PyFunction_SetDefaults(op, defaults) );
}

static inline borrowed_ref<PyObject> Function_GetClosure(PyObject *op)
{
    return safe_borrowed_ref( PyFunction_GetClosure(op) );
}

static inline int Function_SetClosure(PyObject *op, PyObject *closure)
{
    return safe_noref( PyFunction_SetClosure(op, closure) );
}

}

#endif // PYTHONWRAPPER_API_API_FUNCTION__H

