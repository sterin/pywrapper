

#ifndef PYTHONWRAPPER_API_REFCOUNTING__H
#define PYTHONWRAPPER_API_REFCOUNTING__H

namespace py
{

static inline void _INCREF(PyObject *o)
{
    Py_INCREF(o);
    exception::check();
}

static inline void XINCREF(PyObject *o)
{
    Py_XINCREF(o);
    exception::check();
}

static inline void _DECREF(PyObject *o)
{
    Py_DECREF(o);
    exception::check();
}

static inline void XDECREF(PyObject *o)
{
    Py_XDECREF(o);
    exception::check();
}

static inline void CLEAR(PyObject *o)
{
    Py_CLEAR(o);
    exception::check();
}

}

#endif // PYTHONWRAPPER_API_API_REFCOUNTING__H

