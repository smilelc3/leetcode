//
// Created by l30014168 on 2021/10/14.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "score-after-flipping-matrix.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void matrixScoreExample1(void) {
    int nums[][4] = {{0, 0, 1, 1},
                     {1, 0, 1, 0},
                     {1, 1, 0, 0}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize = ARRAY_LENGTH(nums[0]);
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
    }
    int ans = matrixScore(grid, gridSize, &gridColSize);
    int correctAns = 39;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void matrixScoreExample2(void) {
    int nums[][1] = {{0}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize = ARRAY_LENGTH(nums[0]);
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
    }
    int ans = matrixScore(grid, gridSize, &gridColSize);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(matrixScoreExample1);
    RUN_TEST(matrixScoreExample2);
    return UNITY_END();
}