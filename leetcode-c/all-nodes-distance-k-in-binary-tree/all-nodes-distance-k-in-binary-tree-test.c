//
// Created by l30014168 on 2021/7/30.
//

#include <stdlib.h>
#include <unity.h>
#include "all-nodes-distance-k-in-binary-tree.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testDistanceKExample1(void) {
    struct TreeNode *root;
    root = calloc(1, sizeof(struct TreeNode));
    root->val = 3;
    root->left = calloc(1, sizeof(struct TreeNode));
    root->left->val = 5;
    root->right = calloc(1, sizeof(struct TreeNode));
    root->right->val = 1;

    root->left->left = calloc(1, sizeof(struct TreeNode));
    root->left->left->val = 6;
    root->left->right = calloc(1, sizeof(struct TreeNode));
    root->left->right->val = 2;

    root->right->left = calloc(1, sizeof(struct TreeNode));
    root->right->left->val = 0;
    root->right->right = calloc(1, sizeof(struct TreeNode));
    root->right->right->val = 8;

    root->left->right->left = calloc(1, sizeof(struct TreeNode));
    root->left->right->left->val = 7;
    root->left->right->right = calloc(1, sizeof(struct TreeNode));
    root->left->right->right->val = 4;

    struct TreeNode *target = root->left;
    int k = 2;
    int returnSize = -1;
    int *ans = distanceK(root, target, k, &returnSize);
    int rightAns[] = {7, 4, 1};
    TEST_ASSERT_EQUAL_INT(sizeof(rightAns) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);

    TreeDestroy(root);
    free(ans);
}


void testDistanceKExample2(void) {
    struct TreeNode *root;
    root = calloc(1, sizeof(struct TreeNode));
    root->val = 1;

    struct TreeNode *target = root;
    int k = 3;
    int returnSize = -1;
    int *ans = distanceK(root, target, k, &returnSize);
    int *rightAns = NULL;
    TEST_ASSERT_EQUAL_INT(0, returnSize);

    TreeDestroy(root);
    free(ans);
}


void testDistanceKTest0(void) {
    struct TreeNode *root;
    root = calloc(1, sizeof(struct TreeNode));
    root->val = 0;
    root->right = calloc(1, sizeof(struct TreeNode));
    root->right->val = 1;

    root->right->right = calloc(1, sizeof(struct TreeNode));
    root->right->right->val = 2;

    root->right->right->right = calloc(1, sizeof(struct TreeNode));
    root->right->right->right->val = 3;

    struct TreeNode *target = root->right;
    int k = 2;
    int returnSize = -1;
    int *ans = distanceK(root, target, k, &returnSize);
    int rightAns[] = {3};
    TEST_ASSERT_EQUAL_INT(sizeof(rightAns) / sizeof(int), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);

    TreeDestroy(root);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    //RUN_TEST(testDistanceKExample1);
    RUN_TEST(testDistanceKExample2);

    //RUN_TEST(testDistanceKTest0);
    return UNITY_END();
}