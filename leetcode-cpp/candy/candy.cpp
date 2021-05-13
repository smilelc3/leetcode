//
// Created by smile on 2021/5/9.
//

#include <vector>
#include <numeric>

class Solution {
public:
    int candy(std::vector<int> &ratings) {
        std::vector<int> nums(ratings.size(), 1);
        // forward
        for (auto idx = 1; idx < ratings.size(); idx++) {
            if (ratings[idx] > ratings[idx - 1]) {
                nums[idx] = nums[idx - 1] + 1;
            }
        }
        // backward
        for (auto idx = 1; idx < ratings.size(); idx++) {
            if (ratings[ratings.size() - 1 - idx] > ratings[ratings.size() - idx]) {
                nums[ratings.size() - 1 - idx] = std::max(nums[ratings.size() - 1 - idx],
                                                          nums[ratings.size() - idx] + 1);
            }
        }

        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};