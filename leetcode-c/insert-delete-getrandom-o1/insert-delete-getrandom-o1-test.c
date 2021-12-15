//
// Created by l30014168 on 2021/10/18.
//

#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "util.h"
#include "insert-delete-getrandom-o1.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void RandomizedSetTestExample1(void) {
    RandomizedSet *obj = randomizedSetCreate();
    TEST_ASSERT_TRUE(randomizedSetInsert(obj, 1));      // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    TEST_ASSERT_FALSE(randomizedSetRemove(obj, 2));     // 返回 false ，表示集合中不存在 2 。
    TEST_ASSERT_TRUE(randomizedSetInsert(obj, 2));      // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    size_t totTime = 100000;
    float delta = 1e-2f;
    int int1Cnt = 0, int2Cnt = 0;
    for (size_t idx = 0; idx < totTime; idx++) {
        int randInt = randomizedSetGetRandom(obj);
        if (randInt == 1) {
            int1Cnt++;
        } else if (randInt == 2) {
            int2Cnt++;
        }
    }
    TEST_ASSERT_EQUAL_INT(totTime, int1Cnt + int2Cnt);
    TEST_ASSERT_DOUBLE_WITHIN(delta, 1.f / 2, int1Cnt * 1.0 / totTime);      // getRandom 应随机返回 1 或 2 。
    TEST_ASSERT_TRUE(randomizedSetRemove(obj, 1));      // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    TEST_ASSERT_FALSE(randomizedSetInsert(obj, 2));     // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
    // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
    for (size_t idx = 0; idx < totTime; idx++) {
        TEST_ASSERT_EQUAL_INT(2, randomizedSetGetRandom(obj));
    }
    randomizedSetFree(obj);
}

void RandomizedSetTestTest0(void) {
    RandomizedSet *obj = randomizedSetCreate();
    TEST_ASSERT_TRUE(randomizedSetInsert(obj, 0));
    TEST_ASSERT_TRUE(randomizedSetInsert(obj, 1));
    TEST_ASSERT_TRUE(randomizedSetRemove(obj, 0));
    TEST_ASSERT_TRUE(randomizedSetInsert(obj, 2));
    TEST_ASSERT_TRUE(randomizedSetRemove(obj, 1));
    size_t totTime = 100000;
    for (size_t idx = 0; idx < totTime; idx++) {
        TEST_ASSERT_EQUAL_INT(2, randomizedSetGetRandom(obj));
    }
    randomizedSetFree(obj);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(RandomizedSetTestExample1);
    RUN_TEST(RandomizedSetTestTest0);
    return UNITY_END();
}