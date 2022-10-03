//
// Created by smile on 2022/10/3.
//

class Solution {
public:
    static int totalMoney(int n) {
        // 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
        // ans = nWeek * 28 + 7 * (0 + 1 + 2 + ... + nWeek - 1) + nWeek * mod + (1 + 2 + ... + mod)
        auto divRet = std::div(n, 7);

        return divRet.quot * 28 +
               7 * ((divRet.quot - 1) * divRet.quot) / 2 +
               divRet.quot * divRet.rem + ((divRet.rem + 1) * divRet.rem) / 2;

    }
};