//
// Created by l30014168 on 2021/11/2.
//

//
// Created by l30014168 on 2021/10/25.
//

#include <ubench.h>
#include <time.h>
#include "closest-dessert-cost.c"

// Declare a struct that holds the state for your benchmark.
struct fixture {
    int *baseCosts;
    int baseCostsSize;
    int *toppingCosts;
    int toppingCostsSize;
    int target;
};

// Use UBENCH_F_SETUP to initialize your struct (called ubench_fixture in here).
UBENCH_F_SETUP(fixture) {
    srand((unsigned int) time(NULL));

    ubench_fixture->baseCostsSize = 10;
    ubench_fixture->toppingCostsSize = 10;
    ubench_fixture->target = 100000;
    ubench_fixture->baseCosts = (int *) malloc(sizeof(int) * ubench_fixture->baseCostsSize);
    ubench_fixture->toppingCosts = (int *) malloc(sizeof(int) * ubench_fixture->toppingCostsSize);
    for (int i = 0; i < ubench_fixture->baseCostsSize; ++i) {
        ubench_fixture->baseCosts[i] = rand() % 10000;
    }
    for (int i = 0; i < ubench_fixture->toppingCostsSize; ++i) {
        ubench_fixture->toppingCosts[i] = rand() % 10000;
    }
}

// Use UBENCH_F_TEARDOWM to destroy your struct when complete.
UBENCH_F_TEARDOWN(fixture) {
    free(ubench_fixture->baseCosts);
    free(ubench_fixture->toppingCosts);
}

UBENCH_EX_F(fixture, closestCostDFSMethod) {
    UBENCH_DO_BENCHMARK() {
        int ans = closestCostDFSMethod(ubench_fixture->baseCosts, ubench_fixture->baseCostsSize,
                                       ubench_fixture->toppingCosts, ubench_fixture->toppingCostsSize,
                                       ubench_fixture->target);
        UBENCH_DO_NOTHING(&ans);
    }
}

UBENCH_EX_F(fixture, closestCostDPMethod) {
    UBENCH_DO_BENCHMARK() {
        int ans = closestCostDPMethod(ubench_fixture->baseCosts, ubench_fixture->baseCostsSize,
                                       ubench_fixture->toppingCosts, ubench_fixture->toppingCostsSize,
                                       ubench_fixture->target);
        UBENCH_DO_NOTHING(&ans);
    }
}

UBENCH_MAIN();
