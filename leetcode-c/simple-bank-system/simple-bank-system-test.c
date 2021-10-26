//
// Created by l30014168 on 2021/10/26.
//

#include <unity.h>
#include "simple-bank-system.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void BankTestExample1(void) {
    long long nums[] = {10, 100, 20, 50, 30};
    Bank *obj = bankCreate(nums, (int) sizeof(nums) / sizeof(long long));
    TEST_ASSERT_TRUE(bankWithdraw(obj, 3, 10));
    TEST_ASSERT_TRUE(bankTransfer(obj, 5, 1, 10));
    TEST_ASSERT_TRUE(bankDeposit(obj, 5, 20));
    TEST_ASSERT_FALSE(bankTransfer(obj, 3, 4, 15));
    TEST_ASSERT_FALSE(bankWithdraw(obj, 10, 50));
    bankFree(obj);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(BankTestExample1);
    return UNITY_END();
}