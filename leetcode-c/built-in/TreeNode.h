//
// Created by l30014168 on 2021/7/13.
//

#ifndef BUILT_IN_TREENODE_H
#define BUILT_IN_TREENODE_H

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 释放二叉树
void TreeDestroy(struct TreeNode *root);

#endif //BUILT_IN_TREENODE_H
