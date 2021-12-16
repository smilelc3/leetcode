//
// Created by smile on 2021/12/16.
//

#include <stdlib.h>
#include <unity.h>
#include "longest-nice-substring.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void longestNiceSubstringTestExample1(void) {
    char *s = "YazaAay";
    char *ans = longestNiceSubstring(s);
    char *correctAns = "aAa";
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void longestNiceSubstringTestExample2(void) {
    char *s = "Bb";
    char *ans = longestNiceSubstring(s);
    char *correctAns = "Bb";
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void longestNiceSubstringTestExample3(void) {
    char *s = "c";
    char *ans = longestNiceSubstring(s);
    char *correctAns = "";
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void longestNiceSubstringTestExample4(void) {
    char *s = "dDzeE";
    char *ans = longestNiceSubstring(s);
    char *correctAns = "dD";
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void longestNiceSubstringTestTest0(void) {
    char *s = "cChH";
    char *ans = longestNiceSubstring(s);
    char *correctAns = "cChH";
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void longestNiceSubstringTestTest1(void) {
    char *s = "HkhBubUYy";
    char *ans = longestNiceSubstring(s);
    char *correctAns = "BubUYy";
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(longestNiceSubstringTestExample1);
    RUN_TEST(longestNiceSubstringTestExample2);
    RUN_TEST(longestNiceSubstringTestExample3);
    RUN_TEST(longestNiceSubstringTestExample4);
    RUN_TEST(longestNiceSubstringTestTest0);
    RUN_TEST(longestNiceSubstringTestTest1);
    return UNITY_END();
}