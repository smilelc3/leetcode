//
// Created by smile on 2021/5/8.
//

#include <TreeNode.h>

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (root != nullptr) {
            dfsTraversal(root, 0);
        }
        return sum;
    }

private:
    int sum = 0;

    void dfsTraversal(TreeNode *root, int parentSum) {
        if (root->left == nullptr and root->right == nullptr) {
            sum += parentSum * 10 + root->val;
            return;
        }
        if (root->left != nullptr) {
            dfsTraversal(root->left, parentSum * 10 + root->val);
        }
        if (root->right != nullptr) {
            dfsTraversal(root->right, parentSum * 10 + root->val);
        }
    }
};