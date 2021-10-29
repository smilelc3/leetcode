//
// Created by smile on 2021/10/29.
//

#include <unity.h>
#include "reordered-power-of-2.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void reorderedPowerOf2TestExample1(void) {
    int n = 1;
    TEST_ASSERT_TRUE(reorderedPowerOf2(n));
}

void reorderedPowerOf2TestExample2(void) {
    int n = 10;
    TEST_ASSERT_FALSE(reorderedPowerOf2(n));
}

void reorderedPowerOf2TestExample3(void) {
    int n = 16;
    TEST_ASSERT_TRUE(reorderedPowerOf2(n));
}

void reorderedPowerOf2TestExample4(void) {
    int n = 24;
    TEST_ASSERT_FALSE(reorderedPowerOf2(n));
}

void reorderedPowerOf2TestExample5(void) {
    int n = 46;
    TEST_ASSERT_TRUE(reorderedPowerOf2(n));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(reorderedPowerOf2TestExample1);
    RUN_TEST(reorderedPowerOf2TestExample2);
    RUN_TEST(reorderedPowerOf2TestExample3);
    RUN_TEST(reorderedPowerOf2TestExample4);
    RUN_TEST(reorderedPowerOf2TestExample5);
    return UNITY_END();
}