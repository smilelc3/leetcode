//
// Created by smile on 2021/11/26.
//

#include <vector>
#include <algorithm>
#include <queue>

class FriendAction {
public:
    int moment;
    size_t friendIdx{};
    bool isArrival{};

    explicit FriendAction(int _moment, size_t _friendIdx, bool _isArrival) :
            moment(_moment), friendIdx(_friendIdx), isArrival(_isArrival) {}

    bool operator<(const FriendAction &that) const {
        if (this->moment != that.moment) {
            return this->moment < that.moment;
        }
        // 不会存在同时到达的情况，有可能同一时刻：一个到达，一个释放（释放优先）；或者同时释放
        return that.isArrival;
    }
};

class Solution {
public:
    static int smallestChair(std::vector<std::vector<int>> &times, int targetFriend) {
        std::vector<FriendAction> actions;
        std::vector<size_t> friendIdx2ChairNumMap(times.size());
        for (size_t idx = 0; idx < times.size(); ++idx) {
            if (times[idx][0] >= times[targetFriend][0]) {
                continue;   // 如果某人到达时间在目标到达之后，不记录统计(包括目标自己)
            }
            actions.emplace_back(FriendAction(times[idx][0], idx, true));
            if (times[idx][1] <= times[targetFriend][0]) {      // 仅记录某人释放时间在目标到达之前的（包括同时）
                actions.emplace_back(FriendAction(times[idx][1], idx, false));
            }
        }
        std::sort(actions.begin(), actions.end(), std::less<>());
        std::priority_queue<size_t, std::vector<size_t>, std::greater<>> smallestQueue;
        for (size_t idx = 0; idx < times.size(); ++idx) {
            smallestQueue.emplace(idx);
        }
        for (const auto &action: actions) {
            if (action.isArrival) {     // 到达，弹出最小可用座位
                friendIdx2ChairNumMap[action.friendIdx] = smallestQueue.top();
                smallestQueue.pop();
            } else {        // 离开释放获得的座位
                smallestQueue.emplace(friendIdx2ChairNumMap[action.friendIdx]);
            }
        }
        return (int) smallestQueue.top();
    }
};