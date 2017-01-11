#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
#include <google/cmockery.h>

extern int add(int, int);
extern int sub(int, int);
extern int div(int, int);
extern int mul_func(int,  int (*func)(int));

// === assert test ===
void test_add(void **state) {
    assert_int_equal(add(3, 3), 6);
    assert_int_not_equal(add(3, 3), 5);
}

// === malloc test ===
void test_sub(void **state) {
    assert_int_equal(sub(3, 3), 0);
}

// === run before test ===
void before_test_div(void **state) {
    print_message("== before test div == \n");
}

void test_div(void **state) {
    assert_int_equal(div(3, 3), 1);
}

// === mock test ===
int func(int a) {
    check_expected(a);
    return (int)mock();
}

void test_mul_func(void **state) {
    double val = 3.0;
    expect_value(func, a, 3);
    will_return(func, 0x4);
    assert_int_equal(mul_func(3, func), 6);
}

int main(int argc, char* argv[]) 
{
    const UnitTest tests[] = {
        unit_test(test_add),
        unit_test(test_sub),
        unit_test_setup_teardown(before_test_div, test_div, NULL),
        unit_test(test_mul_func),
    };
	
    return run_tests(tests);
}

