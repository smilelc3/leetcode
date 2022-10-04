//
// Created by smile on 2022/10/4.
//

#include <gtest/gtest.h>
#include <sstream>
#include <thread>
#include "print-foobar-alternately.cpp"

static std::stringstream ss;

void invokeFoo(std::unique_ptr<FooBar> &obj) {
    obj->foo([] { ss << "foo"; });
}

void invokeBar(std::unique_ptr<FooBar> &obj) {
    obj->bar([] { ss << "bar"; });
}

namespace {
    TEST(FooBarTest, Example1) {     // NOLINT
        ss.str("");
        auto obj = std::make_unique<FooBar>(1);
        std::thread threadA(invokeFoo, std::ref(obj));
        std::thread threadB(invokeBar, std::ref(obj));
        threadA.join();
        threadB.join();
        EXPECT_EQ(ss.str(), "foobar");
    }

    TEST(FooBarTest, Example2) {     // NOLINT
        ss.str("");
        auto obj = std::make_unique<FooBar>(2);
        std::thread threadA(invokeFoo, std::ref(obj));
        std::thread threadB(invokeBar, std::ref(obj));
        threadA.join();
        threadB.join();
        EXPECT_EQ(ss.str(), "foobarfoobar");
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}