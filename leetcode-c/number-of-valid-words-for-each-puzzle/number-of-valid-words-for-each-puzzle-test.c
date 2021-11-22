//
// Created by l30014168 on 2021/8/5.
//

#include <unity.h>
#include "util.h"
#include "number-of-valid-words-for-each-puzzle.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void findNumOfValidWordsTestExample1(void) {
    char *words[] = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    int wordsSize = ARRAY_LENGTH(words);
    char *puzzles[] = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
    int puzzlesSize = ARRAY_LENGTH(puzzles);
    int rightAns[] = {1, 1, 3, 2, 4, 0};
    int returnSize = -1;
    int *ans = findNumOfValidWords(words, wordsSize, puzzles, puzzlesSize, &returnSize);
    TEST_ASSERT_EQUAL_INT(returnSize, ARRAY_LENGTH(rightAns));
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    free(ans);
}

void findNumOfValidWordsTestTest0(void) {
    char *words[] = {"apple", "pleas", "please"};
    int wordsSize = ARRAY_LENGTH(words);
    char *puzzles[] = {"aelwxyz", "aelpxyz", "aelpsxy", "saelpxy", "xaelpsy"};
    int puzzlesSize = ARRAY_LENGTH(puzzles);
    int rightAns[] = {0, 1, 3, 2, 0};
    int returnSize = -1;
    int *ans = findNumOfValidWords(words, wordsSize, puzzles, puzzlesSize, &returnSize);
    TEST_ASSERT_EQUAL_INT(returnSize, ARRAY_LENGTH(rightAns));
    TEST_ASSERT_EQUAL_INT_ARRAY(rightAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(findNumOfValidWordsTestExample1);
    RUN_TEST(findNumOfValidWordsTestTest0);
    return UNITY_END();
}