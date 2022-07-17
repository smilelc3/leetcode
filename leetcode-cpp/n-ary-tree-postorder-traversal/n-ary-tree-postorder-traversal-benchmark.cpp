//
// Created by smile on 2022/7/17.
//

#include <benchmark/benchmark.h>
#include "TreeNode.h"
#include "n-ary-tree-postorder-traversal.cpp"

static Node *root = nullptr;

static void DoSetup(const benchmark::State &state) {
    root = new Node(1);
    root->children.emplace_back(new Node(3));
    root->children.emplace_back(new Node(2));
    root->children.emplace_back(new Node(4));
    root->children[0]->children.emplace_back(new Node(5));
    root->children[0]->children.emplace_back(new Node(6));

}

static void DoTeardown(const benchmark::State &state) {
    delete root->children[0]->children[0];
    delete root->children[0]->children[1];
    delete root->children[0];
    delete root->children[1];
    delete root->children[2];
    delete root;
}

// 递归方案测试
static void benchPostorderRecursiveMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution().postorderRecursiveMethod(root);
    }
}

BENCHMARK(benchPostorderRecursiveMethod)->Setup(DoSetup)->Teardown(DoTeardown); //NOLINT

// 迭代方案测试
static void benchPostorderIterMethod(benchmark::State &state) {
    for (auto _: state) {
        Solution().postorderIterMethod(root);
    }
}

BENCHMARK(benchPostorderIterMethod)->Setup(DoSetup)->Teardown(DoTeardown);; //NOLINT

BENCHMARK_MAIN();