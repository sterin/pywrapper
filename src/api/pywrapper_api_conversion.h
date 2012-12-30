

#ifndef PYTHONWRAPPER_API_CONVERSION__H
#define PYTHONWRAPPER_API_CONVERSION__H

namespace py
{

static inline int OS_vsnprintf(char *str, size_t size, const char *format, va_list va)
{
    return safe_noref( PyOS_vsnprintf(str, size, format, va) );
}

static inline double OS_string_to_double(const char *s, char **endptr, PyObject *overflow_exception)
{
    return safe_noref( PyOS_string_to_double(s, endptr, overflow_exception) );
}

static inline double OS_ascii_strtod(const char *nptr, char **endptr)
{
    return safe_noref( PyOS_ascii_strtod(nptr, endptr) );
}

static inline char* OS_ascii_formatd(char *buffer, size_t buf_len, const char *format, double d)
{
    return safe_noref( PyOS_ascii_formatd(buffer, buf_len, format, d) );
}

static inline char* OS_double_to_string(double val, char format_code, int precision, int flags, int *ptype)
{
    return safe_noref( PyOS_double_to_string(val, format_code, precision, flags, ptype) );
}

static inline double OS_ascii_atof(const char *nptr)
{
    return safe_noref( PyOS_ascii_atof(nptr) );
}

static inline int OS_stricmp(char *s1, char *s2)
{
    return safe_noref( PyOS_stricmp(s1, s2) );
}

static inline int OS_strnicmp(char *s1, char *s2, Py_ssize_t n)
{
    return safe_noref( PyOS_strnicmp(s1, s2, n) );
}

}

#endif // PYTHONWRAPPER_API_API_CONVERSION__H

