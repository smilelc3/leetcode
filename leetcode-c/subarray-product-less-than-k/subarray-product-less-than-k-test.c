//
// Created by l30014168 on 2021/12/20.
//

#include <unity.h>
#include "util.h"
#include "subarray-product-less-than-k.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void numSubarrayProductLessThanKTestExample1(void) {
    int nums[] = {10, 5, 2, 6};
    int k = 100;
    int ans = numSubarrayProductLessThanK(nums, ARRAY_LENGTH(nums), k);
    int expectAns = 8;
    TEST_ASSERT_EQUAL_INT(expectAns, ans);
}

void numSubarrayProductLessThanKTestExample2(void) {
    int nums[] = {1, 2, 3};
    int k = 0;
    int ans = numSubarrayProductLessThanK(nums, ARRAY_LENGTH(nums), k);
    int expectAns = 0;
    TEST_ASSERT_EQUAL_INT(expectAns, ans);
}

void numSubarrayProductLessThanKTestTest0(void) {
    int nums[] = {10, 2, 2, 5, 4, 4, 4, 3, 7, 7};
    int k = 289;
    int ans = numSubarrayProductLessThanK(nums, ARRAY_LENGTH(nums), k);
    int expectAns = 31;
    TEST_ASSERT_EQUAL_INT(expectAns, ans);
}

void numSubarrayProductLessThanKTestTest1(void) {
    int nums[] = {1, 1, 1};
    int k = 1;
    int ans = numSubarrayProductLessThanK(nums, ARRAY_LENGTH(nums), k);
    int expectAns = 0;
    TEST_ASSERT_EQUAL_INT(expectAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(numSubarrayProductLessThanKTestExample1);
    RUN_TEST(numSubarrayProductLessThanKTestExample2);
    RUN_TEST(numSubarrayProductLessThanKTestTest0);
    RUN_TEST(numSubarrayProductLessThanKTestTest1);
    return UNITY_END();
}