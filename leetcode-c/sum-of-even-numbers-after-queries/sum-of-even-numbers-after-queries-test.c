//
// Created by smile on 2021/10/24.
//

#include <unity.h>
#include <stdlib.h>
#include "sum-of-even-numbers-after-queries.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void sumEvenAfterQueriesTestExample1(void) {
    int nums[] = {1, 2, 3, 4};
    int data[][2] = {{1,  0},
                     {-3, 1},
                     {-4, 0},
                     {2,  3}};
    int queriesSize = 4;
    int *queriesColSize = malloc(sizeof(int) * queriesSize);
    int **queries = malloc(sizeof(int *) * queriesSize);
    for (size_t idx = 0; idx < queriesSize; ++idx) {
        queries[idx] = data[idx];
        queriesColSize[idx] = sizeof(data[idx]) / sizeof(int);
    }
    int returnSize = -1;
    int *ans = sumEvenAfterQueries(nums, sizeof(nums) / sizeof(int),
                                   queries, queriesSize, queriesColSize, &returnSize);
    int correctAns[] = {8, 6, 2, 4};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(queries);
    free(queriesColSize);
    free(ans);
}

void sumEvenAfterQueriesTestExample2(void) {
    int nums[] = {1};
    int data[][2] = {{4, 0}};
    int queriesSize = 1;
    int *queriesColSize = malloc(sizeof(int) * queriesSize);
    int **queries = malloc(sizeof(int *) * queriesSize);
    for (size_t idx = 0; idx < queriesSize; ++idx) {
        queries[idx] = data[idx];
        queriesColSize[idx] = sizeof(data[idx]) / sizeof(int);
    }
    int returnSize = -1;
    int *ans = sumEvenAfterQueries(nums, sizeof(nums) / sizeof(int),
                                   queries, queriesSize, queriesColSize, &returnSize);
    int correctAns[] = {0};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(queries);
    free(queriesColSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(sumEvenAfterQueriesTestExample1);
    RUN_TEST(sumEvenAfterQueriesTestExample2);
    return UNITY_END();
}