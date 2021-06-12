//
// Created by smile on 2021/6/11.
//

#include <string>
#include <regex>
#include <algorithm>

class Solution {
public:
    int compareVersion(std::string &version1, std::string &version2) {
        auto splitVer1 = splitVersion(version1);
        auto splitVer2 = splitVersion(version2);
        int res = 0;
        for (auto idx = 0; idx < std::max(splitVer1.size(), splitVer2.size()); ++idx) {
            auto num1 = idx < splitVer1.size() ? std::stoi(splitVer1[idx]) : 0;
            auto num2 = idx < splitVer2.size() ? std::stoi(splitVer2[idx]) : 0;
            if (num1 != num2) {
                res = num1 > num2 ? 1 : -1;
                break;
            }
        }
        return res;
    }

private:
    inline std::vector<std::string> splitVersion(std::string &version) {
        std::vector<std::string> tokens;
        auto lastPos = version.find_first_not_of('.');
        auto pos = version.find_first_of('.', lastPos);
        while (pos != std::string::npos or lastPos != std::string::npos) {
            tokens.emplace_back(version.substr(lastPos, pos - lastPos));
            lastPos = version.find_first_not_of('.', pos);
            pos = version.find_first_of('.', lastPos);
        }
        return tokens;
    }
};