//
// Created by l30014168 on 2021/7/20.
//

#include <unity.h>
#include <stdlib.h>
#include "contains-duplicate.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void containsDuplicateTestExample1(void) {
    int numsSize = 4;
    int *nums = (int *) malloc(sizeof(int) * numsSize);
    if (nums == NULL) {
        perror("init nums fail");
        return;
    }
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 1;
    bool ans = containsDuplicate(nums, numsSize);
    TEST_ASSERT_TRUE(ans);
    free(nums);
}

void containsDuplicateTestExample2(void) {
    int numsSize = 4;
    int *nums = (int *) malloc(sizeof(int) * numsSize);
    if (nums == NULL) {
        perror("init nums fail");
        return;
    }
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;
    bool ans = containsDuplicate(nums, numsSize);
    TEST_ASSERT_FALSE(ans);
    free(nums);
}

void containsDuplicateTestExample3(void) {
    int numsSize = 10;
    int *nums = (int *) malloc(sizeof(int) * numsSize);
    if (nums == NULL) {
        perror("init nums fail");
        return;
    }
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 1;
    nums[3] = 3;
    nums[4] = 3;
    nums[5] = 4;
    nums[6] = 3;
    nums[7] = 2;
    nums[8] = 4;
    nums[9] = 2;
    bool ans = containsDuplicate(nums, numsSize);
    TEST_ASSERT_TRUE(ans);
    free(nums);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(containsDuplicateTestExample1);
    RUN_TEST(containsDuplicateTestExample2);
    RUN_TEST(containsDuplicateTestExample3);
    return UNITY_END();
}