//
// Created by smile on 2021/10/29.
//

#include "util.h"

static inline int getNumOf15Min(int startHour, int startMin, int endHour, int endMin) {
    // n 除以 m 向上取整 === (n + m - 1) / m
    return max(0, (endHour - startHour) * 4 + endMin / 15 - ((startMin + 14) / 15));
}

int numberOfRounds(const char *startTime, const char *finishTime) {
    uint8_t startHH = (startTime[0] - '0') * 10 + startTime[1] - '0';
    uint8_t startMM = (startTime[3] - '0') * 10 + startTime[4] - '0';
    uint8_t finishHH = (finishTime[0] - '0') * 10 + finishTime[1] - '0';
    uint8_t finishMM = (finishTime[3] - '0') * 10 + finishTime[4] - '0';

    int ans;
    if (startHH > finishHH || (startHH == finishHH && startMM > finishMM)) {   // 存在通宵
        finishHH += 24;
    }
    ans = getNumOf15Min(startHH, startMM, finishHH, finishMM);
    return ans;
}