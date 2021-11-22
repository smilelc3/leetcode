//
// Created by l30014168 on 2021/11/2.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "construct-the-lexicographically-largest-valid-sequence.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void constructDistancedSequenceTestExample1(void) {
    int n = 3;
    int returnSize = -1;
    int *ans = constructDistancedSequence(n, &returnSize);
    int correctAns[] = {3, 1, 2, 3, 2};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void constructDistancedSequenceTestExample2(void) {
    int n = 5;
    int returnSize = -1;
    int *ans = constructDistancedSequence(n, &returnSize);
    int correctAns[] = {5, 3, 1, 4, 3, 5, 2, 4, 2};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(constructDistancedSequenceTestExample1);
    RUN_TEST(constructDistancedSequenceTestExample2);
    return UNITY_END();
}