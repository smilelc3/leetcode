//
// Created by smile on 2023/5/1.
//

#include <string>
#include <sstream>
#include <array>
#include <vector>

class Solution {
public:
    static std::string getHint(const std::string &secret, const std::string &guess) {
        if (secret.size() != guess.size()) {
            return "";
        }
        auto bullNum = 0, cowNum = 0;
        std::array<size_t, 10> bullCnt {};
        std::vector<bool> isSameChar(secret.size(), false);
        // 第一次遍历统计bull数量
        for (size_t idx = 0; idx < secret.size(); ++idx) {
            if (secret[idx] == guess[idx]) {
                bullNum++;
                isSameChar[idx] = true;
            } else {
                auto val = secret[idx] - '0';
                bullCnt[val]++;
            }
        }
        //  第二次遍历统计cow数量
        for (size_t idx = 0; idx < guess.size(); ++idx) {
            if (isSameChar[idx] == true) {
                continue;
            }
            auto val = guess[idx] - '0';
            if (bullCnt[val] > 0) {
                bullCnt[val]--;
                cowNum++;
            }
        }
        std::stringstream ss;
        ss << bullNum << 'A' << cowNum << 'B';
        return  ss.str();
    }
};