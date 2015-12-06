cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project ("c++ sudoku")

enable_testing()

include_directories(
    src
    )

add_executable(
    sudoku
    src/main.cpp
    src/sudoku.cpp
    )

target_compile_features(sudoku PRIVATE cxx_range_for)
