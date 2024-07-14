//
// Created by smile on 24-7-14.
//

#include <gtest/gtest.h>
#include <vector>
#include "partition-equal-subset-sum.cpp"

namespace {
    TEST(canPartitionTest, Example1) { // NOLINT
        std::vector<int> nums = {1, 5, 11, 5};
        ASSERT_TRUE(Solution::canPartition(nums));
    }

    TEST(canPartitionTest, Example2) { // NOLINT
        std::vector<int> nums = {1, 2, 3, 5};
        ASSERT_FALSE(Solution::canPartition(nums));
    }

    TEST(canPartitionTest, Test0) { // NOLINT
        std::vector<int> nums = {1, 2, 5};
        ASSERT_FALSE(Solution::canPartition(nums));
    }
    TEST(canPartitionTest, Test1) { // NOLINT
        std::vector<int> nums = {100};
        ASSERT_FALSE(Solution::canPartition(nums));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
