//
// Created by smile on 2021/9/20.
//

#include <unity.h>
#include "palindrome-linked-list.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void isPalindromeTestExample1(void) {
    int nums[] = {1, 2, 2, 1};
    struct ListNode *head = ListCreateByNums(nums, sizeof(nums) / sizeof(int));
    TEST_ASSERT_TRUE(isPalindrome(head));
    ListDestroy(head);
}

void isPalindromeTestExample2(void) {
    int nums[] = {1, 2};
    struct ListNode *head = ListCreateByNums(nums, sizeof(nums) / sizeof(int));
    TEST_ASSERT_FALSE(isPalindrome(head));
    ListDestroy(head);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(isPalindromeTestExample1);
    RUN_TEST(isPalindromeTestExample2);
    return UNITY_END();
}