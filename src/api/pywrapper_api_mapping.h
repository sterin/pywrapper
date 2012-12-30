

#ifndef PYTHONWRAPPER_API_MAPPING__H
#define PYTHONWRAPPER_API_MAPPING__H

namespace py
{

static inline int Mapping_Check(PyObject *o)
{
    return safe_noref( PyMapping_Check(o) );
}

static inline Py_ssize_t Mapping_Size(PyObject *o)
{
    return safe_noref( PyMapping_Size(o) );
}

static inline int Mapping_DelItemString(PyObject *o, char *key)
{
    return safe_noref( PyMapping_DelItemString(o, key) );
}

static inline int Mapping_DelItem(PyObject *o, PyObject *key)
{
    return safe_noref( PyMapping_DelItem(o, key) );
}

static inline int Mapping_HasKeyString(PyObject *o, char *key)
{
    return safe_noref( PyMapping_HasKeyString(o, key) );
}

static inline int Mapping_HasKey(PyObject *o, PyObject *key)
{
    return safe_noref( PyMapping_HasKey(o, key) );
}

static inline ref<PyObject> Mapping_Keys(PyObject *o)
{
    return safe_ref( PyMapping_Keys(o) );
}

static inline ref<PyObject> Mapping_Values(PyObject *o)
{
    return safe_ref( PyMapping_Values(o) );
}

static inline ref<PyObject> Mapping_Items(PyObject *o)
{
    return safe_ref( PyMapping_Items(o) );
}

static inline ref<PyObject> Mapping_GetItemString(PyObject *o, char *key)
{
    return safe_ref( PyMapping_GetItemString(o, key) );
}

static inline int Mapping_SetItemString(PyObject *o, char *key, PyObject *v)
{
    return safe_noref( PyMapping_SetItemString(o, key, v) );
}

}

#endif // PYTHONWRAPPER_API_API_MAPPING__H

