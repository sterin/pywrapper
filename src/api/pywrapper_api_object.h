

#ifndef PYTHONWRAPPER_API_OBJECT__H
#define PYTHONWRAPPER_API_OBJECT__H

namespace py
{

static inline int Object_Print(PyObject *o, FILE *fp, int flags)
{
    return safe_noref( PyObject_Print(o, fp, flags) );
}

static inline int Object_HasAttr(PyObject *o, PyObject *attr_name)
{
    return safe_noref( PyObject_HasAttr(o, attr_name) );
}

static inline int Object_HasAttrString(PyObject *o, const char *attr_name)
{
    return safe_noref( PyObject_HasAttrString(o, attr_name) );
}

static inline ref<PyObject> Object_GetAttr(PyObject *o, PyObject *attr_name)
{
    return safe_ref( PyObject_GetAttr(o, attr_name) );
}

static inline ref<PyObject> Object_GetAttrString(PyObject *o, const char *attr_name)
{
    return safe_ref( PyObject_GetAttrString(o, attr_name) );
}

static inline ref<PyObject> Object_GenericGetAttr(PyObject *o, PyObject *name)
{
    return safe_ref( PyObject_GenericGetAttr(o, name) );
}

static inline int Object_SetAttr(PyObject *o, PyObject *attr_name, PyObject *v)
{
    return safe_noref( PyObject_SetAttr(o, attr_name, v) );
}

static inline int Object_SetAttrString(PyObject *o, const char *attr_name, PyObject *v)
{
    return safe_noref( PyObject_SetAttrString(o, attr_name, v) );
}

static inline int Object_GenericSetAttr(PyObject *o, PyObject *name, PyObject *value)
{
    return safe_noref( PyObject_GenericSetAttr(o, name, value) );
}

static inline int Object_DelAttr(PyObject *o, PyObject *attr_name)
{
    return safe_noref( PyObject_DelAttr(o, attr_name) );
}

static inline int Object_DelAttrString(PyObject *o, const char *attr_name)
{
    return safe_noref( PyObject_DelAttrString(o, attr_name) );
}

static inline ref<PyObject> Object_RichCompare(PyObject *o1, PyObject *o2, int opid)
{
    return safe_ref( PyObject_RichCompare(o1, o2, opid) );
}

static inline int Object_RichCompareBool(PyObject *o1, PyObject *o2, int opid)
{
    return safe_noref( PyObject_RichCompareBool(o1, o2, opid) );
}

static inline int Object_Cmp(PyObject *o1, PyObject *o2, int *result)
{
    return safe_noref( PyObject_Cmp(o1, o2, result) );
}

static inline int Object_Compare(PyObject *o1, PyObject *o2)
{
    return safe_noref( PyObject_Compare(o1, o2) );
}

static inline ref<PyObject> Object_Repr(PyObject *o)
{
    return safe_ref( PyObject_Repr(o) );
}

static inline ref<PyObject> Object_Str(PyObject *o)
{
    return safe_ref( PyObject_Str(o) );
}

static inline ref<PyObject> Object_Bytes(PyObject *o)
{
    return safe_ref( PyObject_Bytes(o) );
}

static inline ref<PyObject> Object_Unicode(PyObject *o)
{
    return safe_ref( PyObject_Unicode(o) );
}

static inline int Object_IsInstance(PyObject *inst, PyObject *cls)
{
    return safe_noref( PyObject_IsInstance(inst, cls) );
}

static inline int Object_IsSubclass(PyObject *derived, PyObject *cls)
{
    return safe_noref( PyObject_IsSubclass(derived, cls) );
}

static inline int Callable_Check(PyObject *o)
{
    return safe_noref( PyCallable_Check(o) );
}

static inline ref<PyObject> Object_Call(PyObject *callable_object, PyObject *args, PyObject *kw)
{
    return safe_ref( PyObject_Call(callable_object, args, kw) );
}

static inline ref<PyObject> Object_CallObject(PyObject *callable_object, PyObject *args)
{
    return safe_ref( PyObject_CallObject(callable_object, args) );
}

static inline long Object_Hash(PyObject *o)
{
    return safe_noref( PyObject_Hash(o) );
}

static inline long Object_HashNotImplemented(PyObject *o)
{
    return safe_noref( PyObject_HashNotImplemented(o) );
}

static inline int Object_IsTrue(PyObject *o)
{
    return safe_noref( PyObject_IsTrue(o) );
}

static inline int Object_Not(PyObject *o)
{
    return safe_noref( PyObject_Not(o) );
}

static inline ref<PyObject> Object_Type(PyObject *o)
{
    return safe_ref( PyObject_Type(o) );
}

static inline int Object_TypeCheck(PyObject *o, PyTypeObject *type)
{
    return safe_noref( PyObject_TypeCheck(o, type) );
}

static inline Py_ssize_t Object_Length(PyObject *o)
{
    return safe_noref( PyObject_Length(o) );
}

static inline ref<PyObject> Object_GetItem(PyObject *o, PyObject *key)
{
    return safe_ref( PyObject_GetItem(o, key) );
}

static inline int Object_SetItem(PyObject *o, PyObject *key, PyObject *v)
{
    return safe_noref( PyObject_SetItem(o, key, v) );
}

static inline int Object_DelItem(PyObject *o, PyObject *key)
{
    return safe_noref( PyObject_DelItem(o, key) );
}

static inline int Object_AsFileDescriptor(PyObject *o)
{
    return safe_noref( PyObject_AsFileDescriptor(o) );
}

static inline ref<PyObject> Object_Dir(PyObject *o)
{
    return safe_ref( PyObject_Dir(o) );
}

static inline ref<PyObject> Object_GetIter(PyObject *o)
{
    return safe_ref( PyObject_GetIter(o) );
}

}

#endif // PYTHONWRAPPER_API_API_OBJECT__H

