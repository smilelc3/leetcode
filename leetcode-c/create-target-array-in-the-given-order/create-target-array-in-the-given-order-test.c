//
// Created by smile on 2021/8/22.
//

#include <unity.h>
#include <stdlib.h>
#include "create-target-array-in-the-given-order.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void createTargetArrayTestExample1(void) {
    int nums[] = {0, 1, 2, 3, 4}, index[] = {0, 1, 2, 2, 1};
    int returnSize = -1;
    int *ans = createTargetArray(nums, sizeof(nums) / sizeof(int), index, sizeof(index) / sizeof(int), &returnSize);
    int correctAns[] = {0, 4, 1, 3, 2};
    TEST_ASSERT_EQUAL_INT(returnSize, sizeof(correctAns) / sizeof(int));
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void createTargetArrayTestExample2(void) {
    int nums[] = {1, 2, 3, 4, 0}, index[] = {0, 1, 2, 3, 0};
    int returnSize = -1;
    int *ans = createTargetArray(nums, sizeof(nums) / sizeof(int), index, sizeof(index) / sizeof(int), &returnSize);
    int correctAns[] = {0, 1, 2, 3, 4};
    TEST_ASSERT_EQUAL_INT(returnSize, sizeof(correctAns) / sizeof(int));
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void createTargetArrayTestExample3(void) {
    int nums[] = {1}, index[] = {0};
    int returnSize = -1;
    int *ans = createTargetArray(nums, sizeof(nums) / sizeof(int), index, sizeof(index) / sizeof(int), &returnSize);
    int correctAns[] = {1};
    TEST_ASSERT_EQUAL_INT(returnSize, sizeof(correctAns) / sizeof(int));
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(createTargetArrayTestExample1);
    RUN_TEST(createTargetArrayTestExample2);
    RUN_TEST(createTargetArrayTestExample3);
    return UNITY_END();
}