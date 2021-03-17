//
// Created by smile on 2021/3/16.
//
#include <TreeNode.h>
#include <climits>


class Solution {
public:
    int minDepthVal = INT_MAX;

    int minDepth(TreeNode *root) {
        return getMinDepth(root, 1);
    }

private:
    int getMinDepth(TreeNode *root, int curDepth) {
        if (root == nullptr) {
            return 0;
        }
        // 剪枝策略
        if (curDepth >= minDepthVal) {
            return minDepthVal;
        }
        // 到达叶子节点，且curDepth < minDepth
        if (root->left == nullptr and root->right == nullptr) {
            minDepthVal = curDepth;
            return curDepth;
        }

        // 至少存在一个子孩子
        int leftDepth = INT_MAX, rightDepth = INT_MAX;
        if (root->left != nullptr) {
            leftDepth = getMinDepth(root->left, curDepth + 1);
        }
        if (root->right != nullptr) {
            rightDepth = getMinDepth(root->right, curDepth + 1);
        }
        return std::min(leftDepth, rightDepth);
    }
};