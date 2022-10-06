//
// Created by smile on 2022/10/6.
//

int arraySign(const int *nums, int numsSize) {
    int ans = 1;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            return 0;
        }
        if (nums[i] < 0) {
            ans *= -1;
        }
    }

    return ans;
}