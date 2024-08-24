//
// Created by smile on 2024/8/24.
//

#include <unity.h>
#include "numbers-with-repeated-digits.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void numDupDigitsAtMostNExample1(void) {
    int n = 20;
    int ans = numDupDigitsAtMostN(n);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numDupDigitsAtMostNExample2(void) {
    int n = 100;
    int ans = numDupDigitsAtMostN(n);
    int correctAns = 10;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numDupDigitsAtMostNExample3(void) {
    int n = 1000;
    int ans = numDupDigitsAtMostN(n);
    int correctAns = 262;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(numDupDigitsAtMostNExample1);
    RUN_TEST(numDupDigitsAtMostNExample2);
    RUN_TEST(numDupDigitsAtMostNExample3);
    return UNITY_END();
}