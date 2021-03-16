//
// Created by smile on 2021/3/16.
//
#include <vector>

class Solution {
public:
    static std::vector<int> grayCode(int n) {
        std::vector<int> ans;
        ans.reserve(1 << n);        // 预分配空间
        for (int idx = 0; idx < 1 << n; idx++) {
            ans.push_back(idx ^ (idx >> 1));
        }
        return ans;
    }
};