//
// Created by smile on 2021/4/9.
//

#include <gtest/gtest.h>
#include "where-will-the-ball-fall.cpp"

namespace {
    TEST(findBallTest, Example1) {      // NOLINT
        std::vector<std::vector<int>> grid = {{1,  1,  1,  -1, -1},
                                              {1,  1,  1,  -1, -1},
                                              {-1, -1, -1, 1,  1},
                                              {1,  1,  1,  1,  -1},
                                              {-1, -1, -1, -1, -1}};
        auto ans = Solution().findBall(grid);
        decltype(ans) correctAns = {1, -1, -1, -1, -1};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(findBallTest, Example2) {      // NOLINT
        std::vector<std::vector<int>> grid = {{-1}};
        auto ans = Solution().findBall(grid);
        decltype(ans) correctAns = {-1};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(findBallTest, Example3) {      // NOLINT
        std::vector<std::vector<int>> grid = {{1,  1,  1,  1,  1,  1},
                                              {-1, -1, -1, -1, -1, -1},
                                              {1,  1,  1,  1,  1,  1},
                                              {-1, -1, -1, -1, -1, -1}};
        auto ans = Solution().findBall(grid);
        decltype(ans) correctAns = {0, 1, 2, 3, 4, -1};
        ASSERT_EQ(ans, correctAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
