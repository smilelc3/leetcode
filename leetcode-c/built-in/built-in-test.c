//
// Created by l30014168 on 2021/8/16.
//

#include <unity.h>
#include <stdlib.h>
#include <Vector.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

static int ascIntCmpFunc(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void testVectorInt(void) {
    int data[] = {8, 6, 4, 7, 2, 9, 3, 5, 0, 1};
    Vector *vector = VectorCreate(sizeof(int));
    TEST_ASSERT_EQUAL_INT(0, vector->size);
    for (int idx = 0; idx < sizeof(data) / sizeof(int); idx++) {
        errno_t err = VectorAppend(vector, &data[idx]);
        TEST_ASSERT_EQUAL(NO_ERROR, err);
    }
    /* 获取vector大小，期望为10 */
    TEST_ASSERT_EQUAL_INT(10, vector->size);
    /* 获取索引为3的数据，期望为7 */
    TEST_ASSERT_EQUAL_INT(7, *(int *) VectorAt(vector, 3));

    /* 排序后期望为0 1 2 3 4 5 6 7 8 9 */
    VectorSort(vector, ascIntCmpFunc);
    for (int idx = 0; idx < sizeof(data) / sizeof(int); idx++) {
        TEST_ASSERT_EQUAL_INT(idx, *(int *) VectorAt(vector, idx));
    }

    // 删除 索引值从 3 开始，长度为4的元素。期望为0 1 2 7 8 9
    VectorErase(vector, 3, 3 + 4);

    /* 获取vector大小，期望为6 */
    TEST_ASSERT_EQUAL_INT(6, vector->size);

    /* 获取索引为2的数据，期望为2 */
    TEST_ASSERT_EQUAL_INT(2, *(int *) VectorAt(vector, 2));

    /* 获取索引为3的数据，期望为7 */
    TEST_ASSERT_EQUAL_INT(7, *(int *) VectorAt(vector, 3));

    // 清空元素
    VectorClear(vector);
    TEST_ASSERT_TRUE(VectorIsEmpty(vector));


    VectorDestroy(vector);

}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testVectorInt);
    return UNITY_END();
}