//
// Created by l30014168 on 2021/9/24.
//

#include <string.h>
#include <stdbool.h>
#include "Vector.h"

void dfsSolver(const char *num, char *operators, int idx, Vector *ans, int target);

bool isStrWithOperatorsEquTarget(const char *num, const char *operators, int target) {
    // 使用两个栈记录计算流程：数据栈和符号栈
    static int64_t numsStack[10];
    static char oprStack[10];
    size_t numStrLen = strlen(num);
    int numsStackSize = 0;
    int oprStackSize = 0;

    int64_t tmp = 0;
    for (size_t i = 0; i < numStrLen; ++i) {
        tmp *= 10;
        tmp += num[i] - '0';
        if (operators[i] != '\0' || i == numStrLen - 1) {     // 已经记录下一个完整数字
            if (oprStackSize > 0 && oprStack[oprStackSize - 1] == '*') {    // 如果之前的符号栈顶是 *
                oprStack[oprStackSize - 1] = operators[i];     // 弹出 * 符号栈，重新进栈新运算符
                numsStack[numsStackSize - 1] *= tmp;        // 更新数据栈顶元素
            } else {        // 之前是 +/- 号，入栈
                numsStack[numsStackSize++] = tmp;           // 数据栈入栈
                oprStack[oprStackSize++] = operators[i];    // 符号栈入栈
            }
        tmp = 0;
        }
    }
    // 计算仅剩余+-运算符的结果
    int64_t left = numsStack[0];
    for (size_t idx = 1; idx < numsStackSize; ++idx) {
        switch (oprStack[idx - 1]) {
            case '+':
                left += numsStack[idx];
                break;
            case '-':
                left -= numsStack[idx];
        }
    }
    return left == target;
}

// 根据 num 和 operators构建结果字符串
char *connectOperatorsEquTarget(const char *num, const char *operators) {
    size_t operatorsNum = 0;
    size_t numLength;
    for (numLength = 0; num[numLength] != '\0'; ++numLength) {
        if (operators[numLength] != '\0') {
            operatorsNum++;
        }
    }
    char *ret = malloc(sizeof(char) * (operatorsNum + numLength + 1));
    size_t retLength = 0;
    for (int idx = 0; idx < numLength; ++idx) {
        ret[retLength++] = num[idx];
        if (operators[idx] != '\0') {
            ret[retLength++] = operators[idx];
        }
    }
    ret[retLength] = '\0';
    return ret;
}

char **addOperators(const char *num, int target, int *returnSize) {
    char *operators = calloc(1, sizeof(char) * strlen(num));        // operators[i] = t (t!=0) 代表在num[i]后添加t符号
    Vector *ans = VectorCreate(sizeof(char *));

    dfsSolver(num, operators, 0, ans, target);

    char **ret = NULL;
    if (ans->size != 0) {
        ret = malloc(sizeof(char *) * ans->size);
        memcpy(ret, ans->items, ans->size * ans->itemSize);
    }
    *returnSize = (int) ans->size;
    VectorDestroy(ans);
    free(operators);
    return ret;
}

void dfsSolver(const char *num, char *operators, int idx, Vector *ans, int target) {
    if (num[idx + 1] == '\0') {     // 到达终点
        if (isStrWithOperatorsEquTarget(num, operators, target)) {  // 如果满足答案，保存结果
            char *str = connectOperatorsEquTarget(num, operators);
            VectorAppend(ans, &str);
        }
        return;
    }
    // +
    operators[idx] = '+';
    dfsSolver(num, operators, idx + 1, ans, target);

    // -
    operators[idx] = '-';
    dfsSolver(num, operators, idx + 1, ans, target);
    // *

    operators[idx] = '*';
    dfsSolver(num, operators, idx + 1, ans, target);

    // null
    // 不允许出现0前缀的情况，例如：1+05、00+1
    operators[idx] = '\0';
    if (num[idx] == '0') {
        if (idx == 0 || operators[idx - 1] != '\0') {
            return;
        }
    }
    dfsSolver(num, operators, idx + 1, ans, target);
}
