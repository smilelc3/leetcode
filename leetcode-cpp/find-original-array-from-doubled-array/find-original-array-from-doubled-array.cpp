//
// Created by smile on 2021/11/15.
//

#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> findOriginalArray(std::vector<int> &changed) {
        std::vector<int> ans;
        std::sort(changed.begin(), changed.end());
        for (const auto &item: changed) {
            if (queue.empty() or queue.front() * 2 != item) {
                queue.emplace(item);
            } else {
                ans.emplace_back(queue.front());
                queue.pop();
            }
        }
        if (not queue.empty()) {
            return {};
        }
        return ans;
    }
private:
    std::queue<int> queue;
};