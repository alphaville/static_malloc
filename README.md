# Static Malloc

In embedded programming it is often required to be 100% sure that dynamic memory allocation will work.

This is why, it should be used very carefully to guarantee deterministic behaviour. 

If possible, memory should be allocated when the application starts and no further allocation should take place afterwards.

This is a simple framework for safe memory allocation in C.

This framework should be used provided that:

- the exact amount of memory to be allocated is known before the start of the application
- it is not necessary to free memory while the application runs

This is a **header library**, meaning, you just need to include `static_malloc.h` in your C file.

## Using static_malloc
 
**Step 1.** Configure `static_malloc_sizes.h` and define the amount of memory to be allocated.

For example:

```c
#define static_malloc_len_double 123456
#define static_malloc_len_int 1000
#define static_malloc_len_char 50
#define static_malloc_len_uint_t 5000
```

You may define **any** datatype to be allocated.
 =
For example, if you have some datatype called `my_datatype_t`, and you need to pre-allocate memory of size `123000`, you only need to define 

```c
#define static_malloc_len_my_datatype_t 123000
``` 

**Step 2.** You may now use `static_malloc`  as follows

```c
#include "../include/static_malloc.h"
#include <stdio.h>

int main(void){
    /* Allocate an array of double of length 20 */
    double * x = STATIC_MALLOC(double)(20);
    
     /* Allocate an array of double of length 500 */
    double * y = STATIC_MALLOC(double)(500);
    
    /* You don't need to (and you shouldn't) free the memory */
    return 0;
}
```

For the datatypes `double`, `int` and `float`, you may use `STATIC_MALLOC` as above.

For other less frequently used datatypes, e.g., `char`, `short` etc, you need to define `STATIC_MALLOC(...)` as in the following example:

```c
#if STALLOC_ACTIVE_TYPE(char)
STATIC_MALLOC_DFN(char)
#endif
```

Here is a complete example

```c
#include "../include/static_malloc.h"
#include <stdio.h>

#if STALLOC_ACTIVE_TYPE(char)
STATIC_MALLOC_DFN(char)
#endif

int main(void)
{
    /* Allocate 5 chars */
    char *x = STATIC_MALLOC(char)(5);

    return 0;
}
```

## Pros and Cons

Pros:

- Safe usage of memory
- No need to free the memory

Cons: 

- Need to know how much memory the program needs, before it runs
- Freeing memory is not possible
- Reusing memory is difficult