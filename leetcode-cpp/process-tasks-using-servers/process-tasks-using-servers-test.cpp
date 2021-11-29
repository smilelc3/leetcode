//
// Created by smile on 2021/11/29.
//

#include <gtest/gtest.h>
#include <vector>
#include "process-tasks-using-servers.cpp"

namespace {
    TEST(assignTasksTest, Example1) {     // NOLINT
        std::vector<int> servers = {3, 3, 2}, tasks = {1, 2, 3, 2, 1, 2};
        auto ans = Solution().assignTasks(servers, tasks);
        decltype(ans) rightAns = {2, 2, 0, 2, 1, 2};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(assignTasksTest, Example2) {     // NOLINT
        std::vector<int> servers = {5, 1, 4, 3, 2}, tasks = {2, 1, 2, 4, 5, 2, 1};
        auto ans = Solution().assignTasks(servers, tasks);
        decltype(ans) rightAns = {1, 4, 1, 4, 1, 3, 2};
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}