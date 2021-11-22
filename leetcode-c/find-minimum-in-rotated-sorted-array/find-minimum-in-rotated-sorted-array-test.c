//
// Created by l30014168 on 2021/9/13.
//

#include <unity.h>
#include "util.h"
#include "find-minimum-in-rotated-sorted-array.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void findMinTestExample1(void) {
    int nums[] = {3, 4, 5, 1, 2};
    int ans = findMin(nums, ARRAY_LENGTH(nums));
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void findMinTestExample2(void) {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int ans = findMin(nums, ARRAY_LENGTH(nums));
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void findMinTestExample3(void) {
    int nums[] = {11, 13, 15, 172};
    int ans = findMin(nums, ARRAY_LENGTH(nums));
    int correctAns = 11;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(findMinTestExample1);
    RUN_TEST(findMinTestExample2);
    RUN_TEST(findMinTestExample3);
    return UNITY_END();
}