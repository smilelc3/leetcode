//
// Created by smile on 2021/4/29.
//

#include "TreeNode.h"
#include <vector>

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode *root) {
        std::vector<int> ans;
        postorderTraversalBacktrack(root, ans);
        return ans;
    }

private:
    void postorderTraversalBacktrack(TreeNode *root, std::vector<int> &ans) {
        if (root == nullptr) {
            return;
        }
        postorderTraversalBacktrack(root->left, ans);
        postorderTraversalBacktrack(root->right, ans);
        ans.emplace_back(root->val);
    }
};
