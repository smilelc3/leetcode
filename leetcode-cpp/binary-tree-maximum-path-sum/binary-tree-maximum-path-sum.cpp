//
// Created by smile on 2021/4/28.
//
#include "TreeNode.h"
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxPathSum(const TreeNode *root) {
        maxPathSumDFS(root);
        return res;
    }

private:
    int res = INT_MIN;

    int maxPathSumDFS(const TreeNode *pNode) {
        if (pNode == nullptr) {
            return 0;
        }
        auto leftSum = std::max(maxPathSumDFS(pNode->left), 0);
        auto rightSum = std::max(maxPathSumDFS(pNode->right), 0);

        res = std::max(res, leftSum + pNode->val + rightSum);

        return std::max(leftSum, rightSum) + pNode->val;
    }
};