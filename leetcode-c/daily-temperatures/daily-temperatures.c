//
// Created by l30014168 on 2021/7/23.
//

static int *dailyTemperatures(const int *temperatures, const int temperaturesSize, int *returnSize) {
    if (temperatures <= 0) {
        return NULL;
    }
    int *ret;
    ret = calloc(temperaturesSize, sizeof(int));           // 存结果
    if (ret == NULL) {
        perror("malloc fail");
        return NULL;
    };
    int *stack = malloc(sizeof(int) * temperaturesSize);        // 单调非递增栈，记录idx
    if (stack == NULL) {
        perror("malloc fail");
        free(ret);
        return NULL;
    }
    *returnSize = temperaturesSize;
    int stackSize = 0;
    for (int idx = 0; idx < temperaturesSize; ++idx) {
        // 不满足单调栈，持续出栈
        while (stackSize > 0 && temperatures[stack[stackSize - 1]] < temperatures[idx]) {
            ret[stack[stackSize - 1]] = idx - stack[stackSize - 1];     // 当前距离就是答案
            stackSize--;
        }
        stack[stackSize++] = idx;         // 此时栈空或满足单调栈，入栈
    }
    free(stack);
    return ret;
}

