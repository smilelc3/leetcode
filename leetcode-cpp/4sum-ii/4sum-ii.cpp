//
// Created by smile on 2023/6/6.
//

#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>

class Solution {
public:
    static int fourSumCount(const std::vector<int> &nums1, const std::vector<int> &nums2,
                            const std::vector<int> &nums3, const std::vector<int> &nums4) {

        
        // return fourSumCountSortMethod(nums1, nums2, nums3, nums4);
        return fourSumCountHashTableMethod(nums1, nums2, nums3, nums4);
    }

    static int fourSumCountSortMethod(const std::vector<int> &nums1, const std::vector<int> &nums2,
                                      const std::vector<int> &nums3, const std::vector<int> &nums4) {
        // a + b = -(c + d)
        int ans = 0;
        std::vector<std::pair<int, int>> nums12;
        for (auto &num1: nums1) {
            for (auto &num2: nums2) {
                nums12.emplace_back(num1 + num2, 1);
            }
        }
        decltype(nums12) nums34;
        for (auto &num3: nums3) {
            for (auto &num4: nums4) {
                nums34.emplace_back(-(num3 + num4), 1);
            }
        }
        auto pairFirstLessCmp = [](decltype(nums12.front()) a, decltype(a) b) {
            return a.first < b.first;
        };
        std::sort(nums12.begin(), nums12.end(), pairFirstLessCmp);
        std::sort(nums34.begin(), nums34.end(), pairFirstLessCmp);

        mergeSameVal(nums12);
        mergeSameVal(nums34);

        auto nums12Iter = nums12.begin();
        auto nums34Iter = nums34.begin();

        while (nums12Iter != nums12.end() and nums34Iter != nums34.end()) {
            if (nums12Iter->first < nums34Iter->first) {
                nums12Iter++;
            } else if (nums12Iter->first > nums34Iter->first) {
                nums34Iter++;
            } else { // 相等
                ans += nums12Iter->second * nums34Iter->second;
                nums12Iter++;
            }
        }
        return ans;
    }

    static int fourSumCountHashTableMethod(const std::vector<int> &nums1, const std::vector<int> &nums2,
                                           const std::vector<int> &nums3, const std::vector<int> &nums4) {
        std::unordered_map<int, int> num1AddNum2Map;
        int ans = 0;
        for (auto &num1: nums1) {
            for (auto &num2: nums2) {
                auto iter = num1AddNum2Map.find(num1 + num2);
                if (iter != num1AddNum2Map.end()) {
                    iter->second++;
                } else {
                    num1AddNum2Map.emplace(num1 + num2, 1);
                }

            }
        }

        for (auto &num3: nums3) {
            for (auto &num4: nums4) {
                auto iter = num1AddNum2Map.find(-(num3 + num4));
                if (iter != num1AddNum2Map.end()) {
                    ans += iter->second;
                }
            }
        }
        return ans;
    }

private:
    static void mergeSameVal(std::vector<std::pair<int, int>> &nums) {
        auto onlyIter = nums.begin();
        auto iter = nums.begin() + 1;
        while (iter < nums.end()) {
            if (onlyIter->first == iter->first) {
                onlyIter->second++;
                iter++;
            } else {
                onlyIter++;
                *onlyIter = *iter;
                iter++;
            }
        }
        nums.resize(std::distance(nums.begin(), onlyIter + 1));
    }
};