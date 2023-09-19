// see https://pybind11.readthedocs.io/en/stable/basics.html

#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "../C/euler.c"

PYBIND11_MODULE(euler, m) {
  m.def("euler", &euler,
        "Calculate e using the requested number of iterations.");
}
