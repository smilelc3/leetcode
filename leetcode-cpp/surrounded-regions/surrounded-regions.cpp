//
// Created by smile on 2021/5/7.
//

#include "BoolStaComp.h"

#include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char>> &board) {
        // method 1: 使用状态压缩 space: O(nm/8)
        //boolStaCompSolve(board);

        // method 2: 修改原board状态 space: O(1)
        alterBoardSolve(board);
    }

    void boolStaCompSolve(std::vector<std::vector<char>> &board) {
        if (board.empty()) {
            return;
        }
        m = board.size();
        n = board.front().size();
        if (m <= 2 or n <= 2) {
            return;
        }

        // 压缩数组
        hasVisit = BoolStaComp((m - 2) * (n - 2));

        // 遍历第一列和最后一列
        for (auto idx = 0; idx < m; idx++) {
            if (board.at(idx).front() == 'O') {
                dfsVisit(idx, 0, board);
            }
            if (board.at(idx).back() == 'O') {
                dfsVisit(idx, n - 1, board);
            }
        }
        // 遍历第一行和最后一行
        for (auto idx = 1; idx <= n - 1; idx++) {
            if (board.front().at(idx) == 'O') {
                dfsVisit(0, idx, board);
            }
            if (board.back().at(idx) == 'O') {
                dfsVisit(m - 1, idx, board);
            }
        }

        // 清空中间为未标记的cell
        for (auto i = 1; i <= m - 2; i++) {
            for (auto j = 1; j <= n - 2; j++) {
                if (not hasVisit.GetState(getLocByXY(i, j))) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void alterBoardSolve(std::vector<std::vector<char>> &board) {
        if (board.empty()) {
            return;
        }
        m = board.size();
        n = board.front().size();
        if (m <= 2 or n <= 2) {
            return;
        }

        // 遍历第一列和最后一列
        for (auto idx = 0; idx < m; idx++) {
            if (board.at(idx).front() == 'O') {
                dfsVisitAlter(idx, 0, board);
            }
            if (board.at(idx).back() == 'O') {
                dfsVisitAlter(idx, n - 1, board);
            }
        }

        // 遍历第一行和最后一行
        for (auto idx = 1; idx <= n - 1; idx++) {
            if (board.front().at(idx) == 'O') {
                dfsVisitAlter(0, idx, board);
            }
            if (board.back().at(idx) == 'O') {
                dfsVisitAlter(m - 1, idx, board);
            }
        }

        // 清空中间为未标记的cell
        for (auto i = 1; i <= m - 2; i++) {
            for (auto j = 1; j <= n - 2; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:

    BoolStaComp hasVisit = BoolStaComp(0);
    size_t m = 0, n = 0;

    void dfsVisit(size_t x, size_t y, std::vector<std::vector<char>> &board) {
        if (x >= 1 and x <= m - 2 and y >= 1 and y <= n - 2) {
            hasVisit.SetStateTrue(getLocByXY(x, y));
        }
        // 此时 x,y 合法
        // 遍历上下左右
        // (x-1, y)
        if (x >= 2 and isNotOnEdge(x - 1, y) and board[x - 1][y] == 'O'
            and not hasVisit.GetState(getLocByXY(x - 1, y))) {
            dfsVisit(x - 1, y, board);
        }
        // (x+1, y)
        if (isNotOnEdge(x + 1, y) and board[x + 1][y] == 'O'
            and not hasVisit.GetState(getLocByXY(x + 1, y))) {
            dfsVisit(x + 1, y, board);
        }
        // (x,y-1)
        if (y >= 2 and isNotOnEdge(x, y - 1) and board[x][y - 1] == 'O'
            and not hasVisit.GetState(getLocByXY(x, y - 1))) {
            dfsVisit(x, y - 1, board);
        }
        // (x,y+1)
        if (isNotOnEdge(x, y + 1) and board[x][y + 1] == 'O'
            and not hasVisit.GetState(getLocByXY(x, y + 1))) {
            dfsVisit(x, y + 1, board);
        }
    }

    void dfsVisitAlter(size_t x, size_t y, std::vector<std::vector<char>> &board) {
        if (x >= 1 and x <= m - 2 and y >= 1 and y <= n - 2) {
            board[x][y] = '1';
        }
        // 此时 x,y 合法
        // 遍历上下左右
        // (x-1, y)
        if (x >= 2 and isNotOnEdge(x - 1, y) and board[x - 1][y] == 'O'
            and board[x - 1][y] != '1') {
            dfsVisitAlter(x - 1, y, board);
        }
        // (x+1, y)
        if (isNotOnEdge(x + 1, y) and board[x + 1][y] == 'O'
            and board[x + 1][y] != '1') {
            dfsVisitAlter(x + 1, y, board);
        }
        // (x,y-1)
        if (y >= 2 and isNotOnEdge(x, y - 1) and board[x][y - 1] == 'O'
            and board[x][y - 1] != '1') {
            dfsVisitAlter(x, y - 1, board);
        }
        // (x,y+1)
        if (isNotOnEdge(x, y + 1) and board[x][y + 1] == 'O'
            and board[x][y + 1] != '1') {
            dfsVisitAlter(x, y + 1, board);
        }
    }

    constexpr size_t getLocByXY(size_t x, size_t y) const {
        return (x - 1) * (n - 2) + (y - 1);
    }

    constexpr bool isNotOnEdge(size_t x, size_t y) const {
        return x >= 1 and y >= 1 and x <= m - 2 and y <= n - 2;
    }

};