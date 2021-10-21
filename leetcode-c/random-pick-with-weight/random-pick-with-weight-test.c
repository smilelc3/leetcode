//
// Created by l30014168 on 2021/8/31.
//

#include <unity.h>
#include "random-pick-with-weight.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void SolutionTestExample1(void) {
    int w[] = {1};
    Solution *obj = solutionCreate(w, sizeof(w) / sizeof(int));
    int param_1 = solutionPickIndex(obj);
    TEST_ASSERT_EQUAL_INT(0, param_1);
    solutionFree(obj);
}

void SolutionTestExample2(void) {
    int w[] = {1, 3};
    Solution *obj = solutionCreate(w, sizeof(w) / sizeof(int));
    size_t totTime = 100000000;
    float delta = 1e-3f;
    int idx0Cnt = 0, idx1Cnt = 0;
    for (size_t idx = 0 ; idx < totTime; idx++) {
        int pickIdx = solutionPickIndex(obj);
        if (pickIdx == 0) {
            idx0Cnt++;
        }
        if (pickIdx == 1) {
            idx1Cnt++;
        }
    }
    solutionFree(obj);
    TEST_ASSERT_EQUAL_INT(totTime, idx0Cnt + idx1Cnt);
    TEST_ASSERT_FLOAT_WITHIN(delta, 3.f/4, idx1Cnt * 1.0 / totTime);     // 断言actual参数在expected参数的+/-delta参数内。浮点表示法的性质是不能保证对等式的精确计算。
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(SolutionTestExample1);
    RUN_TEST(SolutionTestExample2);
    return UNITY_END();
}