//
// Created by smile on 2022/10/3.
//

#include <gtest/gtest.h>
#include "generate-random-point-in-a-circle.cpp"

bool isPointInCircle(double xCenter, double yCenter, double radius,
                     double x, double y) {
    return (xCenter - x) * (xCenter - x) + (yCenter - y) * (yCenter - y) <=
           radius * radius;
}

namespace {
    TEST(grayCodeTest, Example1) {
        double xCenter = 1.0;
        double yCenter = 1.0;
        double radius = 1.0;
        std::vector<double> point;
        auto obj = std::make_unique<Solution>(radius, xCenter, yCenter);
        point = obj->randPoint();
        EXPECT_TRUE(isPointInCircle(xCenter, yCenter, radius, point[0], point[1]));
        point = obj->randPoint();
        EXPECT_TRUE(isPointInCircle(xCenter, yCenter, radius, point[0], point[1]));
        point = obj->randPoint();
        EXPECT_TRUE(isPointInCircle(xCenter, yCenter, radius, point[0], point[1]));
    }

    TEST(grayCodeTest, Test0) {
        double xCenter = -73839.1;
        double yCenter = -3289891.3;
        double radius = 0.01;
        auto obj = std::make_unique<Solution>(radius, xCenter, yCenter);
        for (int i = 0; i < 30000; ++i) {
            auto point = obj->randPoint();
            ASSERT_TRUE(isPointInCircle(xCenter, yCenter, radius, point[0], point[1]));
        }
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
