#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
#include <math.h>
#include <google/cmockery.h>

int add(int a, int b) {
    return a + b;
}

#define malloc test_malloc
#define calloc test_calloc
#define free test_free

int sub(int a, int b) {
    int *res = (int*)malloc(sizeof(int));
    return *res = a - b;
}

int div(int a, int b) {
    return a / b;
}

int mul_func(int a, int (*func)(int)) {
    return a * func(a);
}

