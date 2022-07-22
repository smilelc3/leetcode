//
// Created by smile on 2022/7/22.
//

#include <string>
#include <array>
#include <vector>

class Solution {
public:
    bool wordPattern(const std::string &pattern, const std::string &s) {
        const char delimiter = ' ';
        decltype(pattern.size()) idx = 0;
        std::vector<uint8_t> keySet;    // keySet 最多26个
        // 映射map: char -> substr; pair 分别代表起始位置，和终止位置的下一个
        std::array<std::pair<decltype(s.size()), decltype(s.size())>, 'z' - 'a' + 1> map;

        // 判断相同key,是否存在不同val
        auto endPos = s.find_first_of(delimiter);
        auto startPos = s.find_first_not_of(delimiter);
        while (endPos != std::string::npos or startPos != std::string::npos) {
            if (idx == pattern.size()) {    // 长度不对等
                return false;
            }
            const auto key = pattern[idx] - 'a';
            auto &val = map[key];
            if (val.first == 0 and val.second == 0) {       // 首次加入
                val.first = startPos;
                val.second = endPos;
                keySet.emplace_back(key);
            } else if (s.substr(val.first, val.second - val.first) != s.substr(startPos, endPos - startPos)) {
                return false;
            }
            startPos = s.find_first_not_of(delimiter, endPos);
            endPos = s.find_first_of(delimiter, startPos);
            idx++;
        }
        if (idx != pattern.size()) {    // 长度不对等
            return false;
        }

        // 判断不同key,是否存在相同val
        for (auto iKeyI = keySet.begin(); iKeyI != keySet.end(); iKeyI++) {
            for (auto iKeyJ = iKeyI + 1; iKeyJ != keySet.end(); iKeyJ++) {
                auto valI = map[*iKeyI];
                auto valJ = map[*iKeyJ];
                if (s.substr(valI.first, valI.second - valI.first) == s.substr(valJ.first, valJ.second - valJ.first)) {
                    return false;
                }
            }
        }
        return true;
    }
};