//
// Created by l30014168 on 2021/9/18.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "multi-search-lcci.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void multiSearchTestExample1(void) {
    char *big = "mississippi";
    char *smalls[] = {"is", "ppi", "hi", "sis", "i", "ssippi"};
    int returnSize = -1;
    int *returnColumnSizes;
    int **ans = multiSearch(big, smalls, sizeof(smalls) / sizeof(char *), &returnSize, &returnColumnSizes);
    int *correctAns[6];
    int correctAnsCol0[] = {1, 4};
    int correctAnsCol1[] = {8};
    int correctAnsCol3[] = {3};
    int correctAnsCol4[] = {1, 4, 7, 10};
    int correctAnsCol5[] = {5};
    correctAns[0] = correctAnsCol0;
    correctAns[1] = correctAnsCol1;
    correctAns[2] = NULL;
    correctAns[3] = correctAnsCol3;
    correctAns[4] = correctAnsCol4;
    correctAns[5] = correctAnsCol5;

    TEST_ASSERT_EQUAL_INT(6, returnSize);
    for (int i = 0; i < returnSize; ++i) {
        qsort(ans[i], returnColumnSizes[i], sizeof(int), intAscCmpFunc);
        TEST_ASSERT_EQUAL_INT_ARRAY(correctAns[i], ans[i], returnColumnSizes[i]);
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(multiSearchTestExample1);
    return UNITY_END();
}