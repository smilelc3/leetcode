//
// Created by smile on 25-8-11.
//


#include <gtest/gtest.h>
#include <set>
#include "course-schedule-ii.cpp"

namespace {
    TEST(canFinishTest, Example1) {
        int numCourses = 2;
        std::vector<std::vector<int> > prerequisites = {{1, 0}};
        auto ans = Solution::findOrder(numCourses, prerequisites);
        decltype(ans) correctAns = {0, 1};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(canFinishTest, Example2) {
        int numCourses = 4;
        std::vector<std::vector<int> > prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
        auto ans = Solution::findOrder(numCourses, prerequisites);
        std::set<std::vector<int>> correctAnsSet = {
            {0, 1, 2, 3},
            {0, 2, 1, 3},
        };
        ASSERT_TRUE(correctAnsSet.count(ans) > 0);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
