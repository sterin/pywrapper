

#ifndef PYTHONWRAPPER_API_DATETIME__H
#define PYTHONWRAPPER_API_DATETIME__H

namespace py
{

static inline int Date_Check(PyObject *ob)
{
    return safe_noref( PyDate_Check(ob) );
}

static inline int Date_CheckExact(PyObject *ob)
{
    return safe_noref( PyDate_CheckExact(ob) );
}

static inline int DateTime_Check(PyObject *ob)
{
    return safe_noref( PyDateTime_Check(ob) );
}

static inline int DateTime_CheckExact(PyObject *ob)
{
    return safe_noref( PyDateTime_CheckExact(ob) );
}

static inline int Time_Check(PyObject *ob)
{
    return safe_noref( PyTime_Check(ob) );
}

static inline int Time_CheckExact(PyObject *ob)
{
    return safe_noref( PyTime_CheckExact(ob) );
}

static inline int Delta_Check(PyObject *ob)
{
    return safe_noref( PyDelta_Check(ob) );
}

static inline int Delta_CheckExact(PyObject *ob)
{
    return safe_noref( PyDelta_CheckExact(ob) );
}

static inline int TZInfo_Check(PyObject *ob)
{
    return safe_noref( PyTZInfo_Check(ob) );
}

static inline int TZInfo_CheckExact(PyObject *ob)
{
    return safe_noref( PyTZInfo_CheckExact(ob) );
}

static inline ref<PyObject> Date_FromDate(int year, int month, int day)
{
    return safe_ref( PyDate_FromDate(year, month, day) );
}

static inline ref<PyObject> DateTime_FromDateAndTime(int year, int month, int day, int hour, int minute, int second, int usecond)
{
    return safe_ref( PyDateTime_FromDateAndTime(year, month, day, hour, minute, second, usecond) );
}

static inline ref<PyObject> Time_FromTime(int hour, int minute, int second, int usecond)
{
    return safe_ref( PyTime_FromTime(hour, minute, second, usecond) );
}

static inline ref<PyObject> Delta_FromDSU(int days, int seconds, int useconds)
{
    return safe_ref( PyDelta_FromDSU(days, seconds, useconds) );
}

static inline int DateTime_GET_YEAR(PyDateTime_Date *o)
{
    return safe_noref( PyDateTime_GET_YEAR(o) );
}

static inline int DateTime_GET_MONTH(PyDateTime_Date *o)
{
    return safe_noref( PyDateTime_GET_MONTH(o) );
}

static inline int DateTime_GET_DAY(PyDateTime_Date *o)
{
    return safe_noref( PyDateTime_GET_DAY(o) );
}

static inline int DateTime_DATE_GET_HOUR(PyDateTime_DateTime *o)
{
    return safe_noref( PyDateTime_DATE_GET_HOUR(o) );
}

static inline int DateTime_DATE_GET_MINUTE(PyDateTime_DateTime *o)
{
    return safe_noref( PyDateTime_DATE_GET_MINUTE(o) );
}

static inline int DateTime_DATE_GET_SECOND(PyDateTime_DateTime *o)
{
    return safe_noref( PyDateTime_DATE_GET_SECOND(o) );
}

static inline int DateTime_DATE_GET_MICROSECOND(PyDateTime_DateTime *o)
{
    return safe_noref( PyDateTime_DATE_GET_MICROSECOND(o) );
}

static inline int DateTime_TIME_GET_HOUR(PyDateTime_Time *o)
{
    return safe_noref( PyDateTime_TIME_GET_HOUR(o) );
}

static inline int DateTime_TIME_GET_MINUTE(PyDateTime_Time *o)
{
    return safe_noref( PyDateTime_TIME_GET_MINUTE(o) );
}

static inline int DateTime_TIME_GET_SECOND(PyDateTime_Time *o)
{
    return safe_noref( PyDateTime_TIME_GET_SECOND(o) );
}

static inline int DateTime_TIME_GET_MICROSECOND(PyDateTime_Time *o)
{
    return safe_noref( PyDateTime_TIME_GET_MICROSECOND(o) );
}

static inline ref<PyObject> DateTime_FromTimestamp(PyObject *args)
{
    return safe_ref( PyDateTime_FromTimestamp(args) );
}

static inline ref<PyObject> Date_FromTimestamp(PyObject *args)
{
    return safe_ref( PyDate_FromTimestamp(args) );
}

}

#endif // PYTHONWRAPPER_API_API_DATETIME__H

