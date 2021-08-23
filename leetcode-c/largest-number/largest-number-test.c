//
// Created by smile on 2021/8/23.
//

#include <unity.h>
#include <stdlib.h>
#include "largest-number.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testLargestNumberExample1(void) {
    int nums[] = {10, 2};
    char correctAns[] = "210";
    char *ans = largestNumber(nums, sizeof(nums) / sizeof(int));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void testLargestNumberExample2(void) {
    int nums[] = {3, 30, 34, 5, 9};
    char correctAns[] = "9534330";
    char *ans = largestNumber(nums, sizeof(nums) / sizeof(int));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void testLargestNumberExample3(void) {
    int nums[] = {1};
    char correctAns[] = "1";
    char *ans = largestNumber(nums, sizeof(nums) / sizeof(int));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void testLargestNumberExample4(void) {
    int nums[] = {10};
    char correctAns[] = "10";
    char *ans = largestNumber(nums, sizeof(nums) / sizeof(int));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void testLargestNumberMyTest0(void) {
    int nums[] = {30, 3};
    char correctAns[] = "330";
    char *ans = largestNumber(nums, sizeof(nums) / sizeof(int));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void testLargestNumberTest0(void) {
    int nums[] = {111311, 1113};
    char correctAns[] = "1113111311";
    char *ans = largestNumber(nums, sizeof(nums) / sizeof(int));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void testLargestNumberTest1(void) {
    int nums[] = {8308, 8308, 830};
    char correctAns[] = "83088308830";
    char *ans = largestNumber(nums, sizeof(nums) / sizeof(int));
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testLargestNumberExample1);
    RUN_TEST(testLargestNumberExample2);
    RUN_TEST(testLargestNumberExample3);
    RUN_TEST(testLargestNumberExample4);
    RUN_TEST(testLargestNumberMyTest0);
    RUN_TEST(testLargestNumberTest0);
    RUN_TEST(testLargestNumberTest1);
    return UNITY_END();
}