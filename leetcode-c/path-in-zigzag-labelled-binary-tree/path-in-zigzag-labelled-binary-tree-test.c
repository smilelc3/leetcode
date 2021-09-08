//
// Created by l30014168 on 2021/7/29.
//

#include <unity.h>
#include "path-in-zigzag-labelled-binary-tree.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void pathInZigZagTreeTestExample1(void) {
    int label = 14;
    int returnSize = -1;
    int *ans = pathInZigZagTree(label, &returnSize);
    int rightAns[] = {1, 3, 4, 14};
    TEST_ASSERT_EQUAL_INT(sizeof(rightAns) / sizeof(rightAns[0]), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    free(ans);
}

void pathInZigZagTreeTestExample2(void) {
    int label = 26;
    int returnSize = -1;
    int *ans = pathInZigZagTree(label, &returnSize);
    int rightAns[] = {1, 2, 6, 10, 26};
    TEST_ASSERT_EQUAL_INT(sizeof(rightAns) / sizeof(rightAns[0]), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    free(ans);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(pathInZigZagTreeTestExample1);
    RUN_TEST(pathInZigZagTreeTestExample2);
    return UNITY_END();
}