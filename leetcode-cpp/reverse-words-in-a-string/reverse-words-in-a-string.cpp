//
// Created by smile on 2021/5/13.
//

#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(const std::string &s) {
        std::string ans;
        ans.reserve(s.size());
        auto noSpaceStart = s.find_last_not_of(' ');
        auto noSpaceStop = s.find_first_not_of(' ');

        // 格式化
        ans.push_back(s[noSpaceStart]);
        for (auto idx = noSpaceStart - 1; idx > noSpaceStop; idx--) {
            if (s[idx] == ' ' and s[idx - 1] == ' ') {
                continue;
            }
            ans.push_back(s[idx]);
        }
        ans.push_back(s[noSpaceStop]);

        ans.shrink_to_fit();

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