//
// Created by l30014168 on 2021/9/30.
//

#include <stdbool.h>

#define DEAD 0
#define ALIVE 1

uint8_t popByte(uint8_t x) {
    uint8_t n = 0;
    while (x != 0) {
        x = x & (x - 1);
        n++;
    }
    return n;
}

inline void byteSetzBit(uint8_t *pByte, uint8_t idx, bool val) {
    if (val == true) {
        *pByte |= 1 << idx;
    } else {
        *pByte &= ~(1 << idx);
    }
}

int checkCell(int8_t conv) {
    // conv第0~7分别表示左上，上，右上，左，右，左下，下，右下细胞状态（0-死亡，1-存活）
    // +---+---+---+
    // | 0 | 1 | 2 |
    // +---+---+---+
    // | 3 |   | 4 |
    // +---+---+---+
    // | 5 | 6 | 7 |
    // +---+---+---+
    uint8_t nbrNum = popByte(conv);
    if (nbrNum < 2) {
        return DEAD;
    }
    if (nbrNum <= 3) {
        return ALIVE;
    }
    return DEAD;
}

void gameOfLife(int **board, int boardSize, const int *boardColSize) {
    uint8_t conv = 0;
    byteSetzBit(&conv, 4, (bool)board[0][1]);
    byteSetzBit(&conv, 6, (bool)board[1][0]);
    byteSetzBit(&conv, 7, (bool)board[1][1]);
    //处理最上和最左
    for (size_t j = 0; j <; ++j) {

    }

    for (size_t i = 1; i < boardSize - 1; ++i) {
        for (size_t j = 1; j < *boardColSize - 1; ++j) {
        }
    }

    // 处理最右和最下
}