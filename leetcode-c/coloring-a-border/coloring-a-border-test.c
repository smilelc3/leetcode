//
// Created by smile on 2021/11/3.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "coloring-a-border.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void colorBorderTestExample1(void) {
    int nums[][2] = {{1, 1},
                     {1, 2}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int row = 0, col = 0, color = 3;
    int returnSize = -1;
    int *returnColumnSizes = NULL;
    int **ans = colorBorder(grid, gridSize, gridColSize, row, col, color, &returnSize, &returnColumnSizes);
    int correctAns[][2] = {{3, 3},
                           {3, 2}};
    TEST_ASSERT_EQUAL_INT(gridSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(gridColSize, returnColumnSizes, returnSize);
    for (int i = 0; i < gridSize; ++i) {
        TEST_ASSERT_EQUAL_INT_ARRAY(correctAns[i], ans[i], gridColSize[i]);
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

void colorBorderTestExample2(void) {
    int nums[][3] = {{1, 2, 2},
                     {2, 3, 2}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int row = 0, col = 1, color = 3;
    int returnSize = -1;
    int *returnColumnSizes = NULL;
    int **ans = colorBorder(grid, gridSize, gridColSize, row, col, color, &returnSize, &returnColumnSizes);
    int correctAns[][3] = {{1, 3, 3},
                           {2, 3, 3}};
    TEST_ASSERT_EQUAL_INT(gridSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(gridColSize, returnColumnSizes, returnSize);
    for (int i = 0; i < gridSize; ++i) {
        TEST_ASSERT_EQUAL_INT_ARRAY(correctAns[i], ans[i], gridColSize[i]);
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

void colorBorderTestExample3(void) {
    int nums[][3] = {{1, 1, 1},
                     {1, 1, 1},
                     {1, 1, 1}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int row = 1, col = 1, color = 2;
    int returnSize = -1;
    int *returnColumnSizes = NULL;
    int **ans = colorBorder(grid, gridSize, gridColSize, row, col, color, &returnSize, &returnColumnSizes);
    int correctAns[][3] = {{2, 2, 2},
                           {2, 1, 2},
                           {2, 2, 2}};
    TEST_ASSERT_EQUAL_INT(gridSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(gridColSize, returnColumnSizes, returnSize);
    for (int i = 0; i < gridSize; ++i) {
        TEST_ASSERT_EQUAL_INT_ARRAY(correctAns[i], ans[i], gridColSize[i]);
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

void colorBorderTestTest0(void) {
    int nums[][3] = {{1, 2, 1},
                     {1, 2, 2},
                     {2, 2, 1}};
    int gridSize = ARRAY_LENGTH(nums);
    int gridColSize[ARRAY_LENGTH(nums)];
    int *grid[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < gridSize; ++idx) {
        grid[idx] = nums[idx];
        gridColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int row = 1, col = 1, color = 2;
    int returnSize = -1;
    int *returnColumnSizes = NULL;
    int **ans = colorBorder(grid, gridSize, gridColSize, row, col, color, &returnSize, &returnColumnSizes);
    int correctAns[][3] = {{1, 2, 1},
                           {1, 2, 2},
                           {2, 2, 1}};
    TEST_ASSERT_EQUAL_INT(gridSize, returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(gridColSize, returnColumnSizes, returnSize);
    for (int i = 0; i < gridSize; ++i) {
        TEST_ASSERT_EQUAL_INT_ARRAY(correctAns[i], ans[i], gridColSize[i]);
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(colorBorderTestExample1);
    RUN_TEST(colorBorderTestExample2);
    RUN_TEST(colorBorderTestExample3);
    RUN_TEST(colorBorderTestTest0);
    return UNITY_END();
}