//
// Created by smile on 2021/5/2.
//

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxPoints(std::vector<std::vector<int>> &points) {
        //  time: O(n^2) space: O(n^2)
        std::vector<std::vector<bool>> hasVisit(points.size(), std::vector<bool>(points.size(), false));
        int maxPointNum = 0;
        if (points.size() == 1) {
            maxPointNum = 1;
        }
        for (auto aIdx = 0; aIdx < points.size(); aIdx++) {
            for (auto bIdx = aIdx + 1; bIdx < points.size(); bIdx++) {
                if (not hasVisit[aIdx][bIdx]) {
                    hasVisit[aIdx][bIdx] = true;
                    auto curLinePointNum = 2;
                    for (auto cIdx = bIdx + 1; cIdx < points.size(); cIdx++) {
                        // aIdx < bIdx < cIdx
                        if (isTreePointsOnSameLine(std::make_pair(points[aIdx][0], points[aIdx][1]),
                                                   std::make_pair(points[bIdx][0], points[bIdx][1]),
                                                   std::make_pair(points[cIdx][0], points[cIdx][1]))) {
                            hasVisit[aIdx][cIdx] = true;
                            hasVisit[bIdx][cIdx] = true;
                            curLinePointNum++;
                        }
                    }
                    maxPointNum = std::max(maxPointNum, curLinePointNum);
                }
            }
        }
        return maxPointNum;
    }

    constexpr inline bool isTreePointsOnSameLine(std::pair<int, int> a, decltype(a) b, decltype(a) c) {
        return b.first * c.second + a.second * c.first + a.first * b.second ==
               b.second * c.first + a.first * c.second + b.first * a.second;
    }
};