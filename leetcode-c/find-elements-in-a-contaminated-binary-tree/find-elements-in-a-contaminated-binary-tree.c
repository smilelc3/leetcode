//
// Created by smile on 2021/12/2.
//

#include <stdbool.h>
#include "TreeNode.h"

typedef struct {
    struct TreeNode *root;
} FindElements;

FindElements *findElementsCreate(struct TreeNode *root) {
    FindElements *obj = malloc(sizeof(FindElements));
    obj->root = root;
    return obj;
}

bool findElementsFind(FindElements *obj, int target) {
    size_t level = 0;               // 目标所在层数
    for (size_t idx = 1; idx <= target; idx = idx * 2 + 1) {
        level++;
    }
    size_t idxAtLevel = target - ((1 << level) - 1);     // 目标当前层数的节点idx
    struct TreeNode *targetNode = obj->root;
    while (level > 0) {
        size_t lastLevelNodeNum = 1 << (level - 1);
        if (idxAtLevel >= lastLevelNodeNum) {
            idxAtLevel -= lastLevelNodeNum;
            targetNode = targetNode->right;
        } else {
            targetNode = targetNode->left;
        }
        if (targetNode == NULL) {
            return false;
        }
        level--;
    }
    return true;
}

void findElementsFree(FindElements *obj) {
    free(obj);
}