//
// Created by smile on 2022/1/26.
//

#include <vector>

class Solution {
public:
    static bool carPooling(std::vector<std::vector<int>> &trips, int capacity) {
        auto tripMax = getFarthestTrip(trips);
        auto num = std::vector<int>(tripMax + 1, 0);
        for (const auto &trip: trips) {
            auto numPassenger = trip[0], from = trip[1], to = trip[2];
            num[from] += numPassenger;
            num[to] -= numPassenger;
        }
        int curPassenger = 0;
        for (auto i = 0; i <= tripMax; ++i) {
            curPassenger += num[i];
            if (curPassenger > capacity) {
                return false;
            }
        }
        return true;
    }

private:
    static int getFarthestTrip(const std::vector<std::vector<int>> &trips) {
        int farthest = 0;
        for (const auto &trip: trips) {
            auto to = trip[2];
            farthest = std::max(farthest, to);
        }
        return farthest;
    }
};