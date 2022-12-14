//
// Created by l30014168 on 2022/1/30.
//

#include <unity.h>
#include "util.h"
#include "remove-linked-list-elements.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void removeElementsTestExample1(void) {
    int nums[] = {1, 2, 6, 3, 4, 5, 6};
    struct ListNode *head = LinkedListCreateByNums(nums, ARRAY_LENGTH(nums));
    int val = 6;
    struct ListNode *ans = removeElements(head, val);
    int correctNums[] = {1, 2, 3, 4, 5};
    struct ListNode *correctAns = LinkedListCreateByNums(correctNums, ARRAY_LENGTH(correctNums));
    TEST_ASSERT_TRUE(LinkedListIsEqual(ans, correctAns));
    LinkedListDestroy(ans);
    LinkedListDestroy(correctAns);
}

void removeElementsTestExample2(void) {
    struct ListNode *head = NULL;
    int val = 1;
    struct ListNode *ans = removeElements(head, val);
    struct ListNode *correctAns = NULL;
    TEST_ASSERT_TRUE(LinkedListIsEqual(ans, correctAns));
    LinkedListDestroy(ans);
    LinkedListDestroy(correctAns);
}

void removeElementsTestExample3(void) {
    int nums[] = {7, 7, 7, 7};
    struct ListNode *head = LinkedListCreateByNums(nums, ARRAY_LENGTH(nums));
    int val = 7;
    struct ListNode *ans = removeElements(head, val);
    struct ListNode *correctAns = NULL;
    TEST_ASSERT_TRUE(LinkedListIsEqual(ans, correctAns));
    LinkedListDestroy(ans);
    LinkedListDestroy(correctAns);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(removeElementsTestExample1);
    RUN_TEST(removeElementsTestExample2);
    RUN_TEST(removeElementsTestExample3);
    return UNITY_END();
}