//
// Created by l30014168 on 2021/7/13.
//

#include <unity.h>
#include "number-of-segments-in-a-string.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void countSegmentsTestExample1(void) {
    char *s = "Hello, my name is John";
    int ans = countSegments(s);
    int rightAns = 5;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void countSegmentsTestExample2(void) {
    char *s = "Hello";
    int ans = countSegments(s);
    int rightAns = 1;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void countSegmentsTestExample3(void) {
    char *s = "love live! mu'sic forever";
    int ans = countSegments(s);
    int rightAns = 4;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void countSegmentsTestExample4(void) {
    char *s = "";
    int ans = countSegments(s);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void countSegmentsTestTest0(void) {
    char *s = "                ";
    int ans = countSegments(s);
    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(countSegmentsTestExample1);
    RUN_TEST(countSegmentsTestExample2);
    RUN_TEST(countSegmentsTestExample3);
    RUN_TEST(countSegmentsTestExample4);
    RUN_TEST(countSegmentsTestTest0);
    return UNITY_END();
}