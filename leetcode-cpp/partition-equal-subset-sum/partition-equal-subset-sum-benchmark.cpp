//
// Created by smile on 24-7-14.
//

#include <random>
#include <benchmark/benchmark.h>
#include "partition-equal-subset-sum.cpp"

std::vector<int> generateRandomNums() {
    std::random_device rd; // 用于获得一个随机数种子
    std::mt19937 gen(rd()); // 以随机数种子初始化一个梅森旋转器
    std::uniform_int_distribution length_dist(1, 200); // 1 <= nums.length <= 200
    std::uniform_int_distribution value_dist(1, 100); // 1 <= nums[i] <= 100

    const int length = length_dist(gen);
    std::vector<int> nums(length);
    for (int i = 0; i < length; ++i) {
        nums[i] = value_dist(gen);
    }
    return nums;
}

// vector<int8_t>
static void dpVectorCharMethod(benchmark::State &state) {
    for (auto _: state) {
        state.PauseTiming();
        std::vector<int> nums = generateRandomNums();
        state.ResumeTiming();
        Solution::canPartition<int8_t>(nums);
    }
}

BENCHMARK(dpVectorCharMethod); //NOLINT

// vector<bool>
static void dpVectorBoolMethod(benchmark::State &state) {
    for (auto _: state) {
        state.PauseTiming();
        std::vector<int> nums = generateRandomNums();
        state.ResumeTiming();
        Solution::canPartition<bool>(nums);
    }
}

BENCHMARK(dpVectorBoolMethod); // NOLINT

BENCHMARK_MAIN();
