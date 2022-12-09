//
// Created by smile on 2022/12/9.
//

#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int leastBricks(const std::vector<std::vector<int>> &wall) {
        std::unordered_map<uint32_t, uint32_t> pointNumMap;
        for (const auto &rowBrick: wall) {
            uint32_t startPoint = 0;
            for (auto brick = rowBrick.begin(); brick < rowBrick.end() - 1; ++brick) {
                startPoint += *brick;
                pointNumMap[startPoint]++;
            }
        }

        if (pointNumMap.empty()) {
            return static_cast<int>(wall.size());
        }
        auto maxPoint = std::max_element(pointNumMap.begin(), pointNumMap.end(),
                                         [](decltype(*pointNumMap.begin()) &a, decltype(a) &b) {
                                             return a.second < b.second;
                                         });
        return wall.size() - maxPoint->second;
    }
};
