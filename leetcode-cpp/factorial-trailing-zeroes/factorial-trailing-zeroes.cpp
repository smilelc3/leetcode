//
// Created by smile on 2021/6/20.
//

class Solution {
public:
    constexpr int trailingZeroes(int n) {
        // max n = 10000
        return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125;
    }
};