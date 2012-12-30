

#ifndef PYTHONWRAPPER_API_COBJECT__H
#define PYTHONWRAPPER_API_COBJECT__H

namespace py
{

static inline int CObject_Check(PyObject *p)
{
    return safe_noref( PyCObject_Check(p) );
}

static inline ref<PyObject> CObject_FromVoidPtr(void* cobj, void (*destr)(void *))
{
    return safe_ref( PyCObject_FromVoidPtr(cobj, destr) );
}

static inline ref<PyObject> CObject_FromVoidPtrAndDesc(void* cobj, void* desc, void (*destr)(void *, void *))
{
    return safe_ref( PyCObject_FromVoidPtrAndDesc(cobj, desc, destr) );
}

static inline void* CObject_AsVoidPtr(PyObject* self)
{
    return safe_noref( PyCObject_AsVoidPtr(self) );
}

static inline void* CObject_GetDesc(PyObject* self)
{
    return safe_noref( PyCObject_GetDesc(self) );
}

static inline int CObject_SetVoidPtr(PyObject* self, void* cobj)
{
    return safe_noref( PyCObject_SetVoidPtr(self, cobj) );
}

}

#endif // PYTHONWRAPPER_API_API_COBJECT__H

