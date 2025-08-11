//
// Created by l30014168 on 25-8-11.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <queue>
#include <vector>

template<typename T=size_t>
class Graph {
public:
    explicit Graph(T _vertex) : vertex(_vertex) {
        indegree.resize(vertex, 0);
        outdegree.resize(vertex, 0);
        edges.resize(vertex, {});
    };

    void addEdge(T start, T end) {
        edges[start].emplace_back(end);
        ++outdegree[start];
        ++indegree[end];
    }

    void topologicalSort(bool &canSort, std::vector<T> &topoSortRet) const {
        auto indegreeCopy = std::vector(indegree);
        std::queue<size_t> indegreeZeroQueue; // 入度为0的队列
        for (T i = 0; i < vertex; ++i) {
            if (indegreeCopy[i] == 0) {
                indegreeZeroQueue.emplace(i);
                topoSortRet.emplace_back(i);
            }
        }
        size_t count = 0; // 记录当前已经输出的顶点数
        while (not indegreeZeroQueue.empty()) {
            auto start = indegreeZeroQueue.front();
            indegreeZeroQueue.pop();
            count++;
            for (const auto &end: edges[start]) {
                --indegreeCopy[end];
                if (indegreeCopy[end] == 0) {
                    indegreeZeroQueue.emplace(end);
                    topoSortRet.emplace_back(end);
                }
            }
        }
        canSort = count == vertex; // 如果被记录的点比总数不等（小于），认为无法完成拓扑排序
    }

private:
    size_t vertex;
    std::vector<T> indegree, outdegree; // 入度和出度
    std::vector<std::vector<T> > edges;
};

#endif //GRAPH_H
