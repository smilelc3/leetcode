//
// Created by l30014168 on 2021/9/14.
//

#include "uthash.h"
#include "Vector.h"
#include "util.h"

typedef struct {
    uint64_t distance;
    Vector *points;
    UT_hash_handle hh;
} Dis2PointsMap;


static inline void freeDis2PointsMap(Dis2PointsMap *head) {
    Dis2PointsMap *cur, *tmp;
    HASH_ITER(hh, head, cur, tmp) {
        HASH_DEL(head, cur);                    // delete map node
        VectorDestroy(cur->points);             // free point vector
        free(cur);                              // free  map node
    }
    free(head);
}


// 获取两点的间的距离（不开平方根）
static inline int64_t getTwoPointsDistance(const int *pointA, const int *pointB) {
    return fastPow(pointA[0] - pointB[0], 2) + fastPow(pointA[1] - pointB[1], 2);
}

int numberOfBoomerangs(int **points, int pointsSize, int *pointsColSize) {
    int ret = 0;
    for (int i = 0; i < pointsSize; i++) {
        Dis2PointsMap *dis2PointsMap = NULL;
        for (int j = 0; j < pointsSize; ++j) {
            if (i == j) {
                continue;
            }
            Dis2PointsMap *find;
            uint64_t dis = getTwoPointsDistance(points[i], points[j]);
            HASH_FIND(hh, dis2PointsMap, &dis, sizeof(uint64_t), find);
            if (find == NULL) {
                Dis2PointsMap *mapNode = calloc(1, sizeof(Dis2PointsMap));
                mapNode->distance = dis;
                mapNode->points = VectorCreate(sizeof(int));
                VectorAppend(mapNode->points, &j);
                HASH_ADD(hh, dis2PointsMap, distance, sizeof(uint64_t), mapNode);
            } else {
                VectorAppend(find->points, &j);
            }
        }

        Dis2PointsMap *cur, *tmp;
        HASH_ITER(hh, dis2PointsMap, cur, tmp) {
            ret += (int) ((cur->points->size) * (cur->points->size - 1));
        }
        freeDis2PointsMap(dis2PointsMap);
    }
    return ret;
}

