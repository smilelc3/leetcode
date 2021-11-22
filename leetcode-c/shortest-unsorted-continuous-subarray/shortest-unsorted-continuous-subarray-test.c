//
// Created by l30014168 on 2021/8/13.
//

#include <unity.h>
#include "util.h"
#include "shortest-unsorted-continuous-subarray.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void findUnsortedSubarrayTestExample1(void) {
    int nums[] = {2, 6, 4, 8, 10, 9, 15};
    int numsSize = ARRAY_LENGTH(nums);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 5;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void findUnsortedSubarrayTestExample2(void) {
    int nums[] = {1, 2, 3, 4};
    int numsSize = ARRAY_LENGTH(nums);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void findUnsortedSubarrayTestExample3(void) {
    int nums[] = {1};
    int numsSize = ARRAY_LENGTH(nums);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void findUnsortedSubarrayTestMyTest0(void) {
    int nums[] = {4, 3, 2, 1};
    int numsSize = ARRAY_LENGTH(nums);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 4;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void findUnsortedSubarrayTestTest0(void) {
    int nums[] = {1, 3, 2, 2, 2};
    int numsSize = ARRAY_LENGTH(nums);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 4;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void findUnsortedSubarrayTestTest1(void) {
    int nums[] = {1, 2, 3, 3, 3};
    int numsSize = ARRAY_LENGTH(nums);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(findUnsortedSubarrayTestExample1);
    RUN_TEST(findUnsortedSubarrayTestExample2);
    RUN_TEST(findUnsortedSubarrayTestExample3);
    RUN_TEST(findUnsortedSubarrayTestMyTest0);
    RUN_TEST(findUnsortedSubarrayTestTest0);
    RUN_TEST(findUnsortedSubarrayTestTest1);
    return UNITY_END();
}