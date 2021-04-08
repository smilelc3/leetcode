//
// Created by smile on 2021/4/8.
//

#include <vector>

class Solution {
public:
    static std::vector<int> getRow(int rowIndex) {
        std::vector<int> ans;
        ans.reserve(2 * rowIndex + 1);
        ans.push_back(1);
        if (rowIndex == 0) {
            return ans;
        }
        ans.push_back(1);
        if (rowIndex == 1) {
            return ans;
        }
        for (auto i = 2; i <= rowIndex; i++) {
            ans.push_back(1);
            for (auto j = 1; j < i; j++) {
                ans.push_back(ans[j - 1] + ans[j]);
            }
            ans.push_back(1);
            ans.erase(ans.begin(), ans.begin() + i);
        }
        return ans;
    }
};