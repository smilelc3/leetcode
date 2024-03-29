//
// Created by l30014168 on 2021/8/16.
//

#include <unity.h>
#include <stdlib.h>
#include "number-of-digit-one.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void countDigitOneTestExample1(void) {
    int n = 13;
    int ans = countDigitOne(n);
    int rightAns = 6;
    TEST_ASSERT_EQUAL_INT(ans, rightAns);
}

void countDigitOneTestExample2(void) {
    int n = 0;
    int ans = countDigitOne(n);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(ans, rightAns);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(countDigitOneTestExample1);
    RUN_TEST(countDigitOneTestExample2);
    return UNITY_END();
}