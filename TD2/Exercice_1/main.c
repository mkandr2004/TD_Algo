#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

#define N 1000

int main(void)
{
    int arr[N];
    // remplir un tableau trié : 0, 2, 4, 6, ...
    for (int i = 0; i < N; i++)
        arr[i] = i * 2;

    int target = 601;
    int target2 = 9939;

    printf("Recherche de %d et %d dans un tableau de %d éléments...\n\n", target, target2, N);

    clock_t start, end;
    double time_used;

    // LINEAR SEARCH
    start = clock();
    int idx_linear = linear_search(arr, N, target);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Linear Search: index = %d, temps = %.6f sec\n", idx_linear, time_used);

    // JUMP SEARCH
    start = clock();
    int idx_jump = jump_search(arr, N, target);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Jump Search:   index = %d, temps = %.6f sec\n", idx_jump, time_used);

    // BINARY SEARCH
    start = clock();
    int idx_binary = binary_search(arr, N, target);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search: index = %d, temps = %.6f sec\n\n", idx_binary, time_used);

    // Vérifier valeur inexistante
    printf("Recherche d'une valeur inexistante (%d):\n", target2);
    printf("Linear : %d | Jump : %d | Binary : %d\n",
           linear_search(arr, N, target2),
           jump_search(arr, N, target2),
           binary_search(arr, N, target2));

    return 0;
}
