//
// Created by l30014168 on 2021/10/25.
//

#include <ubench.h>
#include <time.h>
#include "sliding-window-maximum.c"

// Declare a struct that holds the state for your benchmark.
struct fixture {
    int *nums;
    int numsSize;
    int k;
    int returnSize;
};

// Use UBENCH_F_SETUP to initialize your struct (called ubench_fixture in here).
UBENCH_F_SETUP(fixture) {
    srand((unsigned int) time(NULL));
    ubench_fixture->numsSize = 100000;
    ubench_fixture->nums = (int *) malloc(sizeof(int) * ubench_fixture->numsSize);
    for (int i = 0; i < ubench_fixture->numsSize; ++i) {
        ubench_fixture->nums[i] = rand() % 10000;
        if (rand() % 2 == 1) {
            ubench_fixture->nums[i] = -ubench_fixture->nums[i];
        }
    }
    ubench_fixture->k = ubench_fixture->numsSize / 2;
    ubench_fixture->returnSize = -1;
}

// Use UBENCH_F_TEARDOWM to destroy your struct when complete.
UBENCH_F_TEARDOWN(fixture) {
    free(ubench_fixture->nums);
}

UBENCH_EX_F(fixture, maxSlidingWindowDuLinkListMethod) {
    UBENCH_DO_BENCHMARK() {
        int *ans = maxSlidingWindowDuLinkListMethod(ubench_fixture->nums, ubench_fixture->numsSize, ubench_fixture->k,
                                                    &ubench_fixture->returnSize);
        UBENCH_DO_NOTHING(ans);
        free(ans);
    }
}

UBENCH_EX_F(fixture, maxSlidingWindowVectorMethod) {
    UBENCH_DO_BENCHMARK() {
        int *ans = maxSlidingWindowVectorMethod(ubench_fixture->nums, ubench_fixture->numsSize, ubench_fixture->k,
                                                &ubench_fixture->returnSize);
        UBENCH_DO_NOTHING(ans);
        free(ans);
    }
}

UBENCH_MAIN();
