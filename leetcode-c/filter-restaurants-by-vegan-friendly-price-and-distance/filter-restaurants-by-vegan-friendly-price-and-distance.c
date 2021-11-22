//
// Created by smile on 2021/11/22.
//

#include <stdlib.h>
#include "util.h"

// 按照 rating 从高到低排序。如果 rating 相同，那么按 id 从高到低排序
static inline int restaurantsCmpFunc(const void *a, const void *b) {
    int *restaurantA = *(int **) a;
    int *restaurantB = *(int **) b;
    if (restaurantA[1] != restaurantB[1]) {
        return intDescCmpFunc(&restaurantA[1], &restaurantB[1]);
    }
    return intDescCmpFunc(&restaurantA[0], &restaurantB[0]);
}

int *filterRestaurants(int **restaurants, int restaurantsSize, const int *restaurantsColSize,
                       int veganFriendly, int maxPrice, int maxDistance, int *returnSize) {
    qsort(restaurants, restaurantsSize, sizeof(int *), restaurantsCmpFunc);
    int *ans = malloc(sizeof(int) * restaurantsSize);
    *returnSize = 0;
    for (int i = 0; i < restaurantsSize; ++i) {
        if (veganFriendly == 1 && restaurants[i][2] == 0) {
            continue;
        }
        if (restaurants[i][3] <= maxPrice &&
            restaurants[i][4] <= maxDistance) {
            ans[*returnSize] = restaurants[i][0];
            (*returnSize)++;
        }
    }
    return ans;
}