//
// Created by smile on 2021/8/23.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "largest-number.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void largestNumberTestExample1(void) {
    int nums[] = {10, 2};
    char correctAns[] = "210";
    char *ans = largestNumber(nums, ARRAY_LENGTH(nums));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void largestNumberTestExample2(void) {
    int nums[] = {3, 30, 34, 5, 9};
    char correctAns[] = "9534330";
    char *ans = largestNumber(nums, ARRAY_LENGTH(nums));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void largestNumberTestExample3(void) {
    int nums[] = {1};
    char correctAns[] = "1";
    char *ans = largestNumber(nums, ARRAY_LENGTH(nums));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void largestNumberTestExample4(void) {
    int nums[] = {10};
    char correctAns[] = "10";
    char *ans = largestNumber(nums, ARRAY_LENGTH(nums));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void largestNumberTestExample5(void) {
    int nums[] = {30, 3};
    char correctAns[] = "330";
    char *ans = largestNumber(nums, ARRAY_LENGTH(nums));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void largestNumberTestTest0(void) {
    int nums[] = {111311, 1113};
    char correctAns[] = "1113111311";
    char *ans = largestNumber(nums, ARRAY_LENGTH(nums));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void largestNumberTestTest1(void) {
    int nums[] = {8308, 8308, 830};
    char correctAns[] = "83088308830";
    char *ans = largestNumber(nums, ARRAY_LENGTH(nums));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(largestNumberTestExample1);
    RUN_TEST(largestNumberTestExample2);
    RUN_TEST(largestNumberTestExample3);
    RUN_TEST(largestNumberTestExample4);
    RUN_TEST(largestNumberTestExample5);
    RUN_TEST(largestNumberTestTest0);
    RUN_TEST(largestNumberTestTest1);
    return UNITY_END();
}