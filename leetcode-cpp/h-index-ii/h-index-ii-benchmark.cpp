//
// Created by l30014168 on 2022/10/18.
//

//
// Created by smile on 2022/10/4.
//
//

#include <vector>
#include <random>
#include <algorithm>
#include <benchmark/benchmark.h>
#include "h-index-ii.cpp"


static std::vector<int> citations(1e5);

static void initCitations() {
    std::random_device rd;
    auto eng = std::default_random_engine(rd());
    auto dist = std::uniform_int_distribution<int>(0, 1000);
    std::generate(citations.begin(), citations.end(), [&dist, &eng]() {
        return dist(eng);
    });
    std::sort(citations.begin(), citations.end(), std::less<>());
}

static void benchHIndex2LoopMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution::hIndexLoopMethod(citations);
    }
}

BENCHMARK(benchHIndex2LoopMethod);  // NOLINT

static void benchHIndexBinarySearchMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution::hIndexBinarySearchMethod(citations);
    }
}

BENCHMARK(benchHIndexBinarySearchMethod);  // NOLINT

int main(int argc, char **argv) {
    initCitations();
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
}
