#include "pywrapper.h"

#include "noddy.h"

#include <iostream>

PyMODINIT_FUNC
initnoddy()
{
	using namespace py;
	using namespace std;

    PyMethodDef pywrapper_methods[] = {
        { 0 } };

    borrowed_ref<PyObject> mod = InitModule4(
        "noddy",
        pywrapper_methods,
        "pywrapper doctring",
        NULL,
        PYTHON_API_VERSION
        );

    pyext::Noddy::initialize(mod);

    Module_AddObject( mod, "yyy", Int_FromLong(5) );
}
