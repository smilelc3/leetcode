//
// Created by smile on 2023/2/10.
//

#include <gtest/gtest.h>
#include "contains-duplicate-ii.cpp"

namespace {
    TEST(containsNearbyDuplicateTest, Example1) {     // NOLINT
        std::vector<int> nums = {1, 2, 3, 1};
        int k = 3;
        ASSERT_TRUE(Solution().containsNearbyDuplicate(nums, k));
    }

    TEST(containsNearbyDuplicateTest, Example2) {     // NOLINT
        std::vector<int> nums = {1, 0, 1, 1};
        int k = 1;
        ASSERT_TRUE(Solution().containsNearbyDuplicate(nums, k));
    }

    TEST(containsNearbyDuplicateTest, Example3) {     // NOLINT
        std::vector<int> nums = {1, 2, 3, 1, 2, 3};
        int k = 2;
        ASSERT_FALSE(Solution().containsNearbyDuplicate(nums, k));
    }

    TEST(containsNearbyDuplicateTest, Test0) {     // NOLINT
        std::vector<int> nums = {1, 2, 1};
        int k = 0;
        ASSERT_FALSE(Solution().containsNearbyDuplicate(nums, k));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
