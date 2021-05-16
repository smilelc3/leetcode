//
// Created by smile on 2021/5/15.
//

#include <gtest/gtest.h>
#include <vector>
#include "palindrome-partitioning.cpp"

namespace {
    TEST(partitionTest, Example1) {     // NOLINT
        std::string s = "aab";
        auto ans = Solution().partition(s);
        std::vector<std::vector<std::string>> rightAns = {{"a",  "a", "b"},
                                                          {"aa", "b"}};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(partitionTest, Example2) {     // NOLINT
        std::string s = "a";
        auto ans = Solution().partition(s);
        std::vector<std::vector<std::string>> rightAns = {{"a"}};
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
