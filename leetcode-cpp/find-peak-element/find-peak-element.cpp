//
// Created by smile on 2021/6/11.
//

#include <vector>
#include <stdexcept>
#include <cstdint>

class Solution {
public:
    size_t findPeakElement(std::vector<int> &nums) {
        if (nums.empty()) {
            throw std::out_of_range("nums size must > 0");
        }
        size_t begin = 0, end = nums.size() - 1, mid;
        int leftVal, rightVal;
        while (begin < end) {
            mid = (begin + end) / 2;
            leftVal = mid == 0 ? INT32_MIN : nums[mid - 1];
            rightVal = mid == nums.size() - 1 ? INT32_MIN : nums[mid + 1];

            if (leftVal < nums[mid] and nums[mid] > rightVal) {
                return mid;
            } else if (leftVal <= nums[mid]) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return begin;
    }
};