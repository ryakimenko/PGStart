#include "../src/quadratic_equation.h"
#include <stdlib.h>
#include <check.h>

#define EPSILON 1e-6

START_TEST(test_solve_equation_with_two_roots)
{
    Roots roots = solve_equation(1, -3, 2);

    Roots correct_roots;
    correct_roots.num_roots = 2;
    correct_roots.root1 = 2.0;
    correct_roots.root2 = 1.0;

    ck_assert_int_eq(roots.num_roots, correct_roots.num_roots);
    ck_assert_double_eq_tol(roots.root1,  correct_roots.root1, EPSILON);
    ck_assert_double_eq_tol(roots.root2, correct_roots.root2, EPSILON);
}
END_TEST

START_TEST(test_solve_equation_with_one_root)
{
    Roots roots = solve_equation(1, -2, 1);

    Roots correct_roots;
    correct_roots.num_roots = 1;
    correct_roots.root1 = 1.0;
    correct_roots.root2 = 1.0;  

    ck_assert_int_eq(roots.num_roots, correct_roots.num_roots);
    ck_assert_double_eq_tol(roots.root1,  correct_roots.root1, EPSILON);
    ck_assert_double_eq_tol(roots.root2, correct_roots.root2, EPSILON);
}
END_TEST

START_TEST(test_solve_equation_with_no_roots)
{
    Roots roots = solve_equation(1, 1, 1);

    Roots correct_roots;
    correct_roots.num_roots = 0;
    correct_roots.root1 = 0;
    correct_roots.root2 = 0;

    ck_assert_int_eq(roots.num_roots, correct_roots.num_roots);
    ck_assert_double_eq_tol(roots.root1,  correct_roots.root1, EPSILON);
    ck_assert_double_eq_tol(roots.root2, correct_roots.root2, EPSILON);
}
END_TEST

Suite *solve_equation_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Solve Equation");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_solve_equation_with_two_roots);
    tcase_add_test(tc_core, test_solve_equation_with_one_root);
    tcase_add_test(tc_core, test_solve_equation_with_no_roots);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = solve_equation_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;

}