//
// Created by l30014168 on 2021/7/13.
//

#include <stdlib.h>

// 按照右侧边界排序
int cmpIntervals(const void *a, const void *b) {
    return (*(int **) a)[1] - (*(int **) b)[1];
}

/*
 * eraseOverlapIntervals 函数
 * 参数：
 *     int **intervals      二维数组
 *     int intervalsSize    数组行数
 *     const int *intervalsColSize  数组列数
 *
 */
int eraseOverlapIntervals(int **intervals, int intervalsSize, const int *intervalsColSize) {
    if (intervalsSize == 0) {
        return 0;
    }

    qsort(intervals, intervalsSize, sizeof(int *), cmpIntervals);

    // 贪心策略，找出其中与首个区间不重合并且右端点最小的区间
    int right = intervals[0][1];
    int nonOverNum = 1;
    for (int i = 1; i < intervalsSize; ++i) {
        if (intervals[i][0] >= right) {
            nonOverNum++;
            right = intervals[i][1];
        }
    }
    return intervalsSize - nonOverNum;
}