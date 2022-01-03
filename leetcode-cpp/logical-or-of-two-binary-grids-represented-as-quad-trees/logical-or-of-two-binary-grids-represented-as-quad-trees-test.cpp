//
// Created by smile on 2022/1/3.
//

#include <gtest/gtest.h>
#include "logical-or-of-two-binary-grids-represented-as-quad-trees.cpp"

namespace {
    TEST(intersectTest, Example1) {       // NOLINT
        auto quadTree1 = new Node(
                true, false,
                new Node(true, true),
                new Node(true, true),
                new Node(false, true),
                new Node(false, true)
        );
        auto quadTree2 = new Node(
                true, false,
                new Node(true, true),
                new Node(
                        true, false,
                        new Node(false, true),
                        new Node(false, true),
                        new Node(true, true),
                        new Node(true, true)
                ),
                new Node(true, true),
                new Node(false, true)
        );

        auto ans = Solution().intersect(quadTree1, quadTree2);
        EXPECT_FALSE(ans->isLeaf);
        EXPECT_TRUE(ans->topLeft->isLeaf);
        EXPECT_TRUE(ans->topLeft->val);
        EXPECT_TRUE(ans->topRight->isLeaf);
        EXPECT_TRUE(ans->topRight->val);
        EXPECT_TRUE(ans->bottomLeft->isLeaf);
        EXPECT_TRUE(ans->topRight->val);
        EXPECT_TRUE(ans->bottomRight->isLeaf);
        EXPECT_FALSE(ans->bottomRight->val);

        delete quadTree1;
        delete quadTree2;
        delete ans;
    }

    TEST(intersectTest, Example2) {       // NOLINT
        auto quadTree1 = new Node(false, true);
        auto quadTree2 = new Node(false, true);

        auto ans = Solution().intersect(quadTree1, quadTree2);
        EXPECT_TRUE(ans->isLeaf);
        EXPECT_FALSE(ans->val);
        EXPECT_EQ(ans->topLeft, nullptr);
        EXPECT_EQ(ans->topRight, nullptr);
        EXPECT_EQ(ans->bottomLeft, nullptr);
        EXPECT_EQ(ans->bottomRight, nullptr);

        delete quadTree1;
        delete quadTree2;
        delete ans;
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
