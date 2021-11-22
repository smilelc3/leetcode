//
// Created by l30014168 on 2021/9/22.
//

#include <unity.h>
#include "water-and-jug-problem.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void canMeasureWaterTestExample1(void) {
    int jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4;
    TEST_ASSERT_TRUE(canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity));
}

void canMeasureWaterTestExample2(void) {
    int jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5;
    TEST_ASSERT_FALSE(canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity));
}

void canMeasureWaterTestExample3(void) {
    int jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3;
    TEST_ASSERT_TRUE(canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity));
}

void canMeasureWaterTestTest0(void) {
    int jug1Capacity = 1, jug2Capacity = 1, targetCapacity = 12;
    TEST_ASSERT_FALSE(canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(canMeasureWaterTestExample1);
    RUN_TEST(canMeasureWaterTestExample2);
    RUN_TEST(canMeasureWaterTestExample3);
    RUN_TEST(canMeasureWaterTestTest0);
    return UNITY_END();
}