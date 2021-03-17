//
// Created by smile on 2021/3/16.
//
# include <vector>

class Solution {
public:
    static int singleNumber(std::vector<int> &nums) {
        auto ans = nums[0];
        for (int idx = 1; idx < nums.size(); idx++) {
            ans = ans^nums[idx];
        }
        return ans;
    }
};