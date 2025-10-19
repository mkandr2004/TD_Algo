#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

#define N 1000

// Fonction pour remplir un tableau avec des nbres aléatoires
void fill_random_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }
}

int main(void) {
    srand(time(NULL));

    // Création du tableau original
    int *Tableau = malloc(N * sizeof(int));
    if (!Tableau) {
        printf("Erreur d'allocation mémoire !\n");
        return 1;
    }
    fill_random_array(Tableau, N);

    // Tableaux pour chaque algorithme
    int *arr = malloc(N * sizeof(int));
    if (!arr){ 
        free(Tableau);
        return 1; 
    }

    clock_t start, end;
    double seconds;

    // ----- Selection Sort -----
    copy_array(Tableau, arr, N);
    start = clock();
    selection_sort(arr, N);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort: Temps = %f secondes, Trié  %s\n", seconds,
           is_sorted_nondecreasing(arr, N) ? "Oui" : "Non");

    // ----- Insertion Sort -----
    copy_array(Tableau, arr, N);
    start = clock();
    insertion_sort(arr, N);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort: Temps = %f secondes, Trié  %s\n", seconds,
           is_sorted_nondecreasing(arr, N) ? "Oui" : "Non");

    // ----- Bubble Sort -----
    copy_array(Tableau, arr, N);
    start = clock();
    bubble_sort(arr, N);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort: Temps = %f secondes, Trié  %s\n", seconds,
           is_sorted_nondecreasing(arr, N) ? "Oui" : "Non");

    // ----- Merge Sort -----
    copy_array(Tableau, arr, N);
    start = clock();
    merge_sort(arr, N);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort: Temps = %f secondes, Trié  %s\n", seconds,
           is_sorted_nondecreasing(arr, N) ? "Oui" : "Non");

    // ----- Quick Sort -----
    copy_array(Tableau, arr, N);
    start = clock();
    quick_sort(arr, N);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort: Temps = %f secondes, Trié  %s\n", seconds,
           is_sorted_nondecreasing(arr, N) ? "Oui" : "Non");

    free(Tableau);
    free(arr);

    return 0;
}
