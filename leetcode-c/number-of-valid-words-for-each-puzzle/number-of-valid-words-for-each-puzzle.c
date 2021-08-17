//
// Created by l30014168 on 2021/8/5.
//

#include <stdlib.h>
#include <string.h>
#include <uthash.h>
#include "util.h"

typedef struct tagWordHashMap {
    int cprWord;
    int count;
    UT_hash_handle hh;
} WordsHashMap;


static void freeWordHashSet(WordsHashMap *head) {
    WordsHashMap *cur, *tmp;
    HASH_ITER(hh, head, cur, tmp) {
        HASH_DEL(head, cur);                  // delete it
        free(cur);                            // free it
    }
    free(head);
}


static void dfsSubstrProcess(int cprVal, int start, int end, int curCprVal, int firstLoc, WordsHashMap *wordsHashSet,
                             int *pRet) {
    if (start == end + 1) {     // 已经找完
        WordsHashMap *find;
        HASH_FIND_INT(wordsHashSet, &curCprVal, find);
        if (find != NULL) {
            (*pRet) += find->count;
        }
        return;
    }
    if ((cprVal & (1 << start)) != 0 && start != firstLoc) {     // 该位存在，且不为首位
        dfsSubstrProcess(cprVal, start + 1, end, curCprVal | (1 << start), firstLoc, wordsHashSet, pRet);
    }
    // 无论存不存在都要进行下一位判断
    dfsSubstrProcess(cprVal, start + 1, end, curCprVal, firstLoc, wordsHashSet, pRet);

}

static int *findNumOfValidWords(char **words, int wordsSize, char **puzzles, int puzzlesSize, int *returnSize) {
    int *ret = NULL;
    *returnSize = 0;
    int *cprWord;
    WordsHashMap *wordsHashSet = NULL;
    ret = calloc(puzzlesSize, sizeof(uint32_t));
    if (ret == NULL) {
        perror("calloc ret fail!\n");
        return NULL;
    }
    cprWord = malloc(sizeof(uint32_t) * wordsSize);
    if (cprWord == NULL) {
        free(ret);
        perror("malloc cprWord fail!\n");
        return NULL;
    }

    *returnSize = puzzlesSize;

    // map 初始化
    for (int idx = 0; idx < wordsSize; ++idx) {
        // 字符压缩
        int cprVal = 0;
        size_t wordSize = strlen(words[idx]);
        for (size_t j = 0; j < wordSize; ++j) {
            cprVal |= 1 << (words[idx][j] - 'a');
        }
        WordsHashMap *find;
        HASH_FIND_INT(wordsHashSet, &cprVal, find);
        if (find == NULL) {
            WordsHashMap *item = (WordsHashMap *) malloc(sizeof(WordsHashMap));
            if (item == NULL) {
                free(ret);
                free(cprWord);
                freeWordHashSet(wordsHashSet);
                return NULL;
            }
            item->cprWord = cprVal;
            item->count = 1;
            HASH_ADD_INT(wordsHashSet, cprWord, item);
        } else {
            find->count += 1;
        }
    }


    for (int t = 0; t < puzzlesSize; ++t) {
        char *puzzle = puzzles[t];
        size_t length = strlen(puzzle);
        if (length == 0) {
            continue;
        }
        // 尝试所有子集
        // 方法1：DFS
        // 方法2：for i = 0 to 1<<n
        // 方法3：i = (i -1) & x (x is the bitmap)

        // 使用DFS方法
        int cprVal = 0;
        size_t puzzleSize = strlen(puzzle);
        int maxChar = 'a';
        for (size_t i = 0; i < puzzleSize; ++i) {
            maxChar = max(maxChar, puzzle[i]);
            cprVal |= 1 << (puzzle[i] - 'a');
        }

        dfsSubstrProcess(cprVal, 0, maxChar - 'a', 1 << (puzzle[0] - 'a'), puzzle[0] - 'a', wordsHashSet,
                         &ret[t]);      // 必须包含首位

    }
    free(cprWord);
    freeWordHashSet(wordsHashSet);
    return ret;
}