//
// Created by l30014168 on 2021/9/16.
//

#include <stdlib.h>
#include <unity.h>
#include <limits.h>
#include "util.h"
#include "single-number-iii.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void singleNumberTestExample1(void) {
    int nums[] = {1, 2, 1, 3, 2, 5};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize = -1;
    int *ans = singleNumber(nums, numsSize, &returnSize);
    int correctAns[] = {3, 5};
    TEST_ASSERT_EQUAL_INT(2, returnSize);
    qsort(ans, returnSize, sizeof(int), intAscCmpFunc);
    qsort(correctAns, returnSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void singleNumberTestExample2(void) {
    int nums[] = {-1, 0};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize = -1;
    int *ans = singleNumber(nums, numsSize, &returnSize);
    int correctAns[] = {-1, 0};
    TEST_ASSERT_EQUAL_INT(2, returnSize);
    qsort(ans, returnSize, sizeof(int), intAscCmpFunc);
    qsort(correctAns, returnSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void singleNumberTestExample3(void) {
    int nums[] = {0, 1};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize = -1;
    int *ans = singleNumber(nums, numsSize, &returnSize);
    int correctAns[] = {1, 0};
    TEST_ASSERT_EQUAL_INT(2, returnSize);
    qsort(ans, returnSize, sizeof(int), intAscCmpFunc);
    qsort(correctAns, returnSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void singleNumberTestTest0(void) {
    int nums[] = {1, 1, 0, INT_MIN};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize = -1;
    int *ans = singleNumber(nums, numsSize, &returnSize);
    int correctAns[] = {0, INT_MIN};
    TEST_ASSERT_EQUAL_INT(2, returnSize);
    qsort(ans, returnSize, sizeof(int), intAscCmpFunc);
    qsort(correctAns, returnSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(singleNumberTestExample1);
    RUN_TEST(singleNumberTestExample2);
    RUN_TEST(singleNumberTestExample3);
    RUN_TEST(singleNumberTestTest0);
    return UNITY_END();
}