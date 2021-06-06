//
// Created by smile on 2021/6/6.
//
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int> &nums) {
        // time: O(n), space: O(n) 空间不优化
        //return maxProductV1(nums);

        // time: O(n), space: O(1) 空间优化
        return maxProductV2(nums);
    }

    int maxProductV1(std::vector<int> &nums) {
        // 维护：局部最小值localMin[i]和局部最大值localMax[i];  表示以i结尾的子串最值
        // 维护：全局最大值globalMax[i]
        if (nums.empty()) {
            return 0;
        }
        std::vector<int> localMin(nums.size()), localMax(nums.size());
        int globalMax = localMax[0] = localMin[0] = nums[0];
        for (auto idx = 1; idx < nums.size(); idx++) {
            localMax[idx] = std::max(
                    std::max(
                            localMax[idx - 1] * nums[idx],
                            nums[idx]
                    ),
                    localMin[idx - 1] * nums[idx]
            );
            localMin[idx] = std::min(
                    std::min(
                            localMin[idx - 1] * nums[idx],
                            nums[idx]
                    ),
                    localMax[idx - 1] * nums[idx]
            );
            globalMax = std::max(globalMax, localMax[idx]);
        }
        return globalMax;
    }

    int maxProductV2(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int globalMax, localMax, localMin;
        globalMax = localMax = localMin = nums[0];
        for (auto idx = 1; idx < nums.size(); idx++) {
            auto localMaxCopy = localMax;
            localMax = std::max(
                    std::max(
                            localMax * nums[idx],
                            nums[idx]
                    ),
                    localMin * nums[idx]
            );
            localMin = std::min(
                    std::min(
                            localMin * nums[idx],
                            nums[idx]
                    ),
                    localMaxCopy * nums[idx]
            );
            globalMax = std::max(globalMax, localMax);
        }
        return globalMax;
    }
};