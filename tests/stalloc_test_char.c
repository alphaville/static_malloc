#include "../include/static_malloc.h"
#include <stdio.h>

#if STALLOC_ACTIVE_TYPE(char)
STATIC_MALLOC_DFN(char)
#endif

int main(void)
{
    char *x;
    
    x = STATIC_MALLOC(char)(0);
    if (x!=0) return 1;

    x = STATIC_MALLOC(char)(5);
    if (x==0) return 2;

    x = STATIC_MALLOC(char)(2);
    if (x==0) return 3;

    x = STATIC_MALLOC(char)(4);
    if (x!=0) return 4;

    return 0;
}
