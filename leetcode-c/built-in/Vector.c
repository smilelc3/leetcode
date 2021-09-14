//
// Created by l30014168 on 2021/8/16.
//

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "Vector.h"

// 创建vector实例
Vector *VectorCreate(size_t itemSize) {
    Vector *vector = malloc(sizeof(Vector));
    if (vector == NULL) {
        fprintf(stderr, "malloc fail! function: (%s)\n", __func__);
        return NULL;
    }
    vector->items = NULL;
    vector->itemSize = itemSize;
    vector->size = 0;
    vector->cap = 0;
    return vector;
}

// 末尾追加元素
errno_t VectorAppend(Vector *vector, void *item) {
    errno_t ret = VectorInsert(vector, vector->size, item);
    if (ret != 0) {
        fprintf(stderr, "append fail! function(%s) size(%zu), item(%p)\n", __func__, vector->size, item);
    }
    return ret;
}

// 插入元素，时间O(1)~O(n)
errno_t VectorInsert(Vector *vector, size_t index, void *item) {
    errno_t ret = VectorResize(vector, vector->size + 1);       // 新增一个位置
    if (ret != 0) {
        fprintf(stderr, "insert fail! function(%s), index(%zu), size(%zu)\n", __func__, index, vector->size);
        return ret;
    }
    // 考虑内存覆盖问题，使用memmove函数
    memmove(VectorAtNoCheck(vector, index + 1),
            VectorAtNoCheck(vector, index),
            (vector->size - index - 1) * vector->itemSize);

    memcpy(VectorAtNoCheck(vector, index), item, vector->itemSize);
    return NO_ERROR;
}


// 重新调整vector容量，必须比当前cap大
errno_t VectorReserve(Vector *vector, size_t cap) {
    if (cap <= vector->cap) {
        fprintf(stderr, "cap(%zu) <= vector->cap(%zu)\n", cap, vector->cap);
        return ERANGE;
    }
    void *_newItems = realloc(vector->items, vector->itemSize * cap);
    if (_newItems == NULL) {
        fprintf(stderr, "realloc fail! function(%s) cap(%zu)\n", __func__, cap);
        return ENOMEM;
    } else {
        vector->items = _newItems;
        vector->cap = cap;
        return NO_ERROR;
    }
}

// 修改容器尺寸，有可能会截断
errno_t VectorResize(Vector *vector, size_t size) {
    if (vector->cap < size) {
        // 策略：初始化为8（借鉴utarray策略），倍增cap，直到容纳size;
        size_t _cap = vector->cap == 0 ? 8 : vector->cap;
        while (_cap < size) {
            _cap = _cap << 1;
        }
        errno_t ret = VectorReserve(vector, _cap);
        if (ret != 0) {
            fprintf(stderr, "resize fail! function(%s), size(%zu), cap(%zu)\n", __func__, size, _cap);
            return ret;
        }
    }
    vector->size = size;
    return NO_ERROR;
}

// 删除从beginIdx到endIdx的元素，区间为[beginIdx, endIdx)
errno_t VectorErase(Vector *vector, size_t beginIdx, size_t endIdx) {

    if (beginIdx >= endIdx || beginIdx >= vector->size || endIdx > vector->size) {
        fprintf(stderr, "out of range! function(%s), size(%zu), beginIdx(%zu), endIdx(%zu)\n",
                __func__, vector->size, beginIdx, endIdx);
        return ERANGE;
    }
    // 移动endIdx之后的数据到beginIdx
    memmove(VectorAtNoCheck(vector, beginIdx),
                           VectorAtNoCheck(vector, endIdx),
                           (vector->size - endIdx) * vector->itemSize);
    vector->size -= endIdx - beginIdx;
    return NO_ERROR;
}



