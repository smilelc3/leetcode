//
// Created by l30014168 on 2021/9/16.
//

int *singleNumber(const int *nums, int numsSize, int *returnSize) {
    int *ret = calloc(1, sizeof(int) * 2);
    if (ret == NULL) {
        fprintf(stderr, "calloc fail.\n");
        return NULL;
    }
    *returnSize = 2;

    uint32_t xorNum = 0;
    for (int idx = 0; idx < numsSize; idx++) {
        xorNum ^= nums[idx];
    }
    uint32_t mask = xorNum & (~xorNum + 1);          // 最低非0位掩码
    for (int idx = 0; idx < numsSize; ++idx) {
        if ((nums[idx] & mask) == 0) {      // mask代表该位不同，也就是所有数在该位按照0/1分组，各组数均为奇数
            ret[0] ^= nums[idx];            // 对两组数，分别与或计算，得到不同数
        } else {
            ret[1] ^= nums[idx];
        }
    }
    return ret;
}