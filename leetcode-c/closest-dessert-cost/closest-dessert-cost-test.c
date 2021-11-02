//
// Created by l30014168 on 2021/11/1.
//

#include <unity.h>
#include <stdlib.h>
#include "closest-dessert-cost.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void closestCostTestExample1(void) {
    int baseCosts[] = {1, 7}, toppingCosts[] = {3, 4};
    int target = 10;
    int ans = closestCost(baseCosts, sizeof(baseCosts) / sizeof(int),
                          toppingCosts, sizeof(toppingCosts) / sizeof(int),
                          target);
    int correctAns = 10;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void closestCostTestExample2(void) {
    int baseCosts[] = {2, 3}, toppingCosts[] = {4, 5, 100};
    int target = 18;
    int ans = closestCost(baseCosts, sizeof(baseCosts) / sizeof(int),
                          toppingCosts, sizeof(toppingCosts) / sizeof(int),
                          target);
    int correctAns = 17;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void closestCostTestExample3(void) {
    int baseCosts[] = {3, 10}, toppingCosts[] = {2, 5};
    int target = 9;
    int ans = closestCost(baseCosts, sizeof(baseCosts) / sizeof(int),
                          toppingCosts, sizeof(toppingCosts) / sizeof(int),
                          target);
    int correctAns = 8;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void closestCostTestTest0(void) {
    int baseCosts[] = {8, 4, 4, 5, 8}, toppingCosts[] = {3, 10, 9, 10, 8, 10, 10, 9, 3};
    int target = 6;
    int ans = closestCost(baseCosts, sizeof(baseCosts) / sizeof(int),
                          toppingCosts, sizeof(toppingCosts) / sizeof(int),
                          target);
    int correctAns = 5;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(closestCostTestExample1);
    RUN_TEST(closestCostTestExample2);
    RUN_TEST(closestCostTestExample3);
    RUN_TEST(closestCostTestTest0);
    return UNITY_END();
}