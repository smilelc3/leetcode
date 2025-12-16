//
// Created by smile on 25-12-10.
//

#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findNumOfValidWords(std::vector<std::string> &words, std::vector<std::string> &puzzles) {
        // puzzles[i].length == 7
        // words[i][j], puzzles[i][j] 都是小写英文字母
        // words转换为二进制
        std::unordered_map<uint32_t, uint32_t> wordIntToCount;
        for (const auto &word: words) {
            std::bitset<26> wordBitSet; // 26个字母
            for (const auto &ch: word) {
                wordBitSet.set(ch - 'a');
            }
            if (wordBitSet.count() <= 7) {
                // Puzzles的长度为7，words的长度肯定不能超过7
                wordIntToCount[wordBitSet.to_ulong()]++;
            }
        }
        std::vector<int> ans(puzzles.size(), 0);
        for (decltype(puzzles.size()) i = 0; i < puzzles.size(); ++i) {
            // puzzlesInt puzzles转换为二进制
            uint32_t puzzlesInt = 0;
            for (const auto &puzzleChar: puzzles[i]) {
                puzzlesInt |= 1 << (puzzleChar - 'a');
            }

            uint32_t firstChInt = 1 << (puzzles[i].front() - 'a');
            // 枚举puzzles子集
            uint32_t subSet = puzzlesInt;
            while (subSet != 0) {
                // 必须包含首字母
                if ((subSet & firstChInt) != 0 and wordIntToCount.find(subSet) != wordIntToCount.end()) {
                    ans[i] += wordIntToCount[subSet];
                }
                subSet = (subSet - 1) & puzzlesInt;
            }
        }
        return std::move(ans);
    }
};
