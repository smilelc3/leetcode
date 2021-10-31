//
// Created by l30014168 on 2021/10/26.
//

#include <stdlib.h>
#include <string.h>

typedef struct {
    int *encoding;
    int encodingSize;
    int idx;        // 当前游标的位置
} RLEIterator;


RLEIterator *rLEIteratorCreate(int *encoding, int encodingSize) {
    RLEIterator *obj = malloc(sizeof(RLEIterator));
    obj->encodingSize = encodingSize;
    obj->encoding = malloc(sizeof(int) * encodingSize);
    memcpy(obj->encoding, encoding, sizeof(int) * encodingSize);
    obj->idx = 0;
    return obj;
}

int rLEIteratorNext(RLEIterator *obj, int n) {
    int ans;
    while (n > 0) {
        if (obj->idx >= obj->encodingSize) {
            return -1;
        }
        ans = obj->encoding[obj->idx + 1];
        if (obj->encoding[obj->idx] > n) {
            obj->encoding[obj->idx] -= n;
            n = 0;
        } else {
            n -= obj->encoding[obj->idx];
            obj->idx += 2;
        }
    }
    return ans;
}

void rLEIteratorFree(RLEIterator *obj) {
    free(obj->encoding);
    free(obj);
}