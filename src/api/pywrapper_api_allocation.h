

#ifndef PYTHONWRAPPER_API_ALLOCATION__H
#define PYTHONWRAPPER_API_ALLOCATION__H

namespace py
{

static inline ref<PyObject> _Object_New(PyTypeObject *type)
{
    return safe_ref( _PyObject_New(type) );
}

static inline ref<PyVarObject> _Object_NewVar(PyTypeObject *type, Py_ssize_t size)
{
    return safe_ref( _PyObject_NewVar(type, size) );
}

static inline void _Object_Del(PyObject *op)
{
    _PyObject_Del(op);
    exception::check();
}

static inline borrowed_ref<PyObject> Object_Init(PyObject *op, PyTypeObject *type)
{
    return safe_borrowed_ref( PyObject_Init(op, type) );
}

static inline borrowed_ref<PyVarObject> Object_InitVar(PyVarObject *op, PyTypeObject *type, Py_ssize_t size)
{
    return safe_borrowed_ref( PyObject_InitVar(op, type, size) );
}

static inline void Object_Del(PyObject *op)
{
    PyObject_Del(op);
    exception::check();
}

static inline borrowed_ref<PyObject> InitModule(char *name, PyMethodDef *methods)
{
    return safe_borrowed_ref( Py_InitModule(name, methods) );
}

static inline borrowed_ref<PyObject> InitModule3(char *name, PyMethodDef *methods, char *doc)
{
    return safe_borrowed_ref( Py_InitModule3(name, methods, doc) );
}

static inline borrowed_ref<PyObject> InitModule4(char *name, PyMethodDef *methods, char *doc, PyObject *self, int apiver)
{
    return safe_borrowed_ref( Py_InitModule4(name, methods, doc, self, apiver) );
}

}

#endif // PYTHONWRAPPER_API_API_ALLOCATION__H

