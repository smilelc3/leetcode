//
// Created by smile on 2022/10/6.
//

#include "TreeNode.h"

struct TreeNode *pruneTree(struct TreeNode *root) {
    if (root == NULL) {
        return root;
    }
    struct TreeNode *left = pruneTree(root->left);
    struct TreeNode *right = pruneTree(root->right);
    if (left == NULL && right == NULL && root->val == 0) {
        return NULL;
    }
    struct TreeNode *pruneRoot = malloc(sizeof(struct TreeNode));
    pruneRoot->val = root->val;
    pruneRoot->left = left;
    pruneRoot->right = right;
    return pruneRoot;

}