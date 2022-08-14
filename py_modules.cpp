#include "pybind11/numpy.h"
#include "pybind11/pybind11.h"
#include "pybind11/eigen.h"
#include "typedef.h"

#include <string>

#include "BoxConfiguration.h"
#include "kim.h"
#include "Grid.h"
#include "Sphere.h"
#include "Stress.h"
#include "calculateStress.h"
#include "SubConfiguration.h"
#include "Stencil.h"

namespace py = pybind11;

PYBIND11_MODULE(pymdstresslab, m){
    py::class_<Configuration>(m,"Configuration")
            .def(py::init<int,int>());

    py::class_<BoxConfiguration, Configuration>(m, "BoxConfiguration")
            .def(py::init<int,int>())
            //  .def(py::init<std::string, int>())
            .def("read",&BoxConfiguration::read)
            .def("getConfiguration",&BoxConfiguration::getConfiguration);

    py::class_<Kim>(m, "Kim")
            .def(py::init<>())
            .def(py::init<std::string>());

    py::class_<GridBase>(m, "GridBase")
            .def(py::init<>());

    py::class_<Grid<Current>,GridBase>(m, "GridCurrent")
            .def(py::init<int>())
            .def(py::init<Vector3d, Vector3d, int>())
            .def("read",&Grid<Current>::read)
            .def("read",&Grid<Current>::write);

    py::class_<Grid<Reference>,GridBase>(m, "GridReference")
            .def(py::init<int>())
            .def(py::init<Vector3d, Vector3d, int>())
            .def("read",&Grid<Reference>::read)
            .def("read",&Grid<Reference>::write);

    py::class_<Sphere>(m, "Sphere")
            .def(py::init<double>())
            .def(py::init<Sphere&>());

    py::class_<Stress<Sphere,Cauchy> >(m, "StressCauchy")
            .def(py::init<std::string,Sphere &, Grid<Current>* >());
    py::class_<Stress<Sphere,Piola> >(m, "StressPiola")
            .def(py::init<std::string,Sphere &, Grid<Reference>* >());

    py::class_<Stencil>(m, "Stencil")
            .def(py::init<Configuration&>());
    py::class_<SubConfiguration,Configuration>(m, "SubConfiguration")
            .def(py::init<Stencil &>());

    m.def("calculateStressCauchy",[](BoxConfiguration & body, Kim & kim, Stress<Sphere,Cauchy>& stress){
        calculateStress(body, kim, std::tie(stress));
    });
}