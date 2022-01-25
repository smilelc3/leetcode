//
// Created by smile on 2022/1/10.
//

#include <string>
#include <unordered_map>

// 前缀树（字典树）节点
class WordDict {
public:
    explicit WordDict(bool _isLeaf, int _val) : isLeaf(_isLeaf), val(_val) {};
    bool isLeaf;    // 是否是单词末尾
    int val;        // 值
    std::unordered_map<char, WordDict *> nextMap;   // 指向下一个字符的map

    ~WordDict() {
        for (auto &next: nextMap) {
            delete next.second;
        }
    }
};


class MapSum {
public:
    MapSum() {
        wordDict = new WordDict(false, 0);
    }

    void insert(const std::string &key, int val) {
        insertSolver(key.begin(), key.end(), wordDict, val);
    }

    int sum(const std::string &prefix) {
        return sumSolver(prefix.begin(), prefix.end(), wordDict);
    }

    ~MapSum() {
        delete wordDict;
    }

private:
    WordDict *wordDict;

    void insertSolver(const std::string::const_iterator &iter, const std::string::const_iterator &end,
                      WordDict *root, int val) {
        if (iter + 1 == end) {      // 已达到末尾
            auto nextRoot = root->nextMap.find(*iter);
            if (nextRoot == root->nextMap.end()) {
                root->nextMap[*iter] = new WordDict(true, val);
            } else {
                nextRoot->second->val = val;
                nextRoot->second->isLeaf = true;
            }
            return;
        }
        auto find = root->nextMap.find(*iter);
        WordDict *nextRoot;
        if (find == root->nextMap.end()) {
            nextRoot = new WordDict(false, 0);  // 下面未找到节点，创建
            root->nextMap[*iter] = nextRoot;
        } else {
            nextRoot = find->second;
        }
        insertSolver(iter + 1, end, nextRoot, val);

    }

    int sumSolver(const std::string::const_iterator &iter, const std::string::const_iterator &end, WordDict *root) {
        if (iter != end) {
            auto nextRoot = root->nextMap.find(*iter);
            if (nextRoot == root->nextMap.end()) {
                // 如果找不到接下来的结点
                return 0;
            }
            return sumSolver(iter + 1, end, nextRoot->second);
        }

        int sum = 0;
        if (root->isLeaf) {
            sum += root->val;
        }
        for (const auto &nextRoot: root->nextMap) {
            sum += sumSolver(iter, end, nextRoot.second);
        }
        return sum;
    }
};
