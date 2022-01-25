//
// Created by smile on 2021/10/14.
//

#include <gtest/gtest.h>
#include "design-browser-history.cpp"

namespace {
    TEST(BrowserHistoryTest, Example1) {     // NOLINT
        auto browserHistory = new BrowserHistory("leetcode.com");
        // You are in "leetcode.com". Visit "google.com"
        browserHistory->visit("google.com");
        // You are in "google.com". Visit "facebook.com"
        browserHistory->visit("facebook.com");
        // You are in "facebook.com". Visit "youtube.com"
        browserHistory->visit("youtube.com");
        // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
        ASSERT_EQ("facebook.com", browserHistory->back(1));
        // You are in "facebook.com", move back to "google.com" return "google.com"
        ASSERT_EQ("google.com", browserHistory->back(1));
        // You are in "google.com", move forward to "facebook.com" return "facebook.com"
        ASSERT_EQ("facebook.com", browserHistory->forward(1));
        // You are in "facebook.com". Visit "linkedin.com"
        browserHistory->visit("linkedin.com");
        // You are in "linkedin.com", you cannot move forward any steps.
        ASSERT_EQ("linkedin.com", browserHistory->forward(2));
        // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
        ASSERT_EQ("google.com", browserHistory->back(2));
        // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
        ASSERT_EQ("leetcode.com", browserHistory->back(7));
        delete browserHistory;
    }

    TEST(BrowserHistoryTest, Test0) {     // NOLINT
        auto browserHistory = new BrowserHistory("esgriv.com");
        browserHistory->visit("cgrt.com");
        browserHistory->visit("tip.com");
        ASSERT_EQ("esgriv.com", browserHistory->back(9));
        browserHistory->visit("kttzxgh.com");
        ASSERT_EQ("kttzxgh.com", browserHistory->forward(7));
        browserHistory->visit("crqje.com");
        browserHistory->visit("iybch.com");
        ASSERT_EQ("iybch.com", browserHistory->forward(5));
        browserHistory->visit("uun.com");
        ASSERT_EQ("esgriv.com", browserHistory->back(10));
        browserHistory->visit("hci.com");
        browserHistory->visit("whula.com");
        ASSERT_EQ("whula.com", browserHistory->forward(10));
        delete browserHistory;
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
