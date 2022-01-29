//
// Created by smile on 2021/6/18.
//

#include <gtest/gtest.h>
#include "binary-tree-right-side-view.cpp"

namespace {
    TEST(rightSideViewTest, Example1) {     // NOLINT
        auto root = TreeCreateByNums({1, 2, 3, -1, 5, -1, 4}, -1);
        auto ans = Solution().rightSideView(root);
        decltype(ans) rightAns = {1, 3, 4};
        ASSERT_EQ(ans, rightAns);
        TreeDestroy(root);
    }

    TEST(rightSideViewTest, Example2) {     // NOLINT
        auto root = TreeCreateByNums({1, -1, 3}, -1);
        auto ans = Solution().rightSideView(root);
        decltype(ans) rightAns = {1, 3};
        ASSERT_EQ(ans, rightAns);
        TreeDestroy(root);
    }

    TEST(rightSideViewTest, Example3) {     // NOLINT
        auto root = TreeCreateByNums({});
        auto ans = Solution().rightSideView(root);
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);
        TreeDestroy(root);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}