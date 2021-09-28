//
// Created by l30014168 on 2021/8/16.
//

#ifndef LEETCODE_C_VECTOR_H
#define LEETCODE_C_VECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include <errno.h>

#ifndef errno_t
typedef int errno_t;
#endif

#ifndef NO_ERROR
#define NO_ERROR 0
#endif

#ifndef ERANGE
#define ERANGE 34
#endif

#ifndef ENOMEM
#define ENOMEM 12      /* Out of Memory */
#endif

typedef struct tagVector {
    void *restrict items;       // restrict指针仅能通过该指针进行访问（读/写）
    size_t itemSize;
    size_t size;
    size_t cap;
} Vector;

Vector *VectorCreate(size_t itemSize);

errno_t VectorAppend(Vector *vector, void *item);

// 不带检查的坐标访问
static inline void *VectorAtNoCheck(Vector *vector, size_t idx) {
    // ANSI C 规定，不可以对void指针进行运算操作，因为我们不知道指针指向的数据类型大小，无法进行偏移；
    // GNU 规定，void指针的运算操作与char型保持一致；
    return (char *) vector->items + idx * vector->itemSize;     // 该处做兼容处理
}

// 带检查的坐标访问
static inline void *VectorAt(Vector *vector, size_t idx) {
    if (idx >= vector->size) {
        fprintf(stderr, "out of range! function(%s) index(%zu) size(%zu)\n", __func__, idx, vector->size);
        return NULL;
    }
    return VectorAtNoCheck(vector, idx);
}

errno_t VectorInsert(Vector *vector, size_t index, void *item);

// vector元素排序
static inline void VectorSort(Vector *vector, int (*ptrCmpFunc)(const void *, const void *)) {
    qsort(vector->items, vector->size, vector->itemSize, ptrCmpFunc);
}

errno_t VectorResize(Vector *vector, size_t size);

errno_t VectorReserve(Vector *vector, size_t cap);

errno_t VectorErase(Vector *vector, size_t beginIdx, size_t endIdx);

// 判断 vector 是否为空
static inline bool VectorIsEmpty(Vector *vector) {
    return vector->size == 0;
}

// 清空数据，不销毁内存
static inline void VectorClear(Vector *vector) {
    vector->size = 0;
}

// 销毁vector，回收内存
static inline void VectorDestroy(Vector *vector) {
    free(vector->items);
    free(vector);
}

#endif //LEETCODE_C_VECTOR_H
