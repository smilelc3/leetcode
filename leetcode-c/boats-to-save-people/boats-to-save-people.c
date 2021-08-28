//
// Created by l30014168 on 2021/8/28.
//

#include <stdlib.h>

int descIntCompFunc(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int numRescueBoats(int *people, int peopleSize, int limit) {
    if (peopleSize <= 0) {
        return 0;
    }
    int ret = 0;
    qsort(people, peopleSize, sizeof(int), descIntCompFunc);
    int left = 0, right = peopleSize - 1;
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            right--;
        }
        left++;
        ret++;
    }
    return ret;
}