//
// Created by smile on 2022/1/17.
//

#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    static int calPoints(std::vector<std::string> &ops) {
        std::vector<int> dataStack;
        for (const auto &op: ops) {
            if (op == "D") {
                dataStack.emplace_back(dataStack.back() * 2);
            } else if (op == "+") {
                dataStack.emplace_back(*dataStack.rbegin() + *(dataStack.rbegin() + 1));
            } else if (op == "C") {
                dataStack.pop_back();
            } else {
                dataStack.emplace_back(std::stoi(op));
            }
        }
        return std::accumulate(dataStack.begin(), dataStack.end(), 0);
    }
};