#include <pybind11/pybind11.h>

int add(int i, int j) {
	return i + j;
}

PYBIND11_MODULE(pybind_cpp, m) {
	m.doc() = "pybind11 example plugin";

	m.def("add", &add, "adding function");
}