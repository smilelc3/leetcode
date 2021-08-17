//
// Created by l30014168 on 2021/8/16.
//

// 返回n的最大10次方。如：23->10；99->10；123->100;1000->1000
inline static int getMax10Power(int n) {
    int ret = 1;
    while (n / 10 >= ret) {
        ret *= 10;
    }
    return ret;
}

// 计算所有小于或等于n的非负整数中出现的数字digit的总数。 1 <= digit <= 9
static int countDigit(int n, int digit) {
    if (n < 10) {
        return n >= digit ? 1 : 0;
    }
    int ret = 0;

    int max10Power = getMax10Power(n);
    int highDigit = n / max10Power;
    int remainN = n - highDigit * max10Power;
    // 如果首位 >= digit，叠加
    if (highDigit == digit) {      // 加上剩余 [0, n - highDigit * max10Power]
        ret += remainN + 1;
    } else if (highDigit > digit) {   // 加上完整 [0, max10Power)
        ret += max10Power;
    }

    // 计算除最高位剩余数字
    ret += countDigit(remainN, digit);
    ret += highDigit * countDigit(max10Power - 1, digit);
    return ret;
}


inline static int countDigitOne(int n) {
    return countDigit(n, 1);
}