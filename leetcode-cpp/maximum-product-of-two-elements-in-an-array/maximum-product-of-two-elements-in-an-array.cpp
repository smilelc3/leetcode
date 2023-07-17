//
// Created by smile on 2023/7/17.
//

#include <vector>
#include <array>

class Solution {
public:
    static int maxProduct(const std::vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        std::array<int, 2> max2Num = {nums[0], nums[1]};
        for (size_t idx = 2; idx < nums.size(); ++idx) {
            if (max2Num.front() > max2Num.back()) {     // 保证 front < back
                std::swap(max2Num.front(), max2Num.back());
            }
            if (nums[idx] > max2Num.front()) {
                max2Num.front() = nums[idx];
            }

        }
        return (max2Num.front() - 1) * (max2Num.back() - 1);
    }
};