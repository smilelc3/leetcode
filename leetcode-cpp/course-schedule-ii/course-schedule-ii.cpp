//
// Created by smile on 25-8-11.
//

#include <vector>
#include <Graph.h>

class Solution {
public:
    static std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        auto graph = std::make_unique<Graph<int>>(numCourses);
        for (auto const &prerequisite: prerequisites) {
            graph->addEdge(prerequisite[1], prerequisite[0]);
        }
        bool canSort;
        std::vector<int> topoSort;
        graph->topologicalSort(canSort, topoSort);
        return ((canSort) ? topoSort : std::vector<int>{});
    }
};