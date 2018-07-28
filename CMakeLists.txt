cmake_minimum_required(VERSION 3.10)

project (advent-of-code-2015)
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(${CMAKE_SOURCE_DIR}/src/)

add_executable(one src/one.cpp src/common.hpp)
add_executable(two src/two.cpp src/common.hpp)
add_executable(three src/three.cpp src/common.hpp)
add_executable(four src/four.cpp src/common.hpp)
target_link_libraries(four ssl crypto)

add_executable(twentyFive src/twentyFive.cpp src/common.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow-compatible-local -Wextra -pedantic --std=c++14")
