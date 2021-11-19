//
// Created by l30014168 on 2021/7/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int nthUglyNumber(int n) {
    if( n <= 0) {
        perror("n must > 0");
        return 0;
    }
    // t是丑数 是 2t,3t,5t是丑数 的充分必要条件
    int *dp = malloc(sizeof(int) * n);
    dp[0] = 1;
    int idx2 = 0, idx3 = 0, idx5 = 0;
    for (int idx = 1; idx < n; idx++) {
        int num2 = dp[idx2] * 2, num3 = dp[idx3] * 3, num5 = dp[idx5] * 5;
        dp[idx] = min(min(num2, num3), num5);
        if (dp[idx] == num2) {
            idx2++;
        }
        if (dp[idx] == num3) {
            idx3++;
        }
        if (dp[idx] == num5) {
            idx5++;
        }
    }
    int res = dp[n-1];
    free(dp);
    dp = NULL;
    return res;
}