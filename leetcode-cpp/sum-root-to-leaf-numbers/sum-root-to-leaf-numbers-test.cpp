//
// Created by smile on 2021/5/8.
//

#include <gtest/gtest.h>
#include <vector>

#include "sum-root-to-leaf-numbers.cpp"

namespace {
    TEST(sumNumbersTest, Example1) {    // NOLINT
        auto root = BinaryTree::createByNums({1, 2, 3});
        auto ans = Solution().sumNumbers(root);
        auto rightAns = 25;
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }

    TEST(sumNumbersTest, Example2) {    // NOLINT
        auto root = BinaryTree::createByNums({4, 9, 0, 5, 1});
        auto ans = Solution().sumNumbers(root);
        auto rightAns = 1026;
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}