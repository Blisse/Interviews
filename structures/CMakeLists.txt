cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project ("c data structures")

enable_testing()

set(CMAKE_C_FLAGS "-std=c99")

include_directories(
    src
    src/lists
    src/tests
    )

add_executable(
    linked_list_tests
    src/lists/linked_list.c
    src/tests/linked_list_test.c
    src/tests/test_utilities.c
    )

add_test(
    linked_list_test
    linked_list_tests
    )
