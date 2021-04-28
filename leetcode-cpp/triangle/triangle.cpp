//
// Created by smile on 2021/4/9.
//

#include <vector>
#include <algorithm>
#include <cstdint>

class Solution {
public:
    static int minimumTotal(std::vector<std::vector<int>> &triangle) {
        std::vector<int> dp(triangle.back().size());
        dp[0] = triangle.front().front();
        for (auto i = 1; i < triangle.size(); i++) {
            for (int64_t j = triangle[i].size() - 1; j >= 0; j--) {
                if (j == 0) {
                    dp[j] += triangle[i][j];
                } else if (j == i) {
                    dp[j] = dp[j - 1] + triangle[i][j];
                } else {
                    // 0 < j < i
                    dp[j] = std::min(dp[j], dp[j - 1]) + triangle[i][j];
                }
            }
        }
        return *std::min_element(dp.begin(), dp.end());
    }
};