//
// Created by smile on 2022/10/6.
//

#include <unity.h>
#include "util.h"
#include "sign-of-the-product-of-an-array.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void arraySignTestExample1(void) {
    int nums[] = {-1, -2, -3, -4, 3, 2, 1};
    int ans = arraySign(nums, ARRAY_LENGTH(nums));
    int correctAns = 1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void arraySignTestExample2(void) {
    int nums[] = {1, 5, 0, 2, -3};
    int ans = arraySign(nums, ARRAY_LENGTH(nums));
    int correctAns = 0;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

void arraySignTestExample3(void) {
    int nums[] = {-1, 1, -1, 1, -1};
    int ans = arraySign(nums, ARRAY_LENGTH(nums));
    int correctAns = -1;
    TEST_ASSERT_EQUAL_INT(correctAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(arraySignTestExample1);
    RUN_TEST(arraySignTestExample2);
    RUN_TEST(arraySignTestExample3);
    return UNITY_END();
}