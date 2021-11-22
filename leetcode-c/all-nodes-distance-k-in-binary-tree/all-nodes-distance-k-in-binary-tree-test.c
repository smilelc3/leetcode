//
// Created by l30014168 on 2021/7/30.
//

#include <stdlib.h>
#include <unity.h>
#include "TreeNode.h"
#include "util.h"
#include "all-nodes-distance-k-in-binary-tree.c"

#define null INT_MAX

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void distanceKTestExample1(void) {
    int nums[] = {3, 5, 1, 6, 2, 0, 8, null, null, 7, 4};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    struct TreeNode *target = root->left;
    int k = 2;
    int returnSize = -1;
    int *ans = distanceK(root, target, k, &returnSize);
    int rightAns[] = {7, 4, 1};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(rightAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    TreeDestroy(root);
    free(ans);
}

void distanceKTestExample2(void) {
    int nums[] = {1};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    struct TreeNode *target = root;
    int k = 3;
    int returnSize = -1;
    int *ans = distanceK(root, target, k, &returnSize);
    TEST_ASSERT_EQUAL_INT(0, returnSize);
    TreeDestroy(root);
    free(ans);
}

void distanceKTestTest0(void) {
    int nums[] = {0, 1, null, 2, null, 3};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    struct TreeNode *target = root->left;
    int k = 2;
    int returnSize = -1;
    int *ans = distanceK(root, target, k, &returnSize);
    int rightAns[] = {3};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(rightAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    TreeDestroy(root);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(distanceKTestExample1);
    RUN_TEST(distanceKTestExample2);
    RUN_TEST(distanceKTestTest0);
    return UNITY_END();
}