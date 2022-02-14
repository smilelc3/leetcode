//
// Created by smile on 2022/2/11.
//

#include <vector>
#include <algorithm>

class Solution {
public:
    static int findKthLargest(std::vector<int> &nums, int k) {
        std::nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
    }
};