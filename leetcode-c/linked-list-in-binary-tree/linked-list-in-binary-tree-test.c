//
// Created by l30014168 on 2021/9/8.
//

//
// Created by l30014168 on 2021/7/26.
//


#include <unity.h>
#include <stdlib.h>
#include <limits.h>
#include "linked-list-in-binary-tree.c"


#define null INT_MIN

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void isSubPathExample1(void) {
    int listNums[] = {4, 2, 8};
    struct ListNode *head = ListCreateByNums(listNums, sizeof(listNums) / sizeof(int));
    int treeNums[] = {1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3};
    struct TreeNode *root = TreeCreateByNums(treeNums, sizeof(treeNums) / sizeof(int), null);
    TEST_ASSERT_TRUE(isSubPath(head, root));
    ListDestroy(head);
    TreeDestroy(root);
}

void isSubPathExample2(void) {
    int listNums[] = {1, 4, 2, 6};
    struct ListNode *head = ListCreateByNums(listNums, sizeof(listNums) / sizeof(int));
    int treeNums[] = {1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3};
    struct TreeNode *root = TreeCreateByNums(treeNums, sizeof(treeNums) / sizeof(int), null);
    TEST_ASSERT_TRUE(isSubPath(head, root));
    ListDestroy(head);
    TreeDestroy(root);
}

void isSubPathExample3(void) {
    int listNums[] = {1, 4, 2, 6, 8};
    struct ListNode *head = ListCreateByNums(listNums, sizeof(listNums) / sizeof(int));
    int treeNums[] = {1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3};
    struct TreeNode *root = TreeCreateByNums(treeNums, sizeof(treeNums) / sizeof(int), null);
    TEST_ASSERT_FALSE(isSubPath(head, root));
    ListDestroy(head);
    TreeDestroy(root);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(isSubPathExample1);
    RUN_TEST(isSubPathExample2);
    RUN_TEST(isSubPathExample3);
    return UNITY_END();
}