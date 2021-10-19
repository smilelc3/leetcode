//
// Created by l30014168 on 2021/10/18.
//

#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "Vector.h"

typedef struct {
    int key;
    uint32_t val;
    UT_hash_handle hh;
} Val2IdxMap;


typedef struct {
    Vector *values;
    Val2IdxMap *val2IdxMap;
} RandomizedSet;


RandomizedSet *randomizedSetCreate() {
    RandomizedSet *obj = malloc(sizeof(RandomizedSet));
    obj->values = VectorCreate(sizeof(uint32_t));
    obj->val2IdxMap = NULL;
    srand((unsigned int) time(NULL));
    return obj;
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
    Val2IdxMap *find;
    HASH_FIND(hh, obj->val2IdxMap, &val, sizeof(int), find);
    if (find != NULL) {
        return false;
    }
    find = malloc(sizeof(Val2IdxMap));
    find->key = val;
    VectorAppend(obj->values, &find->key);
    find->val = (uint32_t) obj->values->size - 1;  // 在末尾插入
    HASH_ADD(hh, obj->val2IdxMap, key, sizeof(int), find);
    return true;
}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
    Val2IdxMap *find;
    HASH_FIND(hh, obj->val2IdxMap, &val, sizeof(int), find);
    if (find == NULL) {
        return false;
    }
    int lastVal = *(int *) VectorAt(obj->values, obj->values->size - 1);
    *(int *) VectorAt(obj->values, find->val) = lastVal;        // 当前位置和最后一个替换
    Val2IdxMap *last;
    HASH_FIND(hh, obj->val2IdxMap, &lastVal, sizeof(int), last);
    if (last == NULL) {
        return false;
    }
    last->val = find->val;
    obj->values->size--;
    HASH_DEL(obj->val2IdxMap, find);
    free(find);
    return true;
}

int randomizedSetGetRandom(RandomizedSet *obj) {
    uint32_t randIdx = rand() % obj->values->size;
    return *(int *) VectorAtNoCheck(obj->values, randIdx);
}

void randomizedSetFree(RandomizedSet *obj) {
    Val2IdxMap *cur, *tmp;
    HASH_ITER(hh, obj->val2IdxMap, cur, tmp) {
        HASH_DEL(obj->val2IdxMap, cur);
        free(cur);
    }
    VectorDestroy(obj->values);
    free(obj);
}
