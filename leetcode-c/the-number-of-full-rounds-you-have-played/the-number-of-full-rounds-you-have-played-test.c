//
// Created by smile on 2021/10/29.
//

#include "unity.h"
#include "the-number-of-full-rounds-you-have-played.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void numberOfRoundsTestExample1(void) {
    char *startTime = "12:01", *finishTime = "12:44";
    int ans = numberOfRounds(startTime, finishTime);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numberOfRoundsTestExample2(void) {
    char *startTime = "20:00", *finishTime = "06:00";
    int ans = numberOfRounds(startTime, finishTime);
    int correctAns = 40;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numberOfRoundsTestExample3(void) {
    char *startTime = "00:00", *finishTime = "23:59";
    int ans = numberOfRounds(startTime, finishTime);
    int correctAns = 95;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numberOfRoundsTestTest0(void) {
    char *startTime = "00:47", *finishTime = "00:57";
    int ans = numberOfRounds(startTime, finishTime);
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numberOfRoundsTestTest1(void) {
    char *startTime = "00:01", *finishTime = "00:00";
    int ans = numberOfRounds(startTime, finishTime);
    int correctAns = 95;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numberOfRoundsTestTest2(void) {
    char *startTime = "04:54", *finishTime = "18:51";
    int ans = numberOfRounds(startTime, finishTime);
    int correctAns = 55;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(numberOfRoundsTestExample1);
    RUN_TEST(numberOfRoundsTestExample2);
    RUN_TEST(numberOfRoundsTestExample3);
    RUN_TEST(numberOfRoundsTestTest0);
    RUN_TEST(numberOfRoundsTestTest1);
    RUN_TEST(numberOfRoundsTestTest2);
    return UNITY_END();
}