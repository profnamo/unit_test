// test_math_functions.c
#include <check.h>
#include "math_functions.h"

START_TEST(test_add) {
    ck_assert_int_eq(add(2, 3), 5);
    ck_assert_int_eq(add(-2, -3), -5);
    ck_assert_int_eq(add(-2, 3), 1);
}
END_TEST

START_TEST(test_subtract) {
    ck_assert_int_eq(subtract(5, 3), 2);
    ck_assert_int_eq(subtract(-5, -3), -2);
    ck_assert_int_eq(subtract(-3, 5), -8);
}
END_TEST

Suite *math_functions_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("MathFunctions");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_add);
    tcase_add_test(tc_core, test_subtract);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = math_functions_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}

