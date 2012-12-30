

#ifndef PYTHONWRAPPER_API_MARSHAL__H
#define PYTHONWRAPPER_API_MARSHAL__H

namespace py
{

static inline void Marshal_WriteLongToFile(long value, FILE *file, int version)
{
    PyMarshal_WriteLongToFile(value, file, version);
    exception::check();
}

static inline void Marshal_WriteObjectToFile(PyObject *value, FILE *file, int version)
{
    PyMarshal_WriteObjectToFile(value, file, version);
    exception::check();
}

static inline ref<PyObject> Marshal_WriteObjectToString(PyObject *value, int version)
{
    return safe_ref( PyMarshal_WriteObjectToString(value, version) );
}

static inline long Marshal_ReadLongFromFile(FILE *file)
{
    return safe_noref( PyMarshal_ReadLongFromFile(file) );
}

static inline int Marshal_ReadShortFromFile(FILE *file)
{
    return safe_noref( PyMarshal_ReadShortFromFile(file) );
}

static inline ref<PyObject> Marshal_ReadObjectFromFile(FILE *file)
{
    return safe_ref( PyMarshal_ReadObjectFromFile(file) );
}

static inline ref<PyObject> Marshal_ReadLastObjectFromFile(FILE *file)
{
    return safe_ref( PyMarshal_ReadLastObjectFromFile(file) );
}

static inline ref<PyObject> Marshal_ReadObjectFromString(char *string, Py_ssize_t len)
{
    return safe_ref( PyMarshal_ReadObjectFromString(string, len) );
}

}

#endif // PYTHONWRAPPER_API_API_MARSHAL__H

