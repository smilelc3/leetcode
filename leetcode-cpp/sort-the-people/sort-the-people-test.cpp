//
// Created by smile on 2024/9/17.
//

#include <gtest/gtest.h>
#include <vector>
#include "sort-the-people.cpp"

namespace {
    TEST(sortPeople, Example1) {      // NOLINT
        std::vector<std::string> names = {"Mary", "John", "Emma"};
        std::vector<int> heights = {180, 165, 170};
        auto ans = Solution::sortPeople(names, heights);
        decltype(ans) correctAns = {"Mary", "Emma", "John"};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(sortPeople, Example2) {      // NOLINT
        std::vector<std::string> names = {"Alice", "Bob", "Bob"};
        std::vector<int> heights = {155, 185, 150};
        auto ans = Solution::sortPeople(names, heights);
        decltype(ans) correctAns = {"Bob", "Alice", "Bob"};
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}