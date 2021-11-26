//
// Created by l30014168 on 2021/11/23.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "distant-barcodes.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void rearrangeBarcodesTestExample1(void) {
    int barcodes[] = {1, 1, 1, 2, 2, 2};
    int barcodesSize = ARRAY_LENGTH(barcodes);
    int returnSize = -1;
    int *ans = rearrangeBarcodes(barcodes, barcodesSize, &returnSize);
    TEST_ASSERT_EQUAL_INT(barcodesSize, returnSize);
    for (int i = 0; i < barcodesSize - 1; ++i) {
        TEST_ASSERT_TRUE(ans[i] != ans[i + 1]);
    }
    qsort(barcodes, barcodesSize, sizeof(int), intAscCmpFunc);
    qsort(ans, barcodesSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(ans, ans, returnSize);
    free(ans);
}

void rearrangeBarcodesTestExample2(void) {
    int barcodes[] = {1, 1, 1, 1, 2, 2, 3, 3};
    int barcodesSize = ARRAY_LENGTH(barcodes);
    int returnSize = -1;
    int *ans = rearrangeBarcodes(barcodes, barcodesSize, &returnSize);
    TEST_ASSERT_EQUAL_INT(barcodesSize, returnSize);
    for (int i = 0; i < barcodesSize - 1; ++i) {
        TEST_ASSERT_TRUE(ans[i] != ans[i + 1]);
    }
    qsort(barcodes, barcodesSize, sizeof(int), intAscCmpFunc);
    qsort(ans, barcodesSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(ans, ans, returnSize);
    free(ans);
}

void rearrangeBarcodesTestTest0(void) {
    int barcodes[] = {3, 7, 3, 7, 7, 7, 7, 2, 2, 2};
    int barcodesSize = ARRAY_LENGTH(barcodes);
    int returnSize = -1;
    int *ans = rearrangeBarcodes(barcodes, barcodesSize, &returnSize);
    TEST_ASSERT_EQUAL_INT(barcodesSize, returnSize);
    for (int i = 0; i < barcodesSize - 1; ++i) {
        TEST_ASSERT_TRUE(ans[i] != ans[i + 1]);
    }
    qsort(barcodes, barcodesSize, sizeof(int), intAscCmpFunc);
    qsort(ans, barcodesSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(ans, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(rearrangeBarcodesTestExample1);
    RUN_TEST(rearrangeBarcodesTestExample2);
    RUN_TEST(rearrangeBarcodesTestTest0);
    return UNITY_END();
}