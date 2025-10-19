#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n)
{
    if (! arr || n <= 1 ) 
        return true ;
    for (int i = 1 ; i < n ; i++){
        if (arr[i] < arr[i-1]) 
            return false ;
    }

    return true ;
    // return true if array is sorted and false otherwise
}

int min_int(int a, int b)
{
    if (a < b) 
        return a ;
    return b ;
    // return smallest value between a and b
}
