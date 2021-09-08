//
// Created by l30014168 on 2021/7/15.
//

#include <unity.h>
#include "letter-case-permutation.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void letterCasePermutationTestExample1(void) {
    char s[] = "a1b2";
    int returnSize = 0;
    char **ans = letterCasePermutation(s, &returnSize);

    char *rightAns[] = {"a1b2", "a1B2", "A1b2", "A1B2"};    // 常量类

    for (int idx = 0; idx < returnSize; ++idx) {
        if (ans[idx] != NULL) {
            TEST_ASSERT_EQUAL_STRING(rightAns[idx], ans[idx]);
            free(ans[idx]);
            ans[idx] = NULL;
        }
    }
    free(ans);
    ans = NULL;
}

void letterCasePermutationTestExample2(void) {
    char s[] = "3z4";
    int returnSize = 0;
    char **ans = letterCasePermutation(s, &returnSize);

    char *rightAns[] = {"3z4","3Z4"};    // 常量类

    for (int idx = 0; idx < returnSize; ++idx) {
        if (ans[idx] != NULL) {
            TEST_ASSERT_EQUAL_STRING(rightAns[idx], ans[idx]);
            free(ans[idx]);
            ans[idx] = NULL;
        }
    }
    free(ans);
    ans = NULL;
}

void letterCasePermutationTestExample3(void) {
    char s[] = "12345";
    int returnSize = 0;
    char **ans = letterCasePermutation(s, &returnSize);

    char *rightAns[] = {"12345"};    // 常量类

    for (int idx = 0; idx < returnSize; ++idx) {
        if (ans[idx] != NULL) {
            TEST_ASSERT_EQUAL_STRING(rightAns[idx], ans[idx]);
            free(ans[idx]);
            ans[idx] = NULL;
        }
    }
    free(ans);
    ans = NULL;
}

void letterCasePermutationTestExample4(void) {
    char s[] = "0";
    int returnSize = 0;
    char **ans = letterCasePermutation(s, &returnSize);

    char *rightAns[] = {"0"};    // 常量类

    for (int idx = 0; idx < returnSize; ++idx) {
        if (ans[idx] != NULL) {
            TEST_ASSERT_EQUAL_STRING(rightAns[idx], ans[idx]);
            free(ans[idx]);
            ans[idx] = NULL;
        }
    }
    free(ans);
    ans = NULL;
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(letterCasePermutationTestExample1);
    RUN_TEST(letterCasePermutationTestExample2);
    RUN_TEST(letterCasePermutationTestExample3);
    RUN_TEST(letterCasePermutationTestExample4);
    return UNITY_END();
}