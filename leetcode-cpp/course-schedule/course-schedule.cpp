//
// Created by smile on 2022/2/14.
//

#include <vector>
#include <memory>
#include <Graph.h>


class Solution {
public:
    static bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        auto graph = std::make_unique<Graph<int>>(numCourses);
        for (auto const &prerequisite: prerequisites) {
            graph->addEdge(prerequisite[0], prerequisite[1]);
        }
        bool ans;
        std::vector<int> topoSort;
        graph->topologicalSort(ans, topoSort);
        return ans;
    }
};