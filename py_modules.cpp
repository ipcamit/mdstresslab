#include "pybind11/numpy.h"
#include "pybind11/pybind11.h"
#include "pybind11/eigen.h"
#include "typedef.h"

#include <string>

#include "BoxConfiguration.h"

namespace py = pybind11;

PYBIND11_MODULE(pymdstresslab, m){
    py::class_<Configuration>(m,"Configuration")
            .def(py::init<int,int>());

    py::class_<BoxConfiguration, Configuration>(m, "BoxConfiguration")
            .def(py::init<int,int>())
            //  .def(py::init<std::string, int>())
            .def("read",&BoxConfiguration::read)
            .def("getConfiguration",&BoxConfiguration::getConfiguration);
}