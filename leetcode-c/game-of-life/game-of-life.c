//
// Created by l30014168 on 2021/9/30.
//

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

int checkCell(int val, int8_t conv) {

    // conv第0~7分别表示左上，上，右上，左，右，左下，下，右下细胞状态（0-死亡，1-存活）
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

    //处理最上和最左

    int8_t conv = 0;
    for (size_t i = 1; i < boardSize - 1; ++i) {
        for (int j = 1; j < *boardColSize - 1; ++j) {
        }
    }

    // 处理最右和最下
}