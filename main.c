/* 
 * File:   main.c
 * Author: chung
 *
 * Created on November 19, 2018, 2:40 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "include/static_malloc.h"


/*
 * 
 */
int main(void) {
    printf("Number of doubles allocated : %5d\n", static_malloc_len_double);
    printf("Number of ints allocated    : %5d\n", static_malloc_len_int);
    double * x = STATIC_MALLOC(double)(5);
    double * y = STATIC_MALLOC(double)(5);

    printf("The cursor of double is at  : %5lu\n", stalloc_idx_double);
    printf("The cursor of int is at     : %5lu\n", stalloc_idx_int);
    
    int *z = STATIC_MALLOC(int)(10);

    printf("The cursor of int is at     : %5lu\n", stalloc_idx_int);
    
    printf("Pointers: 0x%p 0x%p 0x%p\n",x,y,z);
    
    
    return (EXIT_SUCCESS);
}

