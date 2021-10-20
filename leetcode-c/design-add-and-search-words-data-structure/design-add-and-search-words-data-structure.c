//
// Created by l30014168 on 2021/10/19.
//

#include <stdlib.h>
#include <stdbool.h>

# define MAX_CHAR_SIZE 26
// 前缀树（字典树）节点， 仅支持26个小写字符
typedef struct tagWordDictionary {
    bool isLeaf;    // 是否是叶子节点（代表单词末尾）
    struct tagWordDictionary *next[MAX_CHAR_SIZE];       // 多分支存储下一个字符
} WordDictionary;


WordDictionary *wordDictionaryCreate() {
    WordDictionary *obj = calloc(1, sizeof(WordDictionary));
    return obj;
}

void wordDictionaryAddWord(WordDictionary *obj, const char *word) {
    if (word[0] == '\0') {
        obj->isLeaf = true;
        return;
    }
    size_t nextIdx = word[0] - 'a';
    if (obj->next[nextIdx] == NULL) {
        obj->next[nextIdx] = calloc(1, sizeof(WordDictionary));
    }
    wordDictionaryAddWord(obj->next[nextIdx], word + 1);
}

bool wordDictionarySearch(WordDictionary *obj, const char *word) {
    if (obj == NULL) {
        return false;
    }
    if (word[0] == '\0') {
        return obj->isLeaf;
    }
    if (word[0] == '.') {
        for (size_t i = 0; i < MAX_CHAR_SIZE; ++i) {
            if (wordDictionarySearch(obj->next[i], word + 1) == true) {
                return true;
            }
        }
        return false;
    } else {
        return wordDictionarySearch(obj->next[word[0] - 'a'], word + 1);
    }
}

void wordDictionaryFree(WordDictionary *obj) {
    for (size_t idx = 0; idx < MAX_CHAR_SIZE; ++idx) {
        if (obj->next[idx] != NULL) {
            wordDictionaryFree(obj->next[idx]);
        }
    }
    free(obj);
}