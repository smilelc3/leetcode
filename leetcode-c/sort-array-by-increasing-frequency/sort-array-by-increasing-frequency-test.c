//
// Created by smile on 2023/10/12.
//

#include <unity.h>
#include "util.h"
#include "sort-array-by-increasing-frequency.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void frequencySortExample1(void) {
    int nums[] = {1, 1, 2, 2, 2, 3};
    int numsSize = ARRAY_LENGTH(nums);
    int returnSize = -1;
    int *ans = frequencySort(nums, numsSize, &returnSize);
    int correctAns[] = {3, 1, 1, 2, 2, 2};
    TEST_ASSERT_EQUAL_INT(numsSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void frequencySortExample2(void) {
    int nums[] = {2, 3, 1, 3, 2};
    int numsSize = ARRAY_LENGTH(nums);
    int returnSize = -1;
    int *ans = frequencySort(nums, numsSize, &returnSize);
    int correctAns[] = {1, 3, 3, 2, 2};
    TEST_ASSERT_EQUAL_INT(numsSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void frequencySortExample3(void) {
    int nums[] = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    int numsSize = ARRAY_LENGTH(nums);
    int returnSize = -1;
    int *ans = frequencySort(nums, numsSize, &returnSize);
    int correctAns[] = {5, -1, 4, 4, -6, -6, 1, 1, 1};
    TEST_ASSERT_EQUAL_INT(numsSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(frequencySortExample1);
    RUN_TEST(frequencySortExample2);
    RUN_TEST(frequencySortExample3);
    return UNITY_END();
}