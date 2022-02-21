//
// Created by smile on 2022/2/21.
//

#include <unity.h>
#include "nim-game.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void canWinNimTestExample1(void) {
    TEST_ASSERT_FALSE(canWinNim(4));
}

void canWinNimTestExample2(void) {
    TEST_ASSERT_TRUE(canWinNim(2));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(canWinNimTestExample1);
    RUN_TEST(canWinNimTestExample2);
    return UNITY_END();
}