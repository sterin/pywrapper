

#ifndef PYTHONWRAPPER_API_NUMBER__H
#define PYTHONWRAPPER_API_NUMBER__H

namespace py
{

static inline int Number_Check(PyObject *o)
{
    return safe_noref( PyNumber_Check(o) );
}

static inline ref<PyObject> Number_Add(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Add(o1, o2) );
}

static inline ref<PyObject> Number_Subtract(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Subtract(o1, o2) );
}

static inline ref<PyObject> Number_Multiply(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Multiply(o1, o2) );
}

static inline ref<PyObject> Number_Divide(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Divide(o1, o2) );
}

static inline ref<PyObject> Number_FloorDivide(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_FloorDivide(o1, o2) );
}

static inline ref<PyObject> Number_TrueDivide(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_TrueDivide(o1, o2) );
}

static inline ref<PyObject> Number_Remainder(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Remainder(o1, o2) );
}

static inline ref<PyObject> Number_Divmod(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Divmod(o1, o2) );
}

static inline ref<PyObject> Number_Power(PyObject *o1, PyObject *o2, PyObject *o3)
{
    return safe_ref( PyNumber_Power(o1, o2, o3) );
}

static inline ref<PyObject> Number_Negative(PyObject *o)
{
    return safe_ref( PyNumber_Negative(o) );
}

static inline ref<PyObject> Number_Positive(PyObject *o)
{
    return safe_ref( PyNumber_Positive(o) );
}

static inline ref<PyObject> Number_Absolute(PyObject *o)
{
    return safe_ref( PyNumber_Absolute(o) );
}

static inline ref<PyObject> Number_Invert(PyObject *o)
{
    return safe_ref( PyNumber_Invert(o) );
}

static inline ref<PyObject> Number_Lshift(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Lshift(o1, o2) );
}

static inline ref<PyObject> Number_Rshift(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Rshift(o1, o2) );
}

static inline ref<PyObject> Number_And(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_And(o1, o2) );
}

static inline ref<PyObject> Number_Xor(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Xor(o1, o2) );
}

static inline ref<PyObject> Number_Or(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_Or(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceAdd(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceAdd(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceSubtract(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceSubtract(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceMultiply(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceMultiply(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceDivide(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceDivide(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceFloorDivide(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceFloorDivide(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceTrueDivide(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceTrueDivide(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceRemainder(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceRemainder(o1, o2) );
}

static inline ref<PyObject> Number_InPlacePower(PyObject *o1, PyObject *o2, PyObject *o3)
{
    return safe_ref( PyNumber_InPlacePower(o1, o2, o3) );
}

static inline ref<PyObject> Number_InPlaceLshift(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceLshift(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceRshift(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceRshift(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceAnd(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceAnd(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceXor(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceXor(o1, o2) );
}

static inline ref<PyObject> Number_InPlaceOr(PyObject *o1, PyObject *o2)
{
    return safe_ref( PyNumber_InPlaceOr(o1, o2) );
}

static inline int Number_Coerce(PyObject **p1, PyObject **p2)
{
    return safe_noref( PyNumber_Coerce(p1, p2) );
}

static inline int Number_CoerceEx(PyObject **p1, PyObject **p2)
{
    return safe_noref( PyNumber_CoerceEx(p1, p2) );
}

static inline ref<PyObject> Number_Int(PyObject *o)
{
    return safe_ref( PyNumber_Int(o) );
}

static inline ref<PyObject> Number_Long(PyObject *o)
{
    return safe_ref( PyNumber_Long(o) );
}

static inline ref<PyObject> Number_Float(PyObject *o)
{
    return safe_ref( PyNumber_Float(o) );
}

static inline ref<PyObject> Number_Index(PyObject *o)
{
    return safe_ref( PyNumber_Index(o) );
}

static inline ref<PyObject> Number_ToBase(PyObject *n, int base)
{
    return safe_ref( PyNumber_ToBase(n, base) );
}

static inline Py_ssize_t Number_AsSsize_t(PyObject *o, PyObject *exc)
{
    return safe_noref( PyNumber_AsSsize_t(o, exc) );
}

static inline int Index_Check(PyObject *o)
{
    return safe_noref( PyIndex_Check(o) );
}

}

#endif // PYTHONWRAPPER_API_API_NUMBER__H

