//
// Created by l30014168 on 2021/11/23.
//

#define MAX_BARCODE 10000

int *rearrangeBarcodes(const int *barcodes, int barcodesSize, int *returnSize) {
    uint16_t *cnt = calloc(1, sizeof(uint16_t) * (MAX_BARCODE + 1));
    uint16_t *val = malloc(sizeof(uint16_t) * MAX_BARCODE);
    uint16_t valSize = 0;

    int *ans = malloc(sizeof(int) * barcodesSize);
    *returnSize = barcodesSize;
    int maxCnt = 0, maxCntVal = 0;      // 最大重复次数，最大重复次数对应的值
    for (int i = 0; i < barcodesSize; ++i) {
        if (cnt[barcodes[i]] == 0) {
            val[valSize] = barcodes[i];
            valSize++;
        }
        cnt[barcodes[i]]++;
        if (cnt[barcodes[i]] > maxCnt) {
            maxCnt = cnt[barcodes[i]];
            maxCntVal = barcodes[i];
        }
    }

    // 先排最大次数的值到偶下标
    for (int idx = 0; idx < maxCnt * 2; idx += 2) {
        ans[idx] = maxCntVal;
    }
    cnt[maxCntVal] = 0;

    // 接着偶下标排满
    for (int idx = maxCnt * 2; idx < barcodesSize; idx += 2) {
        while (cnt[val[valSize - 1]] == 0) {
            valSize--;
        }
        ans[idx] = val[valSize - 1];
        cnt[val[valSize - 1]]--;
    }

    // 奇下标排满
    for (int idx = 1; idx < barcodesSize; idx += 2) {
        while (cnt[val[valSize - 1]] == 0) {
            valSize--;
        }
        ans[idx] = val[valSize - 1];
        cnt[val[valSize - 1]]--;
    }

    free(cnt);
    free(val);
    return ans;
}