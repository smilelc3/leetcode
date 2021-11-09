//
// Created by l30014168 on 2021/11/9.
//

#include <unity.h>
#include <stdlib.h>
#include "integer-replacement.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void integerReplacementTestExample1(void) {
    int n = 8;
    int ans = integerReplacement(n);
    int correctAns = 3;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void integerReplacementTestExample2(void) {
    int n = 7;
    int ans = integerReplacement(n);
    int correctAns = 4;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void integerReplacementTestExample3(void) {
    int n = 4;
    int ans = integerReplacement(n);
    int correctAns = 2;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void integerReplacementTestTest0(void) {
    int n = 7;
    int ans = integerReplacement(n);
    int correctAns = 4;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void integerReplacementTestTest1(void) {
    int n = 6;
    int ans = integerReplacement(n);
    int correctAns = 3;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(integerReplacementTestExample1);
    RUN_TEST(integerReplacementTestExample2);
    RUN_TEST(integerReplacementTestExample3);
    RUN_TEST(integerReplacementTestTest0);
    RUN_TEST(integerReplacementTestTest1);
    return UNITY_END();
}