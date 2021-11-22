//
// Created by l30014168 on 2021/9/22.
//

#include <unity.h>
#include "util.h"
#include "find-minimum-in-rotated-sorted-array-ii.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void findMinTestExample1(void) {
    int nums[] = {1, 3, 5};
    int ans = findMin(nums, ARRAY_LENGTH(nums));
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void findMinTestExample2(void) {
    int nums[] = {2, 2, 2, 0, 1};
    int ans = findMin(nums, ARRAY_LENGTH(nums));
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void findMinTestTest0(void) {
    int nums[] = {3, 3, 1, 3};
    int ans = findMin(nums, ARRAY_LENGTH(nums));
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void findMinTestTest1(void) {
    int nums[] = {10, 1, 10, 10, 10};
    int ans = findMin(nums, ARRAY_LENGTH(nums));
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(findMinTestExample1);
    RUN_TEST(findMinTestExample2);
    RUN_TEST(findMinTestTest0);
    RUN_TEST(findMinTestTest1);
    return UNITY_END();
}