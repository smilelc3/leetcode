//
// Created by smile on 2021/4/19.
//
#include <string>
#include <vector>
#include <unordered_set>


class Solution {
public:
    int ladderLength(std::string &beginWord, std::string &endWord, std::vector<std::string> &wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        auto wordLength = beginWord.length();

        // 双向BFS队列
        std::unordered_set<std::string> queue1{beginWord}, queue2{endWord};
        auto step = 0;
        while (not queue1.empty() and not queue2.empty()) {
            step++;
            if (queue1.size() > queue2.size()) {
                std::swap(queue1, queue2);
            }
            std::unordered_set<std::string> tempQueue;
            for (auto word : queue1) {
                for (auto i = 0; i < wordLength; i++) {
                    // 修改第i位char
                    auto rawChar = word[i];
                    for (auto j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        if (queue2.find(word) != queue2.end()) {
                            return step + 1;
                        }
                        if (dict.find(word) == dict.end()) {
                            continue;
                        }
                        dict.erase(word);
                        tempQueue.insert(word);
                    }
                    word[i] = rawChar;
                }
            }
            std::swap(tempQueue, queue1);
        }
        return 0;
    }
};