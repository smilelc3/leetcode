//
// Created by smile on 2021/10/24.
//

#include <unity.h>
#include <stdlib.h>
#include "sliding-window-maximum.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void maxSlidingWindowTestExample1(void) {
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, sizeof(nums) / sizeof(int), k, &returnSize);
    int correctAns[] = {3, 3, 5, 5, 6, 7};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void maxSlidingWindowTestExample2(void) {
    int nums[] = {1};
    int k = 1;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, sizeof(nums) / sizeof(int), k, &returnSize);
    int correctAns[] = {1};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void maxSlidingWindowTestExample3(void) {
    int nums[] = {1, -1};
    int k = 1;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, sizeof(nums) / sizeof(int), k, &returnSize);
    int correctAns[] = {1, -1};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void maxSlidingWindowTestExample4(void) {
    int nums[] = {9, 11};
    int k = 2;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, sizeof(nums) / sizeof(int), k, &returnSize);
    int correctAns[] = {11};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void maxSlidingWindowTestExample5(void) {
    int nums[] = {4, -2};
    int k = 2;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, sizeof(nums) / sizeof(int), k, &returnSize);
    int correctAns[] = {4};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(maxSlidingWindowTestExample1);
    RUN_TEST(maxSlidingWindowTestExample2);
    RUN_TEST(maxSlidingWindowTestExample3);
    RUN_TEST(maxSlidingWindowTestExample4);
    RUN_TEST(maxSlidingWindowTestExample5);
    return UNITY_END();
}