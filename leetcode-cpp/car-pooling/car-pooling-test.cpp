//
// Created by smile on 2022/1/26.
//

#include <gtest/gtest.h>
#include "car-pooling.cpp"

namespace {
    TEST(carPoolingTest, Example1) {        // NOLINT
        std::vector<std::vector<int>> trips = {{2, 1, 5},
                                               {3, 3, 7}};
        int capacity = 4;
        ASSERT_FALSE(Solution().carPooling(trips, capacity));
    }

    TEST(carPoolingTest, Example2) {        // NOLINT
        std::vector<std::vector<int>> trips = {{2, 1, 5},
                                               {3, 3, 7}};
        int capacity = 5;
        ASSERT_TRUE(Solution().carPooling(trips, capacity));
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}