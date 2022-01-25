//
// Created by smile on 2021/9/14.
//

#include <gtest/gtest.h>
#include "seat-reservation-manager.cpp"

namespace {
    TEST(SeatManagerTest, Example1) { // NOLINT
        auto* obj = new SeatManager(5);
        ASSERT_EQ(1,obj->reserve());
        ASSERT_EQ(2,obj->reserve());
        obj->unreserve(2);
        ASSERT_EQ(2,obj->reserve());
        ASSERT_EQ(3,obj->reserve());
        ASSERT_EQ(4,obj->reserve());
        ASSERT_EQ(5,obj->reserve());
        obj->unreserve(5);
        delete obj;
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}