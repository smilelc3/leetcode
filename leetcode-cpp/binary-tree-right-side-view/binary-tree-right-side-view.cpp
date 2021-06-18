//
// Created by smile on 2021/6/18.
//

#include <TreeNode.h>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<int> res;
        std::queue<TreeNode *> nodesQueue;
        nodesQueue.emplace(root);
        auto levelSize = nodesQueue.size();
        while (not nodesQueue.empty()) {
            res.emplace_back(nodesQueue.back()->val);
            for (auto idx = 0; idx < levelSize; ++idx) {
                auto popNode = nodesQueue.front();
                nodesQueue.pop();
                if (popNode->left != nullptr) {
                    nodesQueue.emplace(popNode->left);
                }
                if (popNode->right != nullptr) {
                    nodesQueue.emplace(popNode->right);
                }
            }
            levelSize = nodesQueue.size();

        }
        return res;
    }
};