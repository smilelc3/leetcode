//
// Created by l30014168 on 2021/10/20.
//

#include <stdbool.h>
#include <stdlib.h>

# define MAX_CHAR_SIZE 26
typedef struct tagTrie {
    bool isEnd;    // 是否是单词末尾
    struct tagTrie *next[MAX_CHAR_SIZE];       // 多分支存储下一个字符
} Trie;


Trie *trieCreate() {
    Trie *obj = calloc(1, sizeof(Trie));
    return obj;
}

void trieInsert(Trie *obj, const char *word) {
    if (word[0] == '\0') {
        obj->isEnd = true;
        return;
    }
    size_t nextIdx = word[0] - 'a';
    if (obj->next[nextIdx] == NULL) {
        obj->next[nextIdx] = calloc(1, sizeof(Trie));
    }
    trieInsert(obj->next[nextIdx], word + 1);
}

bool trieSearch(Trie *obj, const char *word) {
    if (obj == NULL) {
        return false;
    }
    if (word[0] == '\0') {
        return obj->isEnd;
    }
    return trieSearch(obj->next[word[0] - 'a'], word + 1);
}

bool trieStartsWith(Trie *obj, const char *prefix) {
    if (obj == NULL) {
        return false;
    }
    if (prefix[0] == '\0') {
        return true;
    }
    return trieStartsWith(obj->next[prefix[0] - 'a'], prefix + 1);
}

void trieFree(Trie *obj) {
    for (size_t idx = 0; idx < MAX_CHAR_SIZE; ++idx) {
        if (obj->next[idx] != NULL) {
            trieFree(obj->next[idx]);
        }
    }
    free(obj);
}