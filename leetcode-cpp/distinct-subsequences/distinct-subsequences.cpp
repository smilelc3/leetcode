//
// Created by smile on 2021/4/13.
//

#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(const std::string &s, const std::string &t) {
        // dp + 滚动数组
        if (s.size() == t.size()) {
            if (s == t) {
                return 1;
            } else {
                return 0;
            }
        }
        if (s.size() < t.size()) {
            return 0;
        }

        std::vector<int64_t> preLayer(s.size() + 1, 1);
        std::vector<int64_t> curLayer(s.size() + 1);
        for (auto i = 1; i <= t.size(); i++) {
            for (auto j = 1; j <= s.size(); j++) {
                if (t[i - 1] == s[j - 1]) {
                    curLayer[j] = curLayer[j - 1] + preLayer[j - 1];
                } else {
                    curLayer[j] = curLayer[j - 1];
                }
            }
            curLayer.swap(preLayer);
            curLayer[0] = 0;
        }
        return preLayer[s.size()];
    }

    /* dp[i][j] = dp[i][j-1] if t[i-1] == s[j-1] else dp[i][j-1] + dp[i-1][j-1]
     *      Nil r   a   b   b   b   i   t
     * Nil  1   1   1   1   1   1   1   1
     * r    0   1   1   1   1   1   1   1
     * a    0   0   1   1   1   1   1   1
     * b    0   0   0   1   2   3   3   3
     * b    0   0   0   0   1   3   3   3
     * i    0   0   0   0   0   0   3   3
     * t    0   0   0   0   0   0   0   3
     */
};
