//
// Created by smile on 2024/8/13.
//

#include <string.h>

long long countSubstrings(char *s, char c) {

    long long num = 0;
    while (*s != '\0') {
        if (*s == c) {
            num++;
        }
        s++;
    }
    // return n(n-1)/2 + n;
    return num & 1 ? num * ((num + 1) >> 1) : (num >> 1) * (num + 1);
}