//
// Created by smile on 2023/9/8.
//

#include <vector>
#include <queue>

class Point {
public:
    size_t x, y;
    int value;
    explicit Point(size_t _x, size_t _y, int _val) : x(_x), y(_y), value(_val) {}
};

class Solution {
public:
    static std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>> &nums) {
        std::queue<Point> bfsQ{};
        std::vector<int> ans{};
        // 首元素入队
        bfsQ.emplace(Point(0, 0, nums.front().front()));
        while (not bfsQ.empty()) {
            auto curPointNum = bfsQ.size();
            auto head = bfsQ.front();
            // 队首元素尝试下扩展，但不移除元素
            if (head.y == 0 and head.x + 1 < nums.size()) {
                bfsQ.emplace(Point(head.x + 1, 0, nums[head.x + 1][0]));
            }
            // 所有元素尝试右扩展，同时移除元素
            for(; curPointNum != 0; --curPointNum) {
                auto point = bfsQ.front();
                bfsQ.pop();
                ans.emplace_back(point.value);
                if (point.y + 1 < nums[point.x].size()) {
                    bfsQ.emplace(Point(point.x, point.y + 1, nums[point.x][point.y + 1]));
                }
            }
        }

        return ans;
    }
};