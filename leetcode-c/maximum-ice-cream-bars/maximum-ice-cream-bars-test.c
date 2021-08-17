//
// Created by l30014168 on 2021/7/26.
//


#include <unity.h>
#include <stdlib.h>
#include "maximum-ice-cream-bars.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testMaxIceCreamExample1(void) {
    int costs[] = {1, 3, 2, 4, 1};
    int costsSize = sizeof(costs) / sizeof(int);
    int coins = 7;
    int ans = maxIceCream(costs, costsSize, coins);
    int rightAns = 4;
    TEST_ASSERT_EQUAL_INT(ans, rightAns);
}

void testMaxIceCreamExample2(void) {
    int costs[] = {10, 6, 8, 7, 7, 8};
    int costsSize = sizeof(costs) / sizeof(int);
    int coins = 5;
    int ans = maxIceCream(costs, costsSize, coins);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(ans, rightAns);
}

void testMaxIceCreamExample3(void) {
    int costs[] = {1, 6, 3, 1, 2, 5};
    int costsSize = sizeof(costs) / sizeof(int);
    int coins = 20;
    int ans = maxIceCream(costs, costsSize, coins);
    int rightAns = 6;
    TEST_ASSERT_EQUAL_INT(ans, rightAns);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testMaxIceCreamExample1);
    RUN_TEST(testMaxIceCreamExample2);
    RUN_TEST(testMaxIceCreamExample3);
    return UNITY_END();
}