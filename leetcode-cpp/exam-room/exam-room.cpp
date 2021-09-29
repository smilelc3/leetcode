//
// Created by l30014168 on 2021/9/29.
//

#include <set>
#include <unordered_map>
#include <vector>

// 区间类
class Interval {
public:
    int left, right;
    int num;       // num代表下一次分配座位号
    static int n;

    Interval() = default;

    Interval(int left, int right, int num) : left(left), right(right), num(num) {}

    bool operator<(const Interval &that) const {
        auto thisDis = this->getFarDis(), thatDis = that.getFarDis();
        if (thisDis == thatDis) {
            return this->num < that.num;                // 距离相同，返回靠前的
        }
        return thisDis > thatDis;    // 排序优先返回最大距离
    }

private:
    inline int getFarDis() const {      // 获取临近最远距离
        decltype(getFarDis()) ret = this->right - this->left;       // 存在一边没有相邻
        if (this->left != 0 and this->right != n - 1) {
            ret >>= 1;
        }
        return ret;
    }
};

int Interval::n = 0;

class ExamRoom {
private:
    int n;      // 座位数量
    std::set<Interval> intervalSet;     // 用一个二叉平衡树(set)维护所有当前空闲的区间
    // 同时用两个哈希表记录每个位置左边和右边有那些区间（这样在有人离开座位，需要合并区间的时候就会更加方便。）
    std::unordered_map<int, Interval> leftMap, rightMap;

    // 添加一个区间
    void addInterval(int left, int right) {
        if (left > right) {
            return;
        }
        auto num = (left + right) / 2;
        if (left == 0) {
            num = 0;
        } else if (right == n - 1) {
            num = n - 1;
        }
        auto interval = Interval(left, right, num);
        intervalSet.emplace(interval);
        leftMap[right] = interval;
        rightMap[left] = interval;
    }

    // 在set中删除该节点， 在左右节点map删除该区间
    void removeInterval(Interval interval) {
        intervalSet.erase(interval);
        leftMap.erase(interval.right);
        rightMap.erase(interval.left);
    }

public:
    explicit ExamRoom(int n) {
        this->n = n;
        Interval::n = n;
        addInterval(0, n - 1);
    }

    // 分配一个座位
    int seat() {
        auto best = *intervalSet.begin();
        removeInterval(best);
        addInterval(best.left, best.num - 1);
        addInterval(best.num + 1, best.right);
        return best.num;
    }

    // 释放一个座位
    void leave(int p) {
        auto left = p, right = p;        // 删除p的左右区间后，合并的新区间
        auto find = leftMap.find(p - 1);
        if (find != leftMap.end()) {
            left = find->second.left;
            removeInterval(find->second);
        }
        find = rightMap.find(p + 1);
        if (find != rightMap.end()) {
            right = find->second.right;
            removeInterval(find->second);
        }
        addInterval(left, right);
    }
};
