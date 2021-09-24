//
// Created by l30014168 on 2021/9/23.
//

#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "util.h"
#include "shuffle-an-array.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void shuffleAnArrayTestExample1(void) {
    int nums[] = {1, 2, 3};
    int numsSort[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(int);
    int *tmpNums = malloc(sizeof(nums));
    int retSize = -1;
    Solution *obj = solutionCreate(nums, numsSize);

    int *param_1 = solutionShuffle(obj, &retSize);
    TEST_ASSERT_EQUAL_INT(numsSize, retSize);
    memcpy(tmpNums, param_1, sizeof(nums));
    qsort(tmpNums, numsSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(numsSort, tmpNums, numsSize);

    int *param_2 = solutionReset(obj, &retSize);
    TEST_ASSERT_EQUAL_INT(numsSize, retSize);
    memcpy(tmpNums, param_2, sizeof(nums));
    TEST_ASSERT_EQUAL_INT_ARRAY(nums, tmpNums, numsSize);

    int *param_3 = solutionShuffle(obj, &retSize);
    TEST_ASSERT_EQUAL_INT(numsSize, retSize);
    memcpy(tmpNums, param_3, sizeof(nums));
    qsort(tmpNums, numsSize, sizeof(int), intAscCmpFunc);
    TEST_ASSERT_EQUAL_INT_ARRAY(numsSort, tmpNums, numsSize);

    solutionFree(obj);
    free(tmpNums);

}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(shuffleAnArrayTestExample1);
    return UNITY_END();
}