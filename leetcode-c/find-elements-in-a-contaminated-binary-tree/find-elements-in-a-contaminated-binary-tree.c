//
// Created by smile on 2021/12/2.
//

#include <stdbool.h>
#include "TreeNode.h"

typedef struct {
    size_t level;               // 目标所在层数
    size_t idxAtLevel;          // 目标当前层数的节点idx
    struct TreeNode *root;
} FindElements;

void setTreeNodeVal(struct TreeNode *root) {
    if (root->left != NULL) {
        root->left->val = root->val * 2 + 1;
        setTreeNodeVal(root->left);
    }
    if (root->right != NULL) {
        root->right->val = root->val * 2 + 2;
        setTreeNodeVal(root->right);
    }
}

FindElements *findElementsCreate(struct TreeNode *root) {
    FindElements *obj = calloc(1, sizeof(FindElements));
    if (root != NULL) {
        root->val = 0;
        setTreeNodeVal(root);
        obj->root = root;
    }
    return obj;
}

//bool findTreeNodeByVal(struct TreeNode *root, int target) {
//    if (root == NULL) {
//        return false;
//    }
//}

bool findElementsFind(FindElements *obj, int target) {
    size_t idx = 0;
    while (idx < target) {
        obj->level++;
        idx = idx * 2 + 1;
    }
    obj->idxAtLevel = (1 << obj->level) - 1;
    return findTreeNodeByVal(obj->root, target);
}

void findElementsFree(FindElements *obj) {
    free(obj);
}