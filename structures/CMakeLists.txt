cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project ("c data structures")

enable_testing()

set(CMAKE_C_FLAGS "-std=c99")

include_directories(
    src/lists
    src/tests
    )

add_executable(
    linked_list_test
    src/tests/linked_list_test.c
    src/lists/linked_list.c
    )

add_test(
    linked_list_test
    linked_list_test
    )
