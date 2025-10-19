#include "utils.h"

void swap_int(int *a, int *b)
{
    int tmp = *a ;
    *a = *b ;
    *b = tmp ;
}

bool is_sorted_nondecreasing(int *arr, int n)
{
    if (! arr || n <= 1 ) 
        return true ;
    for (int i = 1 ; i < n ; i++){
        if (arr[i] < arr[i-1]) 
            return false ;
    }
    return true ;
}

void copy_array(int *src, int *dst, int n)
{
    for (int i = 0 ; i < n ; i++)
        dst[i] = src[i] ;
}
