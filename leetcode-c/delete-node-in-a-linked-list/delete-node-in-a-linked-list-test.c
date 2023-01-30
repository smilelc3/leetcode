//
// Created by smile on 2023/1/30.
//

#include <unity.h>
#include "util.h"
#include "delete-node-in-a-linked-list.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void deleteNodeExample1(void) {
    int nums[] = {4, 5, 1, 9};
    struct ListNode *head = LinkedListCreateByNums(nums, ARRAY_LENGTH(nums));
    struct ListNode *node = head->next;
    deleteNode(node);
    int correctNums[] = {4, 1, 9};
    struct ListNode *correctHead = LinkedListCreateByNums(correctNums, ARRAY_LENGTH(correctNums));
    TEST_ASSERT_TRUE(LinkedListIsEqual(head, correctHead));
    LinkedListDestroy(head);
    LinkedListDestroy(correctHead);
}

void deleteNodeExample2(void) {
    int nums[] = {4, 5, 1, 9};
    struct ListNode *head = LinkedListCreateByNums(nums, ARRAY_LENGTH(nums));
    struct ListNode *node = head->next->next;
    deleteNode(node);
    int correctNums[] = {4, 5, 9};
    struct ListNode *correctHead = LinkedListCreateByNums(correctNums, ARRAY_LENGTH(correctNums));
    TEST_ASSERT_TRUE(LinkedListIsEqual(head, correctHead));
    LinkedListDestroy(head);
    LinkedListDestroy(correctHead);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(deleteNodeExample1);
    RUN_TEST(deleteNodeExample2);
    return UNITY_END();
}