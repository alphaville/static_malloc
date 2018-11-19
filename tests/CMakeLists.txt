file(GLOB stalloc_tests_all
    "*.c"
)


add_executable(stalloc_test_double stalloc_test_double.c)
add_executable(stalloc_test_int stalloc_test_int.c)
add_executable(stalloc_test_char stalloc_test_char.c)
