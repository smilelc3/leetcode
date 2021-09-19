//
// Created by l30014168 on 2021/7/13.
//

#ifndef BUILT_IN_TREENODE_H
#define BUILT_IN_TREENODE_H

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 根据数组创建树
struct TreeNode *TreeCreateByNums(const int *nums, size_t numsSize, int nullNum);

// 释放二叉树
void TreeDestroy(struct TreeNode *root);

// 判断两颗二叉树是否相同
bool isSameTree(const struct TreeNode *root1, const struct TreeNode *root2);

#endif //BUILT_IN_TREENODE_H
