#include <pybind11/pybind11.h>
#include "signalLib/mysignal.h"


PYBIND11_MODULE(pybind_cpp, m) {
	m.doc() = "pybind11 example plugin";

	m.def("add", &add);
}