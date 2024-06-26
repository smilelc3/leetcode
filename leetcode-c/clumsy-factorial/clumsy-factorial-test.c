//
// Created by smile on 24-6-25.
//

#include <unity.h>
#include "clumsy-factorial.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void clumsyTestExample1(void) {
    int n = 4;
    int ans = clumsy(n);
    int correctAns = 7;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void clumsyTestExample2(void) {
    int n = 10;
    int ans = clumsy(n);
    int correctAns = 12;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void clumsyTestTest0(void) {
    int n = 8;
    int ans = clumsy(n);
    int correctAns = 9;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void clumsyTestTest1(void) {
    int n = 12;
    int ans = clumsy(n);
    int correctAns = 13;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(clumsyTestExample1);
    RUN_TEST(clumsyTestExample2);
    RUN_TEST(clumsyTestTest0);
    RUN_TEST(clumsyTestTest1);
    return UNITY_END();
}
