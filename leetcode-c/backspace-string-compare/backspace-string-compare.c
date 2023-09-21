//
// Created by smile on 2023/9/19.
//
#include <stdbool.h>
#include <string.h>

bool backspaceCompare(char *s, char *t) {
    char *sPtr = s;
    char *newS = s;
    while (*sPtr != '\0') {
        if (*sPtr == '#') {
            if (newS > s) {
                newS--;
            }
        } else {
            *newS = *sPtr;
            newS++;
        }
        sPtr++;

    }
    *newS = '\0';

    char *tPtr = t;
    char *newT = t;
    while (*tPtr != '\0') {
        if (*tPtr == '#') {
            if (newT > t) {
                newT--;
            }
        } else {
            *newT = *tPtr;
            newT++;
        }
        tPtr++;
    }
    *newT = '\0';

    return (newS - s == newT - t) && strcmp(s, t) == 0;
}