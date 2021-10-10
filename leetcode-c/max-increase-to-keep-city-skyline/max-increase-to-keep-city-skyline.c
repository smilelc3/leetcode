//
// Created by l30014168 on 2021/10/9.
//

#include "util.h"

int maxIncreaseKeepingSkyline(int **grid, int gridSize, const int *gridColSize) {
    int *rowMax = calloc(1, sizeof(int) * gridSize);               // i行最大值
    int *colMax = calloc(1, sizeof(int) * (*gridColSize));         // j列最大值

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            rowMax[i] = max(rowMax[i], grid[i][j]);
            colMax[j] = max(colMax[j], grid[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            sum += min(rowMax[i], colMax[j]) - grid[i][j];
        }
    }

    free(rowMax);
    free(colMax);
    return sum;
}