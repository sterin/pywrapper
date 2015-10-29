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

target_compile_options(pywrapper INTERFACE -Wno-write-strings -Wno-invalid-offsetof)
target_include_directories(pywrapper INTERFACE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(pywrapper INTERFACE ${PYTHON_LIBRARIES})
