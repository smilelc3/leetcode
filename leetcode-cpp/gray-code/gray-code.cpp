//
// Created by smile on 2021/3/16.
//
#include <vector>

class Solution {
public:
    static std::vector<int> grayCode(int n) {
        if (n < 0) {
            return {};
        }
        std::vector<int> ans;
        ans.reserve((size_t) 1 << n);        // 预分配空间
        for (auto idx = 0; idx < 1 << n; idx++) {
            ans.emplace_back(idx ^ (idx >> 1));
        }
        return ans;
    }
};