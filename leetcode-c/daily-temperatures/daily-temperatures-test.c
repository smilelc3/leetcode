//
// Created by l30014168 on 2021/7/23.
//

#include <unity.h>
#include <stdlib.h>
#include "daily-temperatures.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testDailyTemperaturesExample1(void) {
    int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int temperaturesSize = sizeof(temperatures) / sizeof(int);
    int returnSize = -1;
    int *ans = dailyTemperatures(temperatures, temperaturesSize, &returnSize);
    int rightAns[] = {1, 1, 4, 2, 1, 1, 0, 0};
    TEST_ASSERT_EQUAL_INT(returnSize, sizeof(rightAns) / sizeof(int));
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    free(ans);
}

void testDailyTemperaturesExample2(void) {
    int temperatures[] = {30, 40, 50, 60};
    int temperaturesSize = sizeof(temperatures) / sizeof(int);
    int returnSize = -1;
    int *ans = dailyTemperatures(temperatures, temperaturesSize, &returnSize);
    int rightAns[] = {1, 1, 1, 0};
    TEST_ASSERT_EQUAL_INT(returnSize, sizeof(rightAns) / sizeof(int));
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    free(ans);
}

void testDailyTemperaturesExample3(void) {
    int temperatures[] = {30, 60, 90};
    int temperaturesSize = sizeof(temperatures) / sizeof(int);
    int returnSize = -1;
    int *ans = dailyTemperatures(temperatures, temperaturesSize, &returnSize);
    int rightAns[] = {1, 1, 0};
    TEST_ASSERT_EQUAL_INT(returnSize, sizeof(rightAns) / sizeof(int));
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    free(ans);
}

void testDailyTemperaturesTest0(void) {
    int temperatures[] = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
    int temperaturesSize = sizeof(temperatures) / sizeof(int);
    int returnSize = -1;
    int *ans = dailyTemperatures(temperatures, temperaturesSize, &returnSize);
    int rightAns[] = {8, 1, 5, 4, 3, 2, 1, 1, 0, 0};
    TEST_ASSERT_EQUAL_INT(returnSize, sizeof(rightAns) / sizeof(int));
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testDailyTemperaturesExample1);
    RUN_TEST(testDailyTemperaturesExample2);
    RUN_TEST(testDailyTemperaturesExample3);

    RUN_TEST(testDailyTemperaturesTest0);
    return UNITY_END();
}