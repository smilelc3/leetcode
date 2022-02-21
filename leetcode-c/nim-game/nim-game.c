//
// Created by smile on 2022/2/21.
//

#include <stdbool.h>

// 1-3块，总是我赢
// 4块，我拿完，对手必赢
// 大于4块，总有方案使数量回归到4的倍数
bool canWinNim(int n) {
    return n % 4 != 0;
}