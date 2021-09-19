//
// Created by l30014168 on 2021/8/16.
//

#include <unity.h>
#include <stdlib.h>
#include "Vector.h"
#include "util.h"
#include "TreeNode.h"
#include "ListNode.h"


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


void VectorIntTest(void) {
    int data[] = {8, 6, 4, 7, 2, 9, 3, 5, 0, 1};
    Vector *vector = VectorCreate(sizeof(int));
    TEST_ASSERT_EQUAL_INT(0, vector->size);
    for (int idx = 0; idx < sizeof(data) / sizeof(int); idx++) {
        errno_t err = VectorAppend(vector, &data[idx]);
        TEST_ASSERT_EQUAL(NO_ERROR, err);
    }
    /* 获取vector大小，期望为10 */
    TEST_ASSERT_EQUAL_INT(10, vector->size);
    /* 获取索引为3的数据，期望为7 */
    TEST_ASSERT_EQUAL_INT(7, *(int *) VectorAt(vector, 3));

    /* 排序后期望为0 1 2 3 4 5 6 7 8 9 */
    VectorSort(vector, intAscCmpFunc);
    for (int idx = 0; idx < sizeof(data) / sizeof(int); idx++) {
        TEST_ASSERT_EQUAL_INT(idx, *(int *) VectorAt(vector, idx));
    }

    // 删除 索引值从 3 开始，长度为4的元素。期望为0 1 2 7 8 9
    VectorErase(vector, 3, 3 + 4);

    /* 获取vector大小，期望为6 */
    TEST_ASSERT_EQUAL_INT(6, vector->size);

    /* 获取索引为2的数据，期望为2 */
    TEST_ASSERT_EQUAL_INT(2, *(int *) VectorAt(vector, 2));

    /* 获取索引为3的数据，期望为7 */
    TEST_ASSERT_EQUAL_INT(7, *(int *) VectorAt(vector, 3));

    // 清空元素
    VectorClear(vector);
    TEST_ASSERT_TRUE(VectorIsEmpty(vector));


    VectorDestroy(vector);

}


void TreeCreateByNumsAndTreeDestroyTest(void) {
    struct TreeNode *rootCorrect;
    rootCorrect = calloc(1, sizeof(struct TreeNode));
    rootCorrect->val = 3;
    rootCorrect->left = calloc(1, sizeof(struct TreeNode));
    rootCorrect->left->val = 5;
    rootCorrect->right = calloc(1, sizeof(struct TreeNode));
    rootCorrect->right->val = 1;

    rootCorrect->left->left = calloc(1, sizeof(struct TreeNode));
    rootCorrect->left->left->val = 6;
    rootCorrect->left->right = calloc(1, sizeof(struct TreeNode));
    rootCorrect->left->right->val = 2;

    rootCorrect->right->left = calloc(1, sizeof(struct TreeNode));
    rootCorrect->right->left->val = 0;
    rootCorrect->right->right = calloc(1, sizeof(struct TreeNode));
    rootCorrect->right->right->val = 8;

    rootCorrect->left->right->left = calloc(1, sizeof(struct TreeNode));
    rootCorrect->left->right->left->val = 7;
    rootCorrect->left->right->right = calloc(1, sizeof(struct TreeNode));
    rootCorrect->left->right->right->val = 4;

    int nums[] = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    struct TreeNode *root = TreeCreateByNums(nums, sizeof(nums) / sizeof(int), -1);
    TEST_ASSERT_TRUE(isSameTree(rootCorrect, root));
    TreeDestroy(rootCorrect);
    TreeDestroy(root);

}

void ListCreateByNumsAndListDestroyTest(void) {
    int nums[] = {1, 4, 2, 6, 8, 0, -1};
    struct ListNode *head = ListCreateByNums(nums, sizeof(nums) / sizeof(int));
    struct ListNode *node = head;
    for (size_t idx = 0; idx < sizeof(nums) / sizeof(int); idx++) {
        TEST_ASSERT_EQUAL_INT(nums[idx], node->val);
        node = node->next;
    }
    ListDestroy(head);
}

void fastPowTest(void) {
    int a = 1, b = 0;
    TEST_ASSERT_EQUAL(1, fastPow(a, b));
    a = 1, b = 1;
    TEST_ASSERT_EQUAL(1, fastPow(a, b));
    a = -1, b = 1;
    TEST_ASSERT_EQUAL(-1, fastPow(a, b));
    a = -2, b = 0;
    TEST_ASSERT_EQUAL(1, fastPow(a, b));
    a = -2, b = 1;
    TEST_ASSERT_EQUAL(-2, fastPow(a, b));
    a = 2, b = 10;
    TEST_ASSERT_EQUAL(1024, fastPow(a, b));
    a = -2, b = 10;
    TEST_ASSERT_EQUAL(1024, fastPow(a, b));
    a = -2, b = 11;
    TEST_ASSERT_EQUAL(-2048, fastPow(a, b));
}

void gcdAndLcmTest(void) {
    int m = 6, n = 8;
    TEST_ASSERT_EQUAL(2, gcd(m, n));
    TEST_ASSERT_EQUAL(24, lcm(m, n));
    m = -6, n = 8;
    TEST_ASSERT_EQUAL(2, gcd(m, n));
    m = -6, n = -8;
    TEST_ASSERT_EQUAL(2, gcd(m, n));
    m = 1, n = -8;
    TEST_ASSERT_EQUAL(1, gcd(m, n));
    TEST_ASSERT_EQUAL(8, lcm(m, n));
    m = 0, n = 1024;
    TEST_ASSERT_EQUAL(1024, gcd(m, n));
    TEST_ASSERT_EQUAL(0, lcm(m, n));
    m = 1024, n = 0;
    TEST_ASSERT_EQUAL(1024, gcd(m, n));
    TEST_ASSERT_EQUAL(0, lcm(m, n));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(VectorIntTest);
    RUN_TEST(TreeCreateByNumsAndTreeDestroyTest);
    RUN_TEST(ListCreateByNumsAndListDestroyTest);
    RUN_TEST(fastPowTest);
    RUN_TEST(gcdAndLcmTest);
    return UNITY_END();
}