//
// Created by smile on 2022/2/23.
//

#include <unity.h>
#include "util.h"
#include "minimum-size-subarray-sum.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void minSubArrayLenTestExample1(void) {
    int target = 7;
    int nums[] = {2, 3, 1, 2, 4, 3};
    int ans = minSubArrayLen(target, nums, ARRAY_LENGTH(nums));
    int correctAns = 2;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void minSubArrayLenTestExample2(void) {
    int target = 4;
    int nums[] = {1, 4, 4};
    int ans = minSubArrayLen(target, nums, ARRAY_LENGTH(nums));
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void minSubArrayLenTestExample3(void) {
    int target = 11;
    int nums[] = {1, 1, 1, 1, 1, 1, 1, 1};
    int ans = minSubArrayLen(target, nums, ARRAY_LENGTH(nums));
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(minSubArrayLenTestExample1);
    RUN_TEST(minSubArrayLenTestExample2);
    RUN_TEST(minSubArrayLenTestExample3);
    return UNITY_END();
}