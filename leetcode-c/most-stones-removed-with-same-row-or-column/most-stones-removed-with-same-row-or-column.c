//
// Created by l30014168 on 2021/10/12.
//

#include <stdbool.h>

#define COORD_MAX 10000

typedef struct tagNode {
    int x, y;
    struct {        // 并查集额外的数据结构，father指向父节点，rank用于按秩合并
        struct tagNode *father;
        uint8_t rank;
    };
} Node;

static inline bool isNodesEqual(Node *node1, Node *node2) {
    return node1->x == node2->x && node1->y == node2->y;
}

Node *getFather(Node *node) {
    if (isNodesEqual(node->father, node)) {
        return node;
    }
    node->father = getFather(node->father);     // 并查集路径压缩
    return node->father;
}

void unionNodes(Node *node1, Node *node2) {
    node1 = getFather(node1);
    node2 = getFather(node2);
    if (isNodesEqual(node1, node2)) return;

    if (node1->rank > node2->rank) {    // 按秩(树深度)合并优化
        node2->father = node1;
    } else {
        if (node1->rank == node2->rank) {
            node2->rank++;
        }
        node1->father = node2;
    }
}

bool isSameClassNodes(Node *node1, Node *node2) {
    node1 = getFather(node1);
    node2 = getFather(node2);
    return isNodesEqual(node1, node2);
}

int removeStones(int **stones, int stonesSize, const int *stonesColSize) {
    int unionNum = 0;
    Node *nodes = malloc(sizeof(Node) * stonesSize);
    for (int i = 0; i < stonesSize; ++i) {
        nodes[i].x = stones[i][0];
        nodes[i].y = stones[i][1];
        nodes[i].father = &nodes[i];
        nodes[i].rank = 0;
    }
    Node *coordX[COORD_MAX] = {0}, *coordY[COORD_MAX] = {0};  // 记录之前存在的节点

    for (int i = 0; i < stonesSize; ++i) {
        if (coordX[nodes[i].x] != NULL) {
            unionNodes(coordX[nodes[i].x], nodes[i].father);
        }
        if (coordY[nodes[i].y] != NULL) {
            unionNodes(coordY[nodes[i].y], nodes[i].father);
        }
        coordX[nodes[i].x] = nodes[i].father;
        coordY[nodes[i].y] = nodes[i].father;
    }
    for (int i = 0; i < stonesSize; ++i) {
        if (isNodesEqual(nodes[i].father, &nodes[i])) {
            unionNum++;
        }
    }
    free(nodes);
    return stonesSize - unionNum;
}