//
// Created by smile on 2021/9/28.
//

#include "TreeNode.h"
#include "uthash.h"

typedef struct {
    int64_t sum;    // 出现过的前缀和
    int times;   // 出现的次数
    UT_hash_handle hh;
} PrefixMap;    // 前缀和哈希集合

void visitTree(struct TreeNode *root, int *pCnt, int targetSum, PrefixMap *prefixMap, int64_t prevSum) {
    if (root == NULL) {
        return;
    }
    PrefixMap *find;
    int64_t needFindVal = prevSum + root->val - targetSum;
    HASH_FIND(hh, prefixMap, &needFindVal, sizeof(int64_t), find);
    if (find != NULL) {
        (*pCnt) += find->times;
    }
    prevSum += root->val;
    HASH_FIND(hh, prefixMap, &prevSum, sizeof(int64_t), find);
    if (find == NULL) {
        find = malloc(sizeof(PrefixMap));
        find->sum = prevSum;
        find->times = 1;
        HASH_ADD(hh, prefixMap, sum, sizeof(uint64_t), find);
    } else {
        find->times++;
    }
    visitTree(root->left, pCnt, targetSum, prefixMap, prevSum);
    visitTree(root->right, pCnt, targetSum, prefixMap, prevSum);
    find->times--;
    if (find->times == 0) {
        HASH_DEL(prefixMap, find);
        free(find);
    }
}

int pathSum(struct TreeNode *root, int targetSum) {
    PrefixMap *prefixMap = NULL;
    PrefixMap *item = malloc(sizeof(PrefixMap));
    item->sum = 0;
    item->times = 1;
    HASH_ADD(hh, prefixMap, sum, sizeof(uint64_t), item);
    int cnt = 0;
    visitTree(root, &cnt, targetSum, prefixMap, 0);
    HASH_DEL(prefixMap, item);
    free(item);
    return cnt;
}