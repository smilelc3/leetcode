//
// Created by smile on 2022/10/5.
//

#include <sstream>
#include <thread>
#include <vector>
#include <gtest/gtest.h>
#include "print-in-order.cpp"

static std::stringstream ss;

void invokeFooFirst(std::unique_ptr<Foo> &obj) {
    obj->first([] { ss << "first"; });
}

void invokeFooSecond(std::unique_ptr<Foo> &obj) {
    obj->second([] { ss << "second"; });
}

void invokeFooThird(std::unique_ptr<Foo> &obj) {
    obj->third([] { ss << "third"; });
}

namespace {
    TEST(FooTest, Example1) {     // NOLINT
        ss.str("");
        auto obj = std::make_unique<Foo>();
        std::vector<std::thread> threads;
        threads.emplace_back(std::thread(invokeFooFirst, std::ref(obj)));
        threads.emplace_back(std::thread(invokeFooSecond, std::ref(obj)));
        threads.emplace_back(std::thread(invokeFooThird, std::ref(obj)));
        threads[0].join();
        threads[1].join();
        threads[2].join();
        EXPECT_EQ(ss.str(), "firstsecondthird");
    }

    TEST(FooTest, Example2) {     // NOLINT
        ss.str("");
        auto obj = std::make_unique<Foo>();
        std::vector<std::thread> threads;
        threads.emplace_back(std::thread(invokeFooFirst, std::ref(obj)));
        threads.emplace_back(std::thread(invokeFooSecond, std::ref(obj)));
        threads.emplace_back(std::thread(invokeFooThird, std::ref(obj)));
        threads[0].join();
        threads[2].join();
        threads[1].join();
        EXPECT_EQ(ss.str(), "firstsecondthird");
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}