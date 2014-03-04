#ifndef PYTHONWRAPPER__H
#define PYTHONWRAPPER__H

#include <Python.h>

#include <exception>
#include <new>
#include <cstdarg>

#define pywrapper_for_iterator(sequence, pyitem) \
    for( ref<PyObject> iter = py::Object_GetIter(sequence) ; ref<PyObject> pyitem = py::Iter_Next(iter) ; )

namespace py
{

namespace utils
{

class va_list_wrapper
{
public:

    va_list_wrapper()
    {
    }

    va_list_wrapper( const va_list_wrapper& rhs)
    {
        va_copy(_args, const_cast<va_list&>(rhs._args));
    }

    va_list_wrapper(std::va_list va)
    {
        va_copy(_args, va);
    }

    ~va_list_wrapper()
    {
        va_end(_args);
    }

    operator va_list&()
    {
        return _args;
    }

    va_list& get()
    {
    	return _args;
    }

private:

    va_list _args;
};

}

struct exception
{
    exception()
    {
    }

    exception(PyObject* type)
    {
        PyErr_SetNone(type);
    }

    exception(PyObject* type, const char* message)
    {
        PyErr_SetString(type, message);
    }

    exception(PyObject* type, PyObject* message)
    {
        PyErr_SetObject(type, message);
    }

    static exception format(PyObject* type, const char* format, ...);

    static void clear()
    {
        PyErr_Clear();
    }

    static void check()
    {
        if( PyErr_Occurred() )
        {
            throw exception();
        }
    }

    static bool matches(PyObject* e)
    {
        return PyErr_ExceptionMatches(e);
    }

    static void handle(PyObject* e)
    {
        if( ! matches(e) )
        {
            throw exception();
        }

        clear();
    }
};

template<typename pytype=PyObject>
class ref;

template<typename pytype=PyObject>
class borrowed_ref;

template<typename pytype=PyObject>
class stolen_ref;

template<typename pytype=PyObject>
class replace_ref;

template<typename pytype>
class ref
{
public:

    ref() :
        _p(0)
    {
    }

    template<typename pytype2>
    explicit ref(pytype2* p) :
        _p(reinterpret_cast<pytype*>(p))
    {
    }

    ref(const ref<pytype>& rhs) :
        _p(rhs.get())
    {
        Py_XINCREF(_p);
    }

    template<typename pytype2>
    ref(const ref<pytype2>& rhs) :
        _p(rhs.template get_cast<pytype>())
    {
        Py_XINCREF(_p);
    }

    template<typename pytype2>
    ref(const borrowed_ref<pytype2>& rhs) :
        _p(rhs.template get_cast<pytype>())
    {
        Py_XINCREF(_p);
    }

    template<typename pytype2>
    ref(const stolen_ref<pytype2>& rhs) :
        _p(rhs.template get_cast<pytype>())
    {
        Py_XINCREF(_p);
    }

    ~ref()
    {
        pytype* p = release();
        Py_XDECREF( p );
    }

//    template<typename pytype2>
//    ref& operator=(pytype2* p)
//    {
//        _p = reinterpret_cast<pytype*>(p);
//        return *this;
//    }
//
    ref& operator=(const ref<pytype>& rhs)
    {
        return operator=<pytype>(rhs);
    }

    template<typename pytype2>
    ref& operator=(const ref<pytype2>& rhs)
    {
        Py_XINCREF(rhs.get());
        Py_XDECREF(_p);
        _p = reinterpret_cast<pytype2*>(rhs.get());
        return *this;
    }

    template<typename pytype2>
    ref& operator=(const borrowed_ref<pytype2>& rhs)
    {
        Py_XINCREF(rhs.get());
        Py_XDECREF(_p);
        _p = reinterpret_cast<pytype2*>(rhs.get());
        return *this;
    }

    template<typename pytype2>
    ref& operator=(const stolen_ref<pytype2*>& rhs)
    {
        Py_XINCREF(rhs.get());
        Py_XDECREF(_p);
        _p = reinterpret_cast<pytype2*>(rhs.get());
        return *this;
    }

    template<typename pytype2> const
    bool operator==(pytype2* rhs)
    {
        return reinterpret_cast<pytype>(rhs)==_p;
    }

    template<typename pytype2> const
    bool operator!=(pytype2* rhs)
    {
        return reinterpret_cast<const pytype*>(rhs)!=_p;
    }

    template<typename pytype2> const
    bool operator==(const ref<pytype2>& rhs)
    {
        return _p == rhs.template get_cast<pytype>();
    }

    template<typename pytype2> const
    bool operator!=(const ref<pytype2>& rhs)
    {
        return _p != rhs.template get_cast<pytype>();
    }

    template<typename pytype2> const
    bool operator==(const borrowed_ref<pytype2>& rhs)
    {
        return _p == rhs.template get_cast<pytype>();
    }

    template<typename pytype2> const
    bool operator!=(const borrowed_ref<pytype2>& rhs)
    {
        return _p != rhs.template get_cast<pytype>();
    }

    template<typename pytype2> const
    bool operator==(const stolen_ref<pytype2>& rhs)
    {
        return _p == rhs.template get_cast<pytype>();
    }

    template<typename pytype2> const
    bool operator!=(const stolen_ref<pytype2>& rhs)
    {
        return _p != rhs.template get_cast<pytype>();
    }

    operator bool() const
    {
        return _p!=0;
    }

    pytype* operator->() const
    {
        return _p;
    }

    operator pytype*() const
    {
        return _p;
    }

    pytype* release()
    {
        pytype* tmp = _p;
        _p = 0;
        return tmp;
    }

    template<typename pytype2>
    pytype2* release_cast()
    {
        return reinterpret_cast<pytype2*>(release());
    }

