//
// Created by l30014168 on 2021/9/28.
//

#include <stdlib.h>
#include <unity.h>
#include "util.h"
#include "numbers-with-same-consecutive-differences.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void numsSameConsecDiffExample1(void) {
    int n = 3, k = 7;
    int returnSize = -1;
    int *ans = numsSameConsecDiff(n, k, &returnSize);
    int correctAns[] = {181, 292, 707, 818, 929};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    qsort(ans, returnSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void numsSameConsecDiffExample2(void) {
    int n = 2, k = 1;
    int returnSize = -1;
    int *ans = numsSameConsecDiff(n, k, &returnSize);
    int correctAns[] = {10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    qsort(ans, returnSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void numsSameConsecDiffExample3(void) {
    int n = 2, k = 0;
    int returnSize = -1;
    int *ans = numsSameConsecDiff(n, k, &returnSize);
    int correctAns[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    qsort(ans, returnSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void numsSameConsecDiffExample4(void) {
    int n = 2, k = 2;
    int returnSize = -1;
    int *ans = numsSameConsecDiff(n, k, &returnSize);
    int correctAns[] = {13, 20, 24, 31, 35, 42, 46, 53, 57, 64, 68, 75, 79, 86, 97};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    qsort(ans, returnSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(numsSameConsecDiffExample1);
    RUN_TEST(numsSameConsecDiffExample2);
    RUN_TEST(numsSameConsecDiffExample3);
    RUN_TEST(numsSameConsecDiffExample4);
    return UNITY_END();
}