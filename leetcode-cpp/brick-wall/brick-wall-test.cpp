//
// Created by smile on 2022/12/9.
//

#include <gtest/gtest.h>
#include "brick-wall.cpp"

namespace {
    TEST(leastBricksTest, Example1) {     // NOLINT
        auto ans = Solution().leastBricks({{1, 2, 2, 1},
                                           {3, 1, 2},
                                           {1, 3, 2},
                                           {2, 4},
                                           {3, 1, 2},
                                           {1, 3, 1, 1}});
        decltype(ans) rightAns = 2;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(leastBricksTest, Example2) {     // NOLINT
        auto ans = Solution().leastBricks({{1},
                                           {1},
                                           {1}});
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}