
find_package(Matplot++ REQUIRED)

add_subdirectory(thirdparty/pybind11)
pybind11_add_module(pybind_cpp binder.cpp)


add_executable (MakeLibrary "MakeLibrary.cpp" "MakeLibrary.h"  "signalLib/signal.h")
target_link_libraries(MakeLibrary PUBLIC Matplot++::matplot)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MakeLibrary PROPERTY CXX_STANDARD 20)
endif()

 