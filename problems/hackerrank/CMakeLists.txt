cmake_minimum_required(VERSION 3.1)

project("hackerrank")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include_directories(src)

add_executable(synchronous_shopping src/synchronous_shopping.cpp)
add_executable(shortest_reach src/shortest_reach.cpp)
