#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "math_utils.h"

static void test_factorial(void **state) {
    (void)state;
    
    assert_int_equal(factorial(0), 1);
    assert_int_equal(factorial(1), 1);
    assert_int_equal(factorial(5), 120);
    assert_int_equal(factorial(10), 3628800);
}

static void test_is_prime(void **state) {
    (void)state;
    
    assert_true(is_prime(2));
    assert_true(is_prime(17));
    assert_true(is_prime(7919)); // Большое простое число
    
    assert_false(is_prime(1));
    assert_false(is_prime(4));
    assert_false(is_prime(15));
    assert_false(is_prime(100));
}

static void test_gcd(void **state) {
    (void)state;
    
    assert_int_equal(gcd(48, 18), 6);
    assert_int_equal(gcd(17, 5), 1);
    assert_int_equal(gcd(0, 5), 5);
    assert_int_equal(gcd(-24, 18), 6);
}

static void test_lcm(void **state) {
    (void)state;
    
    assert_int_equal(lcm(12, 18), 36);
    assert_int_equal(lcm(5, 7), 35);
    assert_int_equal(lcm(0, 5), 0);
    assert_int_equal(lcm(-4, 6), 12);
}

static void test_solve_quadratic(void **state) {
    (void)state;
    
    // Два корня
    QuadraticSolution sol1 = solve_quadratic(1, -3, 2);
    assert_int_equal(sol1.num_roots, 2);
    assert_true(fabs(sol1.root1 - 2.0) < 1e-9);
    assert_true(fabs(sol1.root2 - 1.0) < 1e-9);
    
    // Один корень
    QuadraticSolution sol2 = solve_quadratic(1, -4, 4);
    assert_int_equal(sol2.num_roots, 1);
    assert_true(fabs(sol2.root1 - 2.0) < 1e-9);
    
    // Нет корней
    QuadraticSolution sol3 = solve_quadratic(1, 0, 1);
    assert_int_equal(sol3.num_roots, 0);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_factorial),
        cmocka_unit_test(test_is_prime),
        cmocka_unit_test(test_gcd),
        cmocka_unit_test(test_lcm),
        cmocka_unit_test(test_solve_quadratic),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}