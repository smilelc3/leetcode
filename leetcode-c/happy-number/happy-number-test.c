//
// Created by l30014168 on 2022/1/29.
//

#include <unity.h>
#include "happy-number.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void isHappyTestExample1(void) {
    TEST_ASSERT_TRUE(isHappy(19));
}

void isHappyTestExample2(void) {
    TEST_ASSERT_FALSE(isHappy(2));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(isHappyTestExample1);
    RUN_TEST(isHappyTestExample2);
    return UNITY_END();
}