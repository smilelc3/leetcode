//
// Created by smile on 2021/5/13.
//

#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(const std::string &s) {
        std::string ans(s.rbegin(), s.rend());
        // 清洗 首末空格
        ans.erase(0, ans.find_first_not_of(' '));
        ans.erase(ans.find_last_not_of(' ') + 1);
        // 清洗 中间空格
        for (auto idx = 1; idx < ans.size(); idx++) {
            if (ans[idx] == ' ' and ans[idx + 1] == ' ') {
                ans.erase(idx, ans.find_first_not_of(' ', idx) - idx - 1);
            }
        }

        auto wordBegin = ans.begin(), wordEnd = ans.begin();
        while (wordEnd != ans.end()) {
            if (*wordEnd != ' ') {
                wordEnd++;
                continue;
            }
            std::reverse(wordBegin, wordEnd);
            wordBegin = ++wordEnd++;
        }
        std::reverse(wordBegin, wordEnd);

        return ans;
    }
};