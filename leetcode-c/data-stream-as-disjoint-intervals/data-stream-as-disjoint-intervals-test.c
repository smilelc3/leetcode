//
// Created by smile on 2021/10/10.
//

#include <unity.h>
#include "data-stream-as-disjoint-intervals.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void SummaryRangesTestExample1(void) {
    int retSize = -1;
    int *retColSize;
    int correctPair[2];
    SummaryRanges *obj = summaryRangesCreate();
    summaryRangesAddNum(obj, 1);
    int **param_1 = summaryRangesGetIntervals(obj, &retSize, &retColSize);
    TEST_ASSERT_EQUAL_INT(1, retSize);
    for (int i = 0; i < retSize; ++i) {
        TEST_ASSERT_EQUAL_INT(2, retColSize[i]);
    }
    correctPair[0] = 1, correctPair[1] = 1;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_1[0], retColSize[0]);


    summaryRangesAddNum(obj, 3);
    int **param_2 = summaryRangesGetIntervals(obj, &retSize, &retColSize);
    TEST_ASSERT_EQUAL_INT(2, retSize);
    for (int i = 0; i < retSize; ++i) {
        TEST_ASSERT_EQUAL_INT(2, retColSize[i]);
    }
    correctPair[0] = 1, correctPair[1] = 1;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_2[0], retColSize[0]);
    correctPair[0] = 3, correctPair[1] = 3;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_2[1], retColSize[1]);


    summaryRangesAddNum(obj, 7);
    int **param_3 = summaryRangesGetIntervals(obj, &retSize, &retColSize);
    TEST_ASSERT_EQUAL_INT(3, retSize);
    for (int i = 0; i < retSize; ++i) {
        TEST_ASSERT_EQUAL_INT(2, retColSize[i]);
    }
    correctPair[0] = 1, correctPair[1] = 1;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_3[0], retColSize[0]);
    correctPair[0] = 3, correctPair[1] = 3;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_3[1], retColSize[1]);
    correctPair[0] = 7, correctPair[1] = 7;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_3[2], retColSize[2]);


    summaryRangesAddNum(obj, 2);
    int **param_4 = summaryRangesGetIntervals(obj, &retSize, &retColSize);
    TEST_ASSERT_EQUAL_INT(2, retSize);
    for (int i = 0; i < retSize; ++i) {
        TEST_ASSERT_EQUAL_INT(2, retColSize[i]);
    }
    correctPair[0] = 1, correctPair[1] = 3;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_4[0], retColSize[0]);
    correctPair[0] = 7, correctPair[1] = 7;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_4[1], retColSize[1]);


    summaryRangesAddNum(obj, 6);
    int **param_5 = summaryRangesGetIntervals(obj, &retSize, &retColSize);
    TEST_ASSERT_EQUAL_INT(2, retSize);
    for (int i = 0; i < retSize; ++i) {
        TEST_ASSERT_EQUAL_INT(2, retColSize[i]);
    }
    correctPair[0] = 1, correctPair[1] = 3;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_5[0], retColSize[0]);
    correctPair[0] = 6, correctPair[1] = 7;
    TEST_ASSERT_EQUAL_INT_ARRAY(correctPair,param_5[1], retColSize[1]);

    summaryRangesFree(obj);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(SummaryRangesTestExample1);
    return UNITY_END();
}