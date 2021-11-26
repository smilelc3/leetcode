//
// Created by l30014168 on 2021/11/25.
//

#include <unity.h>
#include "util.h"
#include "advantage-shuffle.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void advantageCountTestExample1(void) {
    int nums1[] = {2, 7, 11, 15}, nums2[] = {1, 10, 4, 11};
    int returnSize = -1;
    int *ans = advantageCount(nums1, ARRAY_LENGTH(nums1), nums2, ARRAY_LENGTH(nums2), &returnSize);
    int ansCorrect[] = {2, 11, 7, 15};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(ansCorrect), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(ansCorrect, ans, returnSize);
    free(ans);
}

void advantageCountTestExample2(void) {
    int nums1[] = {12, 24, 8, 32}, nums2[] = {13, 25, 32, 11};
    int returnSize = -1;
    int *ans = advantageCount(nums1, ARRAY_LENGTH(nums1), nums2, ARRAY_LENGTH(nums2), &returnSize);
    int ansCorrect[] = {24, 32, 8, 12};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(ansCorrect), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(ansCorrect, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(advantageCountTestExample1);
    RUN_TEST(advantageCountTestExample2);
    return UNITY_END();
}