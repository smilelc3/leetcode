//
// Created by smile on 2022/10/3.
//

#include <vector>
#include <queue>
#include "TreeNode.h"


class Solution {
public:
    static std::vector<std::vector<int>> levelOrder(Node *root) {
        if (root == nullptr) {
            return {};
        }
        std::queue<const Node *> queue;
        std::vector<std::vector<int>> ans;
        queue.emplace(root);
        ans.emplace_back(std::vector<int>{root->val});
        while (not queue.empty()) {
            auto parentNum = queue.size();
            auto curLevel = std::vector<int>();
            while (parentNum != 0) {
                const auto &parent = queue.front();
                for (const auto &child: parent->children) {
                    curLevel.emplace_back(child->val);
                    queue.emplace(child);
                }
                parentNum--;
                queue.pop();
            }
            if (not curLevel.empty()) {
                ans.emplace_back(curLevel);
            }
        }
        return ans;
    }
};
