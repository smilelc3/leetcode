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
        auto preStatus = nums[0], curStatus = std::max(nums[0], nums[1]);

        for (auto idx = 2; idx < nums.size(); ++idx) {
            auto curStatusCopy = curStatus;
            curStatus = std::max(preStatus + nums[idx], curStatus);
            preStatus = curStatusCopy;
        }
        return curStatus;
    }
};