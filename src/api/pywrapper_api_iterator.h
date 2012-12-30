

#ifndef PYTHONWRAPPER_API_ITERATOR__H
#define PYTHONWRAPPER_API_ITERATOR__H

namespace py
{

static inline int SeqIter_Check(PyObject* op)
{
    return safe_noref( PySeqIter_Check(op) );
}

static inline ref<PyObject> SeqIter_New(PyObject *seq)
{
    return safe_ref( PySeqIter_New(seq) );
}

static inline int CallIter_Check(PyObject* op)
{
    return safe_noref( PyCallIter_Check(op) );
}

static inline ref<PyObject> CallIter_New(PyObject *callable, PyObject *sentinel)
{
    return safe_ref( PyCallIter_New(callable, sentinel) );
}

}

#endif // PYTHONWRAPPER_API_API_ITERATOR__H

