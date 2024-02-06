//
// Created by smile on 2024/2/6.
//

#include <vector>
#include <unordered_map>
#include <stack>

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

class Solution {
public:
    static int getImportance(const std::vector<Employee *> &employees, int id) {
        std::unordered_map<int, const Employee *> eeIdMap;
        for (const auto employee: employees) {
            eeIdMap[employee->id] = employee;
        }
        int ans = 0;
        std::stack<const Employee *> eeStack;
        eeStack.emplace(eeIdMap[id]);
        while (not eeStack.empty()) {
            auto p = eeStack.top();
            eeStack.pop();
            ans += p->importance;
            for (auto &subordinate: p->subordinates) {
                eeStack.emplace(eeIdMap[subordinate]);
            }
        }
        return ans;
    }
};