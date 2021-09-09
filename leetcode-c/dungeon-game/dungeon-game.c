//
// Created by smile on 2021/9/9.
//

#include <stdbool.h>
#include <string.h>
#include "util.h"

int calculateMinimumHPDPMin(int small, int big, int **dungeon, bool isSwap) {
    // small 代表 宽度; big 代表 高度
    // 高度 >= 宽度
    int *dp = malloc(sizeof(int) * small);
    memset(dp, INT32_MAX - 1, small);

    dp[small - 1] = 1;
    for (int i = big - 1; i >= 0; --i) {
        for (int j = small - 1; j >= 0; --j) {
            dp[j] = max(min(dp[j], dp[j + 1]) - (isSwap ? dungeon[j][i] : dungeon[i][j]), 1);
        }
    }

    int ret = dp[0];
    free(dp);
    return ret;
}


int calculateMinimumHP(int **dungeon, int dungeonSize, const int *dungeonColSize) {
    if (dungeonSize == 0 || *dungeonColSize == 0) {
        return 0;
    }
    if (*dungeonColSize >= dungeonSize) {
        return calculateMinimumHPDPMin(dungeonSize, *dungeonColSize, dungeon, false);
    } else {
        return calculateMinimumHPDPMin(*dungeonColSize, dungeonSize, dungeon, true);
    }
}
