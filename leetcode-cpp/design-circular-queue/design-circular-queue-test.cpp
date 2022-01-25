//
// Created by smile on 2021/10/14.
//

#include <gtest/gtest.h>
#include "design-circular-queue.cpp"

namespace {
    TEST(MyCircularQueue, Example1) {     // NOLINT
        auto obj = new MyCircularQueue(3);
        ASSERT_TRUE(obj->enQueue(1));
        ASSERT_TRUE(obj->enQueue(2));
        ASSERT_TRUE(obj->enQueue(3));
        ASSERT_FALSE(obj->enQueue(4));
        ASSERT_EQ(3, obj->Rear());
        ASSERT_TRUE(obj->isFull());
        ASSERT_TRUE(obj->deQueue());
        ASSERT_TRUE(obj->enQueue(4));
        ASSERT_EQ(4, obj->Rear());
        delete obj;
    }

    TEST(MyCircularQueue, Test0) {     // NOLINT
        auto obj = new MyCircularQueue(2);
        ASSERT_TRUE(obj->enQueue(1));
        ASSERT_TRUE(obj->enQueue(2));
        ASSERT_TRUE(obj->deQueue());
        ASSERT_TRUE(obj->enQueue(3));
        ASSERT_TRUE(obj->deQueue());
        ASSERT_TRUE(obj->enQueue(3));
        ASSERT_TRUE(obj->deQueue());
        ASSERT_TRUE(obj->enQueue(3));
        ASSERT_TRUE(obj->deQueue());
        ASSERT_EQ(3, obj->Rear());
        delete obj;
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}