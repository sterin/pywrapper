python_add_module(noddy SHARED init.cpp noddy.cpp)
target_link_libraries(noddy pywrapper)

add_executable(example example.cpp)
target_link_libraries(example pywrapper)
