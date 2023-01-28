//
// Created by lcsmile on 2023/1/28.
//

#include <random>
#include <benchmark/benchmark.h>
#include "queries-on-number-of-points-inside-a-circle.cpp"

std::vector<std::vector<int>> points(500);
std::vector<std::vector<int>> queries(500);

static void initData() {
    std::random_device rd;
    auto eng = std::default_random_engine(rd());
    auto distXY = std::uniform_int_distribution<int>(0, 500);
    auto distR = std::uniform_int_distribution<int>(1, 500);

    std::generate(points.begin(), points.end(), [&distXY, &eng]() {
        return std::vector<int>{distXY(eng), distXY(eng)};
    });
    std::generate(queries.begin(), queries.end(), [&distXY, &distR, &eng]() {
        return std::vector<int>{distXY(eng), distXY(eng), distR(eng)};
    });
}

static void benchCountPointsDoubleLoopMethod(benchmark::State &state) {
    for (auto _: state) {
        state.PauseTiming();
        auto pointsCopy = decltype(points)(points);
        auto queriesCopy = decltype(queries)(queries);
        state.ResumeTiming();
        Solution().countPointsDoubleLoopMethod(pointsCopy, queriesCopy);
    }
}

BENCHMARK(benchCountPointsDoubleLoopMethod);  // NOLINT

static void benchCountPointsSearchMethod(benchmark::State &state) {
    for (auto _: state) {
        state.PauseTiming();
        auto pointsCopy = decltype(points)(points);
        auto queriesCopy = decltype(queries)(queries);
        state.ResumeTiming();
        Solution().countPointsSearchMethod(pointsCopy, queriesCopy);
    }
}

BENCHMARK(benchCountPointsSearchMethod);  // NOLINT

int main(int argc, char **argv) {
    initData();
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
}
