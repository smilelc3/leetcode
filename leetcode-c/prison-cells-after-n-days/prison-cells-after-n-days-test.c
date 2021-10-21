//
// Created by l30014168 on 2021/10/21.
//

#include <stdlib.h>
#include <unity.h>
#include "prison-cells-after-n-days.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void prisonAfterNDaysTestExample1(void) {
    int cell[8] = {0, 1, 0, 1, 1, 0, 0, 1};
    int n = 7;
    int returnSize = -1;
    int *ans = prisonAfterNDays(cell, sizeof(cell) / sizeof(int), n, &returnSize);
    int correctAns[8] = {0, 0, 1, 1, 0, 0, 0, 0};
    TEST_ASSERT_EQUAL_INT(sizeof(cell) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void prisonAfterNDaysTestExample2(void) {
    int cell[8] = {1, 0, 0, 1, 0, 0, 1, 0};
    int n = 1000000000;
    int returnSize = -1;
    int *ans = prisonAfterNDays(cell, sizeof(cell) / sizeof(int), n, &returnSize);
    int correctAns[8] = {0, 0, 1, 1, 1, 1, 1, 0};
    TEST_ASSERT_EQUAL_INT(sizeof(cell) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(prisonAfterNDaysTestExample1);
    RUN_TEST(prisonAfterNDaysTestExample2);
    return UNITY_END();
}