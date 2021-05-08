//
// Created by smile on 2021/5/8.
//

#include <benchmark/benchmark.h>
#include "TreeNode.h"
#include "surrounded-regions.cpp"

static std::vector<std::vector<char>> board = {{'O', 'X', 'X', 'O', 'X'}, // NOLINT
                                        {'X', 'O', 'O', 'X', 'O'},
                                        {'X', 'O', 'X', 'O', 'X'},
                                        {'O', 'X', 'O', 'O', 'O'},
                                        {'X', 'X', 'O', 'X', 'O'}};

// method1
static void benchMethod1(benchmark::State &state) {
    for (auto _: state) {
        auto boardCopy = board;
        Solution().boolStaCompSolve(boardCopy);
    }
}

BENCHMARK(benchMethod1); //NOLINT

// method2
static void benchMethod2(benchmark::State &state) {
    for (auto _: state) {
        auto boardCopy = board;
        Solution().alterBoardSolve(boardCopy);
    }
}

BENCHMARK(benchMethod2); //NOLINT

BENCHMARK_MAIN();