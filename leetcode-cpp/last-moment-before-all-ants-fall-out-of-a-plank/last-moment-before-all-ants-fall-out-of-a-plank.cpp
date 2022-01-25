//
// Created by smile on 2022/1/25.
//

#include <vector>
#include <algorithm>

class Solution {
public:
    static int getLastMoment(int n, std::vector<int> &left, std::vector<int> &right) {
        int ans = 0;
        if (not left.empty()) {
            ans = std::max(ans, *std::max_element(left.begin(), left.end()));
        }
        if (not right.empty()) {
            ans = std::max(ans, n - *std::min_element(right.begin(), right.end()));
        }
        return ans;
    }
};