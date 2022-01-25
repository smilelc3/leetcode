//
// Created by smile on 2021/8/28.
//

#include <gtest/gtest.h>
#include "find-median-from-data-stream.cpp"

namespace {
    TEST(medianFinderTest, Example1) {         // NOLINT
        auto medianFinder = new MedianFinder();
        medianFinder->addNum(1);
        medianFinder->addNum(2);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 1.5);
        medianFinder->addNum(3);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 2.0);
        delete medianFinder;
    }

    TEST(medianFinderTest, Test0) {         // NOLINT
        auto medianFinder = new MedianFinder();
        medianFinder->addNum(6);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 6);
        medianFinder->addNum(10);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 8);
        medianFinder->addNum(2);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 6);
        medianFinder->addNum(6);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 6);
        medianFinder->addNum(5);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 6);
        medianFinder->addNum(0);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 5.5);
        medianFinder->addNum(6);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 6);
        medianFinder->addNum(3);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 5.5);
        medianFinder->addNum(1);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 5);
        medianFinder->addNum(0);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 4);
        medianFinder->addNum(0);
        ASSERT_DOUBLE_EQ(medianFinder->findMedian(), 3);
        delete medianFinder;
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
