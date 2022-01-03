//
// Created by smile on 2022/1/3.
//

#include <string>

class Solution {
public:
    static std::vector<std::string> ambiguousCoordinates(const std::string &s) {
        std::vector<std::string> ans;
        // 先插入逗号
        std::string buf;
        buf.reserve(s.size() + 4);
        for (size_t idx = 1; idx < s.size() - 2; ++idx) {
            auto xCoords = getAllVailSplit(s.substr(1, idx - 1 + 1));
            if (xCoords.empty()) {
                continue;
            }
            auto yCoords = getAllVailSplit(s.substr(idx + 1, s.size() - idx - 2));
            if (yCoords.empty()) {
                continue;
            }
            for (const auto &xCoord: xCoords) {
                for (const auto &yCoord: yCoords) {
                    buf.clear();
                    buf += "(";
                    buf += xCoord;
                    buf += ", ";
                    buf += yCoord;
                    buf += ")";
                    ans.emplace_back(buf);
                }
            }
        }

        return ans;
    }

private:
    static std::vector<std::string> getAllVailSplit(const std::string &s) {
        // 只有一位，直接返回
        if (s.size() == 1) {
            return {s};
        }
        // 是否存在前导0
        bool isExistPrefixZero = s.front() == '0';
        // 是否存在后导0
        bool isExistSuffixZero = s.back() == '0';

        // 如果存在前缀0，且不存在后导0，仅能在第0位后插入小数点
        if (isExistPrefixZero and not isExistSuffixZero) {
            return {"0." + s.substr(1)};
        }
        std::vector<std::string> ans;
        if (not isExistPrefixZero) { // 不能存在前缀零，可以整体作为解
            ans.emplace_back(s);
            if (isExistSuffixZero) {
                return ans;     // 不存在前导0，但是存在后导0，不能添加小数点
            }
            // 此处，既不存在前导0，也不存在后导0，可以在两字符间添加小数点
            for (int idx = 1; idx < s.size(); ++idx) {  // 在idx位置插入小数点
                ans.emplace_back(s.substr(0, idx) + "." + s.substr(idx));
            }
        }

        return ans;
    }
};