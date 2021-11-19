//
// Created by l30014168 on 2021/7/13.
//

int countSegments(const char *s) {
    int wordsNum = 0;
    for (size_t idx = 0; *(s+idx) != '\0'; ++idx) {
        if (s[idx] != ' ' && (idx == 0 || s[idx - 1] == ' ')) {
            wordsNum++;
        }
    }
    return wordsNum;
}