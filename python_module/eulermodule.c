// See https://docs.python.org/3/extending/extending.html

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "../C/euler.c"

static PyObject *
euler_euler(PyObject *self, PyObject *args)
{
    int iter;
    double e;
    if (!PyArg_ParseTuple(args, "i", &iter))
        return NULL;

    e = euler(iter);
    return Py_BuildValue("d", e);
}

static PyMethodDef EulerMethods[] = {
    {"euler", euler_euler, METH_VARARGS,
     "Calculate e using the requested number of iterations."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef eulermodule = {
    PyModuleDef_HEAD_INIT,
    "euler", /* name of module */
    NULL,    /* module documentation, may be NULL */
    -1,      /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
    EulerMethods};

PyMODINIT_FUNC
PyInit_euler(void)
{
    return PyModule_Create(&eulermodule);
}
