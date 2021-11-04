//
// Created by smile on 2021/11/3.
//

#include <stdlib.h>
#include <string.h>
#include "util.h"

void fillZeroConnectedComponent(int **grid, int gridSize, const int *gridColSize, int x, int y,
                                int targetColor) {
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= gridSize || ty < 0 || ty >= gridColSize[tx]) {
            continue;
        }
        if (grid[tx][ty] == targetColor) {
            grid[tx][ty] = 0;
            fillZeroConnectedComponent(grid, gridSize, gridColSize, tx, ty, targetColor);
        }
    }
}

int **colorBorder(int **grid, int gridSize, int *gridColSize, int row, int col, int color, int *returnSize,
                  int **returnColumnSizes) {
    int targetColor = grid[row][col];
    *returnSize = gridSize;
    *returnColumnSizes = malloc(sizeof(int) * gridSize);
    memcpy(*returnColumnSizes, gridColSize, sizeof(int) * gridSize);

    int **ans = malloc(sizeof(int *) * gridSize);
    for (size_t idx = 0; idx < gridSize; ++idx) {
        ans[idx] = malloc(sizeof(int) * gridColSize[idx]);
        memcpy(ans[idx], grid[idx], sizeof(int) * gridColSize[idx]);
    }

    grid[row][col] = 0;
    fillZeroConnectedComponent(grid, gridSize, gridColSize, row, col, targetColor);

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[i]; ++j) {
            if (grid[i][j] != 0) {
                continue;
            }
            uint8_t sameNeighNum = 0;
            for (int t = 0; t < 4; ++t) {
                int tx = i + dx[t];
                int ty = j + dy[t];
                if (tx < 0 || tx >= gridSize || ty < 0 || ty >= gridColSize[tx]) {
                    continue;
                }
                if (grid[tx][ty] == 0) {
                    sameNeighNum++;
                }
            }
            if (sameNeighNum == 4) {     // 非边缘点
                ans[i][j] = targetColor;
            } else {
                ans[i][j] = color;
            }
        }
    }
    return ans;
}