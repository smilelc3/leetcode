//
// Created by smile on 24-7-10.
//

#include <unity.h>
#include "util.h"
#include "missing-number.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void missingNumberTestExample1(void) {
    int nums[] = {3, 0, 1};
    int ans = missingNumber(nums, ARRAY_LENGTH(nums));
    int correctAns = 2;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void missingNumberTestExample2(void) {
    int nums[] = {0, 1};
    int ans = missingNumber(nums, ARRAY_LENGTH(nums));
    int correctAns = 2;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void missingNumberTestExample3(void) {
    int nums[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int ans = missingNumber(nums, ARRAY_LENGTH(nums));
    int correctAns = 8;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(missingNumberTestExample1);
    RUN_TEST(missingNumberTestExample2);
    RUN_TEST(missingNumberTestExample3);
    return UNITY_END();
}
