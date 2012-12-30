

#ifndef PYTHONWRAPPER_API_MEMORY__H
#define PYTHONWRAPPER_API_MEMORY__H

namespace py
{

static inline void* Mem_Malloc(size_t n)
{
    return safe_noref( PyMem_Malloc(n) );
}

static inline void* Mem_Realloc(void *p, size_t n)
{
    return safe_noref( PyMem_Realloc(p, n) );
}

static inline void Mem_Free(void *p)
{
    PyMem_Free(p);
    exception::check();
}

static inline void Mem_Del(void *p)
{
    PyMem_Del(p);
    exception::check();
}

}

#endif // PYTHONWRAPPER_API_API_MEMORY__H

