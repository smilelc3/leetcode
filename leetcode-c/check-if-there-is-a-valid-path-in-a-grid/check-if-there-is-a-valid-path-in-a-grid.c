//
// Created by smile on 2022/12/14.
//

#include <stdbool.h>
#include "util.h"

// Cell 定义
typedef enum {
    CELL_UNDEFINED = 0,
    LEFT_TO_RIGHT = 1,
    UPPER_TO_LOWER,
    LEFT_TO_LOWER,
    RIGHT_TO_LOWER,
    LEFT_TO_UPPER,
    RIGHT_TO_UPPER,
    CELL_INVALID
} CELL;

// 下一次移动定义
typedef enum {
    MOVE_UPPER,
    MOVE_RIGHT,
    MOVE_LOWER,
    MOVE_LEFT,
    MOVE_NULL // 该值定义为无效
} MOVE;

// next_move = nextMoveTransTable[cur_cell][prev_move]
const MOVE nextMoveTransTable[CELL_INVALID][MOVE_NULL] = {
        {MOVE_NULL,  MOVE_NULL,  MOVE_NULL,  MOVE_NULL},   // CELL_UNDEFINED = 0
        {MOVE_NULL,  MOVE_RIGHT, MOVE_NULL,  MOVE_LEFT},  // LEFT_TO_RIGHT  = 1
        {MOVE_UPPER, MOVE_NULL,  MOVE_LOWER, MOVE_NULL},  // UPPER_TO_LOWER = 2
        {MOVE_LEFT,  MOVE_LOWER, MOVE_NULL,  MOVE_NULL},  // LEFT_TO_LOWER  = 3
        {MOVE_RIGHT, MOVE_NULL,  MOVE_NULL,  MOVE_LOWER},  // RIGHT_TO_LOWER = 4
        {MOVE_NULL,  MOVE_UPPER, MOVE_LEFT,  MOVE_NULL},  // LEFT_TO_UPPER = 5
        {MOVE_NULL,  MOVE_NULL,  MOVE_RIGHT, MOVE_UPPER},  // RIGHT_TO_UPPER = 6
};

typedef struct {
    int **grid;
    int rowSize;
    int *colSize;
} Grid;

// 判断是否存在起点开始的环路
static bool isExistCircle = false;

// 遍历函数
bool isExistValidPath(int row, int col, MOVE pre_move, const Grid *gridInfo) {
    // 越界
    while (row >= 0 && col >= 0 && row < gridInfo->rowSize && col < gridInfo->colSize[row]) {
        // 再次到达起点，存在环
        if (row == 0 && col == 0) {
            isExistCircle = true;
            return false;
        }
        // 到达终点
        if (row == gridInfo->rowSize - 1 && col == gridInfo->colSize[gridInfo->rowSize - 1] - 1) {
            CELL cell = gridInfo->grid[row][col];
            switch (pre_move) { // 只可能往下走或往右走到右下角
                case MOVE_LOWER:
                    return cell == UPPER_TO_LOWER || cell == LEFT_TO_UPPER || cell == RIGHT_TO_UPPER;
                case MOVE_RIGHT:
                    return cell == LEFT_TO_RIGHT || cell == LEFT_TO_LOWER || cell == LEFT_TO_UPPER;
                default:
                    return false;
            }
        }
        MOVE next_move = nextMoveTransTable[gridInfo->grid[row][col]][pre_move];
        if (next_move == MOVE_NULL) {
            return false;
        }
        // 下一次移动
        row += dx[next_move];
        col += dy[next_move];
        pre_move = next_move;
    }
    return false;
}

bool hasValidPath(int **grid, int gridSize, int *gridColSize) {
    if (gridSize == 1 && gridColSize[0] == 1) {
        return true;
    }
    Grid gridInfo = {grid, gridSize, gridColSize};
    switch (grid[0][0]) {
        case LEFT_TO_RIGHT:
        case RIGHT_TO_UPPER:
            return isExistValidPath(0, 1, MOVE_RIGHT, &gridInfo);
        case UPPER_TO_LOWER:
        case LEFT_TO_LOWER:
            return isExistValidPath(1, 0, MOVE_LOWER, &gridInfo);
        case RIGHT_TO_LOWER:
            isExistCircle = false;
            return isExistValidPath(0, 1, MOVE_RIGHT, &gridInfo) ||
                   (isExistCircle == false && isExistValidPath(1, 0, MOVE_LOWER, &gridInfo));
        default:
            return false;
    }
}

