cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project ("c++ poker")

enable_testing()

include_directories(
    src
    )

add_executable(
    poker_exe
    src/main.cpp
    src/poker.cpp
    )

target_compile_features(poker_exe PRIVATE cxx_range_for)
