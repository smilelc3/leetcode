//
// Created by smile on 2021/5/14.
//

#include <gtest/gtest.h>
#include "min-stack.cpp"

namespace {
    TEST(minStackTest, Example1) { // NOLINT
        auto minStack = new MinStack();
        minStack->push(-2);
        minStack->push(0);
        minStack->push(-3);
        ASSERT_EQ(minStack->getMin(), -3);
        minStack->pop();
        ASSERT_EQ(minStack->top(), 0);
        ASSERT_EQ(minStack->getMin(), -2);
        delete minStack;

    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
