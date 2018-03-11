find_package(PythonInterp 2.7 REQUIRED)

python_add_module(noddy SHARED init.cpp noddy.cpp)
target_link_libraries(noddy pywrapper)

add_executable(example example.cpp)
target_link_libraries(example pywrapper)

add_test(
    NAME embed_python
    COMMAND example os getpgid 1
)

add_test(
    NAME python_module
    COMMAND echo ${PYTHON_EXECUTABLE} -c "import noddy ; x = noddy.noddy('foo', 'bar', 3) ; print x.first ; print x.last ; print x "
)
