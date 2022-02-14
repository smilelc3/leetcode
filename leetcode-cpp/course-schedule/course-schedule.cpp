//
// Created by smile on 2022/2/14.
//

#include <vector>
#include <queue>
#include <memory>

class Graph {

public:
    explicit Graph(size_t _vertex) : vertex(_vertex) {
        indegree.resize(vertex, 0);
        outdegree.resize(vertex, 0);
        edges.resize(vertex, {});
    };

    void addEdge(size_t start, size_t end) {
        edges[start].emplace_back(end);
        outdegree[start]++;
        indegree[end]++;

    }

    bool topologicalSort() const {
        auto indegreeCopy = std::vector<size_t>(indegree);
        std::queue<size_t> indegreeZeroQueue;       // 入度为0的队列
        for (size_t i = 0; i < vertex; ++i) {
            if (indegreeCopy[i] == 0) {
                indegreeZeroQueue.emplace(i);
            }
        }
        size_t count = 0;   // 记录当前已经输出的顶点数
        while (not indegreeZeroQueue.empty()) {
            auto start = indegreeZeroQueue.front();
            indegreeZeroQueue.pop();
            count++;
            for (const auto &end: edges[start]) {
                indegreeCopy[end]--;
                if (indegreeCopy[end] == 0) {
                    indegreeZeroQueue.emplace(end);
                }
            }
        }
        return count == vertex;     // 如果被记录的点比总数不等（小于），认为无法完成拓扑排序
    }

private:
    size_t vertex;
    std::vector<size_t> indegree, outdegree;        // 入度和出度
    std::vector<std::vector<size_t>> edges;

};


class Solution {
public:
    static bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        auto graph = std::make_shared<Graph>(numCourses);
        for (auto const &prerequisite: prerequisites) {
            graph->addEdge(prerequisite[0], prerequisite[1]);
        }

        return graph->topologicalSort();
    }
};