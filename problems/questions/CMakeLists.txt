cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project ("c++ questions")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

enable_testing()

include_directories(
    src
    )

add_executable(
    powerset
    src/powerset.cpp
    )

add_executable(
    mapparser
    src/mapparser.cpp
    )

add_executable(
    mergesort
    src/mergesort.cpp
    )

add_executable(
    shortestuniqueprefix
    src/shortestuniqueprefix.cpp
    )

add_executable(
    states
    src/states.cpp
    )

add_executable(
    coins
    src/coins.cpp
    )
