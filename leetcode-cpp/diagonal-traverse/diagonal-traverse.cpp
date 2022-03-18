//
// Created by smile on 2022/3/15.
//

#include <vector>

class Solution {
public:
    static std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>> &mat) {
        std::vector<int> ans{};
        const auto row = mat.size(), col = mat.front().size();
        ans.reserve(row * col);
        bool isSlantUp = true;     // 方向：true斜上，false  斜下
        size_t x = 0, y = 0;
        while (ans.size() != row * col) {
            ans.emplace_back(mat[x][y]);
            if (isSlantUp) {
                if (y == col - 1) {
                    isSlantUp = not isSlantUp;
                    x++;
                } else if (x == 0) {
                    isSlantUp = not isSlantUp;
                    y++;
                } else {
                    x--;
                    y++;
                }
            } else {
                if (x == row - 1) {
                    isSlantUp = not isSlantUp;
                    y++;
                } else if (y == 0) {
                    isSlantUp = not isSlantUp;
                    x++;
                } else {
                    x++;
                    y--;
                }
            }
        }
        return ans;
    }
};