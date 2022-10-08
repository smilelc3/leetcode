//
// Created by smile on 2022/1/4.
//

#include <vector>

class Coord {
public:
    int64_t row, col;

    explicit Coord(int64_t _row, int64_t _col) : row(_row), col(_col) {};

    bool operator==(const Coord &that) const {
        return this->col == that.col and this->row == that.row;
    }

    bool operator!=(const Coord &that) const {
        return not(*this == that);
    }
};


class Solution {
public:
    static bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        if (matrix.empty() or matrix.front().empty()) {
            return false;
        }
        // 四分查找
        // return searchMatrixBinaryMethod(matrix, target);

        // 转化为二叉查找树
        return searchMatrixBinaryTreeMethod(matrix, target);
    }

    static bool searchMatrixBinaryMethod(std::vector<std::vector<int>> &matrix, int target) {
        auto topLeft = Coord(0, 0);
        auto bottomRight = Coord(matrix.size() - 1, matrix.front().size() - 1);
        if (matrix[bottomRight.row][bottomRight.col] == target) {
            return true;
        }
        return searchMatrixBinaryMethodSolver(matrix, target, topLeft, bottomRight);
    }

    static bool searchMatrixBinaryMethodSolver(const std::vector<std::vector<int>> &matrix, int target,
                                               Coord &topLeftCoord, Coord &bottomRightCoord) {
        /*
         * 1,  4,  7,  8, 12
         * 2,  5,  8, 12, 19
         * 3,  6,  9, 16, 22
         * 4, 13, 14, 17, 24
         * 6, 21, 23, 26, 30
         * -> 划分为4个区域
         * 1,  4,  7
         * 2,  5,  8
         * 3,  6,  9
         *
         * 4, 13
         * 6, 21
         *
         *  8, 12
         * 12, 19
         *
         *  9, 16, 22
         * 14, 17, 24
         * 23, 26, 30
         */

        auto midMidCoord = Coord((topLeftCoord.row + bottomRightCoord.row) / 2,
                                 (topLeftCoord.col + bottomRightCoord.col) / 2);
        // 递归终点
        if (midMidCoord == topLeftCoord) {
            if (matrix[midMidCoord.row][midMidCoord.col] == target) {
                return true;
            }
            if (midMidCoord != bottomRightCoord) {
                if (matrix[bottomRightCoord.row][topLeftCoord.col] == target or
                    matrix[topLeftCoord.row][bottomRightCoord.col] == target) {
                    return true;
                }
            }
            return false;
        }
        if (matrix[midMidCoord.row][midMidCoord.col] == target) {
            return true;
        }
        // 先在右上角和左下角区域查找
        if (topLeftCoord.row < midMidCoord.row and midMidCoord.col < bottomRightCoord.col) {       // 右上角区域
            auto topRightAreaTopLeftCoord = Coord(topLeftCoord.row, midMidCoord.col + 1);
            auto topRightAreaBottomRightCoord = Coord(midMidCoord.row - 1, bottomRightCoord.col);
            if (searchMatrixBinaryMethodSolver(matrix, target, topRightAreaTopLeftCoord,
                                               topRightAreaBottomRightCoord)) {
                return true;
            }
        }
        if (midMidCoord.row < bottomRightCoord.row and midMidCoord.col > topLeftCoord.col) {      // 左下角区域
            auto bottomLeftAreaTopLeftCoord = Coord(midMidCoord.row + 1, topLeftCoord.col);
            auto bottomLeftAreaBottomRightCoord = Coord(bottomRightCoord.row, midMidCoord.col - 1);
            if (searchMatrixBinaryMethodSolver(matrix, target, bottomLeftAreaTopLeftCoord,
                                               bottomLeftAreaBottomRightCoord)) {
                return true;
            }
        }
        if (matrix[midMidCoord.row][midMidCoord.col] > target) { // 目标可能在左上角
            return searchMatrixBinaryMethodSolver(matrix, target, topLeftCoord, midMidCoord);
        } else {  // 目标可能在右下角
            return searchMatrixBinaryMethodSolver(matrix, target, midMidCoord, bottomRightCoord);
        }
    }

    static bool searchMatrixBinaryTreeMethod(std::vector<std::vector<int>> &matrix, int target) {
        // 从左下角开始搜索
        // matrix[i][j] > target -> i 上移
        // matrix[i][j] < target -> j 右移；
        // i,j 超出边界则矩阵中没有这个值，返回false
        auto matrixRow = matrix.size();
        auto matrixCol = matrix.front().size();
        auto coord = Coord((int64_t) matrixRow - 1, 0);
        while (coord.row >= 0 and coord.col < static_cast<decltype(coord.col)>(matrixCol)) {
            auto val = matrix[coord.row][coord.col];
            if (val > target) {
                coord.row--;
            } else if (val < target) {
                coord.col++;
            } else {
                return true;
            }
        }
        return false;
    }
};