//
// Created by smile on 2021/4/8.
//

#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    static int longestConsecutive(std::vector<int> &nums) {
        // method 1: sort method O(nlog(n))
        //return longestConsecutiveSortMethod(nums);

        // method 2: hashMap method O(n)
        return longestConsecutiveSetMethod(nums);

    }

    static int longestConsecutiveSetMethod(std::vector<int> &nums) {
        int ans = 0;
        auto numsSet = std::unordered_set<int>(nums.begin(), nums.end());

        for (const auto &num : nums) {
            if (numsSet.find(num - 1) != numsSet.end()) {
                continue;
            }
            int curLength = 1, nextNum = num + 1;
            while (numsSet.find(nextNum) != numsSet.end()) {
                curLength++;
                nextNum++;
            }
            ans = std::max(ans, curLength);
        }
        return ans;
    }

    static int longestConsecutiveSortMethod(std::vector<int> &nums) {
        int ans = 0;
        int left = 0, right = 0;
        int repeat;
        std::sort(nums.begin(), nums.end());
        while (right < nums.size()) {
            right++;
            repeat = 0;
            while (right < nums.size()) {
                if (nums[right] == nums[right - 1]) {
                    right++;
                    repeat++;
                    continue;
                }
                if (nums[right] != nums[right - 1] + 1) {
                    break;
                }
                right++;
            }
            ans = std::max(ans, right - left - repeat);
            left = right;
        }
        return ans;
    }

};