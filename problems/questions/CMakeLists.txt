cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project ("c++ questions")

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
    shortestuniqueprefix
    src/shortestuniqueprefix.cpp
    )

target_compile_features(powerset PRIVATE cxx_range_for)
target_compile_features(mapparser PRIVATE cxx_range_for)
target_compile_features(shortestuniqueprefix PRIVATE cxx_range_for)
