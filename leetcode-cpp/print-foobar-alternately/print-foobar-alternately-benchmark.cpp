//
// Created by smile on 2022/10/4.
//
//

#include <sstream>
#include <thread>
#include <benchmark/benchmark.h>
#include "print-foobar-alternately.cpp"

static std::stringstream ss;

// thread yield
static void benchFooBarThreadYield(benchmark::State &state) {
    for (auto _: state) {
        state.PauseTiming();
        ss.str("");
        state.ResumeTiming();
        auto obj = std::make_unique<FooBar>(state.range(0));
        std::thread threadA([](std::unique_ptr<FooBar> &obj) {
            obj->foo([] { ss << "foo"; });
        }, std::ref(obj));
        std::thread threadB([](std::unique_ptr<FooBar> &obj) {
            obj->bar([] { ss << "bar"; });
        }, std::ref(obj));
        threadA.join();
        threadB.join();
    }
}

BENCHMARK(benchFooBarThreadYield)->DenseRange(256, 1024, 256);    // NOLINT


// 条件变量锁
static void benchFooBarConditionVariable(benchmark::State &state) {
    for (auto _: state) {
        state.PauseTiming();
        ss.str("");
        state.ResumeTiming();
        auto obj = std::make_unique<FooBar2>(state.range(0));
        std::thread threadA([](std::unique_ptr<FooBar2> &obj) {
            obj->foo([] { ss << "foo"; });
        }, std::ref(obj));
        std::thread threadB([](std::unique_ptr<FooBar2> &obj) {
            obj->bar([] { ss << "bar"; });
        }, std::ref(obj));
        threadA.join();
        threadB.join();
    }
}

BENCHMARK(benchFooBarConditionVariable)->DenseRange(256, 1024, 256);  // NOLINT

BENCHMARK_MAIN();
