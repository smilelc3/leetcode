//
// Created by smile on 2022/1/27.
//

#include <vector>

class Solution {
public:
    void rotate(std::vector<int> &nums, int k) {
        k = k % nums.size();
        auto begin = nums.begin(), end = nums.end();
        auto length = end - begin;
        while (k != length and k != 0 and length > 1) {
            if (k <= length >> 1) {    // 交换 k 个
                for (auto i = 0; i < k; ++i) {
                    std::swap(*(begin + i), *(end - k + i));
                }
                begin = begin + k;
            } else {    // 交换另外 length-k 个
                for (auto i = 0; i < length - k; ++i) {
                    std::swap(*(begin + i), *(end - (length - k) + i));
                }
                end -= length - k;
                k -= length - k;
            }
            length = end - begin;
        }
    }
};