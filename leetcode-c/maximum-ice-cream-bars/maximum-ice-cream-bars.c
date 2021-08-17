//
// Created by l30014168 on 2021/7/26.
//

#include <stdlib.h>
#include <util.h>

static inline int cmpFunc(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

static int maxIceCreamQuickSort(int *costs, const int costsSize, int coins) {
    qsort(costs, costsSize, sizeof(int), cmpFunc);
    int ret = 0;
    // every cost >= 1
    for (int idx = 0; idx < costsSize; idx++) {
        if (coins >= costs[idx]) {
            coins -= costs[idx];
            ret++;
        } else {
            break;      // left cost must > coins
        }
    }
    return ret;
}

static int maxIceCreamBucketSort(const int *costs, const int costsSize, int coins) {
    if (costsSize == 0) {
        return 0;
    }
    int minCost = costs[0], maxCost = costs[0];
    for (int idx = 0; idx < costsSize; idx++) {
        minCost = min(minCost, costs[idx]);
        maxCost = max(maxCost, costs[idx]);
    }
    int *bucket = calloc((maxCost - minCost + 1), sizeof(int));
    if (bucket == NULL) {
        perror("calloc fail!");
        return 0;
    }

    for (int idx = 0; idx < costsSize; idx++) {
        bucket[costs[idx] - minCost]++;
    }
    int ret = 0;
    for (int cost = minCost; cost <= maxCost; cost++) {
        // 当前cost个数量 bucket[cost]
        if (bucket[cost - minCost] > 0) {
            if ((int64_t) bucket[cost - minCost] * cost <= (int64_t) coins) {
                ret += bucket[cost - minCost];
                coins -= bucket[cost - minCost] * cost;
            } else {    // 已经不能完全购买
                ret += coins / cost;
                break;
            }
        }
    }
    free(bucket);
    return ret;
}

static int maxIceCream(int *costs, const int costsSize, int coins) {
    // qsort 方法
//    return maxIceCreamQuickSort(costs, costsSize, coins);

    // Bucket Sort
    return maxIceCreamBucketSort(costs, costsSize, coins);
}


