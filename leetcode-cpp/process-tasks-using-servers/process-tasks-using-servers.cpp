//
// Created by smile on 2021/11/29.
//

#include <vector>
#include <queue>

// 服务器类
class Server {
public:
    int weight;
    int idx;

    explicit Server(int _weight, int _serverIdx) : weight(_weight), idx(_serverIdx) {}

    // 重载大于用于小根堆，排序比较规则，优先权重小的，权重相同就序号小的
    bool operator>(const Server &that) const {
        if (this->weight != that.weight) {
            return this->weight > that.weight;
        }
        return this->idx > that.idx;
    }
};

// 在处理中的任务类
class TaskInProcess {
public:
    int serverIdx;
    int finishTime;

    explicit TaskInProcess(int _serverIdx, int _finishTime) : serverIdx(_serverIdx), finishTime(_finishTime) {}

    // 重载大于用于小根堆，排序比较规则，优先返回处理完成的时间
    bool operator>(const TaskInProcess that) const {
        return this->finishTime > that.finishTime;
    }
};

class Solution {
public:
    static std::vector<int> assignTasks(std::vector<int> &servers, std::vector<int> &tasks) {
        std::priority_queue<Server, std::vector<Server>, std::greater<>> seversQueue;
        std::priority_queue<TaskInProcess, std::vector<TaskInProcess>, std::greater<>> tasksQueue;
        for (int idx = 0; idx < servers.size(); ++idx) {
            seversQueue.emplace(Server(servers[idx], idx));
        }
        auto ans = std::vector<int>(tasks.size());
        auto curTime = 0;
        for (auto taskIdx = 0; taskIdx < tasks.size(); ++taskIdx) {
            if (seversQueue.empty()) {
                // 没有可用服务器，直接跳转到最近一次任务释放时间点
                const auto &taskDone = tasksQueue.top();
                curTime = taskDone.finishTime;
                seversQueue.emplace(Server(servers[taskDone.serverIdx], taskDone.serverIdx));
                tasksQueue.pop();
            }
            if (taskIdx > curTime) {
                curTime = taskIdx;
            }
            // 出队所有可能同时结束的任务
            while (not tasksQueue.empty() and tasksQueue.top().finishTime == curTime) {
                const auto &taskDone = tasksQueue.top();
                seversQueue.emplace(Server(Server(servers[taskDone.serverIdx], taskDone.serverIdx)));
                tasksQueue.pop();
            }
            // 分配任务给最小权重服务器
            const auto &server = seversQueue.top();
            tasksQueue.emplace(TaskInProcess(server.idx, curTime + tasks[taskIdx]));
            ans[taskIdx] = server.idx;
            seversQueue.pop();
        }

        return ans;
    }
};