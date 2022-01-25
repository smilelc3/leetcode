//
// Created by smile on 2021/8/30.
//

#include <gtest/gtest.h>
#include "lfu-cache.cpp"

namespace {
    TEST(LRUCacheTest, Example1) {      // NOLINT
        auto lfu = new LFUCache(2);
        lfu->put(1, 1);                // cache=[1,_], cnt(1)=1
        lfu->put(2, 2);                // cache=[2,1], cnt(2)=1, cnt(1)=1
        EXPECT_EQ(1, lfu->get(1));     // return 1 cache=[1,2], cnt(2)=1, cnt(1)=2
        lfu->put(3, 3);                 // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
        // cache=[3,1], cnt(3)=1, cnt(1)=2
        EXPECT_EQ(NOT_FIND, lfu->get(2));      // return -1 (not found)
        EXPECT_EQ(3, lfu->get(3));       // return 3 cache=[3,1], cnt(3)=2, cnt(1)=2
        lfu->put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
        // cache=[4,3], cnt(4)=1, cnt(3)=2
        EXPECT_EQ(NOT_FIND, lfu->get(1));      // return -1 (not found)
        EXPECT_EQ(3, lfu->get(3));      // return 3 cache=[3,4], cnt(4)=1, cnt(3)=3
        EXPECT_EQ(4, lfu->get(4));      // return 4 cache=[3,4], cnt(4)=2, cnt(3)=3
        delete lfu;
    }

    TEST(LRUCacheTest, Test0) {      // NOLINT
        auto lfu = new LFUCache(0);
        lfu->put(0, 0);
        EXPECT_EQ(NOT_FIND, lfu->get(0));
        delete lfu;
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
