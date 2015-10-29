#include <pywrapper.h>

#include <iostream>

using namespace py;
using namespace std;

int
main(int argc, char *argv[])
{
    if (argc < 3) {
        cerr << "Usage: call pythonfile funcname [args]" << endl;
        return 1;
    }

    initialize interpreter;

    try
    {
		ref<PyObject> module = Import_Import(String_FromString(argv[1]));
		ref<PyObject> func = Object_GetAttrString(module, argv[2]);

		if ( Callable_Check(func) )
		{
			ref<PyObject> args = Tuple_New(argc - 3);

			for (int i = 0; i < argc - 3; ++i)
			{
				ref<PyObject> value = Int_FromString(argv[i + 3], 0, 10);
				cout << "value= " << value.get() << endl;;
				Tuple_SetItem(args, i, value);
				cout << "value= " << value.get() << endl;;
			}

			ref<PyObject> value = Object_CallObject(func, args);
			cout << "Result of call: " << Int_AsLong(value) << endl;;
		}
    }
	catch(py::exception& e)
	{
        cout << "exception:" << endl;
		Err_PrintEx(1);
	}

    return 0;
}
