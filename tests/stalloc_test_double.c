#include "../include/static_malloc.h"
#include <stdio.h>

int main(void){

    double * x;
    x  = STATIC_MALLOC(double)(0);
    if (x != 0) return 1;

    x  = STATIC_MALLOC(double)(static_malloc_len_double-1);
    if (x == 0) return 2;

    x = STATIC_MALLOC(double)(1);    
    if (x == 0) return 3;

    x = STATIC_MALLOC(double)(1);    
    if (x != 0) return 4;
        
    
    return 0;
}
