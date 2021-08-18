//
// Created by l30014168 on 2021/7/15.
//

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **dfsSolution(char *s, int *returnSize, int curIdx, char **res) {
    if (curIdx == strlen(s)) {      // 已到达末尾
        char *sCopy = (char *) malloc(sizeof(char) * (curIdx + 1)); // add '\0'
        if (sCopy == NULL) {    // 未成功申请空间
            perror("malloc fail\n");
            return NULL;
        }
        strcpy(sCopy, s);
        if (*returnSize == 0) { // 首次申请空间
            res = (char **) malloc(sizeof(char *));
        } else if (((*returnSize) & ((*returnSize) - 1)) == 0) {    // *returnSize 为2的整数幂
            res = (char **) realloc(res, sizeof(char *) * (*returnSize) * 2); // 后续申请倍增
            if (res == NULL) {// 扩容失败
                return NULL;
            }
        }
        res[(*returnSize)] = sCopy;
        (*returnSize)++;
        return res;
    }

    if (isdigit(s[curIdx])) {
        res = dfsSolution(s, returnSize, curIdx + 1, res);
    } else {
        s[curIdx] = (char) tolower(s[curIdx]);
        res = dfsSolution(s, returnSize, curIdx + 1, res);
        s[curIdx] = (char) toupper(s[curIdx]);
        res = dfsSolution(s, returnSize, curIdx + 1, res);
    }
    return res;
}

char **letterCasePermutation(char *s, int *returnSize) {
    char **res = NULL;
    *returnSize = 0;
    return dfsSolution(s, returnSize, 0, res);
}
