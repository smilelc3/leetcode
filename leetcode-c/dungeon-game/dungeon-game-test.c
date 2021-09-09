//
// Created by smile on 2021/9/9.
//

#include <unity.h>
#include <stdlib.h>
#include "dungeon-game.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void calculateMinimumHPExample1(void) {
    int nums[][3] = {{-2, -3,  3},
                     {-5, -10, 1},
                     {10, 30,  -5}};
    int dungeonColSize = 3;
    int dungeonSize = 3;
    int **dungeon = malloc(sizeof(int *) * dungeonSize);
    for (size_t idx = 0; idx < dungeonSize; ++idx) {
        dungeon[idx] = nums[idx];
    }

    int ans = calculateMinimumHP(dungeon, dungeonSize, &dungeonColSize);
    int correctAns = 7;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    free(dungeon);
}

void calculateMinimumHPExample2(void) {
    int nums[][1] = {{0}};
    int dungeonColSize = 1;
    int dungeonSize = 1;
    int **dungeon = malloc(sizeof(int *) * dungeonSize);
    for (size_t idx = 0; idx < dungeonSize; ++idx) {
        dungeon[idx] = nums[idx];
    }

    int ans = calculateMinimumHP(dungeon, dungeonSize, &dungeonColSize);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    free(dungeon);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(calculateMinimumHPExample1);
    RUN_TEST(calculateMinimumHPExample2);
    return UNITY_END();
}