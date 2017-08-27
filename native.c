#include <Python.h>

#define ASSERT(x) if (!x) { printf((#x)); }
#define PASSERT(x) if (!x) { printf((#x) != NULL); }

// ****************** METHODS ******************

static PyObject *
native_sum(PyObject *self, PyObject *args) {
    long a, b;
    if (!PyArg_ParseTuple(args, "ll", &a, &b))
        return NULL;

    PyObject *asyncio_module = PyImport_ImportModule("asyncio");
    PASSERT(asyncio_module);

    PyObject *future_class = PyObject_GetAttrString(asyncio_module, "Future");
    PASSERT(future_class);

    PyObject *future = PyObject_CallObject(future_class, NULL);
    PASSERT(future);

//    PyObject *future_set_result = PyString_FromString("set_result");
    PyObject *future_set_result = PyUnicode_FromString("set_result");
    PASSERT(future);

    PyObject *result = PyLong_FromLong(a + b);
    PASSERT(result);

    PyObject_CallMethodObjArgs(future, future_set_result, result, NULL);

    return future;
}


// ****************** INITIALIZATION ******************

static PyMethodDef NativeMethods[] = {
    {"sum",  native_sum, METH_VARARGS, "Sum two numbers"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef native_module = {
   PyModuleDef_HEAD_INIT,
   "native",                    /* name of module */
   "This is a native package",  /* module documentation, may be NULL */
   -1,                          /* size of per-interpreter state of the module,
                                   or -1 if the module keeps state in global variables. */
   NativeMethods
};

PyMODINIT_FUNC
PyInit_native(void) {
    return PyModule_Create(&native_module);
}
