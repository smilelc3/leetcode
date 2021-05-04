//
// Created by smile on 2021/5/2.
//

#include "BoolStaComp.h"
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxPoints(std::vector<std::vector<int>> &points) {
        return maxPointsMethod1(points);
    }

    int maxPointsMethod1(std::vector<std::vector<int>> &points) {
        //  time: O(n^2) space: O(n^2)
        if (points.size() <= 2) {
            return points.size();
        }
        // 三角矩阵拉平
        auto hasVisit = BoolStaComp(points.size() * (points.size() - 1) / 2);
        int maxPointNum = 0;
        for (auto aIdx = 0; aIdx < points.size(); aIdx++) {
            for (auto bIdx = aIdx + 1; bIdx < points.size(); bIdx++) {
                auto loc = getLocByTwoIdx(aIdx, bIdx, points.size());
                if (not hasVisit.GetState(loc)) {
                    hasVisit.SetStateTrue(loc);
                    auto curLinePointNum = 2;
                    for (auto cIdx = bIdx + 1; cIdx < points.size(); cIdx++) {
                        // aIdx < bIdx < cIdx
                        if (isTreePointsOnSameLine(std::make_pair(points[aIdx][0], points[aIdx][1]),
                                                   std::make_pair(points[bIdx][0], points[bIdx][1]),
                                                   std::make_pair(points[cIdx][0], points[cIdx][1]))) {
                            hasVisit.SetStateTrue(getLocByTwoIdx(aIdx, cIdx, points.size()));
                            hasVisit.SetStateTrue(getLocByTwoIdx(bIdx, cIdx, points.size()));
                            curLinePointNum++;
                        }
                    }
                    maxPointNum = std::max(maxPointNum, curLinePointNum);
                }
            }
        }
        return maxPointNum;
    }

    static constexpr int getLocByTwoIdx(int m, int n, int size) {
        return (2 * size - 1 - m) * m / 2 + n - m - 1;
    }

    static constexpr bool isTreePointsOnSameLine(std::pair<int, int> a, decltype(a) b, decltype(a) c) {
        return b.first * c.second + a.second * c.first + a.first * b.second ==
               b.second * c.first + a.first * c.second + b.first * a.second;
    }
};