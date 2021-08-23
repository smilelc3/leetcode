//
// Created by smile on 2021/8/22.
//

#include <string.h>
#include <unity.h>
#include <stdlib.h>
#include "TreeNode.h"
#include "serialize-and-deserialize-binary-tree.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testSerializeAndDeserializeExample1(void) {
    int nums[] = {1, 2, 3, -1, -1, 4, 5};
    struct TreeNode *rootCorrect = TreeCreateByNums(nums, sizeof(nums) / sizeof(int), -1);
    char *ser = serialize(rootCorrect);
    char *serRight = "[1,2,3,null,null,4,5]";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(serRight, ser, strlen(serRight));

    struct TreeNode *root = deserialize(serRight);
    TEST_ASSERT_TRUE(isSameTree(rootCorrect, root));

    TreeDestroy(rootCorrect);
    TreeDestroy(root);
    free(ser);
}

void testSerializeAndDeserializeExample2(void) {
    int nums[] = {};
    struct TreeNode *rootCorrect = TreeCreateByNums(nums, sizeof(nums) / sizeof(int), -1);
    char *ser = serialize(rootCorrect);
    char *serRight = "[]";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(serRight, ser, strlen(serRight));

    struct TreeNode *root = deserialize(serRight);
    TEST_ASSERT_TRUE(isSameTree(rootCorrect, root));

    TreeDestroy(rootCorrect);
    TreeDestroy(root);
    free(ser);
}

void testSerializeAndDeserializeExample3(void) {
    int nums[] = {1};
    struct TreeNode *rootCorrect = TreeCreateByNums(nums, sizeof(nums) / sizeof(int), -1);
    char *ser = serialize(rootCorrect);
    char *serRight = "[1]";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(serRight, ser, strlen(serRight));

    struct TreeNode *root = deserialize(serRight);
    TEST_ASSERT_TRUE(isSameTree(rootCorrect, root));

    TreeDestroy(rootCorrect);
    TreeDestroy(root);
    free(ser);
}

void testSerializeAndDeserializeExample4(void) {
    int nums[] = {1, 2};
    struct TreeNode *rootCorrect = TreeCreateByNums(nums, sizeof(nums) / sizeof(int), -1);
    char *ser = serialize(rootCorrect);
    char *serRight = "[1,2]";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(serRight, ser, strlen(serRight));

    struct TreeNode *root = deserialize(serRight);
    TEST_ASSERT_TRUE(isSameTree(rootCorrect, root));

    TreeDestroy(rootCorrect);
    TreeDestroy(root);
    free(ser);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testSerializeAndDeserializeExample1);
    RUN_TEST(testSerializeAndDeserializeExample2);
    RUN_TEST(testSerializeAndDeserializeExample3);
    RUN_TEST(testSerializeAndDeserializeExample4);
    return UNITY_END();
}