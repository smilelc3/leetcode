//
// Created by l30014168 on 2021/10/19.
//

#include <unity.h>
#include "design-add-and-search-words-data-structure.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void WordDictionaryTestExample1(void) {
    WordDictionary* obj = wordDictionaryCreate();
    wordDictionaryAddWord(obj, "bad");
    wordDictionaryAddWord(obj, "dad");
    wordDictionaryAddWord(obj, "mad");
    TEST_ASSERT_FALSE(wordDictionarySearch(obj, "pad"));
    TEST_ASSERT_TRUE(wordDictionarySearch(obj, "bad"));
    TEST_ASSERT_TRUE(wordDictionarySearch(obj, ".ad"));
    TEST_ASSERT_TRUE(wordDictionarySearch(obj, "b.."));
    wordDictionaryFree(obj);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(WordDictionaryTestExample1);
    return UNITY_END();
}