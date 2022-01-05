//
// Created by smile on 2022/1/5.
//

#include <vector>
#include "util.h"


class Solution {
public:
    static const auto modVal = 1337;

    // a ^ b = (a * a) ^ (b / 2)
    static int superPow(int a, std::vector<int> &b) {
        if (a == 1) {
            return 1;
        }
        // 模拟快速幂 time:(O(bLen * bLen))
        // return (int) simFastPow(a, b);

        // 分步快速幂
        return (int) splitFastPow(a, b);
    }


    static int64_t simFastPow(int64_t a, std::vector<int> &b) {
        int64_t ans = 1;
        size_t highest = 0;  // 定义当前b最高位所在idx
        while (highest < b.size()) {
            if ((b.back() & 1) == 1) {
                ans = (ans * a) % modVal;
            }
            a = (a * a) % modVal;
            // b = b / 2;.
            bool isPreOdd = false; // 上一位是否是偶数
            for (auto idx = highest; idx < b.size(); idx++) {
                bool isCurOdd = (b[idx] & 1) == 1;
                b[idx] = isPreOdd ? (b[idx] + 10) / 2 : b[idx] / 2;
                isPreOdd = isCurOdd;
            }
            if (b[highest] == 0) {
                highest++;
            }
        }
        return ans;
    }


    static int64_t splitFastPow(int64_t a, std::vector<int> &b) {
        //   a ^ (b0 + b1 * 10 + b2 * 10^2 + ... + bn * 10^n)
        // = a^b0 * a^(b1 * 10) * a^(b2 * 10^2) * ... * a^(bn * 10^n)
        // = a^b0 * (a^10)^b1 * (a^(10^2))^b2 * ... *(a^(10^n))^bn
        int64_t aPow10N = a;
        int64_t ans = 1;
        for (auto bi = b.rbegin(); bi != b.rend(); ++bi) {
            ans = (ans * fastPow(aPow10N, *bi, modVal)) % modVal;
            aPow10N = (aPow10N * 10) % modVal;
        }
        return ans;
    }


};