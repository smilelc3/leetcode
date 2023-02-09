//
// Created by smile on 2023/2/8.
//

#include <vector>
#include "util.h"

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>> &matrix) {
        //return maximalSquareDP(matrix);
        return maximalSquareDPWithScrollArr(matrix);
    }

private:
    int maximalSquareDP(std::vector<std::vector<char>> &matrix) {
        auto dp = std::vector<std::vector<int>>(matrix.size(), std::vector<int>(matrix.front().size(), 0));
        int maxSideLen = 0;
        // 初始化第0行
        for (size_t i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
                maxSideLen = 1;
            }
        }
        // 初始化第0列
        for (size_t j = 0; j < matrix.size(); j++) {
            if (matrix[j][0] == '1') {
                dp[j][0] = 1;
                maxSideLen = 1;
            }
        }

        // 计算剩余
        for (size_t i = 1; i < matrix.size(); i++) {
            for (size_t j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxSideLen = std::max(maxSideLen, dp[i][j]);
            }
        }

        return util::square(maxSideLen);
    }

    // 带滚动数组状态压缩的DP
    int maximalSquareDPWithScrollArr(std::vector<std::vector<char>> &matrix) {
        //  需要两个DP数组记录状态
        auto preDp = std::vector<int>(matrix.front().size() + 1, 0);    // 多申请一个空间，便于处理边界
        auto curDp = decltype(preDp)(preDp);
        int maxSideLen = 0;
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '0') {
                    curDp[j + 1] = 0;
                    continue;
                }
                curDp[j + 1] = std::min(std::min(preDp[j], preDp[j + 1]), curDp[j]) + 1;
                maxSideLen = std::max(maxSideLen, curDp[j + 1]);
            }
            std::swap(preDp, curDp);
        }

        return util::square(maxSideLen);
    }
};