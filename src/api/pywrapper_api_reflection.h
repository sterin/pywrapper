

#ifndef PYTHONWRAPPER_API_REFLECTION__H
#define PYTHONWRAPPER_API_REFLECTION__H

namespace py
{

static inline borrowed_ref<PyObject> Eval_GetBuiltins()
{
    return safe_borrowed_ref( PyEval_GetBuiltins() );
}

static inline borrowed_ref<PyObject> Eval_GetLocals()
{
    return safe_borrowed_ref( PyEval_GetLocals() );
}

static inline borrowed_ref<PyObject> Eval_GetGlobals()
{
    return safe_borrowed_ref( PyEval_GetGlobals() );
}

static inline borrowed_ref<PyFrameObject> Eval_GetFrame()
{
    return safe_borrowed_ref( PyEval_GetFrame() );
}

static inline int Frame_GetLineNumber(PyFrameObject *frame)
{
    return safe_noref( PyFrame_GetLineNumber(frame) );
}

static inline int Eval_GetRestricted()
{
    return safe_noref( PyEval_GetRestricted() );
}

static inline const char* Eval_GetFuncName(PyObject *func)
{
    return safe_noref( PyEval_GetFuncName(func) );
}

static inline const char* Eval_GetFuncDesc(PyObject *func)
{
    return safe_noref( PyEval_GetFuncDesc(func) );
}

}

#endif // PYTHONWRAPPER_API_API_REFLECTION__H

