cmake_minimum_required(VERSION 3.17)
project(untitled7)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(Google_tests)
add_executable(untitled7 src/main.cpp src/Units/Worker.cpp src/Units/Worker.h src/Units/Master.cpp src/Units/Master.h src/Units/Unit.cpp src/Units/Unit.h Google_tests/test1.cpp src/vector.h src/crew/crew.cpp src/crew/crew.h src/Fields/Field.cpp src/Fields/Field.h src/Simulation/Simulation.h src/Simulation/dialog1.h src/Simulation/dialog2.h src/Simulation/rand/rand.h)