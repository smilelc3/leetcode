//
// Created by smile on 2021/3/16.
//
# include "TreeNode.h"
# include <vector>
#include <iostream>

TreeNode *GenTreeByNums(const std::vector<int> &numsConst, int nullNum) {
    if (numsConst.empty() || numsConst[0] == nullNum) {
        return nullptr;
    }
    auto nums = std::vector<int>(numsConst.begin(), numsConst.end());
    auto root = new TreeNode{nums[0]};
    nums.erase(nums.begin());
    auto preLevelNode = std::vector<TreeNode *>{root}; // 维护上一层所有非空父节点
    while (!nums.empty()) {
        int numPreLevelNodes = preLevelNode.size();
        int numsIdx = 0;
        for (int idx = 0; idx < numPreLevelNodes; idx++) {
            if (numsIdx < nums.size()) {
                if (nums[numsIdx] != nullNum) {
                    preLevelNode[idx]->left = new TreeNode{nums[numsIdx]};
                    preLevelNode.push_back(preLevelNode[idx]->left);
                }
                numsIdx++;
            }
            if (numsIdx < nums.size()) {
                if (nums[numsIdx] != nullNum) {
                    preLevelNode[idx]->right = new TreeNode{nums[numsIdx]};
                    preLevelNode.push_back(preLevelNode[idx]->right);
                }
                numsIdx++;
            }

        }
        preLevelNode.erase(preLevelNode.begin(), preLevelNode.begin() + numPreLevelNodes);
        nums.erase(nums.begin(), nums.begin() + numsIdx);
    }
    return root;
}

TreeNode *GenTreeByNums(const std::vector<int> &numsConst) {
    if (numsConst.empty()) {
        return nullptr;
    }
    auto nums = std::vector<int>(numsConst.begin(), numsConst.end());
    auto root = new TreeNode{nums[0]};
    nums.erase(nums.begin());
    auto preLevelNode = std::vector<TreeNode *>{root}; // 维护上一层所有非空父节点
    while (!nums.empty()) {
        int numPreLevelNodes = preLevelNode.size();
        int numsIdx = 0;
        for (int idx = 0; idx < numPreLevelNodes; idx++) {
            if (numsIdx < nums.size()) {
                preLevelNode[idx]->left = new TreeNode{nums[numsIdx]};
                preLevelNode.push_back(preLevelNode[idx]->left);
                numsIdx++;
            }
            if (numsIdx < nums.size()) {
                preLevelNode[idx]->right = new TreeNode{nums[numsIdx]};
                preLevelNode.push_back(preLevelNode[idx]->right);
                numsIdx++;
            }

        }
        preLevelNode.erase(preLevelNode.begin(), preLevelNode.begin() + numPreLevelNodes);
        nums.erase(nums.begin(), nums.begin() + numsIdx);
    }
    return root;
}

bool isSameTree(TreeNode const *root1, TreeNode const *root2) {
    if (root1 == nullptr and root2 == nullptr) {
        return true;
    } else if (root1 != nullptr and root2 != nullptr) {
        if (root1->val != root2->val) {
            return false;
        }
        return isSameTree(root1->left, root2->left) and isSameTree(root1->right, root2->right);
    } else {
        return false;
    }
}

