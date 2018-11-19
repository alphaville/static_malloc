#include "../include/static_malloc.h"
#include <stdio.h>

int main(void){

    int * y;
    
    y = STATIC_MALLOC(int)(0);
    if (y != 0) return 1;

    y = STATIC_MALLOC(int)(95);
    if (y == 0) return 2;

    y = STATIC_MALLOC(int)(5);
    if (y == 0) return 3;

    y = STATIC_MALLOC(int)(1);
    if (y != 0) return 3;
    
    return 0;
}
