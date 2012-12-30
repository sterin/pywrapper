

#ifndef PYTHONWRAPPER_API_WEAKREF__H
#define PYTHONWRAPPER_API_WEAKREF__H

namespace py
{

static inline int Weakref_Check(PyObject* ob)
{
    return safe_noref( PyWeakref_Check(ob) );
}

static inline int Weakref_CheckRef(PyObject* ob)
{
    return safe_noref( PyWeakref_CheckRef(ob) );
}

static inline int Weakref_CheckProxy(PyObject* ob)
{
    return safe_noref( PyWeakref_CheckProxy(ob) );
}

static inline ref<PyObject> Weakref_NewRef(PyObject *ob, PyObject *callback)
{
    return safe_ref( PyWeakref_NewRef(ob, callback) );
}

static inline ref<PyObject> Weakref_NewProxy(PyObject *ob, PyObject *callback)
{
    return safe_ref( PyWeakref_NewProxy(ob, callback) );
}

static inline borrowed_ref<PyObject> Weakref_GetObject(PyObject *ref)
{
    return safe_borrowed_ref( PyWeakref_GetObject(ref) );
}

static inline borrowed_ref<PyObject> Weakref_GET_OBJECT(PyObject *ref)
{
    return safe_borrowed_ref( PyWeakref_GET_OBJECT(ref) );
}

}

#endif // PYTHONWRAPPER_API_API_WEAKREF__H

