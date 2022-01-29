//
// Created by smile on 2022/1/28.
//

class Solution {
public:
    static int rangeBitwiseAnd(int left, int right) {
        while (left < right) {      // 默认 left <= right
            right &= right - 1;
        }
        return right;
    }
};