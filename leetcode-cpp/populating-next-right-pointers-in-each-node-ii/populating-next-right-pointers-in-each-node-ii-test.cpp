//
// Created by smile on 2021/5/9.
//

#include <gtest/gtest.h>
#include <vector>
#include "populating-next-right-pointers-in-each-node-ii.cpp"

namespace {
    TEST(pathSumTest, Example1) {   // NOLINT
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
                        nullptr,
                        new Node(7),
                        nullptr
                ),
                nullptr
        );
        auto ans = Solution().connect(root);

        ASSERT_EQ(ans->next, nullptr);
        ASSERT_EQ(ans->left->next, ans->right);
        ASSERT_EQ(ans->right->next, nullptr);
        ASSERT_EQ(ans->left->left->next, ans->left->right);
        ASSERT_EQ(ans->left->right->next, ans->right->right);
        ASSERT_EQ(ans->right->right->next, nullptr);
    }

    TEST(pathSumTest, Test0) {  // NOLINT
        auto root = new Node(
                2,
                new Node(
                        1,
                        new Node(
                                0,
                                new Node(2),
                                nullptr,
                                nullptr
                        ),
                        new Node(
                                7,
                                new Node(1),
                                new Node(
                                        0,
                                        new Node(7),
                                        nullptr,
                                        nullptr
                                ),
                                nullptr
                        ),
                        nullptr
                ),
                new Node(
                        3,
                        new Node(9),
                        new Node(
                                1,
                                new Node(8),
                                new Node(8),
                                nullptr
                        ),
                        nullptr
                ),
                nullptr
        );
        auto ans = Solution().connect(root);

        ASSERT_EQ(ans->left->right->right->next, ans->right->right->left);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}