//
// Created by l30014168 on 2021/8/13.
//

#include <unity.h>
#include "shortest-unsorted-continuous-subarray.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testFindUnsortedSubarrayExample1(void) {
    int nums[] = {2, 6, 4, 8, 10, 9, 15};
    int numsSize = sizeof(nums) / sizeof(int);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 5;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void testFindUnsortedSubarrayExample2(void) {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(int);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void testFindUnsortedSubarrayExample3(void) {
    int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(int);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void testFindUnsortedSubarrayMyTest0(void) {
    int nums[] = {4, 3, 2, 1};
    int numsSize = sizeof(nums) / sizeof(int);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 4;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void testFindUnsortedSubarrayTest0(void) {
    int nums[] = {1, 3, 2, 2, 2};
    int numsSize = sizeof(nums) / sizeof(int);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 4;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void testFindUnsortedSubarrayTest1(void) {
    int nums[] = {1, 2, 3, 3, 3};
    int numsSize = sizeof(nums) / sizeof(int);
    int ans = findUnsortedSubarray(nums, numsSize);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testFindUnsortedSubarrayExample1);
    RUN_TEST(testFindUnsortedSubarrayExample2);
    RUN_TEST(testFindUnsortedSubarrayExample3);
    RUN_TEST(testFindUnsortedSubarrayMyTest0);
    RUN_TEST(testFindUnsortedSubarrayTest0);
    RUN_TEST(testFindUnsortedSubarrayTest1);
    return UNITY_END();
}