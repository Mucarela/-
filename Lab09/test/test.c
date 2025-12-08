#include <check.h>
#include "lib.h"

/* Тест для calculate_bills: нормальний позитивний випадок */
START_TEST(test_calculate_bills_normal)
{
    int c10, c5, c2, c1;
    int total = calculate_bills(28, &c10, &c5, &c2, &c1);

    ck_assert_int_eq(total, 5);   
    ck_assert_int_eq(c10, 2);
    ck_assert_int_eq(c5, 1);
    ck_assert_int_eq(c2, 1);
    ck_assert_int_eq(c1, 1);
}
END_TEST

/* Тест для calculate_bills: нуль або від’ємна сума */
START_TEST(test_calculate_bills_invalid)
{
    int c10 = 0, c5 = 0, c2 = 0, c1 = 0;
    int total = calculate_bills(0, &c10, &c5, &c2, &c1);

    ck_assert_int_eq(total, -1);
}
END_TEST

/* Тест для incremental_mean: простий масив */
START_TEST(test_incremental_mean_simple)
{
    double arr[] = { 1.0, 2.0, 3.0 };
    double result = incremental_mean(arr, 3);
    ck_assert_double_eq_tol(result, 2.0, 1e-6);
}
END_TEST

/* Тест для incremental_mean: всі однакові значення */
START_TEST(test_incremental_mean_same_values)
{
    double arr[] = { 5.0, 5.0, 5.0, 5.0 };
    double result = incremental_mean(arr, 4);
    ck_assert_double_eq_tol(result, 5.0, 1e-6);
}
END_TEST

Suite* money_suite(void)
{
    Suite* s = suite_create("Money and Mean");
    TCase* tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_calculate_bills_normal);
    tcase_add_test(tc_core, test_calculate_bills_invalid);
    tcase_add_test(tc_core, test_incremental_mean_simple);
    tcase_add_test(tc_core, test_incremental_mean_same_values);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite* s = money_suite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
