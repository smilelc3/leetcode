//
// Created by smile on 2021/5/2.
//

#include "BoolStaComp.h"
#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    size_t maxPoints(std::vector<std::vector<int>> &points) {
        return maxPointsMethod1(points);

        return maxPointsMethod2(points);
    }

    //  time: O(n^2) space: O(n^2)
    size_t maxPointsMethod1(std::vector<std::vector<int>> &points) {
        if (points.size() <= 2) {
            return points.size();
        }
        // 三角矩阵拉平
        auto hasVisit = BoolStaComp(points.size() * (points.size() - 1) / 2);
        int maxPointNum = 0;
        for (auto aIdx = 0; aIdx < points.size() - 2; aIdx++) {
            for (auto bIdx = aIdx + 1; bIdx < points.size() - 1; bIdx++) {
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

    int maxPointsMethod2(std::vector<std::vector<int>> &points) {
        if (points.size() <= 2) {
            return points.size();
        }
        int ans = 0;
        for (auto first = 0; first < points.size() - 1; first++) {
            std::map<std::pair<int, int>, int> slope;      // first点的斜率->点数的映射, unordered_map 不支持pair作为key
            auto duplicate = 0;     // 重复点
            auto curLinePointMax = 0;
            for (auto second = first + 1; second < points.size(); second++) {
                if (points[first] == points[second]) {
                    duplicate++;
                    continue;
                }
                auto deltaX = points[first][0] - points[second][0];     // gcd运算可以支持双负数
                auto deltaY = points[first][1] - points[second][1];
                if (deltaX == 0) {
                    curLinePointMax = std::max(curLinePointMax, ++slope[{points[first][1], 0}]);        // 一条竖线
                } else if (deltaY == 0) {
                    curLinePointMax = std::max(curLinePointMax, ++slope[{0, points[first][0]}]);      // 一条横线
                } else {
                    auto d = gcd(deltaX, deltaY);
                    curLinePointMax = std::max(curLinePointMax, ++slope[{deltaX / d, deltaY / d}]);
                }
            }
            ans = std::max(ans, curLinePointMax + duplicate + 1);
        }
        return ans;
    }

    static constexpr int getLocByTwoIdx(int m, int n, int size) {
        return (2 * size - 1 - m) * m / 2 + n - m - 1;
    }

    static constexpr bool isTreePointsOnSameLine(std::pair<int, int> a, decltype(a) b, decltype(a) c) {
        return b.first * c.second + a.second * c.first + a.first * b.second ==
               b.second * c.first + a.first * c.second + b.first * a.second;
    }

    template<typename T>
    static int gcd(T m, T n) {
        return n == 0 ? m : gcd(n, m % n);
    }
};

