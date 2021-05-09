//
// Created by smile on 2021/5/9.
//

#include <benchmark/benchmark.h>
#include "populating-next-right-pointers-in-each-node.cpp"

auto root = new Node(
        1,
        new Node(
                2,
                new Node(4),
                new Node(5),
                nullptr
        ),
        new Node(
                3,
                new Node(6),
                new Node(7),
                nullptr
        ),
        nullptr
);

void resumeNodeTree(Node *node) {
    if (node == nullptr) {
        return;
    }
    node->next = nullptr;
    resumeNodeTree(node->left);
    resumeNodeTree(node->right);
}

// method1: time: O(n) space: O(n)
static void BFSMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution().BFSConnect(root);
        // resume
        state.PauseTiming();
        resumeNodeTree(root);
        state.ResumeTiming();
    }
}
BENCHMARK(BFSMethod); // NOLINT

// method2: time: O(n) space: O(1)
static void DFSMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution().DFSConnect(root);
        // resume
        state.PauseTiming();
        resumeNodeTree(root);
        state.ResumeTiming();
    }
}
BENCHMARK(DFSMethod); // NOLINT



BENCHMARK_MAIN();