//
// Created by l30014168 on 2022/1/10.
//

#include <gtest/gtest.h>
#include "map-sum-pairs.cpp"

namespace {
    TEST(MapSumTest, Example1) {        // NOLINT
        auto mapSum = new MapSum();
        mapSum->insert("apple", 3);
        ASSERT_EQ(mapSum->sum("ap"), 3);
        mapSum->insert("app", 2);
        ASSERT_EQ(mapSum->sum("ap"), 5);
        delete mapSum;
    }

    TEST(MapSumTest, Example2) {        // NOLINT
        auto mapSum = new MapSum();
        mapSum->insert("a", 3);
        ASSERT_EQ(mapSum->sum("ap"), 0);
        mapSum->insert("b", 2);
        ASSERT_EQ(mapSum->sum("a"), 3);
        delete mapSum;
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
