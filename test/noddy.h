#ifndef instancewrapper__H
#define instancewrapper__H

#include "pywrapper.h"
#include "pywrapper_types.h"

namespace pyext
{

using namespace py;

class Noddy :
    public type_base_with_new<Noddy>
{
public:

    Noddy();
    ~Noddy();

    void tp_init(PyObject* args, PyObject* kwds);
    ref<PyObject> tp_repr();

    ref<PyObject> name();
    ref<PyObject> eval(PyObject* s);
    ref<PyObject> eval2(PyObject* args, PyObject* kwds);

    ref<PyObject> get_callback();
    void set_callback(PyObject* rhs);

    static void initialize(PyObject* module);

private:

    ref<PyObject> first;
    ref<PyObject> last;

    ref<PyObject> callback;

    int number;
};

} // namespace pyext

#endif // instancewrapper_H_
