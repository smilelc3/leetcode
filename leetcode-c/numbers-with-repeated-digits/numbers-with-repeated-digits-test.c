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

void numDupDigitsAtMostNTest0(void) {
    int n = 7;
    int ans = numDupDigitsAtMostN(n);
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numDupDigitsAtMostNTest1(void) {
    int n = 11;
    int ans = numDupDigitsAtMostN(n);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numDupDigitsAtMostNTest2(void) {
    int n = 110;
    int ans = numDupDigitsAtMostN(n);
    int correctAns = 12;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numDupDigitsAtMostNTest3(void) {
    int n = 365;
    int ans = numDupDigitsAtMostN(n);
    int correctAns = 86;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(numDupDigitsAtMostNExample1);
    RUN_TEST(numDupDigitsAtMostNExample2);
    RUN_TEST(numDupDigitsAtMostNExample3);
    RUN_TEST(numDupDigitsAtMostNTest0);
    RUN_TEST(numDupDigitsAtMostNTest1);
    RUN_TEST(numDupDigitsAtMostNTest2);
    RUN_TEST(numDupDigitsAtMostNTest3);
    return UNITY_END();
}