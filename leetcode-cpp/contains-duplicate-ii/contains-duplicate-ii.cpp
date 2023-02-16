//
// Created by smile on 2023/2/10.
//

#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(const std::vector<int> &nums, int k) {
        if (k <= 0) {
            return false;
        }
        // return containsNearbyDuplicateWithSortMethod(nums, k);
        return containsNearbyDuplicateWithSlidingWindowMethod(nums, k);
    }

    bool containsNearbyDuplicateWithSortMethod(const std::vector<int> &nums, int k) {
        struct SortNode {
            std::remove_reference_t<decltype(nums)>::value_type num;
            decltype(nums.size()) idx;
        };
        auto sortNode = std::vector<SortNode>(nums.size());
        sortNode.shrink_to_fit();
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            sortNode[idx].num = nums[idx];
            sortNode[idx].idx = idx;
        }
        std::sort(sortNode.begin(), sortNode.end(),
                  [](const SortNode &a, const SortNode &b) {
                      return a.num != b.num ? a.num < b.num : a.idx < b.idx;
                  });
        for (auto iter = sortNode.begin(); iter + 1 != sortNode.end(); ++iter) {
            if ((*iter).num == (*(iter + 1)).num and (*(iter + 1)).idx - (*iter).idx <= k) {
                return true;
            }
        }
        return false;
    }

    bool containsNearbyDuplicateWithSlidingWindowMethod(const std::vector<int> &nums, int k) {
        std::unordered_set<std::remove_reference_t<decltype(nums)>::value_type> winSet; // 滑动窗口集合
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (winSet.find(*it) != winSet.end()) {
                return true;
            }
            if (it >= nums.begin() + k) {
                winSet.erase(*(it - k));
            }
            winSet.insert(*it);
        }
        return false;
    }
};