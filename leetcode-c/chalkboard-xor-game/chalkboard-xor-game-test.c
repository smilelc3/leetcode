//
// Created by smile on 2021/11/10.
//

#include <unity.h>
#include "chalkboard-xor-game.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void xorGameTestExample1(void) {
    int nums[] = {1, 1, 2};
    bool ans = xorGame(nums, sizeof(nums) / sizeof(int));
    bool correctAns = false;
    TEST_ASSERT_EQUAL(correctAns, ans);
}

void xorGameTestExample2(void) {
    int nums[] = {0, 1};        // Alice 先移除0，等Bob移除1后，没有剩余，Alice胜利
    bool ans = xorGame(nums, sizeof(nums) / sizeof(int));
    bool correctAns = true;
    TEST_ASSERT_EQUAL(correctAns, ans);
}

void xorGameTestExample3(void) {
    int nums[] = {1, 2, 3};     // Alice先手，此时所有数字xor为0，赢
    bool ans = xorGame(nums, sizeof(nums) / sizeof(int));
    bool correctAns = true;
    TEST_ASSERT_EQUAL(correctAns, ans);
}

void xorGameTestTest0(void) {
    int nums[] = {1, 1, 2, 3};     // Alice先手，
    bool ans = xorGame(nums, sizeof(nums) / sizeof(int));
    bool correctAns = true;
    TEST_ASSERT_EQUAL(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(xorGameTestExample1);
    RUN_TEST(xorGameTestExample2);
    RUN_TEST(xorGameTestExample3);
    RUN_TEST(xorGameTestTest0);
    return UNITY_END();
}