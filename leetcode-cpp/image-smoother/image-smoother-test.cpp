//
// Created by smile on 2023/10/9.
//

#include <gtest/gtest.h>
#include "image-smoother.cpp"

namespace {
    TEST(imageSmootherTest, Example1) {      // NOLINT
        std::vector<std::vector<int>> img = {{1, 1, 1},
                                             {1, 0, 1},
                                             {1, 1, 1}};
        auto ans = Solution::imageSmoother(img);
        decltype(ans) rightAns = {{0, 0, 0},
                                  {0, 0, 0},
                                  {0, 0, 0}};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(imageSmootherTest, Example2) {      // NOLINT
        std::vector<std::vector<int>> img = {{100, 200, 100},
                                             {200, 50,  200},
                                             {100, 200, 100}};
        auto ans = Solution::imageSmoother(img);
        decltype(ans) rightAns = {{137, 141, 137},
                                  {141, 138, 141},
                                  {137, 141, 137}};
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}