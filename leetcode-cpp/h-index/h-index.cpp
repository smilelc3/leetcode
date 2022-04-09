//
// Created by smile on 2022/4/7.
//

#include <vector>
#include <algorithm>


class Solution {
public:
    static int hIndex(std::vector<int> &citations) {
        // O(nlog(n))
        // return hIndexSortMethod(citations);

        // O(max(citations[i]))
        return hIndexBucketMethod(citations);
    }


    static int hIndexSortMethod(std::vector<int> &citations) {
        std::sort(citations.begin(), citations.end(), std::less<>());
        int h = static_cast<int>(citations.size());
        while (h >= 1) {
            if (*(citations.rbegin() + h - 1) >= h) {
                break;
            }
            h--;
        }
        return h;
    }

    // O(max(citations[i]))
    static int hIndexBucketMethod(std::vector<int> &citations) {
        std::vector<int> bucket(*std::max_element(citations.begin(), citations.end()) + 1, 0);
        int h = static_cast<int>(citations.size());
        for (const auto &citation: citations) {
            bucket[citation]++;
        }
        for (int idx = 0; idx < bucket.size(); ++idx) {
            if (idx >= h) {
                break;
            }
            h -= std::min(bucket[idx], h - idx);
        }
        return h;
    }

};