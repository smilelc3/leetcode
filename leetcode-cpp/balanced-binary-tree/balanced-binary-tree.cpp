//
// Created by smile on 2021/3/16.
//
#include "TreeNode.h"
#include <tuple>
#include <cstdlib>

class Solution {
public:

    // 平衡二叉树: 一棵二叉树，其中每个节点的左和右子树的高度差不超过1。
    static bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        bool isBalanced;
        int rootDepth;
        std::tie(isBalanced, rootDepth) = getTreeMaxDepthAndIsBalanced(root);
        return isBalanced;
    }

    static std::tuple<bool, int> getTreeMaxDepthAndIsBalanced(TreeNode *root) {
        if (root->left == nullptr and root->right == nullptr) {
            return {true, 1};
        } else if (root->left != nullptr and root->right == nullptr) {
            bool leftIsBalanced;
            int leftDepth;
            std::tie(leftIsBalanced, leftDepth) = getTreeMaxDepthAndIsBalanced(root->left);
            if (leftIsBalanced and leftDepth == 1) {
                return {true, leftDepth + 1};
            } else {
                return {false, leftDepth + 1};
            }
        } else if (root->left == nullptr and root->right != nullptr) {
            bool rightIsBalanced;
            int rightDepth;
            std::tie(rightIsBalanced, rightDepth) = getTreeMaxDepthAndIsBalanced(root->right);
            if (rightIsBalanced and rightDepth == 1) {
                return {true, rightDepth + 1};
            } else {
                return {false, rightDepth + 1};
            }
        } else {        // 左右均不为空
            bool leftIsBalanced, rightIsBalanced;
            int leftDepth, rightDepth;
            std::tie(leftIsBalanced, leftDepth) = getTreeMaxDepthAndIsBalanced(root->left);
            std::tie(rightIsBalanced, rightDepth) = getTreeMaxDepthAndIsBalanced(root->right);
            if (std::abs(leftDepth - rightDepth) <= 1 and leftIsBalanced and rightIsBalanced) {
                return {true, std::max(leftDepth, rightDepth)+1};
            } else {
                return {false, std::max(leftDepth, rightDepth)+1};
            }
        }
    }
};
