//
// Created by smile on 2022/2/14.
//

#include <gtest/gtest.h>
#include "course-schedule.cpp"

namespace {
    TEST(canFinishTest, Example1) {     // NOLINT
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1, 0}};
        ASSERT_TRUE(Solution().canFinish(numCourses, prerequisites));
    }

    TEST(canFinishTest, Example2) {     // NOLINT
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1, 0},
                                                       {0, 1}};
        ASSERT_FALSE(Solution().canFinish(numCourses, prerequisites));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

