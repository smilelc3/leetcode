//
// Created by smile on 2021/5/2.
//

#include <gtest/gtest.h>
#include "max-points-on-a-line.cpp"

namespace {
    TEST(maxPointsTest, Example1) {
        std::vector<std::vector<int>> points = {{1, 1},
                                                {2, 2},
                                                {3, 3}};
        auto ans = Solution().maxPoints(points);
        int rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }


    TEST(maxPointsTest, Example2) {
        std::vector<std::vector<int>> points = {{1, 1},
                                                {3, 2},
                                                {5, 3},
                                                {4, 1},
                                                {2, 3},
                                                {1, 4}};
        auto ans = Solution().maxPoints(points);
        int rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(maxPointsTest, Example3) {
        std::vector<std::vector<int>> points = {{-783, -667},
                                                {-870, -747},
                                                {87,   133},
                                                {0,    53},
                                                {261,  293},
                                                {-609, -507},
                                                {-435, -347},
                                                {870,  853},
                                                {435,  453},
                                                {609,  613},
                                                {174,  213},
                                                {-261, -187},
                                                {-348, -267},
                                                {-87,  -27},
                                                {-174, -107},
                                                {783,  773},
                                                {696,  693}};
        auto ans = Solution().maxPoints(points);
        int rightAns = 17;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}