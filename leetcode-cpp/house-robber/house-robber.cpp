//
// Created by smile on 2021/6/15.
//

#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums.front();
        }
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (auto idx = 2; idx < nums.size(); ++idx) {
            dp[idx] = std::max(dp[idx - 2] + nums[idx], dp[idx - 1]);
        }
        return dp.back();
    }
};