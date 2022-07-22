//
// Created by smile on 2022/7/22.
//

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    static int firstBadVersion(int n) {
        auto left = 0, right = n;   // left 代表左边界-1，right 代表右边界
        while (true) {
            // 等效于 mid = (left + right) / 2, 避免越界
            auto mid = (left >> 1) + (right >> 1) + (left & 1 & right);
            if (isBadVersion(mid + 1)) {
                if (mid == 0 or not isBadVersion(mid)) {
                    return mid + 1;
                }
                right = mid;
            } else {
                left = mid;
            }
        }
    }
};