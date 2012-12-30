

#ifndef PYTHONWRAPPER_API_CAPSULE__H
#define PYTHONWRAPPER_API_CAPSULE__H

namespace py
{

static inline int Capsule_CheckExact(PyObject *p)
{
    return safe_noref( PyCapsule_CheckExact(p) );
}

static inline ref<PyObject> Capsule_New(void *pointer, const char *name, PyCapsule_Destructor destructor)
{
    return safe_ref( PyCapsule_New(pointer, name, destructor) );
}

static inline void* Capsule_GetPointer(PyObject *capsule, const char *name)
{
    return safe_noref( PyCapsule_GetPointer(capsule, name) );
}

static inline PyCapsule_Destructor Capsule_GetDestructor(PyObject *capsule)
{
    return safe_noref( PyCapsule_GetDestructor(capsule) );
}

static inline void* Capsule_GetContext(PyObject *capsule)
{
    return safe_noref( PyCapsule_GetContext(capsule) );
}

static inline const char* Capsule_GetName(PyObject *capsule)
{
    return safe_noref( PyCapsule_GetName(capsule) );
}

static inline void* Capsule_Import(const char *name, int no_block)
{
    return safe_noref( PyCapsule_Import(name, no_block) );
}

static inline int Capsule_IsValid(PyObject *capsule, const char *name)
{
    return safe_noref( PyCapsule_IsValid(capsule, name) );
}

static inline int Capsule_SetContext(PyObject *capsule, void *context)
{
    return safe_noref( PyCapsule_SetContext(capsule, context) );
}

static inline int Capsule_SetDestructor(PyObject *capsule, PyCapsule_Destructor destructor)
{
    return safe_noref( PyCapsule_SetDestructor(capsule, destructor) );
}

static inline int Capsule_SetName(PyObject *capsule, const char *name)
{
    return safe_noref( PyCapsule_SetName(capsule, name) );
}

static inline int Capsule_SetPointer(PyObject *capsule, void *pointer)
{
    return safe_noref( PyCapsule_SetPointer(capsule, pointer) );
}

}

#endif // PYTHONWRAPPER_API_API_CAPSULE__H

