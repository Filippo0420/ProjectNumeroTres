find_package(PythonLibs REQUIRED)
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(Python3 COMPONENTS Interpreter NumPy)

add_subdirectory(thirdparty/pybind11)
pybind11_add_module(pybind_cpp binder.cpp)


add_executable (MakeLibrary "MakeLibrary.cpp" "MakeLibrary.h" "thirdparty/matplotlibcpp.h" "signalLib/signal.h")
target_link_libraries(MakeLibrary PUBLIC Python3::NumPy)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MakeLibrary PROPERTY CXX_STANDARD 20)
endif()

 