//
// Created by smile on 2021/3/17.
//
#include <TreeNode.h>
#include  <vector>

class Solution {
public:
    std::vector<std::vector<int>> ans;

    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root != nullptr) {
            auto temp = std::vector<int>{};
            traverseTreeNodes(root, targetSum, temp);
        }
        return ans;
    }

private:
    void traverseTreeNodes(TreeNode *root, int targetSum, std::vector<int> &path) {
        if (root->left == nullptr and root->right == nullptr) {
            if (targetSum == root->val) {
                // 确保深copy
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        } else {
            if (root->left != nullptr) {
                path.push_back(root->val);
                traverseTreeNodes(root->left, targetSum - root->val, path);
                path.pop_back();
            }
            if (root->right != nullptr) {
                path.push_back(root->val);
                traverseTreeNodes(root->right, targetSum - root->val, path);
                path.pop_back();
            }
        }
    }
};