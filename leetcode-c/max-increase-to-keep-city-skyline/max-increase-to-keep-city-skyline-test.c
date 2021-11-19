//
// Created by l30014168 on 2021/10/9.
//

#include <stdlib.h>
#include <unity.h>
#include "util.h"
#include "max-increase-to-keep-city-skyline.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void maxIncreaseKeepingSkylineTestExample1(void) {
    int nums[][4] = {{3, 0, 8, 4},
                     {2, 4, 5, 7},
                     {9, 2, 6, 3},
                     {0, 3, 1, 0}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize = ARRAY_LENGTH(nums[0]);

    int **grid = malloc(sizeof(int *) * gridSize);
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
    }
    int ans = maxIncreaseKeepingSkyline(grid, gridSize, &gridColSize);
    int correctAns = 35;
    TEST_ASSERT_EQUAL_INT(ans, correctAns);
    free(grid);
}

void maxIncreaseKeepingSkylineTestExample2(void) {
    int nums[][3] = {{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize = ARRAY_LENGTH(nums[0]);

    int **grid = malloc(sizeof(int *) * gridSize);
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
    }
    int ans = maxIncreaseKeepingSkyline(grid, gridSize, &gridColSize);
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(ans, correctAns);
    free(grid);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(maxIncreaseKeepingSkylineTestExample1);
    RUN_TEST(maxIncreaseKeepingSkylineTestExample2);
    return UNITY_END();
}