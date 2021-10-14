//
// Created by l30014168 on 2021/10/12.
//
#include <unity.h>
#include <stdlib.h>
#include "most-stones-removed-with-same-row-or-column.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


void removeStonesExample1(void) {
    int nums[][2] = {{0, 0},
                     {0, 1},
                     {1, 0},
                     {1, 2},
                     {2, 1},
                     {2, 2}};
    int stonesSize = 6;
    int stonesColSize = 2;

    int **stones = malloc(sizeof(int *) * stonesSize);
    for (size_t idx = 0; idx < stonesSize; ++idx) {
        stones[idx] = nums[idx];
    }
    int ans = removeStones(stones, stonesSize, &stonesColSize);
    int correctAns = 5;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    free(stones);
}

void removeStonesExample2(void) {
    int nums[][2] = {{0, 0},
                     {0, 2},
                     {1, 1},
                     {2, 0},
                     {2, 2}};
    int stonesSize = 5;
    int stonesColSize = 2;

    int **stones = malloc(sizeof(int *) * stonesSize);
    for (size_t idx = 0; idx < stonesSize; ++idx) {
        stones[idx] = nums[idx];
    }
    int ans = removeStones(stones, stonesSize, &stonesColSize);
    int correctAns = 3;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    free(stones);
}

void removeStonesExample3(void) {
    int nums[][2] = {{0, 0}};
    int stonesSize = 1;
    int stonesColSize = 2;

    int **stones = malloc(sizeof(int *) * stonesSize);
    for (size_t idx = 0; idx < stonesSize; ++idx) {
        stones[idx] = nums[idx];
    }
    int ans = removeStones(stones, stonesSize, &stonesColSize);
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    free(stones);
}

void removeStonesTest0(void) {
    int nums[][2] = {{0, 1},
                     {1, 0},
                     {1, 1}};
    int stonesSize = 3;
    int stonesColSize = 2;

    int **stones = malloc(sizeof(int *) * stonesSize);
    for (size_t idx = 0; idx < stonesSize; ++idx) {
        stones[idx] = nums[idx];
    }
    int ans = removeStones(stones, stonesSize, &stonesColSize);
    int correctAns = 2;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    free(stones);
}

void removeStonesTest1(void) {
    int nums[][2] = {{0, 1},
                     {1, 0}};
    int stonesSize = 2;
    int stonesColSize = 2;

    int **stones = malloc(sizeof(int *) * stonesSize);
    for (size_t idx = 0; idx < stonesSize; ++idx) {
        stones[idx] = nums[idx];
    }
    int ans = removeStones(stones, stonesSize, &stonesColSize);
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    free(stones);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(removeStonesExample1);
    RUN_TEST(removeStonesExample2);
    RUN_TEST(removeStonesExample3);
    RUN_TEST(removeStonesTest0);
    RUN_TEST(removeStonesTest1);
    return UNITY_END();
}