

#ifndef PYTHONWRAPPER_API_EXCEPTIONS__H
#define PYTHONWRAPPER_API_EXCEPTIONS__H

namespace py
{

static inline void Err_PrintEx(int set_sys_last_vars)
{
    PyErr_PrintEx(set_sys_last_vars);
    exception::check();
}

static inline void Err_Print()
{
    PyErr_Print();
    exception::check();
}

static inline borrowed_ref<PyObject> Err_Occurred()
{
    return safe_borrowed_ref( PyErr_Occurred() );
}

static inline int Err_ExceptionMatches(PyObject *exc)
{
    return safe_noref( PyErr_ExceptionMatches(exc) );
}

static inline int Err_GivenExceptionMatches(PyObject *given, PyObject *exc)
{
    return safe_noref( PyErr_GivenExceptionMatches(given, exc) );
}

static inline void Err_NormalizeException(PyObject**exc, PyObject**val, PyObject**tb)
{
    PyErr_NormalizeException(exc, val, tb);
    exception::check();
}

static inline void Err_Clear()
{
    PyErr_Clear();
    exception::check();
}

static inline void Err_Fetch(PyObject **ptype, PyObject **pvalue, PyObject **ptraceback)
{
    PyErr_Fetch(ptype, pvalue, ptraceback);
    exception::check();
}

static inline void Err_Restore(PyObject *type, PyObject *value, PyObject *traceback)
{
    PyErr_Restore(type, value, traceback);
    exception::check();
}

static inline void Err_SetString(PyObject *type, const char *message)
{
    PyErr_SetString(type, message);
    exception::check();
}

static inline void Err_SetObject(PyObject *type, PyObject *value)
{
    PyErr_SetObject(type, value);
    exception::check();
}

static inline void Err_SetNone(PyObject *type)
{
    PyErr_SetNone(type);
    exception::check();
}

static inline int Err_BadArgument()
{
    return safe_noref( PyErr_BadArgument() );
}

static inline ref<PyObject> Err_NoMemory()
{
    return safe_ref( PyErr_NoMemory() );
}

static inline ref<PyObject> Err_SetFromErrno(PyObject *type)
{
    return safe_ref( PyErr_SetFromErrno(type) );
}

static inline ref<PyObject> Err_SetFromErrnoWithFilename(PyObject *type, const char *filename)
{
    return safe_ref( PyErr_SetFromErrnoWithFilename(type, filename) );
}

#ifdef _WIN32

static inline ref<PyObject> Err_SetFromWindowsErr(int ierr)
{
    return safe_ref( PyErr_SetFromWindowsErr(ierr) );
}

#endif

#ifdef _WIN32

static inline ref<PyObject> Err_SetExcFromWindowsErr(PyObject *type, int ierr)
{
    return safe_ref( PyErr_SetExcFromWindowsErr(type, ierr) );
}

#endif

#ifdef _WIN32

static inline ref<PyObject> Err_SetFromWindowsErrWithFilename(int ierr, const char *filename)
{
    return safe_ref( PyErr_SetFromWindowsErrWithFilename(ierr, filename) );
}

#endif

#ifdef _WIN32

static inline ref<PyObject> Err_SetExcFromWindowsErrWithFilename(PyObject *type, int ierr, char *filename)
{
    return safe_ref( PyErr_SetExcFromWindowsErrWithFilename(type, ierr, filename) );
}

#endif

static inline void Err_BadInternalCall()
{
    PyErr_BadInternalCall();
    exception::check();
}

static inline int Err_WarnEx(PyObject *category, char *message, int stacklevel)
{
    return safe_noref( PyErr_WarnEx(category, message, stacklevel) );
}

static inline int Err_Warn(PyObject *category, char *message)
{
    return safe_noref( PyErr_Warn(category, message) );
}

static inline int Err_WarnExplicit(PyObject *category, const char *message, const char *filename, int lineno, const char *module, PyObject *registry)
{
    return safe_noref( PyErr_WarnExplicit(category, message, filename, lineno, module, registry) );
}

static inline int Err_WarnPy3k(char *message, int stacklevel)
{
    return safe_noref( PyErr_WarnPy3k(message, stacklevel) );
}

static inline int Err_CheckSignals()
{
    return safe_noref( PyErr_CheckSignals() );
}

static inline void Err_SetInterrupt()
{
    PyErr_SetInterrupt();
    exception::check();
}

static inline int Signal_SetWakeupFd(int fd)
{
    return safe_noref( PySignal_SetWakeupFd(fd) );
}

static inline ref<PyObject> Err_NewException(char *name, PyObject *base, PyObject *dict)
{
    return safe_ref( PyErr_NewException(name, base, dict) );
}

static inline ref<PyObject> Err_NewExceptionWithDoc(char *name, char *doc, PyObject *base, PyObject *dict)
{
    return safe_ref( PyErr_NewExceptionWithDoc(name, doc, base, dict) );
}

static inline void Err_WriteUnraisable(PyObject *obj)
{
    PyErr_WriteUnraisable(obj);
    exception::check();
}

static inline ref<PyObject> UnicodeDecodeError_Create(const char *encoding, const char *object, Py_ssize_t length, Py_ssize_t start, Py_ssize_t end, const char *reason)
{
    return safe_ref( PyUnicodeDecodeError_Create(encoding, object, length, start, end, reason) );
}

static inline ref<PyObject> UnicodeEncodeError_Create(const char *encoding, const Py_UNICODE *object, Py_ssize_t length, Py_ssize_t start, Py_ssize_t end, const char *reason)
{
    return safe_ref( PyUnicodeEncodeError_Create(encoding, object, length, start, end, reason) );
}

static inline ref<PyObject> UnicodeTranslateError_Create(const Py_UNICODE *object, Py_ssize_t length, Py_ssize_t start, Py_ssize_t end, const char *reason)
{
    return safe_ref( PyUnicodeTranslateError_Create(object, length, start, end, reason) );
}

static inline ref<PyObject> UnicodeDecodeError_GetEncoding(PyObject *exc)
{
    return safe_ref( PyUnicodeDecodeError_GetEncoding(exc) );
}

static inline ref<PyObject> UnicodeDecodeError_GetObject(PyObject *exc)
{
    return safe_ref( PyUnicodeDecodeError_GetObject(exc) );
}

static inline int UnicodeDecodeError_GetStart(PyObject *exc, Py_ssize_t *start)
{
    return safe_noref( PyUnicodeDecodeError_GetStart(exc, start) );
}

static inline int UnicodeDecodeError_SetStart(PyObject *exc, Py_ssize_t start)
{
    return safe_noref( PyUnicodeDecodeError_SetStart(exc, start) );
}

static inline int UnicodeDecodeError_GetEnd(PyObject *exc, Py_ssize_t *end)
{
    return safe_noref( PyUnicodeDecodeError_GetEnd(exc, end) );
}

static inline int UnicodeDecodeError_SetEnd(PyObject *exc, Py_ssize_t end)
{
    return safe_noref( PyUnicodeDecodeError_SetEnd(exc, end) );
}

static inline ref<PyObject> UnicodeDecodeError_GetReason(PyObject *exc)
{
    return safe_ref( PyUnicodeDecodeError_GetReason(exc) );
}

static inline int UnicodeDecodeError_SetReason(PyObject *exc, const char *reason)
{
    return safe_noref( PyUnicodeDecodeError_SetReason(exc, reason) );
}

static inline int EnterRecursiveCall(char *where)
{
    return safe_noref( Py_EnterRecursiveCall(where) );
}

static inline void LeaveRecursiveCall()
{
    Py_LeaveRecursiveCall();
    exception::check();
}

}

#endif // PYTHONWRAPPER_API_API_EXCEPTIONS__H

