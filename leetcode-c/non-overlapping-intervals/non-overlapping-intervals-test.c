//
// Created by l30014168 on 2021/7/13.
//

#include <unity.h>
#include "non-overlapping-intervals.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void eraseOverlapIntervalsTestExample1(void) {
    int intervalsRowSize = 4, intervalsColSize = 2;
    int **intervals = (int **) malloc(intervalsRowSize * sizeof(int *));

    for (int idx = 0; idx < intervalsRowSize; ++idx) {
        intervals[idx] = (int *) malloc(intervalsColSize * sizeof(int));
    }
    intervals[0][0] = 1;
    intervals[0][1] = 2;
    intervals[1][0] = 2;
    intervals[1][1] = 3;
    intervals[2][0] = 3;
    intervals[2][1] = 4;
    intervals[3][0] = 1;
    intervals[3][1] = 3;

    int ans = eraseOverlapIntervals(intervals, intervalsRowSize, &intervalsColSize);

    // free memory
    for (int idx = 0; idx < intervalsRowSize; ++idx) {
        free(intervals[idx]);
        intervals[idx] = NULL;
    }
    free(intervals);
    intervals = NULL;

    int rightAns = 1;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void eraseOverlapIntervalsTestExample2(void) {
    int intervalsRowSize = 3, intervalsColSize = 2;
    int **intervals = (int **) malloc(intervalsRowSize * sizeof(int *));

    for (int idx = 0; idx < intervalsRowSize; ++idx) {
        intervals[idx] = (int *) malloc(intervalsColSize * sizeof(int));
    }
    intervals[0][0] = 1;
    intervals[0][1] = 2;
    intervals[1][0] = 1;
    intervals[1][1] = 2;
    intervals[2][0] = 1;
    intervals[2][1] = 2;

    int ans = eraseOverlapIntervals(intervals, intervalsRowSize, &intervalsColSize);

    // free memory
    for (int idx = 0; idx < intervalsRowSize; ++idx) {
        free(intervals[idx]);
        intervals[idx] = NULL;
    }
    free(intervals);
    intervals = NULL;

    int rightAns = 2;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

void eraseOverlapIntervalsTestExample3(void) {
    int intervalsRowSize = 2, intervalsColSize = 2;
    int **intervals = (int **) malloc(intervalsRowSize * sizeof(int *));

    for (int idx = 0; idx < intervalsRowSize; ++idx) {
        intervals[idx] = (int *) malloc(intervalsColSize * sizeof(int));
    }
    intervals[0][0] = 1;
    intervals[0][1] = 2;
    intervals[1][0] = 2;
    intervals[1][1] = 3;

    int ans = eraseOverlapIntervals(intervals, intervalsRowSize, &intervalsColSize);

    // free memory
    for (int idx = 0; idx < intervalsRowSize; ++idx) {
        free(intervals[idx]);
        intervals[idx] = NULL;
    }
    free(intervals);
    intervals = NULL;

    int rightAns = 0;
    TEST_ASSERT_EQUAL_INT(rightAns, ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(eraseOverlapIntervalsTestExample1);
    RUN_TEST(eraseOverlapIntervalsTestExample2);
    RUN_TEST(eraseOverlapIntervalsTestExample3);
    return UNITY_END();
}