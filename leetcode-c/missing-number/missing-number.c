//
// Created by smile on 24-7-10.
//

int missingNumber(int *nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return (1 + numsSize) * numsSize / 2 - sum;
}
