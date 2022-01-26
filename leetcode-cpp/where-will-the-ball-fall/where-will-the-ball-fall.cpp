//
// Created by smile on 2022/1/26.
//

#include <vector>

class Solution {
public:
    static std::vector<int> findBall(const std::vector<std::vector<int>> &grid) {
        auto ans = std::vector<int>(grid.front().size());
        for (auto i = 0; i < ans.size(); ++i) {
            ans[i] = findOneBall(grid, i);
        }
        return ans;
    }

private:
    static int findOneBall(const std::vector<std::vector<int>> &grid, int i) {
        auto curRow = 0, curCol = i;
        while (curRow < grid.size()) {
            if (grid[curRow][curCol] == -1) {  // 右上 -> 左下
                if (curCol == 0 or grid[curRow][curCol - 1] == 1) {
                    return -1;
                }
                curCol--;
            } else { // 左上 -> 右下
                if (curCol == grid[curRow].size() - 1 or grid[curRow][curCol + 1] == -1) {
                    return -1;
                }
                curCol++;
            }
            curRow++;
        }

        return curCol;
    }
};