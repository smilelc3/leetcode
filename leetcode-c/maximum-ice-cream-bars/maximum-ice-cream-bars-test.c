//
// Created by l30014168 on 2021/7/26.
//

#include <unity.h>
#include "util.h"
#include "maximum-ice-cream-bars.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void maxIceCreamTestExample1(void) {
    int costs[] = {1, 3, 2, 4, 1};
    int costsSize = ARRAY_LENGTH(costs);
    int coins = 7;
    int ans = maxIceCream(costs, costsSize, coins);
    int rightAns = 4;
    TEST_ASSERT_EQUAL_INT(ans, rightAns);
}

void maxIceCreamTestExample2(void) {
    int costs[] = {10, 6, 8, 7, 7, 8};
    int costsSize = ARRAY_LENGTH(costs);
    int coins = 5;
    int ans = maxIceCream(costs, costsSize, coins);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(ans, rightAns);
}

void maxIceCreamTestExample3(void) {
    int costs[] = {1, 6, 3, 1, 2, 5};
    int costsSize = ARRAY_LENGTH(costs);
    int coins = 20;
    int ans = maxIceCream(costs, costsSize, coins);
    int rightAns = 6;
    TEST_ASSERT_EQUAL_INT(ans, rightAns);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(maxIceCreamTestExample1);
    RUN_TEST(maxIceCreamTestExample2);
    RUN_TEST(maxIceCreamTestExample3);
    return UNITY_END();
}