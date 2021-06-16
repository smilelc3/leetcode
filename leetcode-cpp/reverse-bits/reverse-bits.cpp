//
// Created by smile on 2021/6/16.
//

class Solution {
public:
    static uint32_t reverseBits(uint32_t n) {
        n = (n & 0x55555555) << 1 | (n >> 1) & 0x55555555;
        n = (n & 0x33333333) << 2 | (n >> 2) & 0x33333333;
        n = (n & 0x0F0F0F0F) << 4 | (n >> 4) & 0x0F0F0F0F;
        n = (n << 24) | ((n & 0xFF00) << 8) | ((n >> 8) & 0xFF00) | (n >> 24);
        return n;
    }
};