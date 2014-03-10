#ifndef PYTHONWRAPPER_CALLBACKS__H
#define PYTHONWRAPPER_CALLBACKS__H

#ifndef PYTHONWRAPPER_USER_CATCH
#define PYTHONWRAPPER_USER_CATCH
#endif // PYTHONWRAPPER_USER_CATCH

#define PYTHONWRAPPER_CATCH \
    \
    PYTHONWRAPPER_USER_CATCH \
    \
    catch (const py::exception& e) \
    { \
    } \
    catch (const std::bad_alloc& e) \
    { \
        PyErr_SetString(PyExc_MemoryError, e.what()); \
    } \
    catch (const std::exception& e) \
    { \
        PyErr_SetString(PyExc_RuntimeError, e.what()); \
    } \
    catch (...) \
    { \
        PyErr_SetNone(PyExc_RuntimeError); \
    }


#define PYTHONWRAPPER_METH_KEYWORDS(class_name, func_name, flags, docstring) \
    { #func_name, reinterpret_cast<PyCFunction>(static_cast<PyCFunctionWithKeywords>(wrappers::meth_keywords<class_name, &class_name::func_name>)), METH_KEYWORDS | (flags), docstring }

#define PYTHONWRAPPER_METH_O(class_name, func_name, flags, docstring) \
    { #func_name, reinterpret_cast<PyCFunction>(static_cast<PyCFunction>(wrappers::meth_o<class_name, &class_name::func_name>)), METH_O | (flags), docstring }

#define PYTHONWRAPPER_METH_NOARGS(class_name, func_name, flags, docstring) \
    { #func_name, reinterpret_cast<PyCFunction>(static_cast<PyNoArgsFunction>(wrappers::meth_noargs<class_name, &class_name::func_name>)), METH_NOARGS | (flags), docstring }

#define PYTHONWRAPPER_METH_VARARGS(class_name, func_name, flags, docstring) \
    { #func_name, reinterpret_cast<PyCFunction>(static_cast<PyCFunction>(wrappers::meth_varargs<class_name, &class_name::func_name>)), METH_VARARGS | (flags), docstring }

#define PYTHONWRAPPER_FUNC_VARARGS(func_name, flags, docstring) \
    { \
        #func_name, \
        reinterpret_cast<PyCFunction>(static_cast<PyCFunction>(wrappers::meth_varargs<func_name>)), \
        METH_VARARGS | (flags), \
        docstring \
    }

#define PYTHONWRAPPER_FUNC_KEYWORDS(func_name, flags, docstring) \
    { \
        #func_name, \
        reinterpret_cast<PyCFunction>(static_cast<PyCFunctionWithKeywords>(wrappers::meth_keywords<func_name>)), \
        METH_KEYWORDS | (flags), \
        docstring \
    }

#define PYTHONWRAPPER_GETSET(pymember_name, class_name, getter_name, setter_name, docstring) \
    { \
        #pymember_name, \
        reinterpret_cast<getter>(wrappers::getter<class_name, &class_name::getter_name>), \
        reinterpret_cast<setter>(wrappers::setter<class_name, &class_name::setter_name>), \
        docstring \
    }

#define PYTHONWRAPPER_GETTER(pymember_name, class_name, getter_name, docstring) \
    { \
        #pymember_name, \
        reinterpret_cast<getter>(wrappers::getter<class_name, &class_name::getter_name>), \
        0, \
        docstring \
    }

#define PYTHONWRAPPER_SETTER(pymember_name, class_name, setter_name, docstring) \
    { \
        #pymember_name, \
        0, \
        reinterpret_cast<setter>(wrappers::setter<class_name, &class_name::setter_name>), \
        docstring \
    }

namespace py
{

namespace wrappers
{

template<typename P>
PyObject* reprfunc(PyObject* self)
{
    assert( self );

    try
    {
        return reinterpret_cast<P*>(self)->tp_repr().release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename P, void (*F)(P*)>
void destructor(PyObject* p)
{
    try
    {
        F(reinterpret_cast<P*>(p));
    }
    PYTHONWRAPPER_CATCH
}

template<typename P, P* (*F)(_typeobject*, Py_ssize_t)>
PyObject* allocfunc(PyTypeObject *self, Py_ssize_t nitems)
{
    try
    {
        return reinterpret_cast<P*>(F(self, nitems));
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename P>
PyObject* newfunc(PyTypeObject *subtype, PyObject *args, PyObject *kwds)
{
    try
    {
        return reinterpret_cast<PyObject*>( P::tp_new(subtype, args, kwds) );
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename P, int (P::*F)(PyObject*)>
int cmpfunc(PyObject *self, PyObject *rhs)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        return (p->*F)(rhs);
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename P, long (P::*F)()>
long hashfunc(PyObject* self)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        return (p->*F)();
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename P, Py_ssize_t (P::*F)()>
Py_ssize_t mp_length(PyObject* self)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        return (p->*F)();
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename P, ref<PyObject> (P::*F)()>
PyObject* mp_subscript(PyObject* self, PyObject* key)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        ref<PyObject> res = (p->*F)();

        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename P, void (P::*F)(PyObject*, PyObject*)>
int mp_ass_subscript(PyObject* self, PyObject* key, PyObject* val)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        (p->*F)(key, val);

        return 0;
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename P, bool(P::*F)()>
int inquiry(PyObject* self)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        bool res = (p->*F)();

        return res ? 1 : 0;
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename P, Py_ssize_t (P::*F)()>
Py_ssize_t lenfunc(PyObject* self)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        return (p->*F)();
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename P, ref<PyObject> (P::*F)()>
PyObject* unaryfunc(PyObject* self)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        ref<PyObject> res = (p->*F)();

        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename P, int (P::*F)(PyObject* key)>
int objobjproc(PyObject* self, PyObject* key)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        return (p->*F)(key);
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename P, int (P::*F)(PyObject* key, PyObject* value)>
int objobjargproc(PyObject* self, PyObject* key, PyObject* value)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        return (p->*F)(key, value);
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename P, ref<PyObject> (P::*F)(PyObject*)>
PyObject* binaryfunc(PyObject* self, PyObject* o1)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        ref<PyObject> res = (p->*F)(o1);

        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename P, ref<PyObject> (P::*F)(PyObject*, PyObject*)>
PyObject* ternaryfunc(PyObject* self, PyObject* o1, PyObject* o2)
{
    assert( self );

    try
    {
        P* p = reinterpret_cast<P*>(self);

        ref<PyObject> res = (p->*F)(o1, o2);

        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename P>
int initproc(PyObject* self, PyObject *args, PyObject *kwds)
{
    assert( self );

    try
    {
        reinterpret_cast<P*>(self)->tp_init(args, kwds);
        return 0;
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename R, typename S, typename O, typename T, R* (*F)(S*,O*,R*)>
PyObject* descrgetfunc(PyObject *self, PyObject *obj, PyObject *type)
{
    try
    {
        return reinterpret_cast<PyObject*>(
            F(
                reinterpret_cast<S*>(self),
                reinterpret_cast<O*>(obj),
                reinterpret_cast<T*>(type)
            )
        );
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}


template<ref<PyObject> (*F)(PyObject*)>
PyObject* meth_varargs(PyObject* self_, PyObject* args_)
{
    try
    {
        ref<PyObject> res = F(args_);
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, ref<PyObject> (S::*F)(PyObject*)>
PyObject* meth_varargs(PyObject* self_, PyObject* args_)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        ref<PyObject> res = (self->*F)(args_);
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, void (S::*F)(PyObject*)>
PyObject* meth_varargs(PyObject* self_, PyObject* args_)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);

        (self->*F)(args_);

        Py_RETURN_NONE;
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, ref<PyObject> (*F)(PyObject*)>
PyObject* meth_o(PyObject*, PyObject* o)
{
    try
    {
        ref<PyObject> res = (*F)(o);
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, ref<PyObject> (S::*F)(PyObject*)>
PyObject* meth_o(PyObject* self_, PyObject* o)
{
    S* self = reinterpret_cast<S*>(self_);

    try
    {
        ref<PyObject> res = (self->*F)(o);
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, void (S::*F)(PyObject*)>
PyObject* meth_o(PyObject* self_, PyObject* o)
{
    S* self = reinterpret_cast<S*>(self_);

    try
    {
        (self->*F)(o);
        Py_RETURN_NONE;
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, ref<PyObject> (S::*F)()>
PyObject* meth_noargs(PyObject* self_)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        ref<PyObject> res = (self->*F)();
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, void (S::*F)()>
PyObject* meth_noargs(PyObject* self_)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);

        (self->*F)();

        Py_RETURN_NONE;
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<ref<PyObject> (*F)(PyObject*, PyObject*)>
PyObject* meth_keywords(PyObject* self_, PyObject* args, PyObject* kwds)
{
    try
    {
        ref<PyObject> res = (*F)(args, kwds);
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}


template<typename S, ref<PyObject> (S::*F)(PyObject*, PyObject*)>
PyObject* meth_keywords(PyObject* self_, PyObject* args, PyObject* kwds)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        ref<PyObject> res = (self->*F)(args, kwds);
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, void (S::*F)(PyObject*, PyObject*)>
PyObject* meth_keywords(PyObject* self_, PyObject* args, PyObject* kwds)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);

        (self->*F)(args, kwds);

        Py_RETURN_NONE;
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, void (S::*F)(borrowed_ref<PyObject>)>
int setter(PyObject* self_, PyObject* value, void *)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        (self->*F)(borrowed_ref<PyObject>(value));
        return 0;
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename S, void (S::*F)(PyObject*, void*)>
int setter(PyObject* self_, PyObject* value, void *closure)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        self->*F(value, closure);
        return 0;
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename S, ref<PyObject> S::*M>
int setter(PyObject* self_, PyObject* value, void*)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        self->*M = borrow(value);
        return 0;
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename S, typename T, ref<T> S::*M>
int setter(PyObject* self_, PyObject* value, void *)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        self->*M = borrow(&T::ensure(value));
        return 0;
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

template<typename S, ref<PyObject> (S::*F)()>
PyObject* getter(PyObject* self_, void *)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        ref<PyObject> res = (self->*F)();
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, ref<PyObject> (S::*F)(void*)>
PyObject* getter(PyObject* self_, void *closure)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        ref<PyObject> res = (self->*F)(closure);
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, ref<PyObject> S::*M>
PyObject* getter(PyObject* self_, void *)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        ref<PyObject> res = self->*M;
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, typename T, ref<T> S::*M>
PyObject* getter(PyObject* self_, void *)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        ref<PyObject> res(self->*M);
        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}

template<typename S, typename I>
PyObject* descrgetfunc(PyObject* self_, PyObject* inst_, PyObject*)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        I* inst = reinterpret_cast<I*>(inst_);

        ref<PyObject> res = self->tp_descr_get(inst);

        return res.release();
    }
    PYTHONWRAPPER_CATCH

    return NULL;
}


template<typename S, typename I>
int descrsetfunc(PyObject* self_, PyObject* inst_, PyObject* value_)
{
    try
    {
        S* self = reinterpret_cast<S*>(self_);
        I* inst = reinterpret_cast<I*>(inst_);

        self->tp_descr_set(inst, value_);

        return 0;
    }
    PYTHONWRAPPER_CATCH

    return -1;
}

} // namespace wrappers

} // namespace py

#endif // PYTHONWRAPPER_CALLBACKS__H
