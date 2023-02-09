//
// Created by smile on 2022/1/2.
//

#include <vector>
#include "util.h"

class Solution {
public:
    int getMaximumGold(const std::vector<std::vector<int>> &grid) {
        raw = grid.size();
        col = grid.front().size();
        isVisit = std::vector<std::vector<bool>>(raw, std::vector<bool>(col, false));
        for (int i = 0; i < raw; ++i) {
            for (int j = 0; j < col; ++j) {
                // 剪枝：起点一定是非0，并在聚团角落
                if (grid[i][j] == 0 or not isStartCoordAtCorner(grid, i, j)) {
                    continue;
                }
                isVisit[i][j] = true;
                dfsSolver(grid, i, j, grid[i][j]);
                isVisit[i][j] = false;
            }
        }
        return (int) maxGold;
    }

private:
    size_t raw, col;
    std::vector<std::vector<bool>> isVisit;
    size_t maxGold = 0;

    // dfs 查找
    void dfsSolver(const std::vector<std::vector<int>> &grid, int i, int j, size_t curGold) {
        bool isEnd = true;
        for (int k = 0; k < 4; ++k) {
            auto x = i + util::dx[k];
            auto y = j + util::dy[k];
            if (not isCoordLegal(x, y) or grid[x][y] == 0 or isVisit[x][y]) {
                continue;
            }
            isEnd = false;
            isVisit[x][y] = true;
            dfsSolver(grid, x, y, curGold + grid[x][y]);
            isVisit[x][y] = false;
        }
        if (isEnd) {
            maxGold = std::max(maxGold, curGold);
        }
    }

    // 判断坐标合法
    inline bool isCoordLegal(int x, int y) const {
        return x >= 0 and x < raw and y >= 0 and y < col;
    }

    // 判断起点坐标是否在聚团边缘，用于剪枝
    bool isStartCoordAtCorner(const std::vector<std::vector<int>> &grid, int x, int y) const {
        unsigned char nearNum = 0;
        if (x - 1 >= 0 and grid[x - 1][y] != 0) {
            nearNum++;
        }
        if (x + 1 < raw and grid[x + 1][y] != 0) {
            nearNum++;
        }
        if (y - 1 >= 0 and grid[x][y - 1] != 0) {
            nearNum++;
        }
        if (y + 1 < col and grid[x][y + 1] != 0) {
            nearNum++;
        }
        return nearNum <= 2;
    }
};
