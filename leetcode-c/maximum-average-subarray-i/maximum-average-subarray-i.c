//
// Created by l30014168 on 2021/12/15.
//

double findMaxAverage(const int *nums, int numsSize, int k) {
    int64_t winSum = 0;
    for (int i = 0; i < k; ++i) {
        winSum += nums[i];
    }
    int64_t maxWinSum = winSum;

    for (int i = k; i < numsSize; ++i) {
        winSum += nums[i] - nums[i - k];
        if (winSum > maxWinSum) {
            maxWinSum = winSum;
        }
    }
    return (double) maxWinSum / k;
}