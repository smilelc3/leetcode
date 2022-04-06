//
// Created by smile on 2022/4/6.
//

#include <vector>

class Solution {
public:
    static void moveZeroes(std::vector<int> &nums) {
        auto iter = nums.begin();
        for (auto &num: nums) {
            if (num != 0) {
                std::swap(*iter, num);
                iter++;
            }
        }
    }
};