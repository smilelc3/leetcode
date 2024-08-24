//
// Created by smile on 2024/8/24.
//

#define N_MAX_LOG10 9

const int notRepeatNum10Table[] = {
        9,
        9 * 9,
        9 * 9 * 8,
        9 * 9 * 8 * 7,
        9 * 9 * 8 * 7 * 6,
        9 * 9 * 8 * 7 * 6 * 5,
        9 * 9 * 8 * 7 * 6 * 5 * 4,
        9 * 9 * 8 * 7 * 6 * 5 * 4 * 3,
        9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2,
        9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1};

/*
 * table[0] 表示 1~9 不重复数个数 = C_9^1 =  9
 * table[1] 表示 10 ~ 99 不重复数个数 = C_9^1 * C9^1
 * table[2] 表示 100 ~ 999 不重复数个数 = C_9^1 * C9^1 * C8^1
 * ......
 */

int numDupDigitsAtMostN(int n) {
    int8_t num10[N_MAX_LOG10];
    int tmpN = n;
    int8_t len10 = 0;
    while (tmpN != 0) {
        num10[len10++] = tmpN % 10;
        tmpN /= 10;
    }

    // 第一个数字只能取1~num (num)个
    int notRepeatPart = num10[len10 - 1];
    for (int idx = len10 - 2; idx >= 0; --idx) {
        // 其余数字可以取0~num (num + 1)个，但是要排除i个前面已经取过
        int i = len10 - idx - 1;
        // *= C_{num + 1 -i}^{1}
        if (num10[idx] + 1 - i <= 0) {
            notRepeatPart = 0;  // 找不到不重复数字组合
            break;
        }
        // 组合取乘
        notRepeatPart *= (num10[idx] + 1 - i);
    }

    for (int idx = 0; idx <= len10 - 2; ++idx) {
        n -= notRepeatNum10Table[idx];
    }
    return n - notRepeatPart;
}