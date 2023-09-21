//
// Created by smile on 2023/9/19.
//

#include <unity.h>
#include "backspace-string-compare.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void backspaceCompareTestExample1(void) {
    char s[] = "ab#c", t[] = "ad#c";
    TEST_ASSERT_TRUE(backspaceCompare(s, t));
}

void backspaceCompareTestExample2(void) {
    char s[] = "ab##", t[] = "c#d#";
    TEST_ASSERT_TRUE(backspaceCompare(s, t));
}

void backspaceCompareTestExample3(void) {
    char s[] = "a#c", t[] = "b";
    TEST_ASSERT_FALSE(backspaceCompare(s, t));
}

void backspaceCompareTestTest0(void) {
    char s[] = "a##c", t[] = "#a#c";
    TEST_ASSERT_TRUE(backspaceCompare(s, t));
}

void backspaceCompareTestTest1(void) {
    char s[] = "xywrrmp", t[] = "xywrrmu#p";
    TEST_ASSERT_TRUE(backspaceCompare(s, t));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(backspaceCompareTestExample1);
    RUN_TEST(backspaceCompareTestExample2);
    RUN_TEST(backspaceCompareTestExample3);
    RUN_TEST(backspaceCompareTestTest0);
    RUN_TEST(backspaceCompareTestTest1);
    return UNITY_END();
}