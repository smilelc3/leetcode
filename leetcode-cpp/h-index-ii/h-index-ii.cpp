//
// Created by smile on 2022/4/11.
//

#include <vector>
#include <algorithm>

class Solution {
public:
    static int hIndex(const std::vector<int> &citations) {
        return hIndexBinarySearchMethod(citations);
    }

    static int hIndexLoopMethod(const std::vector<int> &citations) {
        decltype(citations.size()) ans = 0;
        for (auto citation = citations.rbegin(); citation != citations.rend(); citation++) {
            auto h = std::distance(citations.rbegin(), citation) + 1;
            if (*citation < h) {
                break;
            }
            ans = h;
        }
        return static_cast<int>(ans);
    }

    static int hIndexBinarySearchMethod(const std::vector<int> &citations) {
        auto left = citations.begin(), right = citations.end();
        while (left + 1 != right) {
            auto mid = left + (right - left) / 2;
            auto h = citations.end() - mid;
            if (*mid >= h) {
                right = mid;
            } else {
                left = mid;
            }
        }
        auto h = citations.end() - left;
        return static_cast<int>(*left >= h ? h : h - 1);
    }
};