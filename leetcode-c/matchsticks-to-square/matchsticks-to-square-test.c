//
// Created by smile on 2021/12/16.
//

#include <unity.h>
#include "util.h"
#include "matchsticks-to-square.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void makesquareTestExample1(void) {
    int matchsticks[] = {1, 1, 2, 2, 2};
    TEST_ASSERT_TRUE(makesquare(matchsticks, ARRAY_LENGTH(matchsticks)));
}

void makesquareTestExample2(void) {
    int matchsticks[] = {3, 3, 3, 3, 4};
    TEST_ASSERT_FALSE(makesquare(matchsticks, ARRAY_LENGTH(matchsticks)));
}

void makesquareTestTest0(void) {
    int matchsticks[] = {5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3};
    TEST_ASSERT_TRUE(makesquare(matchsticks, ARRAY_LENGTH(matchsticks)));
}

void makesquareTestTest1(void) {
    int matchsticks[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8};
    TEST_ASSERT_TRUE(makesquare(matchsticks, ARRAY_LENGTH(matchsticks)));
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(makesquareTestExample1);
    RUN_TEST(makesquareTestExample2);
    RUN_TEST(makesquareTestTest0);
    RUN_TEST(makesquareTestTest1);
    return UNITY_END();
}