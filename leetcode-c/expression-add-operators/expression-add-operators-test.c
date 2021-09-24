//
// Created by l30014168 on 2021/9/24.
//
#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "expression-add-operators.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void addOperatorsTestExample1(void) {
    char *num = "123";
    int target = 6;
    int returnSize = -1;
    char **ans = addOperators(num, target, &returnSize);
    char *correctAns[] = {"1+2+3", "1*2*3"};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(char *), returnSize);
    qsort(ans, returnSize, sizeof(char *), strAscCmpFunc);
    qsort(correctAns, returnSize, sizeof(char *), strAscCmpFunc);
    TEST_ASSERT_EQUAL_STRING_ARRAY(correctAns, ans, returnSize);
    for (int i = 0; i < returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
}

void addOperatorsTestExample2(void) {
    char *num = "232";
    int target = 8;
    int returnSize = -1;
    char **ans = addOperators(num, target, &returnSize);
    char *correctAns[] = {"2*3+2", "2+3*2"};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(char *), returnSize);
    qsort(ans, returnSize, sizeof(char *), strAscCmpFunc);
    qsort(correctAns, returnSize, sizeof(char *), strAscCmpFunc);
    TEST_ASSERT_EQUAL_STRING_ARRAY(correctAns, ans, returnSize);
    for (int i = 0; i < returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
}

void addOperatorsTestExample3(void) {
    char *num = "105";
    int target = 5;
    int returnSize = -1;
    char **ans = addOperators(num, target, &returnSize);
    char *correctAns[] = {"1*0+5","10-5"};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(char *), returnSize);
    qsort(ans, returnSize, sizeof(char *), strAscCmpFunc);
    qsort(correctAns, returnSize, sizeof(char *), strAscCmpFunc);
    TEST_ASSERT_EQUAL_STRING_ARRAY(correctAns, ans, returnSize);
    for (int i = 0; i < returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
}

void addOperatorsTestExample4(void) {
    char *num = "00";
    int target = 0;
    int returnSize = -1;
    char **ans = addOperators(num, target, &returnSize);
    char *correctAns[] = {"0+0", "0-0", "0*0"};
    TEST_ASSERT_EQUAL_INT(sizeof(correctAns) / sizeof(char *), returnSize);
    qsort(ans, returnSize, sizeof(char *), strAscCmpFunc);
    qsort(correctAns, returnSize, sizeof(char *), strAscCmpFunc);
    TEST_ASSERT_EQUAL_STRING_ARRAY(correctAns, ans, returnSize);
    for (int i = 0; i < returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
}

void addOperatorsTestExample5(void) {
    char *num = "3456237490";
    int target = 9191;
    int returnSize = -1;
    char **ans = addOperators(num, target, &returnSize);
    char **correctAns = NULL;
    TEST_ASSERT_EQUAL_INT(0, returnSize);
    TEST_ASSERT_EQUAL(NULL, ans);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(addOperatorsTestExample1);
    RUN_TEST(addOperatorsTestExample2);
    RUN_TEST(addOperatorsTestExample3);
    RUN_TEST(addOperatorsTestExample4);
    RUN_TEST(addOperatorsTestExample5);
    return UNITY_END();
}