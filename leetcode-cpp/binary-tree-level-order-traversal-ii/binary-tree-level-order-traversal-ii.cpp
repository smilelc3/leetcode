//
// Created by smile on 2021/4/12.
//
#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode.h"

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        // BFS
        std::vector<std::vector<int>> ans;

        if (root == nullptr) {
            return ans;
        }

        // init
        std::queue<TreeNode *> nodesQueue;
        nodesQueue.push(root);

        while (not nodesQueue.empty()) {
            auto preLayerSize = nodesQueue.size();
            ans.emplace_back();
            for (auto idx = 0; idx < preLayerSize; idx++) {
                auto node = nodesQueue.front();
                nodesQueue.pop();
                ans.back().emplace_back(node->val);
                if (node->left != nullptr) {
                    nodesQueue.push(node->left);
                }
                if (node->right != nullptr) {
                    nodesQueue.push(node->right);
                }
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};