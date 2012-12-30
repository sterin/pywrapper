

#ifndef PYTHONWRAPPER_API_FILE__H
#define PYTHONWRAPPER_API_FILE__H

namespace py
{

static inline int File_Check(PyObject *p)
{
    return safe_noref( PyFile_Check(p) );
}

static inline int File_CheckExact(PyObject *p)
{
    return safe_noref( PyFile_CheckExact(p) );
}

static inline ref<PyObject> File_FromString(char *filename, char *mode)
{
    return safe_ref( PyFile_FromString(filename, mode) );
}

static inline ref<PyObject> File_FromFile(FILE *fp, char *name, char *mode, int (*close)(FILE*))
{
    return safe_ref( PyFile_FromFile(fp, name, mode, close) );
}

static inline FILE* File_AsFile(PyObject *p)
{
    return safe_noref( PyFile_AsFile(p) );
}

static inline void File_IncUseCount(PyFileObject *p)
{
    PyFile_IncUseCount(p);
    exception::check();
}

static inline void File_DecUseCount(PyFileObject *p)
{
    PyFile_DecUseCount(p);
    exception::check();
}

static inline ref<PyObject> File_GetLine(PyObject *p, int n)
{
    return safe_ref( PyFile_GetLine(p, n) );
}

static inline borrowed_ref<PyObject> File_Name(PyObject *p)
{
    return safe_borrowed_ref( PyFile_Name(p) );
}

static inline void File_SetBufSize(PyObject *f, int bufsize)
{
    PyFile_SetBufSize(f, bufsize);
    exception::check();
}

static inline int File_SetEncoding(PyObject *p, const char *enc)
{
    return safe_noref( PyFile_SetEncoding(p, enc) );
}

static inline int File_SetEncodingAndErrors(PyObject *p, const char *enc, char *errors)
{
    return safe_noref( PyFile_SetEncodingAndErrors(p, enc, errors) );
}

static inline int File_SoftSpace(PyObject *p, int newflag)
{
    return safe_noref( PyFile_SoftSpace(p, newflag) );
}

static inline int File_WriteObject(PyObject *obj, PyObject *p, int flags)
{
    return safe_noref( PyFile_WriteObject(obj, p, flags) );
}

static inline int File_WriteString(const char *s, PyObject *p)
{
    return safe_noref( PyFile_WriteString(s, p) );
}

}

#endif // PYTHONWRAPPER_API_API_FILE__H

