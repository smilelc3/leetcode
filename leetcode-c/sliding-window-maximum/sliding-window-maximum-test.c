//
// Created by smile on 2021/10/24.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
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
    int *ans = maxSlidingWindow(nums, ARRAY_LENGTH(nums), k, &returnSize);
    int correctAns[] = {3, 3, 5, 5, 6, 7};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void maxSlidingWindowTestExample2(void) {
    int nums[] = {1};
    int k = 1;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, ARRAY_LENGTH(nums), k, &returnSize);
    int correctAns[] = {1};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void maxSlidingWindowTestExample3(void) {
    int nums[] = {1, -1};
    int k = 1;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, ARRAY_LENGTH(nums), k, &returnSize);
    int correctAns[] = {1, -1};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void maxSlidingWindowTestExample4(void) {
    int nums[] = {9, 11};
    int k = 2;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, ARRAY_LENGTH(nums), k, &returnSize);
    int correctAns[] = {11};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void maxSlidingWindowTestExample5(void) {
    int nums[] = {4, -2};
    int k = 2;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, ARRAY_LENGTH(nums), k, &returnSize);
    int correctAns[] = {4};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void maxSlidingWindowTestTest0(void) {
    int nums[] = {1, 3, 1, 2, 0, 5};
    int k = 3;
    int returnSize = -1;
    int *ans = maxSlidingWindow(nums, ARRAY_LENGTH(nums), k, &returnSize);
    int correctAns[] = {3, 3, 2, 5};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
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
    RUN_TEST(maxSlidingWindowTestTest0);
    return UNITY_END();
}