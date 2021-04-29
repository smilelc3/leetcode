//
// Created by smile on 2021/4/28.
//

#include <utility>
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = std::vector<Node *>();
    }

    explicit Node(int _val) {
        val = _val;
        neighbors = std::vector<Node *>();
    }

    Node(int _val, std::vector<Node *> _neighbors) {
        val = _val;
        neighbors = std::move(_neighbors);
    }
};

#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
public:
    // 无向图的复制
    Node *cloneGraph(Node* const node) {
        if (node == nullptr) {
            return nullptr;
        }
        std::queue<Node*> nodeQueue;
        nodeQueue.emplace(node);
        auto nodeCopy = new Node(node->val);
        rawNode2CpyNodeMap[node] = nodeCopy;

        while (not nodeQueue.empty()) {
            auto pNode = nodeQueue.front();
            nodeQueue.pop();
            auto pNodeCopy = rawNode2CpyNodeMap.at(pNode);
            for (const auto &neighbor : pNode->neighbors) {
                if (rawNode2CpyNodeMap.find(neighbor) == rawNode2CpyNodeMap.end()) {
                    // neighbor 节点之前未创建
                    auto neighborCopy = new Node(neighbor->val);
                    pNodeCopy->neighbors.emplace_back(neighborCopy);
                    rawNode2CpyNodeMap[neighbor] = neighborCopy;
                    if (visitNodesSet.find(neighbor) == visitNodesSet.end()) {
                        nodeQueue.emplace(neighbor);
                    }
                } else {
                    // neighbor 节点之前已经创建
                    pNodeCopy->neighbors.emplace_back(rawNode2CpyNodeMap.at(neighbor));
                }
            }
            visitNodesSet.insert(pNode);
        }
        return nodeCopy;
    }

private:
    std::unordered_map<Node *, Node *> rawNode2CpyNodeMap;
    std::unordered_set<Node *> visitNodesSet;
};