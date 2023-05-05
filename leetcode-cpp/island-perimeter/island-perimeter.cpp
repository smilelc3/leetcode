//
// Created by smile on 2023/5/5.
//


#include <vector>

class Solution {
public:
    static int islandPerimeter(const std::vector<std::vector<int>> &grid) {
        size_t landNum = 0;
        size_t commonEdgeNum = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }
                landNum++;
                if (i > 0 and grid[i - 1][j] == 1) {
                    commonEdgeNum++;
                }
                if (j > 0 and grid[i][j - 1] == 1) {
                    commonEdgeNum++;
                }
            }
        }

        return static_cast<int>(landNum * 4 - commonEdgeNum * 2);
    }
};