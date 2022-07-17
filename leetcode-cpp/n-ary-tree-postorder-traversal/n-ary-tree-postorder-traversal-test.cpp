//
// Created by smile on 2022/7/9.
//

#include <gtest/gtest.h>
#include "n-ary-tree-postorder-traversal.cpp"

namespace {
    TEST(postorderTest, Example1) {    // NOLINT
        auto root = new Node(1);
        root->children.emplace_back(new Node(3));
        root->children.emplace_back(new Node(2));
        root->children.emplace_back(new Node(4));
        root->children[0]->children.emplace_back(new Node(5));
        root->children[0]->children.emplace_back(new Node(6));

        auto ans = Solution().postorder(root);
        decltype(ans) correctAns = {5, 6, 3, 2, 4, 1};
        delete root->children[0]->children[0];
        delete root->children[0]->children[1];
        delete root->children[0];
        delete root->children[1];
        delete root->children[2];
        delete root;
        ASSERT_EQ(ans, correctAns);

    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
