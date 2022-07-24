//
// Created by smile on 2022/7/23.
//

#include <vector>
#include <algorithm>

class Solution {
public:
    static int findRadius(std::vector<int> &houses, std::vector<int> &heaters) {
        if (houses.empty() or heaters.empty()) {
            return 0;
        }
        std::sort(houses.begin(), houses.end(), std::less<>());
        std::sort(heaters.begin(), heaters.end(), std::less<>());
        int radius = 0;
        if (houses.front() < heaters.front()) {
            radius = heaters.front() - houses.front();
        }
        auto houseIter = houses.begin();
        auto heaterIter = heaters.begin();
        while (heaterIter + 1 != heaters.end() and houseIter != houses.end()) {
            if (*houseIter < *heaterIter) {
                houseIter++;
                continue;
            }
            if (*(heaterIter + 1) > *houseIter) {    // 计算落在heater区间 [*heaterIter, *(heaterIter + 1)) 内的houses
                radius = std::max(radius, std::min(*houseIter - *heaterIter, *(heaterIter + 1) - *houseIter));
                houseIter++;
            } else {
                heaterIter++;
            }
        }
        if (houses.back() > heaters.back()) {
            radius = std::max(radius, houses.back() - heaters.back());
        }
        return radius;
    }
};