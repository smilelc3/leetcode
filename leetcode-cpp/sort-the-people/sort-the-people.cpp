//
// Created by smile on 2024/9/17.
//

#include <vector>
#include <string>
#include <algorithm>


class Solution {
public:
    static std::vector<std::string> sortPeople(std::vector<std::string> &names, std::vector<int> &heights) {
        std::vector<People> peoples;
        peoples.reserve(names.size());
        for (size_t idx = 0; idx < names.size(); ++idx) {
            peoples.emplace_back(names[idx], heights[idx]);
        }
        std::sort(peoples.begin(), peoples.end());
        std::vector<std::string> ans;
        ans.reserve(names.size());
        for (const auto &people: peoples) {
            ans.emplace_back(people.name);
        }
        return std::move(ans);
    }

private:
    class People {
    public:
        std::string name;
        int height;

        explicit People(std::string &name, int height) : name(name), height(height) {}

        // 重载小于运算符，按照身高降序
        bool operator<(const People &other) const {
            return this->height > other.height;
        }

    };
};