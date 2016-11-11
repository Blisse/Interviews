cmake_minimum_required(VERSION 2.8)

project("hackerrank")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

enable_testing()

include_directories(src)

add_executable(kruskals src/kruskals.cpp)
add_executable(prims src/prims.cpp)
add_executable(shortest_reach src/shortest_reach.cpp)
add_executable(synchronous_shopping src/synchronous_shopping.cpp)
