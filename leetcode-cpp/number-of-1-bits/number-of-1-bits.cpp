//
// Created by smile on 2021/6/16.
//
class Solution {
public:
    int hammingWeight(uint32_t n) noexcept {
        n -= (n >> 1) & 0x55555555;
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = ((n >> 4) + n) & 0x0F0F0F0F;
        n += n >> 8;
        return (n + (n >> 16)) & 0x3F;        // NOLINT
    }
};