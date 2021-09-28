//
// Created by l30014168 on 2021/9/27.
//

#include "ListNode.h"

typedef struct {
    int n;
    struct DuListNode *left, *right;    // 指向最长距离的左右两节点
    int maxDis;                         // 当前最大距离
    struct DuListNode *head;
} ExamRoom;


ExamRoom *examRoomCreate(int n) {
    ExamRoom *ret = calloc(1, sizeof(ExamRoom));
    ret->head = DuCirListCreate();
    ret->n = n;
    ret->maxDis = n - 1;
    return ret;
}

int examRoomSeat(ExamRoom *obj) {
    if (obj->left == NULL) {
        DuCirListInsert(obj->head, 0);
        obj->left = obj->head->next;
        return 0;
    }
    if (obj->right == NULL) {
        DuCirListInsert(obj->head->prev, obj->n - 1);
        obj->right = obj->head->prev;
        return obj->n - 1;
    }

    // 左右节点均存在


}

void examRoomLeave(ExamRoom *obj, int p) {

}

void examRoomFree(ExamRoom *obj) {
    DuCirListDestroy(obj->head);
    free(obj);
    obj = NULL;
}