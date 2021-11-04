//
// Created by l30014168 on 2021/9/30.
//

#include <stdbool.h>
#include "util.h"

#define DEAD 0
#define ALIVE 1

static inline bool isCellAlive(int **board, int x, int y, int row, int col) {
    if (x < 0 || y < 0 || x >= row || y >= col) {
        return false;
    }
    return board[x][y] & 1;
}

void gameOfLife(int **board, int boardSize, const int *boardColSize) {
    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < *boardColSize; ++y) {
            // 将结果保存在第二位
            uint8_t nbrAliveCnt = 0;
            for (int i = 0; i < 8; ++i) {
                if (isCellAlive(board, x + dx[i], y + dy[i], boardSize, *boardColSize) == true) {
                    nbrAliveCnt++;
                }
            }
            // 下一次存活的情况
            if ((board[x][y] == ALIVE && nbrAliveCnt >= 2 && nbrAliveCnt <= 3) ||
                (board[x][y] == DEAD && nbrAliveCnt == 3)) {
                board[x][y] += 2;   // 第二位为 1-ALIVE
            }

        }
    }
    for (size_t i = 0; i < boardSize; ++i) {
        for (size_t j = 0; j < *boardColSize; ++j) {
            board[i][j] >>= 1;  // 替换为新结果
        }
    }
}