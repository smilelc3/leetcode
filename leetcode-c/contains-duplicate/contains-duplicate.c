//
// Created by l30014168 on 2021/7/20.
//

#include <stdbool.h>
#include "uthash.h"

struct HashSet {
    int id;                    /* key */
    UT_hash_handle hh;         /* makes this structure hashable */
};


bool containsDuplicate(const int *nums, const int numsSize) {
    struct HashSet *hashSet = NULL;
    bool ans = false;
    for (int idx = 0; idx < numsSize; idx++) {
        struct HashSet *find;
        HASH_FIND_INT(hashSet, &nums[idx], find);  /* s: output pointer */
        if (find != NULL) {
            ans = true;
            break;
        }
        struct HashSet *item;
        item = (struct HashSet *) malloc(sizeof(struct HashSet));
        item->id = nums[idx];
        HASH_ADD_INT(hashSet, id, item);
    }

    // free ALL
    struct HashSet *cur;
    struct HashSet *temp;
    HASH_ITER(hh, hashSet, cur, temp) {
        HASH_DEL(hashSet, cur);  /* delete it (users advances to next) */
        free(cur);             /* free it */
    }
    return ans;
}