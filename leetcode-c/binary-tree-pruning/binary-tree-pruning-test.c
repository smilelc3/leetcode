//
// Created by smile on 2022/10/6.
//

#include <unity.h>
#include "util.h"
#include "binary-tree-pruning.c"

#define null INT_MAX

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void pruneTreeTestExample1(void) {
    int nums[] = {1, 0, 1, 0, 0, 0, 1};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    struct TreeNode *ans = pruneTree(root);
    int correctNums[] = {1, null, 1, null, 1};
    struct TreeNode *correctAns = TreeCreateByNums(correctNums, ARRAY_LENGTH(correctNums), null);
    TEST_ASSERT_TRUE(isSameTree(ans, correctAns));
    TreeDestroy(root);
    TreeDestroy(ans);
    TreeDestroy(correctAns);
}

void pruneTreeTestExample2(void) {
    int nums[] = {1, 0, 1, 0, 0, 0, 1};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    struct TreeNode *ans = pruneTree(root);
    int correctNums[] = {1, null, 1, null, 1};
    struct TreeNode *correctAns = TreeCreateByNums(correctNums, ARRAY_LENGTH(correctNums), null);
    TEST_ASSERT_TRUE(isSameTree(ans, correctAns));
    TreeDestroy(root);
    TreeDestroy(ans);
    TreeDestroy(correctAns);
}

void pruneTreeTestExample3(void) {
    int nums[] = {1, 1, 0, 1, 1, 0, 1, 0};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    struct TreeNode *ans = pruneTree(root);
    int correctNums[] = {1, 1, 0, 1, 1, null, 1};
    struct TreeNode *correctAns = TreeCreateByNums(correctNums, ARRAY_LENGTH(correctNums), null);
    TEST_ASSERT_TRUE(isSameTree(ans, correctAns));
    TreeDestroy(root);
    TreeDestroy(ans);
    TreeDestroy(correctAns);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(pruneTreeTestExample1);
    RUN_TEST(pruneTreeTestExample2);
    RUN_TEST(pruneTreeTestExample3);
    return UNITY_END();
}