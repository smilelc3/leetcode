//
// Created by smile on 2022/3/22.
//

#include <string>
#include <array>
#include <algorithm>
#include <vector>

class Item {
public:
    char character;
    unsigned int frequency;

    explicit Item(char _c, unsigned int _f) : character(_c), frequency(_f) {};

    bool operator<(const Item &that) const {
        if (this->frequency != that.frequency) {
            return this->frequency < that.frequency;
        }
        return this->character > that.character;
    }

    bool operator>(const Item &that) const {
        return not(*this < that);
    }
};

class Solution {
public:
    static std::string frequencySort(const std::string &s) {
        std::array<unsigned int, 26> lowerMap{}, upperMap{};
        std::array<unsigned int, 10> numMap{};
        for (const auto &ch: s) {
            if (std::isupper(ch)) {
                upperMap[ch - 'A']++;
            } else if (std::islower(ch)) {
                lowerMap[ch - 'a']++;
            } else if (std::isalnum(ch)) {
                numMap[ch - '0']++;
            }
        }
        std::vector<Item> items;
        for (auto iter = lowerMap.begin(); iter != lowerMap.end(); iter++) {
            if (*iter > 0) {
                items.emplace_back(static_cast<char>(iter - lowerMap.begin()) + 'a', *iter);
            }
        }
        for (auto iter = upperMap.begin(); iter != upperMap.end(); iter++) {
            if (*iter > 0) {
                items.emplace_back(static_cast<char>(iter - upperMap.begin()) + 'A', *iter);
            }
        }
        for (auto iter = numMap.begin(); iter != numMap.end(); iter++) {
            if (*iter > 0) {
                items.emplace_back(static_cast<char>(iter - numMap.begin()) + '0', *iter);
            }
        }
        std::sort(items.begin(), items.end(), std::greater<>());

        std::string ans;
        ans.reserve(s.size());
        for (const auto &item: items) {
            for (auto time = item.frequency; time > 0; --time) {
                ans.push_back(item.character);
            }
        }
        return ans;
    }
};