//
// Created by smile on 2024/7/6.
//

#include <vector>
#include <array>
#include "util.h"

constexpr int MOD = 1'000'000'007;
constexpr int MX = 2001;

// 组合数模板
std::array<int64_t, MX> fac, inv_fac;

// 计算
static auto init = [] {
    fac[0] = 1;
    for (int i = 1; i < MX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[MX - 1] = util::fastPow(fac[MX - 1], MOD - 2, MOD);
    for (int i = MX - 1; i > 0; i--) {
        inv_fac[i - 1] = inv_fac[i] * i % MOD;
    }
    return 0;
}();

class Solution {
public:
    static int valueAfterKSeconds(const int n, const int k) {
        // return valueAfterKSecondsDoubleLoopMethod(n, k);
        return valueAfterKSecondsMathMethod(n, k);
    }

    static int valueAfterKSecondsDoubleLoopMethod(int n, int k) {
        // f(n,k) = f(n-1,k) + f(n,k-1)
        std::vector<int> nArr(n, 1);
        for (decltype(k) iK = 0; iK < k; ++iK) {
            for (decltype(n) iN = 1; iN < n; ++iN) {
                nArr[iN] = (nArr[iN] + nArr[iN - 1]) % MOD;
            }
        }
        return nArr.back();
    }

    static int valueAfterKSecondsMathMethod(const int n, const int k) {
        // ans = C(n+k−1,n−1) = C(n+k−1,k);
        return comb(n + k - 1, k);
    }

private:
    static int comb(const int n, const int k) {
        return static_cast<int>(fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD);
    }
};
