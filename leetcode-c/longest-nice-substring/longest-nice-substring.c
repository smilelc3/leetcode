//
// Created by smile on 2021/12/16.
//

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

# define LETTER_NUM_MAX 26

typedef struct {
    size_t left;
    size_t right;
} Window;   // 滑动窗口：left指代开始位置，right指代结束的下一个位置

// 返回种类数为 typeNum，满足 美好子串 的最大窗口
Window slidingWindowSolver(char *s, size_t sLength, uint8_t typeNum) {
    Window ret = {0, 0}, win = {0, 0};
    size_t LowerLetterNum[LETTER_NUM_MAX] = {0};     // 统计窗口内某种字符的小写个数
    size_t UpperLetterNum[LETTER_NUM_MAX] = {0};     // 统计窗口内某种字符的大写个数

    size_t unpairNum = 0;
    uint8_t winTypeNum = 0;
    while (win.right < sLength) {
        win.right++;
        uint8_t curLetterIdx = tolower(s[win.right - 1]) - 'a';
        bool isCurLetterLower = islower(s[win.right - 1]);
        if (LowerLetterNum[curLetterIdx] == 0 && UpperLetterNum[curLetterIdx] == 0) {   // 该字符均未出现过
            unpairNum++;
            winTypeNum++;
        } else if (LowerLetterNum[curLetterIdx] == 0 && UpperLetterNum[curLetterIdx] != 0) {   // 该字符出现过大写，未出现小写
            if (isCurLetterLower) {
                unpairNum--;
            }
        } else if (LowerLetterNum[curLetterIdx] != 0 && UpperLetterNum[curLetterIdx] == 0) {   // 该字符出现过小写，未出现大写
            if (!isCurLetterLower) {
                unpairNum--;
            }
        }
        if (isCurLetterLower) {
            LowerLetterNum[curLetterIdx]++;
        } else {
            UpperLetterNum[curLetterIdx]++;
        }

        // 开始缩减左边界
        while (winTypeNum > typeNum) {
            uint8_t rmLetterIdx = tolower(s[win.left]) - 'a';
            bool isRmLetterLower = islower(s[win.left]);
            if (isRmLetterLower) {
                LowerLetterNum[rmLetterIdx]--;
                if (LowerLetterNum[rmLetterIdx] == 0 && UpperLetterNum[rmLetterIdx] != 0) {
                    unpairNum++;    // 可能破坏掉配对，需要新增unpairNum
                }
            } else {
                UpperLetterNum[rmLetterIdx]--;
                if (LowerLetterNum[rmLetterIdx] != 0 && UpperLetterNum[rmLetterIdx] == 0) {
                    unpairNum++;
                }
            }
            // 如果清空了某一种字母，更新 winTypeNum 和 unpairNum
            if (LowerLetterNum[rmLetterIdx] == 0 && UpperLetterNum[rmLetterIdx] == 0) {
                winTypeNum--;
                unpairNum--;
            }
            win.left++;
        }
        // 统计
        if (winTypeNum == typeNum && unpairNum == 0) {
            if (ret.right - ret.left < win.right - win.left) {
                ret = win;
            }
        }
    }

    return ret;
}

char *longestNiceSubstring(char *s) {
    size_t strLen = strlen(s);
    // 统计字符种类（26种）
    uint8_t letterTypeNum = 0;
    bool isLetterExist[LETTER_NUM_MAX];
    memset(isLetterExist, false, sizeof(bool) * LETTER_NUM_MAX);
    for (size_t idx = 0; idx < strLen; ++idx) {
        if (isLetterExist[tolower(s[idx]) - 'a'] == false) {
            letterTypeNum++;
            isLetterExist[tolower(s[idx]) - 'a'] = true;
        }
    }
    // 对最多26种情况遍历
    size_t niceStrLeft = 0, niceStrLen = 0;
    for (uint8_t typeNum = 1; typeNum <= letterTypeNum; ++typeNum) {
        Window win = slidingWindowSolver(s, strLen, typeNum);
        if (win.right - win.left > niceStrLen) {
            niceStrLeft = win.left;
            niceStrLen = win.right - win.left;
        }
    }
    char *niceStr = malloc(sizeof(char) * (niceStrLen + 1));
    memcpy(niceStr, s + niceStrLeft, sizeof(char) * niceStrLen);
    niceStr[niceStrLen] = '\0';
    return niceStr;
}

