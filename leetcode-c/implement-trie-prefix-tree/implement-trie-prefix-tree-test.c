//
// Created by l30014168 on 2021/10/20.
//

#include <unity.h>
#include "implement-trie-prefix-tree.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void TrieTestExample1(void) {
    Trie *obj = trieCreate();
    trieInsert(obj, "apple");
    TEST_ASSERT_TRUE(trieSearch(obj, "apple"));
    TEST_ASSERT_FALSE(trieSearch(obj, "app"));
    TEST_ASSERT_TRUE(trieStartsWith(obj, "app"));
    trieInsert(obj, "app");
    TEST_ASSERT_TRUE(trieSearch(obj, "app"));
    trieFree(obj);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(TrieTestExample1);
    return UNITY_END();
}