//
// Created by smile on 2021/6/14.
//

#include <vector>
#include <array>

class Solution {
public:
    int majorityElement(std::vector<int> &nums) {
        // use bit method. time: O(32n) space: O(1)
        //return bitsMethod(nums);

        // use Majority Vote Algorithm. time: O(n) space: O(1)
        return majorityVoteAlgorithm(nums);
    }

    int bitsMethod(std::vector<int> &nums) {
        int res = 0;
        for (char bit = 0; bit < 32; ++bit) {
            uint32_t bits = 0;
            for (const auto &num: nums) {
                bits += (num >> bit) & 1;
            }
            if (bits * 2 >= nums.size()) {
                res |= 1 << bit;
            }
        }
        return res;
    }

    int majorityVoteAlgorithm(std::vector<int> &nums) {
        int res = 0, votes = 0;
        for (const auto &num: nums) {
            if (votes == 0) {
                res = num;  // 擂台无人时候，设置新上来的队伍就是擂主队伍
            }
            if (num == res) {
                votes++;    // 与擂主队伍同队时，擂台人数加一
            } else {
                votes--;    // 否则，一对一换掉，人数减一
            }
        }
        return res; // 剩下的那队一定是超过半数的队伍
    }
};