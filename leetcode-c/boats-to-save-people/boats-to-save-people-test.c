//
// Created by l30014168 on 2021/8/28.
//

#include <stdlib.h>
#include <unity.h>
#include "boats-to-save-people.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void numRescueBoatsTestExample1(void) {
    int people[] = {1, 2};
    int limit = 3;
    int ans = numRescueBoats(people, sizeof(people) / sizeof(int), limit);
    int ansCorrect = 1;
    TEST_ASSERT_EQUAL_INT(ansCorrect, ans);
}

void numRescueBoatsTestExample2(void) {
    int people[] = {3, 2, 2, 1};
    int limit = 3;
    int ans = numRescueBoats(people, sizeof(people) / sizeof(int), limit);
    int ansCorrect = 3;
    TEST_ASSERT_EQUAL_INT(ansCorrect, ans);
}

void numRescueBoatsTestExample3(void) {
    int people[] = {3, 5, 3, 4};
    int limit = 5;
    int ans = numRescueBoats(people, sizeof(people) / sizeof(int), limit);
    int ansCorrect = 4;
    TEST_ASSERT_EQUAL_INT(ansCorrect, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(numRescueBoatsTestExample1);
    RUN_TEST(numRescueBoatsTestExample2);
    RUN_TEST(numRescueBoatsTestExample3);
    return UNITY_END();
}