//
// Created by l30014168 on 2021/11/22.
//

#include <stdlib.h>
#include <unity.h>
#include "util.h"
#include "find-right-interval.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void findRightIntervalExample1(void) {
    int nums[][2] = {{1, 2}};
    int intervalsSize = ARRAY_LENGTH(nums);
    int intervalsColSize[ARRAY_LENGTH(nums)];
    int **intervals = malloc(sizeof(int *) * intervalsSize);
    for (int idx = 0; idx < intervalsSize; ++idx) {
        intervals[idx] = nums[idx];
        intervalsColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int returnSize = -1;
    int *ans = findRightInterval(intervals, intervalsSize, intervalsColSize, &returnSize);
    int correctAns[] = {-1};
    TEST_ASSERT_EQUAL_INT(intervalsSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void findRightIntervalExample2(void) {
    int nums[][2] = {{3, 4},
                     {2, 3},
                     {1, 2}};
    int intervalsSize = ARRAY_LENGTH(nums);
    int intervalsColSize[ARRAY_LENGTH(nums)];
    int **intervals = malloc(sizeof(int *) * intervalsSize);
    for (int idx = 0; idx < intervalsSize; ++idx) {
        intervals[idx] = nums[idx];
        intervalsColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int returnSize = -1;
    int *ans = findRightInterval(intervals, intervalsSize, intervalsColSize, &returnSize);
    int correctAns[] = {-1, 0, 1};
    TEST_ASSERT_EQUAL_INT(intervalsSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void findRightIntervalExample3(void) {
    int nums[][2] = {{1, 4},
                     {2, 3},
                     {3, 4}};
    int intervalsSize = ARRAY_LENGTH(nums);
    int intervalsColSize[ARRAY_LENGTH(nums)];
    int **intervals = malloc(sizeof(int *) * intervalsSize);
    for (int idx = 0; idx < intervalsSize; ++idx) {
        intervals[idx] = nums[idx];
        intervalsColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int returnSize = -1;
    int *ans = findRightInterval(intervals, intervalsSize, intervalsColSize, &returnSize);
    int correctAns[] = {-1, 2, -1};
    TEST_ASSERT_EQUAL_INT(intervalsSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void findRightIntervalTest0(void) {
    int nums[][2] = {{4, 5},
                     {2, 3},
                     {1, 2}};
    int intervalsSize = ARRAY_LENGTH(nums);
    int intervalsColSize[ARRAY_LENGTH(nums)];
    int **intervals = malloc(sizeof(int *) * intervalsSize);
    for (int idx = 0; idx < intervalsSize; ++idx) {
        intervals[idx] = nums[idx];
        intervalsColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int returnSize = -1;
    int *ans = findRightInterval(intervals, intervalsSize, intervalsColSize, &returnSize);
    int correctAns[] = {-1, 0, 1};
    TEST_ASSERT_EQUAL_INT(intervalsSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
//    RUN_TEST(findRightIntervalExample1);
//    RUN_TEST(findRightIntervalExample2);
//    RUN_TEST(findRightIntervalExample3);
    RUN_TEST(findRightIntervalTest0);
    return UNITY_END();
}