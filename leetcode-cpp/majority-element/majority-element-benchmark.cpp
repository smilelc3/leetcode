//
// Created by smile on 2021/6/14.
//

#include <benchmark/benchmark.h>
#include "majority-element.cpp"

static std::vector<int> nums = {4, 2, 0, 4, 2, 1, 5, 4, 4, 1, 1, 2, 4, 4, 2, 0, 4, 4};


static void bitsMethod(benchmark::State &state) {
    for (auto _: state) {
        benchmark::DoNotOptimize(Solution().bitsMethod(nums));
    }
}

BENCHMARK(bitsMethod);      // NOLINT


static void majorityVoteAlgorithm(benchmark::State &state) {
    for (auto _: state) {
        benchmark::DoNotOptimize(Solution().majorityVoteAlgorithm(nums));
    }
}

BENCHMARK(majorityVoteAlgorithm);   // NOLINT

BENCHMARK_MAIN();