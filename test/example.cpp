#include <pywrapper.h>

#include <iostream>

using namespace py;

int
main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: call pythonfile funcname [args]" << std::endl;
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
				std::cout << "value= " << value.get() << std::endl;;
				Tuple_SetItem(args, i, value);
				std::cout << "value= " << value.get() << std::endl;;
			}

			ref<PyObject> value = Object_CallObject(func, args);
			std::cout << "Result of call: " << Int_AsLong(value) << std::endl;;
		}
    }
	catch(py::exception& e)
	{
        std::cout << "exception:" << std::endl;
		Err_PrintEx(1);
	}

    return 0;
}
