//
// Created by l30014168 on 2021/8/31.
//

#include <stdlib.h>
#include <time.h>

typedef struct {
    int *prefixSum;
    int length;
} Solution;


Solution *solutionCreate(const int *w, int wSize) {
    Solution *obj = malloc(sizeof(Solution));
    if (obj == NULL) {
        perror("malloc Solution object fail.\n");
        return NULL;
    }
    if (wSize <= 0) {
        obj->prefixSum = NULL;
        return obj;
    }
    obj->prefixSum = malloc(sizeof(int) * wSize);
    if (obj->prefixSum == NULL) {
        perror("malloc Solution->prefixSum fail.");
        free(obj);
        return NULL;
    }
    obj->prefixSum[0] = w[0];
    obj->length = wSize;
    for (int idx = 1; idx < wSize; ++idx) {
        obj->prefixSum[idx] = obj->prefixSum[idx - 1] + w[idx];
    }
    srand(time(NULL));
    return obj;
}

int solutionPickIndex(Solution *obj) {
    int randNum = rand() % obj->prefixSum[obj->length - 1];
    int left = 0, right = obj->length - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        int midVal = obj->prefixSum[mid];
        if (midVal <= randNum) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}

void solutionFree(Solution *obj) {
    free(obj->prefixSum);
    free(obj);
}