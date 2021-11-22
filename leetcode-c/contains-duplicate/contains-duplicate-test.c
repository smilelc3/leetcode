//
// Created by l30014168 on 2021/7/20.
//

#include <unity.h>
#include "util.h"
#include "contains-duplicate.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void containsDuplicateTestExample1(void) {
    int nums[] = {1, 2, 3, 1};
    int numsSize = ARRAY_LENGTH(nums);
    bool ans = containsDuplicate(nums, numsSize);
    TEST_ASSERT_TRUE(ans);
}

void containsDuplicateTestExample2(void) {
    int nums[] = {1, 2, 3, 4};
    int numsSize = ARRAY_LENGTH(nums);
    bool ans = containsDuplicate(nums, numsSize);
    TEST_ASSERT_FALSE(ans);
}

void containsDuplicateTestExample3(void) {
    int nums[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int numsSize = ARRAY_LENGTH(nums);
    bool ans = containsDuplicate(nums, numsSize);
    TEST_ASSERT_TRUE(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(containsDuplicateTestExample1);
    RUN_TEST(containsDuplicateTestExample2);
    RUN_TEST(containsDuplicateTestExample3);
    return UNITY_END();
}