    pytype* get() const
    {
        return _p;
    }

    template<typename pytype2>
    pytype2* get_cast() const
    {
        return reinterpret_cast<pytype2*>(get());
    }

    pytype** operator&()
    {
        Py_XDECREF(_p);
        _p = 0;
        return &_p;
    }

private:

    ref& operator=(pytype*);

    template<typename pytype2>
    ref& operator=(pytype2* p);

    pytype* _p;
};

template<typename pytype>
class borrowed_ref
{
public:

    borrowed_ref() :
        _p(0)
    {
    }

    template<typename pytype2>
    explicit borrowed_ref(pytype2* p) :
        _p(reinterpret_cast<pytype*>(p))
    {
    }

    template<typename pytype2>
    borrowed_ref(const ref<pytype2>& rhs) :
        _p(rhs.template get_cast<pytype>())
    {
    }

    borrowed_ref(const borrowed_ref<pytype>& rhs) :
        _p(rhs.get())
    {
    }

    template<typename pytype2>
    borrowed_ref(const borrowed_ref<pytype2>& rhs) :
        _p(rhs.template get_cast<pytype>())
    {
    }

    template<typename pytype2>
    borrowed_ref(const stolen_ref<pytype2>& rhs) :
        _p(rhs.template get_cast<pytype>())
    {
    }

    ~borrowed_ref()
    {
    }

    template<typename pytype2>
    bool operator==(pytype2* rhs)
    {
        return reinterpret_cast<pytype>(rhs)==_p;
    }

    template<typename pytype2>
    bool operator!=(pytype2* rhs)
    {
        return reinterpret_cast<pytype>(rhs)!=_p;
    }

    operator bool() const
    {
        return _p!=0;
    }

    pytype* operator->() const
    {
        return _p;
    }

    operator pytype*() const
    {
        return _p;
    }

    pytype* get() const
    {
        return _p;
    }

    template<typename pytype2>
    pytype2* get_cast() const
    {
        return reinterpret_cast<pytype2*>(get());
    }

    pytype** operator&()
    {
        return &_p;
    }

private:

    pytype* _p;
};

template<typename pytype>
borrowed_ref<pytype> borrow(pytype* p)
{
    return borrowed_ref<pytype>(p);
}

template<typename pytype>
class stolen_ref
{
public:

    stolen_ref() :
        _p(0)
    {
    }

    template<typename pytype2>
    stolen_ref(const ref<pytype2>& rhs) :
        _p(const_cast<ref<pytype2>&>(rhs).template release_cast<pytype>())
    {
    }

    template<typename pytype2>
    stolen_ref(const borrowed_ref<pytype2>& rhs) :
        _p(rhs.template get_cast<pytype>())
    {
        Py_XINCREF(_p);
    }

    stolen_ref(const stolen_ref<pytype>& rhs) :
        _p(const_cast<stolen_ref<pytype>&>(rhs).release())
    {
    }

    template<typename pytype2>
    stolen_ref(const stolen_ref<pytype2>& rhs) :
        _p(const_cast<stolen_ref<pytype2>&>(rhs).template release_cast<pytype>())
    {
    }

    ~stolen_ref()
    {
        Py_XDECREF(_p);
    }

    template<typename pytype2>
    bool operator==(pytype2* rhs) const
    {
        return reinterpret_cast<pytype>(rhs)==_p;
    }

    template<typename pytype2>
    bool operator!=(pytype2* rhs) const
    {
        return reinterpret_cast<pytype>(rhs)!=_p;
    }

    operator bool() const
    {
        return _p!=0;
    }

    pytype* operator->() const
    {
        return _p;
    }

    pytype get() const
    {
        return _p;
    }

    template<typename pytype2>
    pytype2* get_cast() const
    {
        return reinterpret_cast<pytype2*>(get());
    }

    pytype* release()
    {
        pytype* tmp = _p;
        _p = 0;
        return tmp;
    }

    template<typename pytype2>
    pytype2* release_cast()
    {
        return reinterpret_cast<pytype2*>(release());
    }

private:

    stolen_ref& operator=(const stolen_ref<pytype>&);

    pytype* _p;
};

template<typename pytype>
class replace_ref
{
public:

    template<typename pytype2>
    replace_ref(ref<pytype2>& rhs) :
        _pp(reinterpret_cast<pytype**>(&rhs._p))
    {
    }

    operator pytype**()
    {
    	return _pp;
    }

private:

    pytype** _pp;
};

template<typename expr_type>
ref<expr_type> safe_ref(expr_type* expr)
{
    ref<expr_type> res(expr);
    exception::check();
    return res;
}

template<typename expr_type>
borrowed_ref<expr_type> safe_borrowed_ref(expr_type* expr)
{
    borrowed_ref<expr_type> res(expr);
    exception::check();
    return res;
}

template<typename expr_type>
expr_type safe_noref(expr_type expr)
{
    expr_type res = expr;
    exception::check();
    return res;
}

const static borrowed_ref<PyObject> None(Py_None);
const static borrowed_ref<PyObject> True(Py_True);
const static borrowed_ref<PyObject> False(Py_False);
const static borrowed_ref<PyObject> NotImplemented(Py_NotImplemented);

} // namespace py

#include "api/pywrapper_api.h"

namespace py
{

inline exception
exception::format(PyObject* type, const char* format, ...)
{
      utils::va_list_wrapper vargs;
      va_start(vargs, format);

      ref<PyObject> message = Unicode_FromFormatV(format, vargs);

      return exception(type, message);
}

} // namespace py

#include "pywrapper_embed.h"
#include "pywrapper_object.h"

#endif // PYTHONWRAPPER__H
