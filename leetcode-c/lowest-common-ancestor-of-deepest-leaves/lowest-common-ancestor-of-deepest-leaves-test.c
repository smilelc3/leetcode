//
// Created by l30014168 on 2021/12/2.
//

#include <unity.h>
#include "TreeNode.h"
#include "util.h"
#include "lowest-common-ancestor-of-deepest-leaves.c"

#define null INT_MAX

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void lcaDeepestLeavesTestExample1(void) {
    int nums[] = {3, 5, 1, 6, 2, 0, 8, null, null, 7, 4};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    struct TreeNode *ans = lcaDeepestLeaves(root);
    struct TreeNode *correctAns = root->left->right;
    TEST_ASSERT_EQUAL(correctAns, ans);
    TreeDestroy(root);
}

void lcaDeepestLeavesTestExample2(void) {
    int nums[] = {1};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    struct TreeNode *ans = lcaDeepestLeaves(root);
    struct TreeNode *correctAns = root;
    TEST_ASSERT_EQUAL(correctAns, ans);
    TreeDestroy(root);
}

void lcaDeepestLeavesTestExample3(void) {
    int nums[] = {0, 1, 3, null, 2};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    struct TreeNode *ans = lcaDeepestLeaves(root);
    struct TreeNode *correctAns = root->left->right;
    TEST_ASSERT_EQUAL(correctAns, ans);
    TreeDestroy(root);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(lcaDeepestLeavesTestExample1);
    RUN_TEST(lcaDeepestLeavesTestExample2);
    RUN_TEST(lcaDeepestLeavesTestExample3);
    return UNITY_END();
}