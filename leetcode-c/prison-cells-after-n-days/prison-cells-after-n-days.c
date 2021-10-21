//
// Created by l30014168 on 2021/10/21.
//

#include <stdbool.h>
#include "util.h"

static void transVal(uint8_t *val) {
    *val = ~((*val << 1) ^ (*val >> 1));
    clrBit(*val, 0);
    clrBit(*val, 7);
}

int *prisonAfterNDays(const int *cells, int cellsSize, int n, int *returnSize) {
    uint8_t val = 0;
    *returnSize = 8;
    for (int i = 0; i < 8; ++i) {
        val <<= 1;
        val += cells[i];
    }
    // 必然存在周期
    bool visit[256] = {0};
    uint8_t period = 0;
    for (int i = 0; i < n; ++i) {
        transVal(&val);
        if (visit[val] == true) {
            break;
        }
        period++;
        visit[val] = true;
    }
    if (n != period) {
        n = (n - 1) % period;
        for (int i = 0; i < n; ++i) {
            transVal(&val);
        }
    }

    int *ret = malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < 8; ++i) {
        ret[i] = getBit(val, 7 - i);
    }
    return ret;
}