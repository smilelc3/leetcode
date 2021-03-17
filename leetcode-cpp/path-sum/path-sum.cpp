//
// Created by smile on 2021/3/16.
//
#include <TreeNode.h>

class Solution {
public:
    static bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr and root->right == nullptr) {
            return targetSum == root->val;
        } else {
            bool isLeftHasPathSum = false, isRightHasPathSum = false;
            if (root->left != nullptr) {
                isLeftHasPathSum = hasPathSum(root->left, targetSum - root->val);
            }
            if (root->right != nullptr) {
                isRightHasPathSum = hasPathSum(root->right, targetSum - root->val);
            }
            return isRightHasPathSum or isLeftHasPathSum;
        }
    }

};