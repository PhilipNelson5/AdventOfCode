cmake_minimum_required(VERSION 3.19)
set_property(GLOBAL PROPERTY GLOBAL_DEPENDS_NO_CYCLES on)
project(
  AdventOfCode2022
  VERSION 1.0.0
  LANGUAGES CXX
)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(AOC)

add_subdirectory(Challenges)

include(Dependencies)
include(CTest)
add_subdirectory(Dependencies/Catch2)
include(Catch)
fix_dependencies(Catch2::Catch2WithMain Catch2::Catch2)
add_subdirectory(Tests)