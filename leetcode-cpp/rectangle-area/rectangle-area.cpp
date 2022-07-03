//
// Created by smile on 2022/7/2.
//

class Solution {
public:
    static int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        auto rectAreaA = getRectArea(ax1, ay1, ax2, ay2);
        auto rectAreaB = getRectArea(bx1, by1, bx2, by2);
        auto rectAndArea = getTwoRectAndArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        if (rectAndArea == 0) {
            rectAndArea = getTwoRectAndArea(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2);
        }
        return rectAreaA + rectAreaB - rectAndArea;
    }

private:
    // 计算矩形面积
    static int getRectArea(int x1, int y1, int x2, int y2) {
        return std::abs(x1 - x2) * std::abs(y1 - y2);
    }

    // 计算矩形相交面积
    static int getTwoRectAndArea(int ax1, int ay1, int ax2, int ay2,
                                 int bx1, int by1, int bx2, int by2) {
        uint8_t pointInRectNum = 0;
        bool isLUInRect = false, isRUInRect = false, isLDInRect = false, isRDInRect = false;
        if (isPointInRect(ax1, ay2, bx1, by1, bx2, by2)) {
            isLUInRect = true;
            pointInRectNum++;
        }
        if (isPointInRect(ax2, ay2, bx1, by1, bx2, by2)) {
            isRUInRect = true;
            pointInRectNum++;
        }
        if (isPointInRect(ax1, ay1, bx1, by1, bx2, by2)) {
            isLDInRect = true;
            pointInRectNum++;
        }
        if (isPointInRect(ax2, ay1, bx1, by1, bx2, by2)) {
            isRDInRect = true;
            pointInRectNum++;
        }
        if (pointInRectNum == 4) {
            return getRectArea(ax1, ay1, ax2, ay2);
        }
        if (pointInRectNum == 1) {
            if (isLUInRect) {
                return getRectArea(ax1, ay2, bx2, by1);
            }
            if (isRUInRect) {
                return getRectArea(ax2, ay2, bx1, by1);
            }
            if (isLDInRect) {
                return getRectArea(ax1, ay1, bx2, by2);
            }
            if (isRDInRect) {
                return getRectArea(ax2, ay1, bx1, by2);
            }
        }
        if (pointInRectNum == 2) {
            if (isLUInRect and isRUInRect) {        // 上边
                return getRectArea(ax1, ay2, ax2, by1);
            }
            if (isLDInRect and isRDInRect) {        // 下边
                return getRectArea(ax1, by2, ax2, ay1);
            }
            if (isLUInRect and isLDInRect) {        // 左边
                return getRectArea(ax1, ay2, bx2, ay1);
            }
            if (isRUInRect and isRDInRect) {        // 右边
                return getRectArea(bx1, ay2, ax2, ay1);
            }
        }
        if (pointInRectNum == 0) {
            if ((ax1 <= bx1 && bx2 <= ax2) && (by1 <= ay1 && ay2 <= by2)) {
                return getRectArea(bx1, ay2, bx2, ay1);
            }
        }
        return 0;
    }

    // 判断点是否在矩形内
    static bool isPointInRect(int x, int y,
                              int rx0, int ry0, int rx1, int ry1) {
        return (rx0 <= x and x <= rx1) and (ry0 <= y and y <= ry1);
    }
};