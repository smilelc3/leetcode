//
// Created by smile on 2022/3/15.
//

#include <string>
#include <array>
#include <algorithm>

class Solution {
public:
    static bool isAnagram(const std::string &s, const std::string &t) {
        std::array<uint32_t, 26> nums{};
        if (s.size() != t.size()) {
            return false;
        }
        for (const auto &ch: s) {
            nums[ch - 'a']++;
        }
        for (const auto &ch: t) {
            if (nums[ch - 'a'] == 0) {
                return false;
            }
            nums[ch - 'a']--;
        }
        return std::all_of(nums.begin(), nums.end(), [](auto num) { return num == 0; });
    }
};