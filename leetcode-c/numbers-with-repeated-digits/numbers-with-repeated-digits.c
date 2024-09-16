//
// Created by smile on 2024/8/24.
//

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"

#define N_MAX_LOG10 10

/*
 * table[0] 表示 1~9 不重复数个数 = C_9^1 =  9
 * table[1] 表示 10 ~ 99 不重复数个数 = C_9^1 * C9^1
 * table[2] 表示 100 ~ 999 不重复数个数 = C_9^1 * C9^1 * C8^1
 * ......
 */
const int notRepeatNum10Table[] = {
    9,             // [1, 9]
    9 * 9,         // [10, 99]
    9 * 9 * 8,     // [100, 999]
    9 * 9 * 8 * 7, // [1000, 9999]
    9 * 9 * 8 * 7 * 6,
    9 * 9 * 8 * 7 * 6 * 5,
    9 * 9 * 8 * 7 * 6 * 5 * 4,
    9 * 9 * 8 * 7 * 6 * 5 * 4 * 3,
    9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2,
    9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1};

int numDupDigitsAtMostN(int n) {
    if (n <= 9) { // 个位数无法融入当前流程
        return 0;
    }
    int8_t num10[N_MAX_LOG10 + 1];
    int tmpN = n;
    int8_t len10 = 0;
    while (tmpN != 0) {
        num10[len10++] = tmpN % 10;
        tmpN /= 10;
    }
    int notRepeatPart = 0;
    // 第一个数字只能取1~num (num)个
    for (int8_t i = 0; i < len10 - 1; ++i) {
        notRepeatPart += notRepeatNum10Table[i];
    }

    // 开始计算中间数据
    bool suffixExist[10] = {0}; // 前缀是否出现过
    int8_t curIdx = len10 - 1;
    while (curIdx >= 0) {
        int8_t curNum = num10[curIdx];
        int8_t suffixRepTot = 0;
        if (curIdx < len10 - 1) {
            // 当前数字要取 0 ~ n-1, 如果是末尾还需+1取上本身, 判重
            for (int8_t i = 0; i <= (curIdx == 0 ? curNum : curNum - 1); i++) {
                if (suffixExist[i] == true) {
                    suffixRepTot++;
                }
            }
        }
        int curComb;
        if (curIdx == len10 - 1) {
            curComb = curNum - 1; // 1 ~ n-1
        } else if (curIdx == 0) {
            curComb = max(curNum + 1 - suffixRepTot, 0); // 末尾数字取 // 0 ~ n - 重复
        } else {
            curComb = max(curNum - suffixRepTot, 0); // 中间数字 0 ~ n-1 - 重复
        }
        if (curComb > 0) {
            for (int8_t i = curIdx - 1; i >= 0; --i) {
                curComb *= 10 - (len10 - 1 - i);
            }
            notRepeatPart += curComb;
        }

        if (suffixExist[curNum] == true) {
            break; // 前面处理的数字已有重复，退出
        }
        suffixExist[curNum] = true;
        curIdx--;
    }

    return n - notRepeatPart;
}