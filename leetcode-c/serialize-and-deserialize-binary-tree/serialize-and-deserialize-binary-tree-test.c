//
// Created by smile on 2021/8/22.
//

#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unity.h>
#include "TreeNode.h"
#include "util.h"
#include "serialize-and-deserialize-binary-tree.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void serializeAndDeserializeTestExample1(void) {
    int nums[] = {1, 2, 3, INT_MIN, INT_MIN, 4, 5};
    struct TreeNode *rootCorrect = BinaryTreeCreateByNums(nums, ARRAY_LENGTH(nums), INT_MIN);
    char *ser = serialize(rootCorrect);
    char *serRight = "[1,2,3,null,null,4,5]";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(serRight, ser, strlen(serRight));

    struct TreeNode *root = deserialize(serRight);
    TEST_ASSERT_TRUE(BinaryTreeIsEqual(rootCorrect, root));

    BinaryTreeDestroy(rootCorrect);
    BinaryTreeDestroy(root);
    free(ser);
}

void serializeAndDeserializeTestExample2(void) {
    int* nums = NULL;
    struct TreeNode *rootCorrect = BinaryTreeCreateByNums(nums, 0, INT_MIN);
    char *ser = serialize(rootCorrect);
    char *serRight = "[]";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(serRight, ser, strlen(serRight));

    struct TreeNode *root = deserialize(serRight);
    TEST_ASSERT_TRUE(BinaryTreeIsEqual(rootCorrect, root));

    BinaryTreeDestroy(rootCorrect);
    BinaryTreeDestroy(root);
    free(ser);
}

void serializeAndDeserializeTestExample3(void) {
    int nums[] = {1};
    struct TreeNode *rootCorrect = BinaryTreeCreateByNums(nums, ARRAY_LENGTH(nums), INT_MIN);
    char *ser = serialize(rootCorrect);
    char *serRight = "[1]";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(serRight, ser, strlen(serRight));

    struct TreeNode *root = deserialize(serRight);
    TEST_ASSERT_TRUE(BinaryTreeIsEqual(rootCorrect, root));

    BinaryTreeDestroy(rootCorrect);
    BinaryTreeDestroy(root);
    free(ser);
}

void serializeAndDeserializeTestExample4(void) {
    int nums[] = {1, 2};
    struct TreeNode *rootCorrect = BinaryTreeCreateByNums(nums, ARRAY_LENGTH(nums), INT_MIN);
    char *ser = serialize(rootCorrect);
    char *serRight = "[1,2]";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(serRight, ser, strlen(serRight));

    struct TreeNode *root = deserialize(serRight);
    TEST_ASSERT_TRUE(BinaryTreeIsEqual(rootCorrect, root));

    BinaryTreeDestroy(rootCorrect);
    BinaryTreeDestroy(root);
    free(ser);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(serializeAndDeserializeTestExample1);
    RUN_TEST(serializeAndDeserializeTestExample2);
    RUN_TEST(serializeAndDeserializeTestExample3);
    RUN_TEST(serializeAndDeserializeTestExample4);
    return UNITY_END();
}
