

#ifndef PYTHONWRAPPER_API_DESCRIPTOR__H
#define PYTHONWRAPPER_API_DESCRIPTOR__H

namespace py
{

static inline ref<PyObject> Descr_NewGetSet(PyTypeObject *type, struct PyGetSetDef *getset)
{
    return safe_ref( PyDescr_NewGetSet(type, getset) );
}

static inline ref<PyObject> Descr_NewMember(PyTypeObject *type, struct PyMemberDef *meth)
{
    return safe_ref( PyDescr_NewMember(type, meth) );
}

static inline ref<PyObject> Descr_NewMethod(PyTypeObject *type, struct PyMethodDef *meth)
{
    return safe_ref( PyDescr_NewMethod(type, meth) );
}

static inline ref<PyObject> Descr_NewWrapper(PyTypeObject *type, struct wrapperbase *wrapper, void *wrapped)
{
    return safe_ref( PyDescr_NewWrapper(type, wrapper, wrapped) );
}

static inline ref<PyObject> Descr_NewClassMethod(PyTypeObject *type, PyMethodDef *method)
{
    return safe_ref( PyDescr_NewClassMethod(type, method) );
}

static inline int Descr_IsData(PyObject *descr)
{
    return safe_noref( PyDescr_IsData(descr) );
}

static inline ref<PyObject> Wrapper_New(PyObject * arg0, PyObject * arg1)
{
    return safe_ref( PyWrapper_New(arg0, arg1) );
}

}

#endif // PYTHONWRAPPER_API_API_DESCRIPTOR__H

