//
// Created by smile on 24-6-15.
//

#include <vector>
#include <limits>
#include <cstdint>

class Solution {
public:
    static long long maxScore(std::vector<int> &nums, int x) { // 1 <= nums[i], x <= 10^6
        int64_t dp_odd, dp_even;
        if (isOdd(nums[0])) { // 0位置需要特殊处理，必选
            dp_odd = nums[0];
            dp_even = std::numeric_limits<int>::min();
        } else {
            dp_odd = std::numeric_limits<int>::min();
            dp_even = nums[0];
        }
        for (decltype(nums.size()) idx = 1; idx < nums.size(); ++idx) {
            if (isOdd(nums[idx])) {
                dp_odd = std::max(dp_odd + nums[idx], dp_even + nums[idx] - x);
            } else {
                dp_even = std::max(dp_even + nums[idx], dp_odd + nums[idx] - x);
            }
        }

        return std::max(dp_odd, dp_even);
    }
private:
    static constexpr bool isOdd(const uint32_t value) {
        return (value & 1);
    }
};
