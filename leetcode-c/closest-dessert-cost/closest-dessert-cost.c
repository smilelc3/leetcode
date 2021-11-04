//
// Created by l30014168 on 2021/11/1.
//

#include <limits.h>
#include <stdbool.h>
#include "util.h"

void closeToppings(const int *toppingCosts, int idx, int toppingCostsSize, int curCost, int target, int curMinDiff,
                   int *pCurTarget) {
    if (idx == toppingCostsSize) {      // 搜索完毕
        if (abs(target - curCost) < abs(target - *pCurTarget)) {
            *pCurTarget = curCost;
        }
        if (abs(target - curCost) == abs(target - *pCurTarget)) {
            *pCurTarget = min(*pCurTarget, curCost);
        }
        return;
    }
    if (curCost - target < curMinDiff) { // 剪枝策略
        closeToppings(toppingCosts, idx + 1, toppingCostsSize, curCost, target, curMinDiff, pCurTarget);
        closeToppings(toppingCosts, idx + 1, toppingCostsSize, curCost + toppingCosts[idx], target, curMinDiff,
                      pCurTarget);
        closeToppings(toppingCosts, idx + 1, toppingCostsSize, curCost + toppingCosts[idx] * 2, target, curMinDiff,
                      pCurTarget);

    }
}


int closestCostDFSMethod(const int *baseCosts, int baseCostsSize,
                         const int *toppingCosts, int toppingCostsSize,
                         int target) {
    int closestTarget;
    int minDiff = INT32_MAX;
    int curTarget = INT32_MAX;
    for (int i = 0; i < baseCostsSize; ++i) {
        if (minDiff == 0) {     // 剪枝策略
            break;
        }
        closeToppings(toppingCosts, 0, toppingCostsSize, baseCosts[i], target, minDiff, &curTarget);
        if (abs(target - curTarget) < minDiff) {
            minDiff = abs(target - curTarget);
            closestTarget = curTarget;
        }
        if (abs(target - curTarget) == minDiff) {
            closestTarget = min(closestTarget, curTarget);
        }
    }
    return closestTarget;
}

int closestCostDPMethod(const int *baseCosts, int baseCostsSize,
                        const int *toppingCosts, int toppingCostsSize,
                        int target) {
    int maxBaseCost = baseCosts[0];
    for (int i = 1; i < baseCostsSize; ++i) {
        maxBaseCost = max(maxBaseCost, baseCosts[i]);
    }
    int dpLimit = max(maxBaseCost, target) * 2;
    bool *dp = calloc(1, sizeof(bool) * (dpLimit + 1));
    for (int i = 0; i < baseCostsSize; ++i) {
        dp[baseCosts[i]] = true;
    }

    for (int i = 0; i < toppingCostsSize * 2; ++i) {   // 每种可以重复两次
        for (int j = dpLimit; j > toppingCosts[i % toppingCostsSize]; --j) {
            if (dp[j - toppingCosts[i % toppingCostsSize]] == true) {
                dp[j] = true;
            }
        }
    }

    int minDiff = INT32_MAX, ans = 0;
    for (int i = 1; i <= dpLimit; ++i) {
        if (dp[i] == true && abs(i - target) < minDiff) {
            ans = i;
            minDiff = abs(i - target);
        }
    }

    free(dp);
    return ans;
}

int closestCost(const int *baseCosts, int baseCostsSize,
                const int *toppingCosts, int toppingCostsSize,
                int target) {
    // DFS 方案 时间O(n*3^m)
    return closestCostDFSMethod(baseCosts, baseCostsSize, toppingCosts, toppingCostsSize, target);

    // DP 方案 时间O(2*m*max(maxN, target) * 2)
    // return closestCostDPMethod(baseCosts, baseCostsSize, toppingCosts, toppingCostsSize, target);
}