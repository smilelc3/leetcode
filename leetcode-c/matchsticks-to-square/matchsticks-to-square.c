//
// Created by smile on 2021/12/16.
//

#include <stdbool.h>
#include <stdlib.h>
#include "util.h"

#define MAX_STICK_NUM 15

typedef struct {
    int *matchsticks;
    int matchsticksSize;
    int edgeLength;
    uint8_t *belongEdge;
} DfsStaticInfo;    // 在 Dfs 中传递的静态信息

bool dfsSolver(DfsStaticInfo *staticInfo, int stickIdx, int EdgeIdx, int curLength) {
    if (stickIdx == staticInfo->matchsticksSize) {      // 如果达到最后，认为已经结束
        return EdgeIdx == 4;        // 返回是否满足4边
    }
    if (curLength == staticInfo->edgeLength) {        // 当前积累边已经被填充满，填充下一条边
        return dfsSolver(staticInfo, 0, EdgeIdx + 1, 0);
    }

    if (staticInfo->belongEdge[stickIdx] != 0) {        // 如果被占用，继续尝试下一个火柴
        return dfsSolver(staticInfo, stickIdx + 1, EdgeIdx, curLength);
    }

    if (curLength + staticInfo->matchsticks[stickIdx] <= staticInfo->edgeLength) { // 如果当前火柴可以加入
        staticInfo->belongEdge[stickIdx] = EdgeIdx;     // 加入并计算下一个
        if (dfsSolver(staticInfo, stickIdx + 1, EdgeIdx, curLength + staticInfo->matchsticks[stickIdx])) {
            return true;    // 如果加入能找到解，直接返回true
        }
        staticInfo->belongEdge[stickIdx] = 0;   // 恢复未占用
    }
    // 当前边放不下或则不放入，继续尝试下一个火柴
    return dfsSolver(staticInfo, stickIdx + 1, EdgeIdx, curLength);
}

bool makesquare(int *matchsticks, int matchsticksSize) {
    int64_t sum = 0;
    for (int i = 0; i < matchsticksSize; ++i) {
        sum += matchsticks[i];
    }
    if ((sum & 3) != 0) {       // 总和不能被4整除
        return false;
    }
    int edgeLength = (int) (sum / 4);

    qsort(matchsticks, matchsticksSize, sizeof(int), intDescCmpFunc);

    if (matchsticks[0] > edgeLength) {
        return false;
    }
    uint8_t belongEdge[MAX_STICK_NUM] = {0};        // 归属边，未归属为0
    DfsStaticInfo dfsStaticInfo = {matchsticks, matchsticksSize, edgeLength, belongEdge};
    return dfsSolver(&dfsStaticInfo, 0, 1, 0);
}