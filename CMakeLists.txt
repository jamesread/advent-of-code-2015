cmake_minimum_required(VERSION 3.10)

project (advent-of-code-2015)
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(${CMAKE_SOURCE_DIR}/src/)


#add_executable(two src/two.cpp src/common.cpp)

add_executable(three src/three.cpp src/common.cpp)

add_executable(four src/four.cpp src/common.cpp)
target_link_libraries(four ssl crypto)

add_executable(five src/five_main.cpp src/five.cpp src/common.cpp)

add_executable(five_test tst/five.cpp src/five.cpp src/common.cpp)
target_link_libraries(five_test gtest)

add_executable(six_part1 src/six_part1.cpp src/six_part1_main.cpp src/common.cpp src/common.hpp src/six.hpp)
#add_executable(six_part1_test tst/six_part1.cpp src/six_part1.cpp src/common.cpp)
#target_link_libraries(six_part1_test gtest)

add_executable(twentyFive src/twentyFive.cpp src/common.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow-compatible-local -Wextra -pedantic --std=c++17")
