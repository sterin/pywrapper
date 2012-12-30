

#ifndef PYTHONWRAPPER_API_DICT__H
#define PYTHONWRAPPER_API_DICT__H

namespace py
{

static inline int Dict_Check(PyObject *p)
{
    return safe_noref( PyDict_Check(p) );
}

static inline int Dict_CheckExact(PyObject *p)
{
    return safe_noref( PyDict_CheckExact(p) );
}

static inline ref<PyObject> Dict_New()
{
    return safe_ref( PyDict_New() );
}

static inline ref<PyObject> DictProxy_New(PyObject *dict)
{
    return safe_ref( PyDictProxy_New(dict) );
}

static inline void Dict_Clear(PyObject *p)
{
    PyDict_Clear(p);
    exception::check();
}

static inline int Dict_Contains(PyObject *p, PyObject *key)
{
    return safe_noref( PyDict_Contains(p, key) );
}

static inline ref<PyObject> Dict_Copy(PyObject *p)
{
    return safe_ref( PyDict_Copy(p) );
}

static inline int Dict_SetItem(PyObject *p, PyObject *key, PyObject *val)
{
    return safe_noref( PyDict_SetItem(p, key, val) );
}

static inline int Dict_SetItemString(PyObject *p, const char *key, PyObject *val)
{
    return safe_noref( PyDict_SetItemString(p, key, val) );
}

static inline int Dict_DelItem(PyObject *p, PyObject *key)
{
    return safe_noref( PyDict_DelItem(p, key) );
}

static inline int Dict_DelItemString(PyObject *p, char *key)
{
    return safe_noref( PyDict_DelItemString(p, key) );
}

static inline borrowed_ref<PyObject> Dict_GetItem(PyObject *p, PyObject *key)
{
    return safe_borrowed_ref( PyDict_GetItem(p, key) );
}

static inline borrowed_ref<PyObject> Dict_GetItemString(PyObject *p, const char *key)
{
    return safe_borrowed_ref( PyDict_GetItemString(p, key) );
}

static inline ref<PyObject> Dict_Items(PyObject *p)
{
    return safe_ref( PyDict_Items(p) );
}

static inline ref<PyObject> Dict_Keys(PyObject *p)
{
    return safe_ref( PyDict_Keys(p) );
}

static inline ref<PyObject> Dict_Values(PyObject *p)
{
    return safe_ref( PyDict_Values(p) );
}

static inline Py_ssize_t Dict_Size(PyObject *p)
{
    return safe_noref( PyDict_Size(p) );
}

static inline int Dict_Next(PyObject *p, Py_ssize_t *ppos, PyObject **pkey, PyObject **pvalue)
{
    return safe_noref( PyDict_Next(p, ppos, pkey, pvalue) );
}

static inline int Dict_Merge(PyObject *a, PyObject *b, int override)
{
    return safe_noref( PyDict_Merge(a, b, override) );
}

static inline int Dict_Update(PyObject *a, PyObject *b)
{
    return safe_noref( PyDict_Update(a, b) );
}

static inline int Dict_MergeFromSeq2(PyObject *a, PyObject *seq2, int override)
{
    return safe_noref( PyDict_MergeFromSeq2(a, seq2, override) );
}

}

#endif // PYTHONWRAPPER_API_API_DICT__H

