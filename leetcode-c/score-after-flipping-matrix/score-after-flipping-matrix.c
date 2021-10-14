//
// Created by l30014168 on 2021/10/14.
//

void reverseRow(int **grid, int row, size_t rowSize) {
    for (size_t j = 0; j < rowSize; ++j) {
        grid[row][j] = !grid[row][j];
    }
}

void reverseCol(int **grid, int col, size_t colSize) {
    for (size_t i = 0; i < colSize; ++i) {
        grid[i][col] = !grid[i][col];
    }
}

int matrixScore(int **grid, int gridSize, const int *gridColSize) {
    for (int i = 0; i < gridSize; ++i) {
        if (grid[i][0] == 0) {
            reverseRow(grid, i, *gridColSize);
        }
    }
    for (int j = 0; j < *gridColSize; ++j) {
        int numOf1 = 0;
        for (int i = 0; i < gridSize; ++i) {
            if (grid[i][j] == 1) {
                numOf1++;
            }
        }
        if (numOf1 * 2 < gridSize) {
            reverseCol(grid, j, gridSize);
        }
    }

    int sum = 0;
    for (int i = 0; i < gridSize; ++i) {
        int val = 0;
        for (int j = 0; j < *gridColSize; ++j) {
            val = (val << 1) + grid[i][j];
        }
        sum += val;
    }
    return sum;
}