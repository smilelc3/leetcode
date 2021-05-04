//
// Created by smile on 2021/5/3.
//

#include <benchmark/benchmark.h>
#include "TreeNode.h"
#include "max-points-on-a-line.cpp"

// method1 : time: O(n^2) space: O(n^2)
static void benchMethod1(benchmark::State &state) {
    std::vector<std::vector<int>> points = {{1, 1},
                                            {3, 2},
                                            {5, 3},
                                            {4, 1},
                                            {2, 3},
                                            {1, 4}};
    for (auto _: state) {
        Solution().maxPointsMethod1(points);
    }
}

BENCHMARK(benchMethod1);

BENCHMARK_MAIN();