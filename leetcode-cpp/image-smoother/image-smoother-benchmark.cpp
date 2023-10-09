//
// Created by smile on 2023/10/9.
//

#include <benchmark/benchmark.h>
#include <random>
#include "image-smoother.cpp"


auto img = std::vector<std::vector<int>>(200, std::vector<int>(200));
static void initData() {
    std::random_device rd;
    auto eng = std::default_random_engine(rd());
    auto dist = std::uniform_int_distribution<int>(0, 255);
    std::for_each(img.begin(), img.end(), [&dist, &eng](auto &t){
        std::generate(t.begin(), t.end(), [&dist, &eng]() {
            return dist(eng);
        });
    });
}

static void seqMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution::imageSmootherSeqMethod(img);
    }
}
BENCHMARK(seqMethod);  // NOLINT

#if defined(__cpp_lib_parallel_algorithm)
static void parallelMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution::imageSmootherParallelMethod(img);
    }
}
BENCHMARK(parallelMethod);  // NOLINT
#endif

int main(int argc, char **argv) {
    initData();
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
}
