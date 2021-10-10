//
// Created by smile on 2021/10/10.
//

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"

#define VAL_MAX 10000

typedef struct {
    bool exist[VAL_MAX + 3];
    int minVal, maxVal;
    int **sum;
    int sumSize;
    int *sumColSize;
} SummaryRanges;


SummaryRanges *summaryRangesCreate() {
    SummaryRanges *obj = malloc(sizeof(SummaryRanges));
    memset(obj->exist, false, sizeof(obj->exist));

    obj->minVal = VAL_MAX + 1;
    obj->maxVal = -1;

    obj->sum = malloc(sizeof(int *) * VAL_MAX);
    for (int i = 0; i < VAL_MAX; ++i) {
        obj->sum[i] = malloc(sizeof(int) * 2);
    }
    obj->sumSize = 0;
    obj->sumColSize = malloc(sizeof(int) * VAL_MAX);
    return obj;
}

void summaryRangesAddNum(SummaryRanges *obj, int val) {
    obj->maxVal = max(obj->maxVal, val);
    obj->minVal = min(obj->minVal, val);
    obj->exist[val + 1] = true;     // 做一下偏移1，便于后续判断
}

int **summaryRangesGetIntervals(SummaryRanges *obj, int *retSize, int **retColSize) {
    int left, right;
    obj->sumSize = 0;
    for (int i = obj->minVal + 1; i <= obj->maxVal + 2; ++i) {
        if (obj->exist[i] == true) {
            if (obj->exist[i - 1] == false) {
                left = right = i - 1;
            } else {
                right = i - 1;
            }
        } else {
            if (obj->exist[i - 1] == true) {
                obj->sum[obj->sumSize][0] = left;
                obj->sum[obj->sumSize][1] = right;
                obj->sumColSize[obj->sumSize] = 2;
                obj->sumSize++;
            }
        }
    }
    *retSize = obj->sumSize;
    *retColSize = obj->sumColSize;
    return obj->sum;
}

void summaryRangesFree(SummaryRanges *obj) {
    for (int i = 0; i < VAL_MAX; ++i) {
        free(obj->sum[i]);
    }
    free(obj->sum);
    free(obj->sumColSize);
    free(obj);
}