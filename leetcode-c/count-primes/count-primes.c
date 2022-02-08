//
// Created by l30014168 on 2022/1/30.
//

#include <stdbool.h>

#define N_MAX 5 * 1000000

int countPrimes(int n) {
    static bool isNotPrime[N_MAX + 1] = {0};
    static bool isInit = false;
    static int prefix[N_MAX + 1] = {0};
    static int preMax = 2;
    if (!isInit) {
        int primes[N_MAX + 1], primesSize = 0;
        for (int i = 2; i <= N_MAX; i++) {
            if (!isNotPrime[i]) {
                primes[primesSize++] = i;
            }
            for (int j = 0; j < primesSize; j++) {
                if (primes[j] * i > N_MAX) {
                    break;
                }
                isNotPrime[primes[j] * i] = true;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        isInit = true;
    }
    if (n > preMax) {
        int count = prefix[preMax];
        for (int i = preMax + 1; i <= n; i++) {
            if (!isNotPrime[i - 1]) {
                count++;
            }
            prefix[i] = count;
        }
        preMax = n;
    }

    return prefix[n];
}