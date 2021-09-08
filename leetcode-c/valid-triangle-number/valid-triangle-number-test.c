//
// Created by l30014168 on 2021/8/5.
//

#include "unity.h"
#include "valid-triangle-number.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void triangleNumberTestExample1(void) {
    int nums[] = {2, 2, 3, 4};
    int numsSize = 4;
    int ans = triangleNumber(nums, numsSize);
    int rightAns = 3;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void triangleNumberTestExample2(void) {
    int nums[] = {4, 2, 3, 4};
    int numsSize = 4;
    int ans = triangleNumber(nums, numsSize);
    int rightAns = 4;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(triangleNumberTestExample1);
    RUN_TEST(triangleNumberTestExample2);
    return UNITY_END();
}