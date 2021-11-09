//
// Created by l30014168 on 2021/11/8.
//

#include "unity.h"
#include "broken-calculator.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void brokenCalcTestExample1(void) {
    int startValue = 2, target = 3;
    int ans = brokenCalc(startValue, target);
    int correctAns = 2;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void brokenCalcTestExample2(void) {
    int startValue = 5, target = 8;
    int ans = brokenCalc(startValue, target);
    int correctAns = 2;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void brokenCalcTestExample3(void) {
    int startValue = 3, target = 10;
    int ans = brokenCalc(startValue, target);
    int correctAns = 3;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void brokenCalcTestExample4(void) {
    int startValue = 1024, target = 1;
    int ans = brokenCalc(startValue, target);
    int correctAns = 1023;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void brokenCalcTestTest0(void) {
    int startValue = 1, target = 1000000000;
    int ans = brokenCalc(startValue, target);
    int correctAns = 39;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(brokenCalcTestExample1);
    RUN_TEST(brokenCalcTestExample2);
    RUN_TEST(brokenCalcTestExample3);
    RUN_TEST(brokenCalcTestExample4);
    RUN_TEST(brokenCalcTestTest0);
    return UNITY_END();
}