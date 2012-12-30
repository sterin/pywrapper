

#ifndef PYTHONWRAPPER_API_BOOL__H
#define PYTHONWRAPPER_API_BOOL__H

namespace py
{

static inline int Bool_Check(PyObject *o)
{
    return safe_noref( PyBool_Check(o) );
}

static inline ref<PyObject> Bool_FromLong(long v)
{
    return safe_ref( PyBool_FromLong(v) );
}

}

#endif // PYTHONWRAPPER_API_API_BOOL__H

