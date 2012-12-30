

#ifndef PYTHONWRAPPER_API_IMPORT__H
#define PYTHONWRAPPER_API_IMPORT__H

namespace py
{

static inline ref<PyObject> Import_ImportModule(const char *name)
{
    return safe_ref( PyImport_ImportModule(name) );
}

static inline ref<PyObject> Import_ImportModuleNoBlock(const char *name)
{
    return safe_ref( PyImport_ImportModuleNoBlock(name) );
}

static inline ref<PyObject> Import_ImportModuleEx(char *name, PyObject *globals, PyObject *locals, PyObject *fromlist)
{
    return safe_ref( PyImport_ImportModuleEx(name, globals, locals, fromlist) );
}

static inline ref<PyObject> Import_ImportModuleLevel(char *name, PyObject *globals, PyObject *locals, PyObject *fromlist, int level)
{
    return safe_ref( PyImport_ImportModuleLevel(name, globals, locals, fromlist, level) );
}

static inline ref<PyObject> Import_Import(PyObject *name)
{
    return safe_ref( PyImport_Import(name) );
}

static inline ref<PyObject> Import_ReloadModule(PyObject *m)
{
    return safe_ref( PyImport_ReloadModule(m) );
}

static inline borrowed_ref<PyObject> Import_AddModule(const char *name)
{
    return safe_borrowed_ref( PyImport_AddModule(name) );
}

static inline ref<PyObject> Import_ExecCodeModule(char *name, PyObject *co)
{
    return safe_ref( PyImport_ExecCodeModule(name, co) );
}

static inline ref<PyObject> Import_ExecCodeModuleEx(char *name, PyObject *co, char *pathname)
{
    return safe_ref( PyImport_ExecCodeModuleEx(name, co, pathname) );
}

static inline long Import_GetMagicNumber()
{
    return safe_noref( PyImport_GetMagicNumber() );
}

static inline borrowed_ref<PyObject> Import_GetModuleDict()
{
    return safe_borrowed_ref( PyImport_GetModuleDict() );
}

static inline ref<PyObject> Import_GetImporter(PyObject *path)
{
    return safe_ref( PyImport_GetImporter(path) );
}

static inline void _Import_Init()
{
    _PyImport_Init();
    exception::check();
}

static inline void Import_Cleanup()
{
    PyImport_Cleanup();
    exception::check();
}

static inline void _Import_Fini()
{
    _PyImport_Fini();
    exception::check();
}

static inline ref<PyObject> _Import_FindExtension(char * arg0, char * arg1)
{
    return safe_ref( _PyImport_FindExtension(arg0, arg1) );
}

static inline ref<PyObject> _Import_FixupExtension(char * arg0, char * arg1)
{
    return safe_ref( _PyImport_FixupExtension(arg0, arg1) );
}

static inline int Import_ImportFrozenModule(char *name)
{
    return safe_noref( PyImport_ImportFrozenModule(name) );
}

static inline int Import_AppendInittab(const char *name, void (*initfunc)(void))
{
    return safe_noref( PyImport_AppendInittab(name, initfunc) );
}

static inline int Import_ExtendInittab(struct _inittab *newtab)
{
    return safe_noref( PyImport_ExtendInittab(newtab) );
}

}

#endif // PYTHONWRAPPER_API_API_IMPORT__H

