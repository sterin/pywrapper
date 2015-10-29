#include "noddy.h"

#include <iostream>
#include <sstream>
#include "structmember.h"

namespace pyext
{

Noddy::Noddy() :
    first(String_FromString("")),
    last(String_FromString("")),
    callback(None),
    number(0)
{
}

Noddy::~Noddy()
{
}

ref<PyObject>
Noddy::name()
{
    if (!first)
    {
        throw exception(PyExc_AttributeError, "first");
    }

    if (!last)
    {
        throw exception(PyExc_AttributeError, "last");
    }

    return String_Format(
        String_FromString("%s %s"),
        BuildValue("OO", first.get(), last.get()));
}

ref<PyObject>
Noddy::eval(PyObject* s)
{
    ref<PyObject> code = CompileString(String_AsString(s), "test", Py_eval_input);

    borrowed_ref<PyObject> main_module = Import_AddModule("__main__");

    borrowed_ref<PyObject> global_dict = Module_GetDict(main_module);
    ref<PyObject> local_dict = Dict_New();

    return Eval_EvalCode(code.get_cast<PyCodeObject>(), global_dict, local_dict);
}

ref<PyObject>
Noddy::eval2(PyObject* args, PyObject* kwds)
{
    return eval(args);
}

void
Noddy::tp_init(PyObject *args, PyObject *kwds)
{
    static char *kwlist[] = { "first", "last", "number", NULL };

    borrowed_ref<PyObject> f, l;
    int n;

    Arg_ParseTupleAndKeywords(args, kwds, "|OOi", kwlist, &f, &l, &n);

    if(f)
    {
        first = f;
    }

    if(l)
    {
        last = l;
    }

    number = n;
}

ref<PyObject>
Noddy::tp_repr()
{
    std::ostringstream os;
    os << "<first=\"" << String_AsString(first) << "\", last=\"" << String_AsString(last) << "\", number=" << number << ">";

    return String_FromString(os.str().c_str());
}

ref<PyObject>
Noddy::get_callback()
{
    return callback;
}

void Noddy::set_callback(PyObject* rhs)
{
    callback = borrowed_ref<PyObject>(rhs);
}

void
Noddy::initialize(PyObject* module)
{
    _type.tp_init = wrappers::initproc<Noddy>;
    _type.tp_repr = wrappers::reprfunc<Noddy>;

    static PyMethodDef methods[] = {
        PYTHONWRAPPER_METH_NOARGS(Noddy, name, 0, "Return the name, combining the first and last name"),
        PYTHONWRAPPER_METH_O(Noddy, eval, 0, "Evaluate s and return the result"),
        PYTHONWRAPPER_METH_KEYWORDS(Noddy, eval2, 0, "Evaluate s and return the result, ignore keywords"),
        { NULL }  // sentinel
    };

    _type.tp_methods = methods;

    static PyGetSetDef getset[] = {
        PYTHONWRAPPER_GETSET(first, Noddy, first, first, "first name"),
        PYTHONWRAPPER_GETSET(last, Noddy, last, last, "first name"),
        PYTHONWRAPPER_GETSET(callback, Noddy, callback, callback, "callback"),
        { NULL } // sentinel
    };

    _type.tp_getset = getset;

    static PyMemberDef members[] = {
        { "number", T_INT, offsetof(Noddy, number), 0, "noddy number"},
        { NULL}  // sentinel
    };

    _type.tp_members = members;

    base::initialize("pyext.noddy");
    add_to_module(module, "noddy");

}

} // namespace pyext
