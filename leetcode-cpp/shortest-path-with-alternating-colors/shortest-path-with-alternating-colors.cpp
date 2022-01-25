//
// Created by smile on 2021/11/8.
//

#include <vector>

const int INF_DIS = -1;

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges) {
        redDis.resize(n, INF_DIS);
        blueDis.resize(n, INF_DIS);
        redDis[0] = blueDis[0] = 0;
        redEdges.resize(n, {});
        blueEdges.resize(n, {});

        for (const auto &redEdge: red_edges) {
            redEdges[redEdge[0]].emplace_back(redEdge[1]);
        }
        for (const auto &blueEdge: blue_edges) {
            blueEdges[blueEdge[0]].emplace_back(blueEdge[1]);
        }
        blueDis[0] = 0;
        dfsSolver(0, 0, false);    // 先走红色
        redDis[0] = 0;
        dfsSolver(0, 0, true);     // 再走蓝色

        auto dis = vector<int>(n);
        for (auto i = 0; i < n; ++i) {
            if (redDis[i] != INF_DIS and blueDis[i] != INF_DIS) {
                dis[i] = min(redDis[i], blueDis[i]);
            } else {
                dis[i] = redDis[i] == INF_DIS ? blueDis[i] : redDis[i];
            }
        }
        return dis;
    }

private:
    vector<int> redDis, blueDis;                // 红边/蓝边到达的最短距离
    vector<vector<int>> redEdges, blueEdges;    // i点的所有红色/蓝色出边

    void dfsSolver(int node, int step, bool isPreRedEdge) {
        auto &nextEdges = isPreRedEdge ? blueEdges : redEdges;
        auto &nextDis = isPreRedEdge ? blueDis : redDis;
        for (auto &nextNode: nextEdges[node]) {
            if (nextDis[nextNode] == INF_DIS or nextDis[nextNode] > step + 1) {     // 仅考虑未更新节点或可缩近节点
                nextDis[nextNode] = step + 1;
                dfsSolver(nextNode, step + 1, not isPreRedEdge);
            }
        }
    }
};