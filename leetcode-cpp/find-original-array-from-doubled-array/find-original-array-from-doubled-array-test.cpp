//
// Created by smile on 2021/11/19.
//

#include <gtest/gtest.h>
#include "find-original-array-from-doubled-array.cpp"

namespace {
    TEST(findOriginalArrayTest, Example1) {   // NOLINT
        std::vector<int> changed = {1, 3, 4, 2, 6, 8};
        auto ans = Solution().findOriginalArray(changed);
        decltype(ans) rightAns = {1, 3, 4};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(findOriginalArrayTest, Example2) {   // NOLINT
        std::vector<int> changed = {6, 3, 0, 1};
        auto ans = Solution().findOriginalArray(changed);
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(findOriginalArrayTest, Example3) {   // NOLINT
        std::vector<int> changed = {1};
        auto ans = Solution().findOriginalArray(changed);
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}