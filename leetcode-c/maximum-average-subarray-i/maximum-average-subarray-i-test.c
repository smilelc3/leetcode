//
// Created by l30014168 on 2021/12/15.
//

#include <unity.h>
#include "util.h"
#include "maximum-average-subarray-i.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void findMaxAverageTestExample1(void) {
    int num[] = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double ans = findMaxAverage(num, ARRAY_LENGTH(num), k);
    double correctAns = 12.75000;
    TEST_ASSERT_EQUAL_DOUBLE(ans, correctAns);
}

void findMaxAverageTestExample2(void) {
    int num[] = {5};
    int k = 1;
    double ans = findMaxAverage(num, ARRAY_LENGTH(num), k);
    double correctAns = 5;
    TEST_ASSERT_EQUAL_DOUBLE(ans, correctAns);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(findMaxAverageTestExample1);
    RUN_TEST(findMaxAverageTestExample2);
    return UNITY_END();
}