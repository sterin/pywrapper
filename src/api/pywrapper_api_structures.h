

#ifndef PYTHONWRAPPER_API_STRUCTURES__H
#define PYTHONWRAPPER_API_STRUCTURES__H

namespace py
{

static inline ref<PyObject> FindMethod(PyMethodDef table[], PyObject *ob, char *name)
{
    return safe_ref( Py_FindMethod(table, ob, name) );
}

}

#endif // PYTHONWRAPPER_API_API_STRUCTURES__H

