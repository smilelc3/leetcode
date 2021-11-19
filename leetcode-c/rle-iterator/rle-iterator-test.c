//
// Created by l30014168 on 2021/10/26.
//

#include <unity.h>
#include "util.h"
#include "rle-iterator.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void RLEIteratorExample1(void) {
    int nums[] = {3, 8, 0, 9, 2, 5};
    RLEIterator *obj = rLEIteratorCreate(nums, (int) ARRAY_LENGTH(nums));
    TEST_ASSERT_EQUAL_INT(8, rLEIteratorNext(obj, 2));
    TEST_ASSERT_EQUAL_INT(8, rLEIteratorNext(obj, 1));
    TEST_ASSERT_EQUAL_INT(5, rLEIteratorNext(obj, 1));
    TEST_ASSERT_EQUAL_INT(-1, rLEIteratorNext(obj, 2));
    rLEIteratorFree(obj);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(RLEIteratorExample1);
    return UNITY_END();
}