#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    for (int i = 0 ; i < n ; i++){
        if (arr[i] == target) 
            return i ;
    }
    return -1 ;
}

int jump_search(int *arr, int n, int target)
{
    if (!arr || n <= 0) return -1;
    if (!is_sorted_nondecreasing(arr, n)) return -1;

    int step = sqrt(n);
    int prev = 0 ;
    while (arr[min_int(step,n)-1] < target ){
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    for(int i=prev  ; i <= min_int(step,n) ; i++ ){

        if ( arr[i] ==  target ) return i ;
    }
    
    return -1;
}

int binary_search(int *arr, int n, int target)
{
    if (!arr || n <= 0) return -1;
    if (!is_sorted_nondecreasing(arr, n)) return -1;

    int left = 0 , right = n - 1 ;
    while (left <= right)
    {
        int mid = (left + right )/2 ;
        if ( arr[mid] == target ) return mid ; 
        else if (arr[mid] < target ) return left  = mid + 1 ;
        else right = mid - 1 ;
    }
    return -1;
}
