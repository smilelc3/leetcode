//
// Created by smile on 2024/1/18.
//

#include <unity.h>
#include "TreeNode.h"
#include "util.h"
#include "find-bottom-left-tree-value.c"

#define null INT_MAX

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void findBottomLeftValueExample1(void) {
    int nums[] = {2, 1, 3};
    struct TreeNode *root = BinaryTreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    int ans = findBottomLeftValue(root);
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    BinaryTreeDestroy(root);
}

void findBottomLeftValueExample2(void) {
    int nums[] = {1, 2, 3, 4, null, 5, 6, null, null, 7};
    struct TreeNode *root = BinaryTreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    int ans = findBottomLeftValue(root);
    int correctAns = 7;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    BinaryTreeDestroy(root);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(findBottomLeftValueExample1);
    RUN_TEST(findBottomLeftValueExample2);
    return UNITY_END();
}