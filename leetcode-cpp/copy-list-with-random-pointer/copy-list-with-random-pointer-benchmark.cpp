//
// Created by smile on 2021/5/9.
//

#include <benchmark/benchmark.h>
#include "copy-list-with-random-pointer.cpp"

// copyRandomListUsingTwoTraverWithMap  time: O(2n) space: O(n)
static void benchCopyRandomListUsingTwoTraverWithMap(benchmark::State &state) {
    auto head = Node(7);
    auto Node1 = Node(13);
    auto Node2 = Node(11);
    auto Node3 = Node(10);
    auto Node4 = Node(1);

    head.next = &Node1;
    Node1.next = &Node2;
    Node2.next = &Node3;
    Node3.next = &Node4;

    Node1.random = &head;
    Node3.random = &Node2;
    Node4.random = &head;

    for (auto _: state) {
        auto pHeadCopy = Solution().copyRandomListUsingTwoTraverWithMap(&head);
        state.PauseTiming();
        Solution().destroyList(pHeadCopy);
        state.ResumeTiming();
    }
}

BENCHMARK(benchCopyRandomListUsingTwoTraverWithMap);    // NOLINT


// copyRandomListUsingThreeTraver  time: O(3n) space: O(1)
static void benchCopyRandomListUsingThreeTraver(benchmark::State &state) {
    auto head = Node(7);
    auto Node1 = Node(13);
    auto Node2 = Node(11);
    auto Node3 = Node(10);
    auto Node4 = Node(1);

    head.next = &Node1;
    Node1.next = &Node2;
    Node2.next = &Node3;
    Node3.next = &Node4;

    Node1.random = &head;
    Node3.random = &Node2;
    Node4.random = &head;
    for (auto _: state) {
        auto pHeadCopy = Solution().copyRandomListUsingThreeTraver(&head);
        state.PauseTiming();
        Solution().destroyList(pHeadCopy);
        state.ResumeTiming();
    }
}

BENCHMARK(benchCopyRandomListUsingThreeTraver);  // NOLINT


BENCHMARK_MAIN();
