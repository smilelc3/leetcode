//
// Created by smile on 2022/12/10.
//

#include <stdlib.h>
#include <string.h>

char *reverseWords(char *s) {
    if (s == NULL) {
        return NULL;
    }

    size_t len = strlen(s);
    char *ans = malloc((len + 1) * sizeof(char));

    size_t wordStart = 0, wordEnd = 1;  // 单个单词开始位置，单个单词结束位置的下一个
    while (wordStart != len) {
        if (s[wordEnd] != ' ' && s[wordEnd] != '\0') {
            wordEnd++;
            continue;
        }

        // 找到一个单词: s[wordStart, wordEnd)
        for (size_t t = wordStart; t < wordEnd; ++t) {
            ans[t] = s[wordEnd - (t - wordStart) - 1];
        }

        // 可能存在多个空格
        wordStart = wordEnd;
        while (s[wordStart] == ' ') {
            ans[wordStart] = ' ';
            wordStart++;
        }
        wordEnd = wordStart + 1;
    }
    ans[len] = '\0';
    return ans;
}