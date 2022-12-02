//
// Created by smile on 2022/12/2.
//

class Solution {
public:
    static int singleNonDuplicate(const std::vector<int> &nums) {
        auto left = nums.begin();
        auto right = nums.end();
        while (left + 1 != right) {
            auto mid = left + (std::distance(left, right)) / 2;
            if ((std::distance(left, mid) & 1) == 0) {  // 偶数间隔
                if (*mid == *(mid + 1)) {
                    left = mid + 2;
                } else {
                    right = mid + 1;
                }
            } else {    // 奇数间隔
                if (*mid == *(mid + 1)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return *left;
    }
};