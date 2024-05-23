//
// Created by smile on 24-5-22.
//

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

char *pushDominoes(char *dominoes) {
    size_t len = strlen(dominoes);
    char *ans = malloc((len + 1) * sizeof(char));
    ans[len] = '\0';

    int *LTime = malloc(sizeof(int) * (len + 1)); // 代表向L倒下时间
    bool LFlag = false;
    for (size_t idx = len; idx-- > 0;) {
        if (dominoes[idx] == 'L') {
            LTime[idx] = 1;
            LFlag = true;
        } else if (dominoes[idx] == 'R') {
            LTime[idx] = INT_MAX; // 代表永远不会倒下
            LFlag = false;
        } else { // dominoes[idx] == '.'
            LTime[idx] = LFlag == true ? LTime[idx + 1] + 1 : INT_MAX;
        }
    }

    int curRTime = 0; // 代表向R倒下时间
    bool RFlag = 0;
    for (size_t idx = 0; idx < len; ++idx) {
        if (dominoes[idx] == 'R') {
            curRTime = 1;
            RFlag = true;
        } else if (dominoes[idx] == 'L') {
            curRTime = INT_MAX;
            RFlag = false;
        } else { // dominoes[idx] == '.'
            curRTime = RFlag == true ? curRTime + 1 : INT_MAX;
        }

        if (LTime[idx] > curRTime) { // 先向右边倒 -> R
            ans[idx] = 'R';
        } else if (LTime[idx] < curRTime) { // 先向左边倒 -> L
            ans[idx] = 'L';
        } else { // L[idx] == curRVal，均永远不倒或同时两边倒 -> 均不倒
            ans[idx] = '.';
        }
    }
    free(LTime);
    return ans;
}
