//
// Created by smile on 2021/4/29.
//

#include "TreeNode.h"
#include <vector>

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> ans;
        preorderTraversalBacktrack(root, ans);
        return ans;
    }

private:
    void preorderTraversalBacktrack(TreeNode *root, std::vector<int> &ans) {
        if (root == nullptr) {
            return;
        }
        ans.emplace_back(root->val);
        preorderTraversalBacktrack(root->left, ans);
        preorderTraversalBacktrack(root->right, ans);

    }
};