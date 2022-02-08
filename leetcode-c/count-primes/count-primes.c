//
// Created by lcsmile on 2022/1/30.
//

#include <stdbool.h>

int countPrimeNumLessEqN(int n) {
    bool *isNotPrime = calloc(n + 1, sizeof(bool));
    int *primes = malloc((n + 1) * sizeof(int));
    int primesSize = 0;
    for (int i = 2; i <= n; i++) {
        if (!isNotPrime[i]) {
            primes[primesSize++] = i;
        }
        for (int j = 0; j < primesSize; j++) {
            if (primes[j] * i > n) {
                break;
            }
            isNotPrime[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    free(isNotPrime);
    free(primes);
    return primesSize;
}

int countPrimes(int n) {
    return countPrimeNumLessEqN(n - 1);
}

