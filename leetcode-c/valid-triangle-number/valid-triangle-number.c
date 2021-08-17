//
// Created by l30014168 on 2021/8/5.
//

#include <stdlib.h>

static inline int AscCmpFun(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

static int triangleNumber(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), AscCmpFun);
    // 三角形第三边小于两边之和，大于两边之差
    // 先查找 第三边（最大边）c
    // 已升序排序
    // 另外两边 a,b 必须满足: a + b > c即可 (a < b < c)
    // 双指针加速
    int ret = 0;
    for (int edgeCIdx = 2; edgeCIdx < numsSize; ++edgeCIdx) {
        int edgeAIdx = 0, edgeBIdx = edgeCIdx - 1;          // 已定位第三条边
        while (edgeAIdx < edgeBIdx) {
            if (nums[edgeAIdx] > nums[edgeCIdx] - nums[edgeBIdx]) {
                ret += edgeBIdx - edgeAIdx;
                edgeBIdx--;         // 当前a + b > c, 计算 b,c 确定，a的可能性，并减少b
            } else {
                edgeAIdx++;         // 当前a + b <= c, 增大a
            }
        }
    }
    return ret;
}