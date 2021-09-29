//
// Created by l30014168 on 2021/9/29.
//

#include <set>
#include <unordered_map>
#include <vector>

// 用一个二叉平衡树(set)维护所有当前空闲的区间，同时用两个哈希表记录每个位置左边和右边是否有区间（这样在有人离开座位，需要合并区间的时候就会更加方便。）
struct Segment {
    int l, r, no, dist;

    bool operator<(const Segment &that) const {
        return this->dist > that.dist or (this->dist == that.dist and this->no < that.no);
    }
};

class ExamRoom {
private:
    int N;
    std::unordered_map<int, std::vector<Segment>> left, right;
    std::set<Segment> s;

    void add_segment(int l, int r) {
        l = std::max(l, 1);
        r = std::min(r, N);
        if (r < l) {
            return;
        }
        int mid = (l + r) / 2;
        int dist = mid - l + 1;
        if (l == 1) {
            mid = 1;
            dist = r;
        } else if (r == N) {
            mid = r;
            dist = r - l + 1;
        }
        Segment new_segment{l, r, mid, dist};
        s.insert(new_segment);
        left[r + 1].emplace_back(new_segment);
        right[l - 1].emplace_back(new_segment);
    }

    void remove_segment(Segment &segment) {
        left[segment.r + 1].clear();
        right[segment.l - 1].clear();
        s.erase(segment);
    }

public:
    explicit ExamRoom(int N) {
        this->N = N;
        Segment start{1, N, 1, N};
        s.insert(start);
        right[0].emplace_back(start);
        left[N + 1].emplace_back(start);
    }

    int seat() {
        Segment best = *s.begin();
        remove_segment(best);
        add_segment(best.l, best.no - 1);
        add_segment(best.no + 1, best.r);
        return best.no - 1;
    }

    void leave(int p) {
        p++;
        int l = p, r = p;
        if (not left[p].empty()) {
            Segment ls = left[p][0];
            l = ls.l;
            remove_segment(ls);
        }
        if (not right[p].empty()) {
            Segment rs = right[p][0];
            r = rs.r;
            remove_segment(rs);
        }
        add_segment(l, r);
    }
};
