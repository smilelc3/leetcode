//
// Created by smile on 2023/10/12.
//
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int freq;
    int val;
} FreqVal;

#define MIN_NUM (-100)
#define MAX_NUM 100

// int升序比较函数
static inline int freqValCmpFunc(const void *a, const void *b) {
    const FreqVal *freqValA = a;
    const FreqVal *freqValB = b;
    if (freqValA->freq != freqValB->freq) {
        return freqValA->freq - freqValB->freq;
    }
    return freqValB->val - freqValA->val;

}

int *frequencySort(const int *nums, int numsSize, int *returnSize) {
    int bucket[MAX_NUM - MIN_NUM + 1] = {0};
    for (int idx = 0; idx < numsSize; ++idx) {
        bucket[nums[idx] - MIN_NUM]++;
    }

    FreqVal *freqValArr = malloc(sizeof(FreqVal) * numsSize);
    int freqValArrSize = 0;
    for (int idx = 0; idx <= MAX_NUM - MIN_NUM; ++idx) {
        if (bucket[idx] != 0) {
            freqValArr[freqValArrSize].val = idx + MIN_NUM;
            freqValArr[freqValArrSize].freq = bucket[idx];
            freqValArrSize++;
        }
    }

    qsort(freqValArr, freqValArrSize, sizeof(FreqVal), freqValCmpFunc);
    int *ans = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int idx = 0; idx < freqValArrSize; ++idx) {
        for (int time = 0; time < freqValArr[idx].freq; ++time) {
            ans[*returnSize] = freqValArr[idx].val;
            (*returnSize)++;
        }
    }

    free(freqValArr);
    return ans;
}