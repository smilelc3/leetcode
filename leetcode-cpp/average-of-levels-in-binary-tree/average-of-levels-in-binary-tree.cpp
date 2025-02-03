//
// Created by smile on 2025/2/3.
//

#include <vector>
#include <cstdint>
#include <algorithm>
#include "TreeNode.h"

class Solution {
public:
    static std::vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<double> ans;
        std::vector<const TreeNode *> level;
        level.emplace_back(root);
        while(not level.empty()) {
            decltype(level) nextLevel;
            int64_t sum = 0;
            std::for_each(level.begin(), level.end(), [&sum, &nextLevel](auto &node) { 
                sum += node->val;
                if (node->left != nullptr) {
                    nextLevel.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    nextLevel.emplace_back(node->right);
                }
            });
           ans.emplace_back(sum * 1.0 / level.size());
            level.swap(nextLevel);
        }
        return ans;
    }
};