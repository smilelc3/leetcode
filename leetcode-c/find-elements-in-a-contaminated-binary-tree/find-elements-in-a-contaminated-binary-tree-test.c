//
// Created by smile on 2021/12/2.
//

#include <limits.h>
#include <unity.h>
#include "TreeNode.h"
#include "util.h"
#include "find-elements-in-a-contaminated-binary-tree.c"

#define null INT_MAX

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void FindElementsExample1(void) {
    int nums[] = {-1, null, -1};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    FindElements *obj = findElementsCreate(root);
    TEST_ASSERT_FALSE(findElementsFind(obj, 1));
    TEST_ASSERT_TRUE(findElementsFind(obj, 2));
    findElementsFree(obj);
    TreeDestroy(root);
}

void FindElementsExample2(void) {
    int nums[] = {-1, -1, -1, -1, -1};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    FindElements *obj = findElementsCreate(root);
    TEST_ASSERT_TRUE(findElementsFind(obj, 1));
    TEST_ASSERT_TRUE(findElementsFind(obj, 3));
    TEST_ASSERT_FALSE(findElementsFind(obj, 5));
    findElementsFree(obj);
    TreeDestroy(root);
}

void FindElementsExample3(void) {
    int nums[] = {-1, null, -1, -1, null, -1};
    struct TreeNode *root = TreeCreateByNums(nums, ARRAY_LENGTH(nums), null);
    FindElements *obj = findElementsCreate(root);
    TEST_ASSERT_TRUE(findElementsFind(obj, 2));
    TEST_ASSERT_FALSE(findElementsFind(obj, 3));
    TEST_ASSERT_FALSE(findElementsFind(obj, 4));
    TEST_ASSERT_TRUE(findElementsFind(obj, 5));
    findElementsFree(obj);
    TreeDestroy(root);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(FindElementsExample1);
    RUN_TEST(FindElementsExample2);
    RUN_TEST(FindElementsExample3);
    return UNITY_END();
}