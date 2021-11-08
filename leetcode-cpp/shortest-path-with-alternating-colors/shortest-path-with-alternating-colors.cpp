//
// Created by l30014168 on 2021/11/8.
//

#include <vector>

const int INF_DIS = -1;

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges) {
        dis.resize(n, INF_DIS);
        dis[0] = 0;
        redEdges.resize(n, {});
        blueEdges.resize(n, {});
        redVis.resize(n, false);
        blueVis.resize(n, false);

        for (const auto &redEdge: red_edges) {
            redEdges[redEdge[0]].emplace_back(redEdge[1]);
        }
        for (const auto &blueEdge: blue_edges) {
            blueEdges[blueEdge[0]].emplace_back(blueEdge[1]);
        }
        redVis.resize(n, false);
        blueVis.resize(n, false);
        blueVis[0] = true;
        dfsSolver(0, 0, false);    // 先走红色
        redVis.resize(n, false);
        blueVis.resize(n, false);
        redVis[0] = true;
        dfsSolver(0, 0, true);     // 再走蓝色
        return dis;
    }

private:
    vector<int> dis;
    vector<vector<int>> redEdges;           // redEdges[i] 表示i点的所有红色出边
    vector<vector<int>> blueEdges;          // blueEdges[i] 表示i点的所有蓝色出边
    vector<bool> redVis;                    // 红边指向的节点是否被访问过
    vector<bool> blueVis;

    void dfsSolver(int node, int step, bool isPreRedEdge) {
        cout << node <<endl;
        auto nextEdges = isPreRedEdge ? blueEdges : redEdges;
        auto nextVis = isPreRedEdge ? blueVis : redVis;
        for (auto &nextNode: nextEdges[node]) {
            if (dis[nextNode] == INF_DIS or dis[nextNode] < step + 1) {
                dis[nextNode] = step + 1;
                if (nextVis[nextNode]) {
                    continue;
                }
                nextVis[nextNode] = true;
                dfsSolver(nextNode, step + 1, not isPreRedEdge);
            }
        }
    }
};