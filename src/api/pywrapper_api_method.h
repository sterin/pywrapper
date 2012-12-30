

#ifndef PYTHONWRAPPER_API_METHOD__H
#define PYTHONWRAPPER_API_METHOD__H

namespace py
{

static inline int Method_Check(PyObject *o)
{
    return safe_noref( PyMethod_Check(o) );
}

static inline ref<PyObject> Method_New(PyObject *func, PyObject *self, PyObject *class_)
{
    return safe_ref( PyMethod_New(func, self, class_) );
}

static inline borrowed_ref<PyObject> Method_Class(PyObject *meth)
{
    return safe_borrowed_ref( PyMethod_Class(meth) );
}

static inline borrowed_ref<PyObject> Method_GET_CLASS(PyObject *meth)
{
    return safe_borrowed_ref( PyMethod_GET_CLASS(meth) );
}

static inline borrowed_ref<PyObject> Method_Function(PyObject *meth)
{
    return safe_borrowed_ref( PyMethod_Function(meth) );
}

static inline borrowed_ref<PyObject> Method_GET_FUNCTION(PyObject *meth)
{
    return safe_borrowed_ref( PyMethod_GET_FUNCTION(meth) );
}

static inline borrowed_ref<PyObject> Method_Self(PyObject *meth)
{
    return safe_borrowed_ref( PyMethod_Self(meth) );
}

static inline borrowed_ref<PyObject> Method_GET_SELF(PyObject *meth)
{
    return safe_borrowed_ref( PyMethod_GET_SELF(meth) );
}

static inline int Method_ClearFreeList()
{
    return safe_noref( PyMethod_ClearFreeList() );
}

}

#endif // PYTHONWRAPPER_API_API_METHOD__H

