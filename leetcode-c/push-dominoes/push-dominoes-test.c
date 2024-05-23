//
// Created by smile on 24-5-22.
//

#include <unity.h>
#include "push-dominoes.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void pushDominoesTestExample1(void) {
    char *dominoes = "RR.L";
    char *correctAns = "RR.L";
    char *ans = pushDominoes(dominoes);
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

void pushDominoesTestExample2(void) {
    char *dominoes = ".L.R...LR..L..";
    char *correctAns = "LL.RR.LLRRLL..";
    char *ans = pushDominoes(dominoes);
    TEST_ASSERT_EQUAL_STRING(correctAns, ans);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(pushDominoesTestExample1);
    RUN_TEST(pushDominoesTestExample2);
    return UNITY_END();
}
