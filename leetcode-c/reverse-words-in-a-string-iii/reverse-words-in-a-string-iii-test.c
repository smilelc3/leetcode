//
// Created by smile on 2022/12/10.
//


#include <unity.h>
#include "reverse-words-in-a-string-iii.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void reverseWordsTestExample1(void) {
    char s[] = "Let's take LeetCode contest";
    char *ans = reverseWords(s);
    char correctAns[] = "s'teL ekat edoCteeL tsetnoc";
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void reverseWordsTestExample2(void) {
    char s[] = "God Ding";
    char *ans = reverseWords(s);
    char correctAns[] = "doG gniD";
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void reverseWordsTestMyTest0(void) {
    char s[] = "Let's    take LeetCode  contest";
    char *ans = reverseWords(s);
    char correctAns[] = "s'teL    ekat edoCteeL  tsetnoc";
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(reverseWordsTestExample1);
    RUN_TEST(reverseWordsTestExample2);
    RUN_TEST(reverseWordsTestMyTest0);
    return UNITY_END();
}