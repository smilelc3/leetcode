//
// Created by smile on 2021/4/19.
//
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>>
    findLadders(std::string &beginWord, std::string &endWord, std::vector<std::string> &wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return {};
        }
        std::vector<std::vector<std::string>> ans;

        // 删除beginWord endWord 避免重复出现
        dict.erase(beginWord);
        dict.erase(endWord);

        // 记录某个单词可以由那些单词扩展出来
        std::unordered_map<std::string, std::vector<std::string>> children;

        auto wordLength = beginWord.length();

        // 是否找到解
        bool found = false;
        // 当前扩展方向是不是反方向
        bool backward = false;
        // 双向BFS队列
        std::unordered_set<std::string> queue1{beginWord}, queue2{endWord};


        while (not queue1.empty() and not queue2.empty() && not found) {
            // 始终从最小队列开始
            if (queue1.size() > queue2.size()) {    //换方向
                std::swap(queue1, queue2);
                backward = not backward;
            }

            // 从字典中移除上一层的单词，避免重复扩展
            for (const auto &word : queue1) {
                dict.erase(word);
            }
            for (const auto &word : queue2) {
                dict.erase(word);
            }

            // 创建临时扩展队列
            std::unordered_set<std::string> tempQueue;

            for (const auto &word : queue1) {
                // 遍历 queue1
                auto current = word;
                for (auto i = 0; i < wordLength; i++) {
                    // 修改第i位char
                    auto rawChar = current[i];
                    for (auto j = 'a'; j <= 'z'; j++) {
                        current[i] = j;

                        const auto *parent = &word;
                        const auto *child = &current;

                        // 确定方向
                        if (backward) {
                            std::swap(parent, child);
                        }

                        if (queue2.find(current) != queue2.end()) {
                            // queue1 中的单词，经过修改能在 queue2 中找到
                            found = true;
                            children[*parent].emplace_back(*child);
                        } else if (dict.find(current) != dict.end() && not found) {
                            // 在queue中找不到且存在于字典中，入队
                            tempQueue.insert(current);
                            children[*parent].emplace_back(*child);
                        }
                    }
                    current[i] = rawChar;
                }
            }
            // 新队列代替queue1
            std::swap(tempQueue, queue1);
        }

        if (found) {
            std::vector<std::string> path{beginWord};
            getPaths(beginWord, endWord, children, path, ans);
        }
        return ans;
    }

private:
    void getPaths(const std::string &word,
                  const std::string &endWord,
                  const std::unordered_map<std::string, std::vector<std::string>> &children,
                  std::vector<std::string> &path,
                  std::vector<std::vector<std::string>> &ans) {
        if (word == endWord) {
            ans.emplace_back(path);
            return;
        }
        const auto iter = children.find(word);
        if (iter == children.end()) {
            return;
        }
        for (const auto &child: iter->second) {
            path.emplace_back(child);
            getPaths(child, endWord, children, path, ans);
            path.pop_back();
        }
    }
};