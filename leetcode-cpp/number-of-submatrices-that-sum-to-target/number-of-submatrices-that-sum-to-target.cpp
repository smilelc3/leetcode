//
// Created by smile on 2024/7/18.
//

#include <vector>
#include <unordered_map>

class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>> &matrix, int target) {
        auto mSum = std::remove_reference<decltype(matrix)>::type(matrix.size() + 1,
                                                                  std::remove_reference<decltype(matrix.front())>::type(
                                                                          matrix.front().size() + 1, 0));

        // 在外圈一层0
        for (size_t i = 1; i <= matrix.size(); ++i) {
            for (size_t j = 1; j <= matrix.front().size(); ++j) {
                mSum[i][j] = mSum[i][j - 1] + mSum[i - 1][j] - mSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (size_t up = 1; up <= matrix.size(); ++up) {     // 上边界
            for (size_t down = up; down <= matrix.size(); ++down) { // 下边界
                std::unordered_map<int, int> areaMap;
                for (size_t right = 1; right <= matrix.front().size(); ++right) {   // 右边界
                    auto curArea = mSum[down][right] - mSum[up - 1][right];
                    if (curArea == target) {
                        ans++;
                    }
                    auto remainArea = curArea - target;
                    if (areaMap.find(remainArea) != areaMap.end()) {
                        ans += areaMap[remainArea];
                    }
                    areaMap[curArea]++;

                }

            }
        }
        return ans;
    }
};