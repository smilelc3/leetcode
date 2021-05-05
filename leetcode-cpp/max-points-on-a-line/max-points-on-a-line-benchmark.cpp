//
// Created by smile on 2021/5/3.
//

#include <benchmark/benchmark.h>
#include "TreeNode.h"
#include "max-points-on-a-line.cpp"

static std::vector<std::vector<int>> points = {{1, 1},
                                               {3, 2},
                                               {5, 3},
                                               {4, 1},
                                               {2, 3},
                                               {1, 4}};

// method1: time: O(n^2) space: O(n^2)
static void benchMethod1(benchmark::State &state) {
    for (auto _: state) {
        Solution().maxPointsMethod1(points);
    }
}

BENCHMARK(benchMethod1);

// method2: time: O(n^2) space: O(n^2)
static void benchMethod2(benchmark::State &state) {
    for (auto _: state) {
        Solution().maxPointsMethod2(points);
    }
}

BENCHMARK(benchMethod2);

BENCHMARK_MAIN();