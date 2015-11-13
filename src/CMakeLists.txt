add_library(pywrapper INTERFACE)

target_include_directories(pywrapper INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )

target_compile_features(
    pywrapper
    INTERFACE
        cxx_lambdas
        cxx_auto_type
        cxx_constexpr
        cxx_nullptr
        cxx_range_for
        cxx_right_angle_brackets
        cxx_rvalue_references
        cxx_uniform_initialization
)

find_package(PythonLibs 2.7 REQUIRED)

target_compile_options(pywrapper INTERFACE -Wno-write-strings -Wno-invalid-offsetof)
target_include_directories(pywrapper INTERFACE ${PYTHON_INCLUDE_DIRS})

find_package(PythonInterp 2.7 REQUIRED)

execute_process(COMMAND ${PYTHON_EXECUTABLE}-config --libs OUTPUT_VARIABLE EXTRA_PYTHON_LIBRARIES)
string(STRIP "${EXTRA_PYTHON_LIBRARIES}" EXTRA_PYTHON_LIBRARIES)
target_link_libraries(pywrapper INTERFACE ${EXTRA_PYTHON_LIBRARIES})

function(pyabc_python_add_module target type)
    python_add_module(${target} ${type} ${ARGN})
    if(APPLE AND (type STREQUAL SHARED))
        set_target_properties(${target} PROPERTIES SUFFIX .so)
    endif()
endfunction()
