//
// Created by smile on 2021/11/22.
//

#include <stdlib.h>
#include <unity.h>
#include "util.h"
#include "filter-restaurants-by-vegan-friendly-price-and-distance.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void filterRestaurantsExample1(void) {
    int nums[][5] = {{1, 4,  1, 40, 10},
                     {2, 8,  0, 50, 5},
                     {3, 8,  1, 30, 4},
                     {4, 10, 0, 10, 3},
                     {5, 1,  1, 15, 1}};
    int restaurantsSize = ARRAY_LENGTH(nums);
    int restaurantsColSize[ARRAY_LENGTH(nums)];
    int *restaurants[ARRAY_LENGTH(nums)];
    for (int idx = 0; idx < restaurantsSize; ++idx) {
        restaurants[idx] = nums[idx];
        restaurantsColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int veganFriendly = 1, maxPrice = 50, maxDistance = 10, returnSize = -1;
    int *ans = filterRestaurants(restaurants, restaurantsSize, restaurantsColSize,
                                 veganFriendly, maxPrice, maxDistance, &returnSize);
    int correctAns[] = {3, 1, 5};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void filterRestaurantsExample2(void) {
    int nums[][5] = {{1, 4,  1, 40, 10},
                     {2, 8,  0, 50, 5},
                     {3, 8,  1, 30, 4},
                     {4, 10, 0, 10, 3},
                     {5, 1,  1, 15, 1}};
    int restaurantsSize = ARRAY_LENGTH(nums);
    int restaurantsColSize[ARRAY_LENGTH(nums)];
    int *restaurants[ARRAY_LENGTH(nums)];
    for (int idx = 0; idx < restaurantsSize; ++idx) {
        restaurants[idx] = nums[idx];
        restaurantsColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int veganFriendly = 0, maxPrice = 50, maxDistance = 10, returnSize = -1;
    int *ans = filterRestaurants(restaurants, restaurantsSize, restaurantsColSize,
                                 veganFriendly, maxPrice, maxDistance, &returnSize);
    int correctAns[] = {4, 3, 2, 1, 5};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

void filterRestaurantsExample3(void) {
    int nums[][5] = {{1, 4,  1, 40, 10},
                     {2, 8,  0, 50, 5},
                     {3, 8,  1, 30, 4},
                     {4, 10, 0, 10, 3},
                     {5, 1,  1, 15, 1}};
    int restaurantsSize = ARRAY_LENGTH(nums);
    int restaurantsColSize[ARRAY_LENGTH(nums)];
    int *restaurants[ARRAY_LENGTH(nums)];
    for (int idx = 0; idx < restaurantsSize; ++idx) {
        restaurants[idx] = nums[idx];
        restaurantsColSize[idx] = ARRAY_LENGTH(nums[idx]);
    }
    int veganFriendly = 0, maxPrice = 30, maxDistance = 3, returnSize = -1;
    int *ans = filterRestaurants(restaurants, restaurantsSize, restaurantsColSize,
                                 veganFriendly, maxPrice, maxDistance, &returnSize);
    int correctAns[] = {4, 5};
    TEST_ASSERT_EQUAL_INT(ARRAY_LENGTH(correctAns), returnSize);
    TEST_ASSERT_EQUAL_INT_ARRAY(correctAns, ans, returnSize);
    free(ans);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(filterRestaurantsExample1);
    RUN_TEST(filterRestaurantsExample2);
    RUN_TEST(filterRestaurantsExample3);
    return UNITY_END();
}