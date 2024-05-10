
add_subdirectory(thirdparty/matplotplusplus)
add_subdirectory(thirdparty/pybind11)
pybind11_add_module(pybind_cpp binder.cpp signalLib/mysignal.cpp)

add_library(signalLib signalLib/mysignal.h signalLib/mysignal.cpp)

add_executable (MakeLibrary "MakeLibrary.cpp")
target_link_libraries(MakeLibrary PUBLIC matplot signalLib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MakeLibrary PROPERTY CXX_STANDARD 20)
endif()

 