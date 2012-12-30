

#ifndef PYTHONWRAPPER_API_ITER__H
#define PYTHONWRAPPER_API_ITER__H

namespace py
{

static inline int Iter_Check(PyObject *o)
{
    return safe_noref( PyIter_Check(o) );
}

static inline ref<PyObject> Iter_Next(PyObject *o)
{
    return safe_ref( PyIter_Next(o) );
}

}

#endif // PYTHONWRAPPER_API_API_ITER__H

