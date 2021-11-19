//
// Created by smile on 2021/11/19.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "queue-reconstruction-by-height.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void reconstructQueueTestExample1(void) {
    int nums[][2] = {{7, 0},
                     {4, 4},
                     {7, 1},
                     {5, 0},
                     {6, 1},
                     {5, 2}};
    int peopleSize = ARRAY_LENGTH(nums);
    int peopleColSize[ARRAY_LENGTH(nums)];
    int **people = malloc(sizeof(int *) * peopleSize);
    for (size_t idx = 0; idx < peopleSize; ++idx) {
        people[idx] = nums[idx];
        peopleColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int returnSize = -1;
    int *returnColumnSizes = NULL;
    int **ans = reconstructQueue(people, peopleSize, peopleColSize, &returnSize, &returnColumnSizes);
    int correctAns[][2] = {{5, 0},
                           {7, 0},
                           {5, 2},
                           {6, 1},
                           {4, 4},
                           {7, 1}};
    TEST_ASSERT_EQUAL_INT(peopleSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(peopleColSize, returnColumnSizes, returnSize);
    for (int i = 0; i < peopleSize; ++i) {
        TEST_ASSERT_EQUAL_INT_ARRAY(correctAns[i], ans[i], peopleColSize[i]);
        free(ans[i]);
    }
    free(people);
    free(returnColumnSizes);
    free(ans);
}

void reconstructQueueTestExample2(void) {
    int nums[][2] = {{6, 0},
                     {5, 0},
                     {4, 0},
                     {3, 2},
                     {2, 2},
                     {1, 4}};
    int peopleSize = ARRAY_LENGTH(nums);
    int peopleColSize[ARRAY_LENGTH(nums)];
    int **people = malloc(sizeof(int *) * peopleSize);
    for (size_t idx = 0; idx < peopleSize; ++idx) {
        people[idx] = nums[idx];
        peopleColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int returnSize = -1;
    int *returnColumnSizes = NULL;
    int **ans = reconstructQueue(people, peopleSize, peopleColSize, &returnSize, &returnColumnSizes);
    int correctAns[][2] = {{4, 0},
                           {5, 0},
                           {2, 2},
                           {3, 2},
                           {1, 4},
                           {6, 0}};
    TEST_ASSERT_EQUAL_INT(peopleSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(peopleColSize, returnColumnSizes, returnSize);
    for (int i = 0; i < peopleSize; ++i) {
        TEST_ASSERT_EQUAL_INT_ARRAY(correctAns[i], ans[i], peopleColSize[i]);
        free(ans[i]);
    }
    free(people);
    free(returnColumnSizes);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(reconstructQueueTestExample1);
    RUN_TEST(reconstructQueueTestExample2);
    return UNITY_END();
}