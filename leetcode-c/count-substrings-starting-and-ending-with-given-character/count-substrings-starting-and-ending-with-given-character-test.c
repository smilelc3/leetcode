//
// Created by smile on 2024/8/13.
//


#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "count-substrings-starting-and-ending-with-given-character.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void countSubstringsTestExample1(void) {
    char *s = "abada";
    char c = 'a';
    long long ans = countSubstrings(s, c);
    long long correctAns = 6;
    TEST_ASSERT_EQUAL_INT64(ans, correctAns);
}

void countSubstringsTestExample2(void) {
    char *s = "zzz";
    char c = 'z';
    long long ans = countSubstrings(s, c);
    long long correctAns = 6;
    TEST_ASSERT_EQUAL_INT64(ans, correctAns);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(countSubstringsTestExample1);
    RUN_TEST(countSubstringsTestExample2);
    return UNITY_END();
}