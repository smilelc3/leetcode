//
// Created by smile on 2021/6/14.
//

#include <vector>
#include "util.h"

class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) noexcept {
        if (grid.empty() or grid.front().empty()) {
            return 0;
        }
        visit = decltype(visit)(grid.size(), std::vector<bool>(grid.front().size(), false));
        for (auto x = 0; x < grid.size(); ++x) {
            for (auto y = 0; y < grid.front().size(); ++y) {
                if (not visit[x][y] and grid[x][y] == '1') {
                    numOfIslands++;
                    dfs(x, y, grid);
                }
            }
        }
        return numOfIslands;
    }

private:
    int numOfIslands = 0;
    std::vector<std::vector<bool>> visit;

    // 坐标合法性判断
    constexpr bool isLegalCoord(int x, int y) noexcept {
        return x >= 0 and x < visit.size() and y >= 0 and y < visit.front().size();
    }

    void dfs(int _x, int _y, const std::vector<std::vector<char>> &grid) {
        visit[_x][_y] = true;
        for (char idx = 0; idx < 4; ++idx) {
            auto x = _x + util::dx[idx], y = _y + util::dy[idx];
            if (isLegalCoord(x, y) and grid[x][y] == '1' and not visit[x][y]) {
                dfs(x, y, grid);
            }
        }
    }
};