//
// Created by smile on 2021/12/16.
//

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

# define MAX_LITTLE_NUM 26

char *longestNiceSubstring(char *s) {
    uint8_t littleFlag[MAX_LITTLE_NUM] = {0};       // 定义字母状态，0 未出现， 1出现小写，2出现大写，3既出现大写也出现小写
    size_t strLen = strlen(s);
    char *ans = malloc(sizeof(char) * (strLen + 1));
    size_t ansLeft = 0, ansLen = 0;

    for (size_t left = 0; left < strLen; ++left) {
        memset(littleFlag, 0, sizeof(uint8_t) * MAX_LITTLE_NUM);
        int unpairNum = 1;
        if (islower(s[left])) {
            littleFlag[s[left] - 'a'] = 1;
        } else if (isupper(s[left])) {
            littleFlag[s[left] - 'A'] = 2;
        }
        for (size_t right = left + 1; right < strLen; ++right) {
            bool isLittleLower;
            size_t littleIdx;
            if (islower(s[right])) {
                isLittleLower = true;
                littleIdx = s[right] - 'a';
            } else {
                isLittleLower = false;
                littleIdx = s[right] - 'A';
            }
            if (isLittleLower) {
                if (littleFlag[littleIdx] == 2) {
                    littleFlag[littleIdx] = 3;
                    unpairNum--;
                } else if (littleFlag[littleIdx] == 0) {
                    littleFlag[littleIdx] = 1;
                    unpairNum++;
                }
            } else {
                if (littleFlag[littleIdx] == 1) {
                    littleFlag[littleIdx] = 3;
                    unpairNum--;
                } else if (littleFlag[littleIdx] == 0) {
                    littleFlag[littleIdx] = 2;
                    unpairNum++;
                }
            }
            if (unpairNum == 0) {
                if (right - left + 1 > ansLen) {
                    ansLeft = left;
                    ansLen = right - left + 1;
                }
            }
        }
    }
    memcpy(ans, s + ansLeft, sizeof(char) * ansLen);
    ans[ansLen] = '\0';
    return ans;
}