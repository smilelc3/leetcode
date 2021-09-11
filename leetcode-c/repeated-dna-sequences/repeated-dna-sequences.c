//
// Created by l30014168 on 2021/7/22.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <uthash.h>

#define DNA_SUB_MAX_LEN 10

typedef struct {
    int cprStr;
    UT_hash_handle hh;
} ZipStrSet;

// 压缩DNA字符串，每个字符仅可能为A/C/G/T，单个符号压缩成2位二进制
static int zipDnaStr(const char *str, size_t length) {
    if (length > sizeof(int) * 8 / 2) {
        fprintf(stderr, "cpr str length(%zu) > limit(%zu).\n", length, sizeof(int) * 8 / 2);
        return 0;
    }
    int ret = 0;
    for (size_t idx = 0; idx < length; idx++) {
        switch (str[idx]) {
            case 'A':
                // ret |= 0b00 << (idx * 2);         // 无意义
                break;
            case 'C':
                ret |= 0b01 << (idx * 2);
                break;
            case 'G':
                ret |= 0b10 << (idx * 2);
                break;
            case 'T':
                ret |= 0b11 << (idx * 2);
                break;
            default:
                fprintf(stderr, "DNA str at(%zu) char(%c) illegal.\n", idx, str[idx]);
        }
    }
    return ret;
}

// 解压DNA字符串
static char *unZipDnaStr(int zipDna) {
    char *ret = malloc(sizeof(char) * (DNA_SUB_MAX_LEN + 1));
    if (ret == NULL) {
        fprintf(stderr, "malloc unzip DNA str fail. zipDNA(%u)\n", zipDna);
        return NULL;
    }
    for (size_t idx = 0; idx < DNA_SUB_MAX_LEN; ++idx) {
        switch (zipDna & 0b11) {
            case 0b00:
                ret[idx] = 'A';
                break;
            case 0b01:
                ret[idx] = 'C';
                break;
            case 0b10:
                ret[idx] = 'G';
                break;
            case 0b11:
                ret[idx] = 'T';
                break;
        }
        zipDna = zipDna >> 2;
    }
    ret[DNA_SUB_MAX_LEN] = '\0';
    return ret;
}

// 释放ZipStrSet空间
static void freeZipStrSet(ZipStrSet *set) {
    ZipStrSet *cur, *tmp;
    HASH_ITER(hh, set, cur, tmp) {
        HASH_DEL(set, cur);
        free(cur);
    }
    free(set);
}

char **findRepeatedDnaSequences(char *s, int *returnSize) {
    *returnSize = 0;
    ZipStrSet *dnaHashSet = NULL;
    ZipStrSet *retHashSet = NULL;
    char **ret = NULL;
    size_t sSize = strlen(s);
    if (sSize <= DNA_SUB_MAX_LEN) {
        return ret;
    }
    for (size_t idx = 0; idx + DNA_SUB_MAX_LEN <= sSize; ++idx) {
        static int zipDNA;
        if (idx == 0) {
            zipDNA = zipDnaStr(s, DNA_SUB_MAX_LEN);
        } else {    // 复用之前的计算结果，减少计算量(删除末位，更新首位)
            zipDNA = zipDNA >> 2 | (zipDnaStr(s + idx + DNA_SUB_MAX_LEN - 1, 1) << 2 * (DNA_SUB_MAX_LEN - 1));
        }

        ZipStrSet *find;
        HASH_FIND_INT(dnaHashSet, &zipDNA, find);
        if (find == NULL) {
            // 之前不存在该DNA段，添加的DNA hash
            ZipStrSet *item = malloc(sizeof(ZipStrSet));
            if (item == NULL) {
                fprintf(stderr, "malloc new CprStrSet item fail.\n");
                freeZipStrSet(dnaHashSet); // 回收哈希表
                freeZipStrSet(retHashSet);
                return NULL;
            }
            item->cprStr = zipDNA;
            HASH_ADD_INT(dnaHashSet, cprStr, item);
        } else {
            // 之前已存在该DNA段，添加到retHashSet
            HASH_FIND_INT(retHashSet, &zipDNA, find);
            if (find == NULL) {
                ZipStrSet *item = malloc(sizeof(ZipStrSet));
                if (item == NULL) {
                    fprintf(stderr, "malloc new CprStrSet item fail.\n");
                    freeZipStrSet(dnaHashSet); // 回收哈希表
                    freeZipStrSet(retHashSet);
                    return NULL;
                }
                item->cprStr = zipDNA;
                HASH_ADD_INT(retHashSet, cprStr, item);
            }
        }
    }
    freeZipStrSet(dnaHashSet);

    *returnSize = HASH_COUNT(retHashSet);
    ret = (char **) realloc(ret, sizeof(char *) * (*returnSize));
    if (ret == NULL) {
        fprintf(stderr, "malloc ret fail.\n");
        freeZipStrSet(retHashSet);
        return NULL;
    }
    int idx = 0;
    for (ZipStrSet *pSet = retHashSet; pSet != NULL; pSet = pSet->hh.next, idx++) {
        ret[idx] = unZipDnaStr(pSet->cprStr);
    }
    freeZipStrSet(retHashSet);
    return ret;
}
