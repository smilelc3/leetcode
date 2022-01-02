//
// Created by smile on 2022/1/2.
//

#include <benchmark/benchmark.h>
#include "find-the-winner-of-the-circular-game.cpp"

static int k = 500, n = 500;


static void findTheWinnerVectorSimMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution::findTheWinnerVectorSimMethod(n, k);
    }
}
BENCHMARK(findTheWinnerVectorSimMethod);      // NOLINT

static void findTheWinnerVectorSkipMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution::findTheWinnerVectorSkipMethod(n, k);
    }
}
BENCHMARK(findTheWinnerVectorSkipMethod);      // NOLINT

static void findTheWinnerLinkSkipMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution::findTheWinnerLinkSkipMethod(n, k);
    }
}
BENCHMARK(findTheWinnerLinkSkipMethod);      // NOLINT

static void findTheWinnerDpMethod(benchmark::State &state) {
    for (auto _: state) {
        benchmark::DoNotOptimize(Solution::findTheWinnerDpMethod(n, k));
    }
}
BENCHMARK(findTheWinnerDpMethod);      // NOLINT

BENCHMARK_MAIN();