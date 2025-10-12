#include "fib.h"

long long int fib_naive(int n ){
    if (n <= 1)
        return n ;
    else
        return fib_naive(n-1) + fib_naive(n-2);
}

long long int fib_dynamic (int n, long long int DPFib[]){
    if (n<=1)
        return n ;
    if (DPFib[n] != -1)
        return DPFib[n] ;
    
    DPFib[n] = fib_dynamic(n-1 ,DPFib) + fib_dynamic(n-2 , DPFib);
    return DPFib[n] ;
}
