//
// Created by l30014168 on 2021/9/29.
//

#include <gtest/gtest.h>
#include "exam-room.cpp"

namespace {
    TEST(ExamRoomTest, Example1) {        // NOLINT
        auto obj = new ExamRoom(10);
        ASSERT_EQ(0, obj->seat());
        ASSERT_EQ(9, obj->seat());
        ASSERT_EQ(4, obj->seat());
        ASSERT_EQ(2, obj->seat());
        obj->leave(4);
        ASSERT_EQ(5, obj->seat());
        delete obj;
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}