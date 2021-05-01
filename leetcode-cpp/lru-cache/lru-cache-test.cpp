//
// Created by smile on 2021/4/30.
//

#include <gtest/gtest.h>
#include <vector>
#include "lru-cache.cpp"

namespace {
    TEST(LRUCacheTest, Example1) {
        auto lRUCache = new LRUCache(2);
        lRUCache->put(1, 1);    // cache is {1=1}
        lRUCache->put(2, 2);    // cache is {1=1, 2=2}

        EXPECT_EQ(1, lRUCache->get(1));               // return 1
        lRUCache->put(3, 3);                            // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        EXPECT_EQ(-1, lRUCache->get(2));               // returns -1 (not found)
        lRUCache->put(4, 4);                        // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        EXPECT_EQ(-1, lRUCache->get(1));           // return -1 (not found)
        EXPECT_EQ(3, lRUCache->get(3));           // return 3
        EXPECT_EQ(4, lRUCache->get(4));              // return 4
    }

    TEST(LRUCacheTest, Example2) {
        auto lRUCache = new LRUCache(2);
        lRUCache->put(1, 0);
        lRUCache->put(2, 2);

        EXPECT_EQ(0, lRUCache->get(1));
        lRUCache->put(3, 3);
        EXPECT_EQ(-1, lRUCache->get(2));
        lRUCache->put(4, 4);
        EXPECT_EQ(-1, lRUCache->get(1));
        EXPECT_EQ(3, lRUCache->get(3));
        EXPECT_EQ(4, lRUCache->get(4));
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}