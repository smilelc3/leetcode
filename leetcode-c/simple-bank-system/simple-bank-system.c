//
// Created by l30014168 on 2021/10/26.
//

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long *balance;
    int num;
} Bank;


Bank *bankCreate(long long *balance, int balanceSize) {
    Bank *obj = malloc(sizeof(Bank));
    obj->balance = malloc(sizeof(long long) * balanceSize);
    memcpy(obj->balance, balance, balanceSize * sizeof(long long));
    obj->num = balanceSize;
    return obj;
}

bool bankWithdraw(Bank *obj, int account, long long money) {
    if (account > obj->num) {
        return false;
    }
    if (obj->balance[account - 1] < money) {
        return false;
    }
    obj->balance[account - 1] -= money;
    return true;
}

bool bankDeposit(Bank *obj, int account, long long money) {
    if (account > obj->num) {
        return false;
    }
    obj->balance[account - 1] += money;
    return true;
}

bool bankTransfer(Bank *obj, int account1, int account2, long long money) {
    if (bankWithdraw(obj, account1, money) == true) {
        if (bankDeposit(obj,account2, money) == true) {     // 可能存在account2不存在
            return true;
        }
        bankDeposit(obj, account1, money);
    }
    return false;
}

void bankFree(Bank *obj) {
    free(obj->balance);
    free(obj);
}
