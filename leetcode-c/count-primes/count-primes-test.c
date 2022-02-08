//
// Created by l30014168 on 2022/1/30.
//

#include <unity.h>
#include <stdlib.h>
#include "util.h"
#include "count-primes.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void countPrimesTestExample1(void) {
    int n = 10;
    int ans = countPrimes(n);
    int correctAns = 4;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void countPrimesTestExample2(void) {
    int n = 0;
    int ans = countPrimes(n);
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void countPrimesTestExample3(void) {
    int n = 1;
    int ans = countPrimes(n);
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void countPrimesTestTest0(void) {
    int n = 106543;
    int ans = countPrimes(n);
    int correctAns = 10155;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void countPrimesTestTest1(void) {
    int n = 117153;
    int ans = countPrimes(n);
    int correctAns = 11057;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void countPrimesTestTest2(void) {
    int n = 10;
    int ans = countPrimes(n);
    int correctAns = 4;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void countPrimesTestTest3(void) {
    int n = 2;
    int ans = countPrimes(n);
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(countPrimesTestExample1);
    RUN_TEST(countPrimesTestExample2);
    RUN_TEST(countPrimesTestExample3);
    RUN_TEST(countPrimesTestTest0);
    RUN_TEST(countPrimesTestTest1);
    RUN_TEST(countPrimesTestTest2);
    RUN_TEST(countPrimesTestTest3);
    return UNITY_END();
}