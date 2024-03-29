//
// Created by smile on 2021/3/16.
//
# include "TreeNode.h"
# include <vector>
#include <iostream>

namespace BinaryTree {

    TreeNode *createByNums(const std::vector<int> &nums, int nullNum) {
        if (nums.empty() || nums[0] == nullNum) {
            return nullptr;
        }
        auto numsCopy = std::vector<int>(nums.begin(), nums.end());
        auto root = new TreeNode{numsCopy[0]};
        numsCopy.erase(numsCopy.begin());
        auto preLevelNode = std::vector<TreeNode *>{root}; // 维护上一层所有非空父节点
        while (!numsCopy.empty()) {
            decltype(preLevelNode.size()) numPreLevelNodes = preLevelNode.size();
            decltype(numsCopy.size()) numsIdx = 0;
            for (decltype(numPreLevelNodes) idx = 0; idx < numPreLevelNodes; idx++) {
                if (numsIdx < numsCopy.size()) {
                    if (numsCopy[numsIdx] != nullNum) {
                        preLevelNode[idx]->left = new TreeNode{numsCopy[numsIdx]};
                        preLevelNode.emplace_back(preLevelNode[idx]->left);
                    }
                    numsIdx++;
                }
                if (numsIdx < numsCopy.size()) {
                    if (numsCopy[numsIdx] != nullNum) {
                        preLevelNode[idx]->right = new TreeNode{numsCopy[numsIdx]};
                        preLevelNode.emplace_back(preLevelNode[idx]->right);
                    }
                    numsIdx++;
                }

            }
            preLevelNode.erase(preLevelNode.begin(), preLevelNode.begin() + numPreLevelNodes);
            numsCopy.erase(numsCopy.begin(), numsCopy.begin() + numsIdx);
        }
        return root;
    }

    TreeNode *createByNums(const std::vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        auto numsCopy = std::vector<int>(nums.begin(), nums.end());
        auto root = new TreeNode{numsCopy[0]};
        numsCopy.erase(numsCopy.begin());
        auto preLevelNode = std::vector<TreeNode *>{root}; // 维护上一层所有非空父节点
        while (!numsCopy.empty()) {
            decltype(preLevelNode.size()) numPreLevelNodes = preLevelNode.size();
            decltype(numsCopy.size()) numsIdx = 0;
            for (decltype(numPreLevelNodes) idx = 0; idx < numPreLevelNodes; idx++) {
                if (numsIdx < numsCopy.size()) {
                    preLevelNode[idx]->left = new TreeNode{numsCopy[numsIdx]};
                    preLevelNode.emplace_back(preLevelNode[idx]->left);
                    numsIdx++;
                }
                if (numsIdx < numsCopy.size()) {
                    preLevelNode[idx]->right = new TreeNode{numsCopy[numsIdx]};
                    preLevelNode.emplace_back(preLevelNode[idx]->right);
                    numsIdx++;
                }

            }
            preLevelNode.erase(preLevelNode.begin(), preLevelNode.begin() + numPreLevelNodes);
            numsCopy.erase(numsCopy.begin(), numsCopy.begin() + numsIdx);
        }
        return root;
    }

    void destroy(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        BinaryTree::destroy(root->left);
        BinaryTree::destroy(root->right);
        delete root;
    }


    bool isEqual(TreeNode const *root1, TreeNode const *root2) {
        if (root1 == nullptr and root2 == nullptr) {
            return true;
        } else if (root1 != nullptr and root2 != nullptr) {
            if (root1->val != root2->val) {
                return false;
            }
            return isEqual(root1->left, root2->left) and isEqual(root1->right, root2->right);
        } else {
            return false;
        }
    }


}