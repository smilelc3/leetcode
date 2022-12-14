//
// Created by smile on 2021/9/28.
//

#include <limits.h>
#include <unity.h>
#include "TreeNode.h"
#include "util.h"
#include "path-sum-iii.c"

#define null INT_MAX

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void pathSumTestExample1(void) {
    int nums[] = {10, 5, -3, 3, 2, null, 11, 3, -2, null, 1};
    struct TreeNode *root = BinaryTreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    int targetSum = 8;
    int ans = pathSum(root, targetSum);
    int correctAns = 3;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    BinaryTreeDestroy(root);
}

void pathSumTestExample2(void) {
    int nums[] = {5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1};
    struct TreeNode *root = BinaryTreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    int targetSum = 22;
    int ans = pathSum(root, targetSum);
    int correctAns = 3;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    BinaryTreeDestroy(root);
}

void pathSumTestTest0(void) {
    int nums[] = {0, 1, 1};
    struct TreeNode *root = BinaryTreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    int targetSum = 1;
    int ans = pathSum(root, targetSum);
    int correctAns = 4;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
    BinaryTreeDestroy(root);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(pathSumTestExample1);
    RUN_TEST(pathSumTestExample2);
    RUN_TEST(pathSumTestTest0);
    return UNITY_END();
}