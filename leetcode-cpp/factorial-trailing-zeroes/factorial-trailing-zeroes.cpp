//
// Created by smile on 2021/6/20.
//

#include <algorithm>

class Solution {
public:
    int trailingZeroes(int n) {
        int fiveNum = 0;
        while (n != 0) {
            n /= 5;
            fiveNum += n;
        }
        return fiveNum;
    }
};