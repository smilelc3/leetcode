//
// Created by l30014168 on 2021/7/13.
//

#include <stdlib.h>
#include <stdio.h>
#include <Vector.h>
#include "TreeNode.h"


struct TreeNode *TreeCreateByNums(const int *nums, size_t numsSize, int nullNum) {
    if (numsSize == 0 || nums[0] == nullNum) {
        return NULL;
    }
    struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
    if (root == NULL) {
        fprintf(stderr, "calloc TreeNode fail.\n");
        return NULL;
    }
    size_t numsIdx = 0;
    root->val = nums[numsIdx++];
    Vector *preLevelNodes = VectorCreate(sizeof(struct TreeNode *));     // 维护上一层所有非空父节点
    VectorAppend(preLevelNodes, &root);
    while (numsIdx < numsSize) {
        size_t numPreLevelNodes = preLevelNodes->size;
        for (size_t idx = 0; idx < numPreLevelNodes; idx++) {
            if (numsIdx < numsSize) {        // left
                if (nums[numsIdx] != nullNum) {
                    struct TreeNode **pPreLevelNode = VectorAtNoCheck(preLevelNodes, idx);
                    (*pPreLevelNode)->left = calloc(1, sizeof(struct TreeNode));
                    if ((*pPreLevelNode)->left == NULL) {
                        fprintf(stderr, "calloc TreeNode fail.\n");
                        TreeDestroy(root);
                        return NULL;
                    }
                    (*pPreLevelNode)->left->val = nums[numsIdx];
                    VectorAppend(preLevelNodes, &(*pPreLevelNode)->left);
                }
                numsIdx++;
            }
            if (numsIdx < numsSize) {       // right
                if (nums[numsIdx] != nullNum) {
                    struct TreeNode **pPreLevelNode = VectorAtNoCheck(preLevelNodes, idx);
                    (*pPreLevelNode)->right = calloc(1, sizeof(struct TreeNode));
                    if ((*pPreLevelNode)->right == NULL) {
                        fprintf(stderr, "calloc TreeNode fail.\n");
                        return NULL;
                    }
                    (*pPreLevelNode)->right->val = nums[numsIdx];
                    VectorAppend(preLevelNodes, &(*pPreLevelNode)->right);
                }
                numsIdx++;
            }
        }
        VectorErase(preLevelNodes, 0, numPreLevelNodes);    // 清除上一层，继续下一层
    }
    VectorDestroy(preLevelNodes);
    return root;
}

// 删除树
void TreeDestroy(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    TreeDestroy(root->left);
    TreeDestroy(root->right);
    free(root);
}


bool isSameTree(const struct TreeNode *root1, const struct TreeNode *root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 != NULL && root2 != NULL) {
        if (root1->val != root2->val) {
            return false;
        }
        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    } else {
        return false;
    }
}