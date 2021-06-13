//
// Created by smile on 2021/6/13.
//
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int> &numbers, const int target) {
        if (numbers.empty()) {
            return {};
        }
        int left = 0, right = int(numbers.size() - 1);
        while (left < right) {
            auto sum = numbers[left] + numbers[right];
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};