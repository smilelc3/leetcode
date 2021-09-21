//
// Created by smile on 2021/9/20.
//

#include <gtest/gtest.h>
#include <vector>
#include "binary-search-tree-iterator.cpp"

const auto null = INT_MAX;

namespace {
    TEST(BSTIteratorTest, Example1) {      // NOLINT
        auto root = TreeCreateByNums({7, 3, 15, null, null, 9, 20}, null);
        auto iter = new BSTIterator(root);
        ASSERT_EQ(3, iter->next());
        ASSERT_EQ(7, iter->next());
        ASSERT_TRUE(iter->hasNext());
        ASSERT_EQ(9, iter->next());
        ASSERT_TRUE(iter->hasNext());
        ASSERT_EQ(15, iter->next());
        ASSERT_TRUE(iter->hasNext());
        ASSERT_EQ(20, iter->next());
        ASSERT_FALSE(iter->hasNext());
        TreeDestroy(root);
        delete iter;
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
