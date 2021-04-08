//
// Created by smile on 2021/4/8.
//

#include <vector>

class Solution {
public:
    static std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ans;
        ans.reserve(numRows);
        if (numRows == 0) {
            return ans;
        }

        ans.push_back(std::vector<int>{1});
        if (numRows == 1) {
            return ans;
        }

        ans.push_back(std::vector<int>{1, 1});
        if (numRows == 2) {
            return ans;
        }

        for (auto i = 2; i < numRows; i++) {
            auto &preLayer = ans[i - 1];
            ans.push_back(std::vector<int>{1});
            auto &curLayer = ans.back();
            curLayer.reserve(i + 1);
            for (auto j = 0; j < preLayer.size() - 1; j++) {
                curLayer.push_back(preLayer[j] + preLayer[j + 1]);
            }
            curLayer.push_back(1);
        }
        return ans;
    }
};