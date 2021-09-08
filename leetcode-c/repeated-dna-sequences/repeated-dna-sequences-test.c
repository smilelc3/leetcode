//
// Created by l30014168 on 2021/7/22.
//

#include <unity.h>
#include "repeated-dna-sequences.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void findRepeatedDnaSequencesTestExample1(void) {
    char s[] = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    int returnSize = -1;
    char **ans = findRepeatedDnaSequences(s, &returnSize);

    char *rightAns[] = {"AAAAACCCCC", "CCCCCAAAAA"};
    TEST_ASSERT_EQUAL_INT(2, returnSize);
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

void findRepeatedDnaSequencesTestExample2(void) {
    char s[] = "AAAAAAAAAAAAA";
    int returnSize = -1;
    char **ans = findRepeatedDnaSequences(s, &returnSize);

    char *rightAns[] = {"AAAAAAAAAA"};
    TEST_ASSERT_EQUAL_INT(1, returnSize);
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

void findRepeatedDnaSequencesTestTest0(void) {
    char s[] = "A";
    int returnSize = -1;
    char **ans = findRepeatedDnaSequences(s, &returnSize);
    TEST_ASSERT_EQUAL_INT(0, returnSize);
    free(ans);
    ans = NULL;
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(findRepeatedDnaSequencesTestExample1);
    RUN_TEST(findRepeatedDnaSequencesTestExample2);
    RUN_TEST(findRepeatedDnaSequencesTestTest0);
    return UNITY_END();
}