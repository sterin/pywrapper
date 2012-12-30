#ifndef PYTHONWRAPPER_API_GEN__H
#define PYTHONWRAPPER_API_GEN__H

namespace py
{

static inline int Gen_Check(PyObject* ob)
{
    return safe_noref( PyGen_Check(ob) );
}

static inline int Gen_CheckExact(PyObject* ob)
{
    return safe_noref( PyGen_CheckExact(ob) );
}

static inline ref<PyObject> Gen_New(stolen_ref<PyFrameObject> frame)
{
    return safe_ref( PyGen_New(frame.release()) );
}

}

#endif // PYTHONWRAPPER_API_API_GEN__H

