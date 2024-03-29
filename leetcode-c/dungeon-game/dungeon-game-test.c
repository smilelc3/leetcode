//
// Created by smile on 2021/9/9.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "dungeon-game.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void calculateMinimumHPTestExample1(void) {
    int nums[][3] = {{-2, -3,  3},
                     {-5, -10, 1},
                     {10, 30,  -5}};
    int dungeonSize = ARRAY_LENGTH(nums);
    int dungeonColSize = ARRAY_LENGTH(nums[0]);
    int *dungeon[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < dungeonSize; ++idx) {
        dungeon[idx] = nums[idx];
    }
    int ans = calculateMinimumHP(dungeon, dungeonSize, &dungeonColSize);
    int correctAns = 7;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void calculateMinimumHPTestExample2(void) {
    int nums[][1] = {{0}};
    int dungeonSize = ARRAY_LENGTH(nums);
    int dungeonColSize = ARRAY_LENGTH(nums[0]);
    int *dungeon[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < dungeonSize; ++idx) {
        dungeon[idx] = nums[idx];
    }
    int ans = calculateMinimumHP(dungeon, dungeonSize, &dungeonColSize);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void calculateMinimumHPTestTest0(void) {
    int nums[][2] = {{0, 0}};
    int dungeonSize = ARRAY_LENGTH(nums);
    int dungeonColSize = ARRAY_LENGTH(nums[0]);
    int *dungeon[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < dungeonSize; ++idx) {
        dungeon[idx] = nums[idx];
    }
    int ans = calculateMinimumHP(dungeon, dungeonSize, &dungeonColSize);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(calculateMinimumHPTestExample1);
    RUN_TEST(calculateMinimumHPTestExample2);
    RUN_TEST(calculateMinimumHPTestTest0);
    return UNITY_END();
}