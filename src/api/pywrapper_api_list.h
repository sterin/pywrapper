

#ifndef PYTHONWRAPPER_API_LIST__H
#define PYTHONWRAPPER_API_LIST__H

namespace py
{

static inline int List_Check(PyObject *p)
{
    return safe_noref( PyList_Check(p) );
}

static inline int List_CheckExact(PyObject *p)
{
    return safe_noref( PyList_CheckExact(p) );
}

static inline ref<PyObject> List_New(Py_ssize_t len)
{
    return safe_ref( PyList_New(len) );
}

static inline Py_ssize_t List_Size(PyObject *list)
{
    return safe_noref( PyList_Size(list) );
}

static inline Py_ssize_t List_GET_SIZE(PyObject *list)
{
    return safe_noref( PyList_GET_SIZE(list) );
}

static inline borrowed_ref<PyObject> List_GetItem(PyObject *list, Py_ssize_t index)
{
    return safe_borrowed_ref( PyList_GetItem(list, index) );
}

static inline borrowed_ref<PyObject> List_GET_ITEM(PyObject *list, Py_ssize_t i)
{
    return safe_borrowed_ref( PyList_GET_ITEM(list, i) );
}

static inline int List_SetItem(PyObject *list, Py_ssize_t index, stolen_ref<PyObject> item)
{
    return safe_noref( PyList_SetItem(list, index, item.release()) );
}

static inline void List_SET_ITEM(PyObject *list, Py_ssize_t index, stolen_ref<PyObject> item)
{
    PyList_SET_ITEM(list, index, item.release());
    exception::check();
}

static inline int List_Insert(PyObject *list, Py_ssize_t index, PyObject *item)
{
    return safe_noref( PyList_Insert(list, index, item) );
}

static inline int List_Append(PyObject *list, PyObject *item)
{
    return safe_noref( PyList_Append(list, item) );
}

static inline ref<PyObject> List_GetSlice(PyObject *list, Py_ssize_t low, Py_ssize_t high)
{
    return safe_ref( PyList_GetSlice(list, low, high) );
}

static inline int List_SetSlice(PyObject *list, Py_ssize_t low, Py_ssize_t high, PyObject *itemlist)
{
    return safe_noref( PyList_SetSlice(list, low, high, itemlist) );
}

static inline int List_Sort(PyObject *list)
{
    return safe_noref( PyList_Sort(list) );
}

static inline int List_Reverse(PyObject *list)
{
    return safe_noref( PyList_Reverse(list) );
}

static inline ref<PyObject> List_AsTuple(PyObject *list)
{
    return safe_ref( PyList_AsTuple(list) );
}

}

#endif // PYTHONWRAPPER_API_API_LIST__H

