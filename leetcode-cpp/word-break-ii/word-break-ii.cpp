//
// Created by smile on 2021/5/13.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>

class Solution {
public:
    std::vector<std::string> wordBreak( std::string &s, std::vector<std::string> &wordDict) {
        for (const auto &word : wordDict) {
            wordsSet.emplace(word);
        }
        std::vector<std::string> temp;
        dfsSolution(s, temp);
        return ans;
    }

private:
    std::unordered_set<std::string> wordsSet;
    std::vector<std::string> ans;

    void dfsSolution(std::string &cur, std::vector<std::string> &temp) {
        if (cur.empty()) {
            // join
            ans.emplace_back(
                    temp.empty() ? "" :
                    std::accumulate(
                            std::next(temp.begin()), temp.end(),
                            temp[0],
                            [](auto &&a, auto &&b) -> auto & {
                                return (a += ' ') += b;
                            }
                    )
            );
            return;
        }

        for (auto len = 1; len <= cur.size(); len++) {
            if (wordsSet.find(cur.substr(0,len)) != wordsSet.end()) {
                temp.emplace_back(cur.substr(0,len));
                auto next = cur.substr(len);
                dfsSolution(next, temp);
                temp.pop_back();
            }
        }

    }

};