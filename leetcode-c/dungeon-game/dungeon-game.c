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
    dp[small - 1] = max(1 - (isSwap ? dungeon[small - 1][big - 1] : dungeon[big - 1][small - 1]),
                        1);     // 终点所需要的最小生命值


    // 初始化最下行
    for (int j = small - 2; j >= 0; --j) {
        dp[j] = max(dp[j + 1] - (isSwap ? dungeon[j][big - 1] : dungeon[big - 1][j]), 1);
    }
    // 从右下角向左上角DP
    for (int i = big - 2; i >= 0; --i) {
        dp[small - 1] = max(dp[small - 1] - (isSwap ? dungeon[small - 1][i] : dungeon[i][small - 1]), 1);
        for (int j = small - 2; j >= 0; --j) {
            dp[j] = max(min(dp[j], dp[j + 1]) - (isSwap ? dungeon[j][i] : dungeon[i][j]),
                        1);
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
    if (*dungeonColSize <= dungeonSize) {
        return calculateMinimumHPDPMin(*dungeonColSize, dungeonSize, dungeon, false);
    } else {
        return calculateMinimumHPDPMin(dungeonSize, *dungeonColSize, dungeon, true);
    }
}
