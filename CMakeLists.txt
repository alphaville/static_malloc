cmake_minimum_required (VERSION 2.6)
project (StaticAllocationFramework C)

# compile the main file
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_BUILD_TYPE Release)


set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wextra -fprofile-arcs -ftest-coverage -std=c90")
set(CMAKE_C_FLAGS_RELEASE "-g -O3 -std=c90")

# compile main.c and produce the executable file 'output'
add_executable(output main.c)

enable_testing()
add_subdirectory(tests)
add_test (stalloc_test_double tests/stalloc_test_double)
add_test (stalloc_test_int tests/stalloc_test_int)
add_test (stalloc_test_char tests/stalloc_test_char)

