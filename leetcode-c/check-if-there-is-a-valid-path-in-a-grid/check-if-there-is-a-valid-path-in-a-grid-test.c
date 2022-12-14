//
// Created by smile on 2022/12/14.
//

#include <unity.h>
#include "check-if-there-is-a-valid-path-in-a-grid.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void hasValidPathTestExample1(void) {
    int nums[][3] = {{2, 4, 3},
                     {6, 5, 2}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    TEST_ASSERT_TRUE(hasValidPath(grid, gridSize, gridColSize));
}

void hasValidPathTestExample2(void) {
    int nums[][3] = {{1, 2, 1},
                     {1, 2, 1}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    TEST_ASSERT_FALSE(hasValidPath(grid, gridSize, gridColSize));
}

void hasValidPathTestExample3(void) {
    int nums[][3] = {{1, 1, 2}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    TEST_ASSERT_FALSE(hasValidPath(grid, gridSize, gridColSize));
}

void hasValidPathTestTest0(void) {
    int nums[][1] = {{2},
                     {2},
                     {2},
                     {2},
                     {2},
                     {2},
                     {6}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    TEST_ASSERT_TRUE(hasValidPath(grid, gridSize, gridColSize));
}

void hasValidPathTestTest1(void) {
    int nums[][2] = {{2, 6}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    TEST_ASSERT_FALSE(hasValidPath(grid, gridSize, gridColSize));
}

void hasValidPathTestTest2(void) {
    int nums[][3] = {{4, 3, 3},
                     {6, 5, 2}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    TEST_ASSERT_FALSE(hasValidPath(grid, gridSize, gridColSize));
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(hasValidPathTestExample1);
    RUN_TEST(hasValidPathTestExample2);
    RUN_TEST(hasValidPathTestExample3);
    RUN_TEST(hasValidPathTestTest0);
    RUN_TEST(hasValidPathTestTest1);
    RUN_TEST(hasValidPathTestTest2);
    return UNITY_END();
}