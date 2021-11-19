//
// Created by l30014168 on 2021/10/22.
//

#include <unity.h>
#include "util.h"
#include "utf-8-validation.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void validUtf8TestExample1(void) {
    int data[] = {197, 130, 1};
    TEST_ASSERT_TRUE(validUtf8(data, ARRAY_LENGTH(data)));
}

void validUtf8TestExample2(void) {
    int data[] = {235, 140, 4};
    TEST_ASSERT_FALSE(validUtf8(data, ARRAY_LENGTH(data)));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(validUtf8TestExample1);
    RUN_TEST(validUtf8TestExample2);
    return UNITY_END();
}