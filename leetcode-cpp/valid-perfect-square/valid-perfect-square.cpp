//
// Created by smile on 2023/4/15.
//

#include <cstdint>
#include <climits>
#include "util.h"

class Solution {
public:
    static bool isPerfectSquare(int num) {
        uint32_t left = 1;
        uint32_t right = 1 << (sizeof(num) * CHAR_BIT / 2);
        while (left + 1 != right) {
            auto mid = (left + right) / 2;
            auto midSquare = util::square(mid);
            if (midSquare == num) {
                return true;
            }
            if (midSquare < num) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return util::square(left) == num;
    }

};