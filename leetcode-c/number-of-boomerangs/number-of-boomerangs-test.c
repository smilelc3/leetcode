//
// Created by l30014168 on 2021/9/14.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "number-of-boomerangs.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void numberOfBoomerangsTestExample1(void) {
    int nums[][2] = {{0, 0},
                     {1, 0},
                     {2, 0}};
    int pointsSize = ARRAY_LENGTH(nums);
    int pointsColSize = ARRAY_LENGTH(nums[0]);
    int *points[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < pointsSize; ++idx) {
        points[idx] = nums[idx];
    }
    int ans = numberOfBoomerangs(points, pointsSize, &pointsColSize);
    int correctAns = 2;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numberOfBoomerangsTestExample2(void) {
    int nums[][2] = {{1, 1},
                     {2, 2},
                     {3, 3}};
    int pointsSize = ARRAY_LENGTH(nums);
    int pointsColSize = ARRAY_LENGTH(nums[0]);
    int *points[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < pointsSize; ++idx) {
        points[idx] = nums[idx];
    }
    int ans = numberOfBoomerangs(points, pointsSize, &pointsColSize);
    int correctAns = 2;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void numberOfBoomerangsTestExample3(void) {
    int nums[][2] = {{1, 1}};
    int pointsSize = ARRAY_LENGTH(nums);
    int pointsColSize = ARRAY_LENGTH(nums[0]);
    int *points[ARRAY_LENGTH(nums)];
    for (size_t idx = 0; idx < pointsSize; ++idx) {
        points[idx] = nums[idx];
    }
    int ans = numberOfBoomerangs(points, pointsSize, &pointsColSize);
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(numberOfBoomerangsTestExample1);
    RUN_TEST(numberOfBoomerangsTestExample2);
    RUN_TEST(numberOfBoomerangsTestExample3);
    return UNITY_END();
}