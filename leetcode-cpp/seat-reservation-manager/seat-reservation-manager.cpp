//
// Created by smile on 2021/9/14.
//

#include <queue>

class SeatManager {
public:
    explicit SeatManager(int n) {

    }

    int reserve() {
        decltype(reserve()) ret;
        if (not minQueue.empty()) {
            ret = minQueue.top();
            minQueue.pop();
        } else {
            ret = ++cache;
        }
        return ret;
    }

    void unreserve(int seatNumber) {
        minQueue.emplace(seatNumber);
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<>> minQueue;
    int cache = 0;
};
