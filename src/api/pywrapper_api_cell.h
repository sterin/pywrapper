

#ifndef PYTHONWRAPPER_API_CELL__H
#define PYTHONWRAPPER_API_CELL__H

namespace py
{

static inline int Cell_Check(PyObject* ob)
{
    return safe_noref( PyCell_Check(ob) );
}

static inline ref<PyObject> Cell_New(PyObject *ob)
{
    return safe_ref( PyCell_New(ob) );
}

static inline ref<PyObject> Cell_Get(PyObject *cell)
{
    return safe_ref( PyCell_Get(cell) );
}

static inline borrowed_ref<PyObject> Cell_GET(PyObject *cell)
{
    return safe_borrowed_ref( PyCell_GET(cell) );
}

static inline int Cell_Set(PyObject *cell, PyObject *value)
{
    return safe_noref( PyCell_Set(cell, value) );
}

static inline void Cell_SET(PyObject *cell, PyObject *value)
{
    PyCell_SET(cell, value);
    exception::check();
}

}

#endif // PYTHONWRAPPER_API_API_CELL__H

