//
// Created by l30014168 on 2021/11/25.
//

#include <unity.h>
#include "util.h"
#include "the-number-of-the-smallest-unoccupied-chair.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void smallestChairTestExample1(void) {
    int nums[][2] = {{1, 4},
                     {2, 3},
                     {4, 6}};
    int targetFriend = 1;
    int timesSize = ARRAY_LENGTH(nums);
    int timesColSize[ARRAY_LENGTH(nums)];
    int *times[ARRAY_LENGTH(nums)];
    for (int idx = 0; idx < timesSize; ++idx) {
        times[idx] = nums[idx];
        timesColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int ans = smallestChair(times, timesSize, timesColSize, targetFriend);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void smallestChairTestExample2(void) {
    int nums[][2] = {{3, 10},
                     {1, 5},
                     {2, 6}};
    int targetFriend = 2;
    int timesSize = ARRAY_LENGTH(nums);
    int timesColSize[ARRAY_LENGTH(nums)];
    int *times[ARRAY_LENGTH(nums)];
    for (int idx = 0; idx < timesSize; ++idx) {
        times[idx] = nums[idx];
        timesColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int ans = smallestChair(times, timesSize, timesColSize, targetFriend);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(smallestChairTestExample1);
    RUN_TEST(smallestChairTestExample2);
    return UNITY_END();
}