//
// Created by smile on 2021/11/26.
//

#include <gtest/gtest.h>
#include <vector>
#include "the-number-of-the-smallest-unoccupied-chair.cpp"

namespace {
    TEST(smallestChairTest, Example1) {      // NOLINT
        std::vector<std::vector<int>> times = {{1, 4},
                                               {2, 3},
                                               {4, 6}};
        int targetFriend = 1;
        auto ans = Solution().smallestChair(times, targetFriend);
        decltype(ans) correctAns = 1;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(smallestChairTest, Example2) {      // NOLINT
        std::vector<std::vector<int>> times = {{3, 10},
                                               {1, 5},
                                               {2, 6}};
        int targetFriend = 0;
        auto ans = Solution().smallestChair(times, targetFriend);
        decltype(ans) correctAns = 2;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(smallestChairTest, Test0) {      // NOLINT
        std::vector<std::vector<int>> times = {{3,  100000},
                                               {13, 100000},
                                               {27, 100000},
                                               {10, 100000},
                                               {21, 100000},
                                               {38, 100000},
                                               {11, 100000},
                                               {46, 100000},
                                               {2,  100000},
                                               {33, 100000},
                                               {20, 100000},
                                               {8,  100000},
                                               {35, 100000},
                                               {43, 100000},
                                               {23, 100000},
                                               {22, 100000},
                                               {15, 100000},
                                               {44, 100000},
                                               {45, 100000},
                                               {7,  100000},
                                               {24, 100000},
                                               {42, 100000},
                                               {6,  100000},
                                               {1,  100000},
                                               {26, 100000},
                                               {39, 100000},
                                               {32, 100000},
                                               {40, 100000},
                                               {41, 100000},
                                               {4,  100000}};
        int targetFriend = 23;
        auto ans = Solution().smallestChair(times, targetFriend);
        decltype(ans) correctAns = 0;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
