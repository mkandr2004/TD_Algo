#include <stdio.h>
#include <time.h>
#include "fib.h"
#include "prime.h"

int main() {

    // ----- Fibonacci

    int n = 45;
    clock_t start, end;
    double secondes;

    // Version naive
    start = clock();
    long long int r1 = fib_naive(n);
    end = clock();
    secondes = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Naive Fibonacci(%d) = %lld, Time = %f secondes\n", n, r1, secondes);

    // Version dynamique 
    long long int DPFib[n + 1];
    for (int i = 0; i <= n; i++) {
        DPFib[i] = -1;
    }

    start = clock();
    long long int r2 = fib_dynamic(n, DPFib);
    end = clock();
    secondes = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Dynamic Fibonacci(%d) = %lld, Time = %f secondes\n", n, r2, secondes);

    // ----- Prime Numbers

    int nbr = 400; 

    // Version naive
    start = clock();
    int primes_naive = count_primes_naive(nbr);
    end = clock();
    secondes = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Naive Prime Count (<%d) = %d, Time = %f secondes\n", nbr, primes_naive, secondes);

    // Version optimale
    start = clock();
    int primes_opt = count_primes_optimal(nbr);
    end = clock();
    secondes = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Optimal Prime Count (<%d) = %d, Time = %f secondes\n", nbr, primes_opt, secondes);

    return 0;
}
