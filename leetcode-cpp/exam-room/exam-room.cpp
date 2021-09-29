//
// Created by l30014168 on 2021/9/29.
//

#include <set>
#include <unordered_map>
#include <vector>

// 用一个二叉平衡树(set)维护所有当前空闲的区间，同时用两个哈希表记录每个位置左边和右边有那些区间（这样在有人离开座位，需要合并区间的时候就会更加方便。）

// 区间类
class Interval {
public:
    int left, right;
    int num;       // num代表下一次分配座位号

    Interval(int left, int right, int num) : left(left), right(right), num(num) {}

    bool operator<(const Interval &that) const {
        auto diff = std::abs(this->getDis() - that.getDis());
        if (diff <= 1) {
            return this->num < that.num;            // 区间长度差距在1以内，返回靠前的
        }
        return this->getDis() > that.getDis();        // 排序优先返回最大区间
    }

private:
    inline int getDis() const {
        return right - left;
    }
};

class ExamRoom {
private:
    int n;      // 座位数量
    std::unordered_map<int, std::vector<Interval>> leftMap, rightMap;
    std::set<Interval> intervalSet;

    // 添加一个区间
    void addInterval(int left, int right) {
        if (left >= right) {
            return;
        }
        auto num = (left + right) / 2;
        if (left == 0) {
            num = 0;
        } else if (right == n - 1) {
            num = n - 1;
        }
        auto interval = Interval(left, right, num);
        intervalSet.insert(interval);
        leftMap[right].emplace_back(interval);
        rightMap[left].emplace_back(interval);
    }

    // 在set中删除该节点， 在左右节点map删除该区间
    void removeInterval(Interval &interval) {
        intervalSet.erase(interval);
        leftMap[interval.right].clear();        // 这里不采用erase，仅清空value，不删除key,以便后需添加
        rightMap[interval.left].clear();
    }

public:
    explicit ExamRoom(int n) {
        this->n = n;
        auto whole = Interval(0, n - 1, 0);
        intervalSet.insert(whole);          // 添加 0 ~ n-1 区间段
        rightMap[0].emplace_back(whole);       // 0 的右边添加该区间
        leftMap[n - 1].emplace_back(whole);    // n-1 的左边添加该区间
    }

    // 分配一个座位
    int seat() {
        auto best = *intervalSet.begin();
        removeInterval(best);
        addInterval(best.left, best.num);
        addInterval(best.num, best.right);
        return best.num;
    }

    // 释放一个座位
    void leave(int p) {
        auto left = p, right = p;        // 删除p的左右区间后，合并的新区间
        if (not leftMap[p].empty()) {
            auto leftInr = leftMap[p].front();
            left = leftInr.left;
            removeInterval(leftInr);
        }
        if (not rightMap[p].empty()) {
            auto rightInr = rightMap[p].front();
            right = rightInr.right;
            removeInterval(rightInr);
        }
        addInterval(left, right);
    }
};
