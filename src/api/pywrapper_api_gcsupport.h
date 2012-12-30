

#ifndef PYTHONWRAPPER_API_GCSUPPORT__H
#define PYTHONWRAPPER_API_GCSUPPORT__H

namespace py
{

static inline void Object_GC_Track(PyObject *op)
{
    PyObject_GC_Track(op);
    exception::check();
}

static inline void _Object_GC_TRACK(PyObject *op)
{
    _PyObject_GC_TRACK(op);
    exception::check();
}

static inline void Object_GC_Del(void *op)
{
    PyObject_GC_Del(op);
    exception::check();
}

static inline void Object_GC_UnTrack(void *op)
{
    PyObject_GC_UnTrack(op);
    exception::check();
}

static inline void _Object_GC_UNTRACK(PyObject *op)
{
    _PyObject_GC_UNTRACK(op);
    exception::check();
}

}

#endif // PYTHONWRAPPER_API_API_GCSUPPORT__H

