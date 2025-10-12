#include <stdlib.h>
#include <math.h>
#include "prime.h"

int is_prime_naive(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int count_primes_naive(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime_naive(i))
            count++;
    }
    return count;
}

int count_primes_optimal(int n) {
    if (n < 2)
        return 0;

    int isPrime[n + 1];

    for (int i = 0; i <= n; i++)
        isPrime[i] = 1;

    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int j = 2; j * j <= n; j++) {
        if (isPrime[j]) {
            for (int multiple = j * j; multiple <= n; multiple += j) {
                isPrime[multiple] = 0;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i])
            count++;
    }

    return count;
}
