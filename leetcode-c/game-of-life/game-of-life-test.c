//
// Created by l30014168 on 2021/9/30.
//

#include <stdlib.h>
#include <unity.h>
#include "util.h"
#include "game-of-life.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void gameOfLifeExample1(void) {
    int nums[][3] = {{0, 1, 0},
                     {0, 0, 1},
                     {1, 1, 1},
                     {0, 0, 0}};
    int boardSize = ARRAY_LENGTH(nums);
    int boardColSize = ARRAY_LENGTH(nums[0]);
    int **board = malloc(sizeof(int *) * boardSize);
    for (size_t idx = 0; idx < boardSize; ++idx) {
        board[idx] = nums[idx];
    }
    gameOfLife(board, boardSize, &boardColSize);
    int correctAns[][3] = {{0, 0, 0},
                           {1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 0}};
    TEST_ASSERT_EQUAL_INT(3, boardColSize);
    for (size_t idx = 0; idx < boardSize; ++idx) {
        TEST_ASSERT_EQUAL_INT_ARRAY(correctAns[idx], board[idx], boardColSize);
    }
    free(board);
}

void gameOfLifeExample2(void) {
    int nums[][2] = {{1, 1},
                     {1, 0}};
    int boardSize = ARRAY_LENGTH(nums);
    int boardColSize = ARRAY_LENGTH(nums[0]);
    int **board = malloc(sizeof(int *) * boardSize);
    for (size_t idx = 0; idx < boardSize; ++idx) {
        board[idx] = nums[idx];
    }
    gameOfLife(board, boardSize, &boardColSize);
    int correctAns[][2] = {{1, 1},
                           {1, 1}};
    TEST_ASSERT_EQUAL_INT(2, boardColSize);
    for (size_t idx = 0; idx < boardSize; ++idx) {
        TEST_ASSERT_EQUAL_INT_ARRAY(correctAns[idx], board[idx], boardColSize);
    }
    free(board);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(gameOfLifeExample1);
    RUN_TEST(gameOfLifeExample2);
    return UNITY_END();
}