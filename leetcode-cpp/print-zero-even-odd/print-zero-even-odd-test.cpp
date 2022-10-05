//
// Created by smile on 2022/10/5.
//

//
// Created by smile on 2022/10/4.
//

#include <gtest/gtest.h>
#include <sstream>
#include <thread>
#include "print-zero-even-odd.cpp"

static std::stringstream ss;

void invokeZero(std::unique_ptr<ZeroEvenOdd> &obj) {
    obj->zero([](int x) { ss << std::to_string(x); });
}

void invokeEven(std::unique_ptr<ZeroEvenOdd> &obj) {
    obj->even([](int x) { ss << std::to_string(x); });
}

void invokeOdd(std::unique_ptr<ZeroEvenOdd> &obj) {
    obj->odd([](int x) { ss << std::to_string(x); });
}

namespace {
    TEST(ZeroEvenOddTest, Example1) {     // NOLINT
        ss.str("");
        auto obj = std::make_unique<ZeroEvenOdd>(2);
        std::thread threadA(invokeZero, std::ref(obj));
        std::thread threadB(invokeEven, std::ref(obj));
        std::thread threadC(invokeOdd, std::ref(obj));
        threadA.join();
        threadB.join();
        threadC.join();
        EXPECT_EQ(ss.str(), "0102");
    }

    TEST(ZeroEvenOddTest, Example2) {     // NOLINT
        ss.str("");
        auto obj = std::make_unique<ZeroEvenOdd>(5);
        std::thread threadA(invokeZero, std::ref(obj));
        std::thread threadB(invokeEven, std::ref(obj));
        std::thread threadC(invokeOdd, std::ref(obj));
        threadA.join();
        threadB.join();
        threadC.join();
        EXPECT_EQ(ss.str(), "0102030405");
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}