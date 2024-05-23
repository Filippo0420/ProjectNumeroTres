import sys
sys.path.insert(1, "out/build/x64-release/MakeLibrary")
import pybind_cpp

pybind_cpp.generateWave("sin", 1, 20, 30)