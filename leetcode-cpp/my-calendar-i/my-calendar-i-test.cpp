//
// Created by smile on 2021/9/11.
//

#include <gtest/gtest.h>
#include "my-calendar-i.cpp"

namespace {
    TEST(MyCalendarTest, Example1) {    // NOLINT
        auto myCalendar = new MyCalendar();
        ASSERT_TRUE(myCalendar->book(10, 20));
        ASSERT_FALSE(myCalendar->book(15, 25));
        ASSERT_TRUE(myCalendar->book(20, 30));
        delete myCalendar;
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
