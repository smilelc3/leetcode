//
// Created by l30014168 on 2021/9/18.
//

#include <stdlib.h>

# define MAX_CHAR_SIZE 26
// 前缀树（字典树）节点， 仅支持26个小写字符
typedef struct tagTriedNode {
    int wordIdx; // 原单词有序表idx, 为-1时表示非完整单词
    struct tagTriedNode *next[MAX_CHAR_SIZE];       // 多分支存储下一个字符
} TrieNode;

// 创建前缀树
static inline TrieNode *TrieCreate(void) {
    TrieNode *ret = calloc(1, sizeof(TrieNode));
    ret->wordIdx = -1;
    return ret;
}

// 前缀树添加单词
void TrieAddWord(TrieNode *this, const char *word, int wordIdx);

// 前缀树删除
void TrieDestroy(TrieNode *this);

void TrieAddWord(TrieNode *this, const char *word, int wordIdx) {
    if (word[0] == '\0') {
        this->wordIdx = wordIdx;
        return;
    }
    size_t nextIdx = word[0] - 'a';
    if (this->next[nextIdx] == NULL) {
        this->next[nextIdx] = calloc(1, sizeof(TrieNode));
        this->next[nextIdx]->wordIdx = -1;
    }
    TrieAddWord(this->next[nextIdx], word + 1, wordIdx);
}

void TrieDestroy(TrieNode *this) {
    for (size_t idx = 0; idx < MAX_CHAR_SIZE; ++idx) {
        if (this->next[idx] != NULL) {
            TrieDestroy(this->next[idx]);
        }
    }
    free(this);
}

// 在trie中搜索key开头存在的所有解
void TrieSearch(char *key, TrieNode *root, int **ret, int *returnColumnSizes, int startIdx) {
    if (root == NULL) {
        return;
    }
    if (root->wordIdx != -1) {      // 找到解
        ret[root->wordIdx][returnColumnSizes[root->wordIdx]] = startIdx;
        returnColumnSizes[root->wordIdx]++;
    }
    if (key[0] == '\0') {
        return;
    }
    TrieSearch(key + 1, root->next[key[0] - 'a'], ret, returnColumnSizes, startIdx);
}

#define MAX_BIG_LEN 1000

int **multiSearch(char *big, char **smalls, int smallsSize, int *returnSize, int **returnColumnSizes) {
    // 根据smalls实现前缀树
    TrieNode *smallsTrie = TrieCreate();
    for (int idx = 0; idx < smallsSize; ++idx) {
        if (smalls[idx][0] == '\0') {
            continue;
        }
        TrieAddWord(smallsTrie, smalls[idx], idx);
    }

    *returnSize = smallsSize;
    int **ret = malloc(sizeof(int *) * *returnSize);
    for (int idx = 0; idx < *returnSize; ++idx) {
        ret[idx] = malloc(MAX_BIG_LEN * sizeof(int));
    }

    *returnColumnSizes = calloc(*returnSize, sizeof(int));

    for (int idx = 0; idx < strlen(big); ++idx) {
        TrieSearch(big + idx, smallsTrie, ret, *returnColumnSizes, idx);
    }

    TrieDestroy(smallsTrie);
    return ret;
}