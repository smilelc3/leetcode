//
// Created by l30014168 on 2021/9/22.
//

#include <stdbool.h>
#include <limits.h>
#include "util.h"

// 判断数组
inline bool isLessOrEqual(const int *nums, size_t idxA, size_t idxB) {
    return nums[idxA] <= nums[idxB];
}

// 最好情况O(log(n))，最坏情况O(n)
int binarySearch(int *nums, size_t start, size_t end) {
    if (end - start <= 1) {
        return min(nums[start], nums[end]);
    }
    /* 三种情况：
     * @start <= @mid and @mid+1 > @end, 最小值在[mid + 1, end]中；
     * @start > @mid and @mid+1 <= @end, 最小值在[start, mid]中；
     * @start <= @mid and @mid+1 <= @end, 最小值可能在两者之中；
    */
    size_t mid = (start + end) / 2;
    bool isLeftAsc = isLessOrEqual(nums, start, mid);
    bool isRightAsc = isLessOrEqual(nums, mid + 1, end);

    if (isLeftAsc == true && isRightAsc == false) {
        return binarySearch(nums, mid + 1, end);
    } else if (isLeftAsc == false && isRightAsc == true) {
        return binarySearch(nums, start, mid);
    } else if (isLeftAsc == true && isRightAsc == true) {
        return min(binarySearch(nums, start, mid), binarySearch(nums, mid + 1, end));       // 该情况无法判断在那个范围，需要都处理
    } else {
        fprintf(stderr, "branch undefined. \n");
        return INT_MAX;
    }
}


int findMin(int *nums, int numsSize) {
    if (numsSize <= 0) {
        fprintf(stderr, "numSize(%d) must > 0\n", numsSize);
        return INT_MAX;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    return binarySearch(nums, 0, numsSize - 1);
}