
add_subdirectory(thirdparty/matplotplusplus)
add_subdirectory(thirdparty/pybind11)
pybind11_add_module(pybind_cpp binder.cpp)


target_link_libraries(pybind_cpp PRIVATE matplot)

add_executable(MakeLibrary "MakeLibrary.cpp" "MakeLibrary.h")
target_link_libraries(MakeLibrary PUBLIC matplot)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MakeLibrary PROPERTY CXX_STANDARD 20)
endif()

 