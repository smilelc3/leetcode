//
// Created by lcsmile on 2023/1/18.
//

#include <vector>
#include <algorithm>

class Solution {
// 坐标范围[0, 500]
public:
    std::vector<int> countPoints(std::vector<std::vector<int>> &points, std::vector<std::vector<int>> &queries) {
        // 二重循环
        //return countPointsDoubleLoopMethod(points, queries);
        // sort + 二分查找
        return countPointsSearchMethod(points, queries);
    }

    auto countPointsSearchMethod(std::vector<std::vector<int>> &points,
                                 std::vector<std::vector<int>> &queries) -> std::vector<int> {
        std::vector<int> ans(queries.size(), 0);
        // 以x轴对点进行排序
        std::sort(points.begin(), points.end(),
                  [](const std::vector<int> &a, const std::vector<int> &b) {
                      return a.front() < b.front();
                  });
        for (auto circleIter = queries.begin(); circleIter != queries.end(); ++circleIter) {
            // 开始二分查找左边界
            auto cx = (*circleIter)[0], cy = (*circleIter)[1], cr = (*circleIter)[2];
            auto pointIter = std::lower_bound(points.begin(), points.end(),
                                              cx - cr,
                                              [](const std::vector<int> &p, int v) {
                                                  return p[0] < v;
                                              });
            // 从左边界向右扩展 2r
            while (pointIter != points.end() and (*pointIter)[0] <= cx + cr) {
                if (isPointInCircle((*pointIter)[0], (*pointIter)[1],
                                    cx, cy, cr)) {
                    ans[std::distance(queries.begin(), circleIter)]++;
                }
                pointIter++;
            }
        }

        return ans;
    }

    auto countPointsDoubleLoopMethod(std::vector<std::vector<int>> &points,
                                     std::vector<std::vector<int>> &queries) -> std::vector<int> {
        std::vector<int> ans(queries.size(), 0);
        for (const auto &point: points) {
            for (auto circleIter = queries.begin(); circleIter != queries.end(); ++circleIter) {
                if (isPointInCircle(point[0], point[1],
                                    (*circleIter)[0], (*circleIter)[1], (*circleIter)[2])) {
                    ans[std::distance(queries.begin(), circleIter)]++;
                }
            }
        }
        return ans;
    }

private:
    static inline bool isPointInCircle(int px, int py, int cx, int cy, int cr) {
        return (px - cx) * (px - cx) + (py - cy) * (py - cy) <= cr * cr;
    }
};