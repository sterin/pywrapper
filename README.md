# *pywrapper*

*pywrapper* is a library that tries to make it easier to write C++ code that uses the Python C/API. It tries to make the C++ code as concise as possible, mainly by getting rid of most error-handling code.

+ It provides wrappers around the Python C/API, so that errors are thrown as C++ exceptions

+ PyObject* are held using smart pointers. If these pointer are used according to a few simple rulesthe code is exception safe with as little need for try/catch blocks as possible

+ On the boundary between C++ code and the interpreter, C++ exceptions are caught are reported as Python exceptions.  

+ It provides utilities for writing extension functions, types and modules.

## Rules for exception-safe reference counting

A a Python object can be held in the following way:

+ A naked ```PyObject*``` pointer
+ ```ref<T>```
+ ```borrowed_ref<T>```
+ ```stolen_ref<T>```

### Naked pointers

To maintain exception-safety, a naked pointer can only be held if the reference is owned by some other part of of the program.

### ```ref<T>```

Represents ownership of the reference, it releases the reference (by calling ```Py_DECREF()``` on destruction. It has the following constructors (and matching ```operator=``` methods):

+ ```ref(T* p)```: takes ownership of the reference
+ ```ref(ref<T> p)```: creates a new reference
+ ```ref(borrowed_ref<T> p)```: creates a new reference
+ ```ref(stolen_ref<T> p)```: creates a new reference

Ownership can be released by the one of the release methods.

### ```borrowed_ref<T>```

Represents a borrowed reference. That is, a reference that is owned somewhere else in the program. It does not release anything. It neither takes ownership of the reference nor creates a new one.

+ ```ref(T* p)```: 
+ ```ref(ref<T> p)```
+ ```ref(borrowed_ref<T> p)```
+ ```ref(stolen_ref<T> p)```

### ```stolen_ref<T>```

Represents the concept of a stolen ownership of a reference. It releases the reference (by calling ```Py_DECREF()``` on destruction. It has the following constructors (and matching ```operator=``` methods):

+ ```ref(T* p)```: takes ownership of the reference
+ ```ref(ref<T> p)```: steals the ownership of the reference from ```p```, and then zeros ```p```
+ ```ref(borrowed_ref<T> p)```: creates a new reference (a borrowed reference cannot be stolen)
+ ```ref(stolen_ref<T> p)```: steals the ownership of the reference from ```p```, and then zeros ```p```

Similar to ```ref<T>```, ownership can be released using the release methods.

The main use of ```borrowed_ref``` and ```stolen_ref``` is in function arguments, especially the wrappers around the Python C/API functions, where it encodes the usage rules of the API. 

TO BE CONTINNUED