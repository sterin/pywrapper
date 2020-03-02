find_package(PythonInterp 2.7 REQUIRED)
find_package(PythonLibs 2.7 REQUIRED)

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

if( NOT WIN32 )
    target_compile_options(pywrapper INTERFACE -Wno-write-strings -Wno-invalid-offsetof)
endif()

target_include_directories(pywrapper INTERFACE ${PYTHON_INCLUDE_DIRS})

execute_process(COMMAND ${PYTHON_EXECUTABLE}-config --libs OUTPUT_VARIABLE EXTRA_PYTHON_LIBRARIES)
string(STRIP "${EXTRA_PYTHON_LIBRARIES}" EXTRA_PYTHON_LIBRARIES)

target_link_libraries(pywrapper INTERFACE ${PYTHON_LIBRARY} ${EXTRA_PYTHON_LIBRARIES})

function(pyabc_python_add_module target type)

    add_library(${target} ${type} ${ARGN})

    if(type STREQUAL SHARED)
        set_target_properties(${target} PROPERTIES PREFIX "")
    endif()

    if(APPLE AND (type STREQUAL SHARED))
        set_target_properties(${target} PROPERTIES SUFFIX .so)
    endif()

    if(WIN32 AND (type STREQUAL SHARED))
        set_target_properties(${target} PROPERTIES SUFFIX .pyd)
    endif()

endfunction()
