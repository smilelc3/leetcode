//
// Created by l30014168 on 2021/7/19.
//

#include <unity.h>
#include "ugly-number-ii.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void nthUglyNumberTestExample1(void) {
    int n = 10;
    int ans = nthUglyNumber(n);
    int rightAns = 12;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void nthUglyNumberTestExample2(void) {
    int n = 1;
    int ans = nthUglyNumber(n);
    int rightAns = 1;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(nthUglyNumberTestExample1);
    RUN_TEST(nthUglyNumberTestExample2);
    return UNITY_END();
}