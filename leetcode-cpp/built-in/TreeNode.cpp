//
// Created by smile on 2021/3/16.
//
# include "TreeNode.h"
# include <vector>
#include <iostream>

TreeNode *GenTreeByNums(std::vector<int> &nums, int nullNum) {
    if (nums.empty() || nums[0] == nullNum) {
        return nullptr;
    }
    auto root = new TreeNode{nums[0]};
    nums.erase(nums.begin());
    auto queueNode = std::vector<TreeNode *>{root}; // 维护上一层包含空节点的所有节点（父节点）
    while (!nums.empty()) {
        int numPreLevelNodes = queueNode.size();
        for (int idx = 0; idx < numPreLevelNodes; idx++) {
            if (2 * idx < nums.size() and nums[2 * idx] != nullNum) {
                queueNode[idx]->left = new TreeNode{nums[2 * idx]};
                queueNode.push_back(queueNode[idx]->left);
            } else {
                queueNode.push_back(nullptr);
            }
            if (2 * idx + 1 < nums.size() and nums[2 * idx + 1] != nullNum) {
                queueNode[idx]->right = new TreeNode{nums[2 * idx + 1]};
                queueNode.push_back(queueNode[idx]->right);
            } else {
                queueNode.push_back(nullptr);
            }
        }
        queueNode.erase(queueNode.begin(), queueNode.begin() + numPreLevelNodes);
        nums.erase(nums.begin(), nums.begin() + std::min(numPreLevelNodes * 2, int(nums.size())));
    }
    return root;
}

