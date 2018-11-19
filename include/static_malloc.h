/* 
 * File:   static_malloc.h
 * Author: P. Sopasakis
 *
 * Created on November 19, 2018, 2:41 AM
 */
#include "static_malloc_sizes.h"
#include <stddef.h>

#ifndef STATIC_MALLOC_H
#define STATIC_MALLOC_H

#ifdef __cplusplus
extern "C"
{
#endif

    typedef unsigned int uint_t;


#define STALLOC_DATA_DFN(stalloc_data_type)                                      \
     static stalloc_data_type                                                    \
         (stalloc_data_ ## stalloc_data_type)                                    \
             [static_malloc_len_ ## stalloc_data_type]
#define STALLOC_IDX_DFN(stalloc_data_type)                                       \
     static size_t (stalloc_idx_ ## stalloc_data_type) = 0

#define S_ALLOC_DFN(stalloc_data_type)                                           \
    stalloc_data_type * STATIC_MALLOC(stalloc_data_type) (size_t len) {          \
    if (len > (static_malloc_len_ ## stalloc_data_type)                          \
       - (stalloc_idx_ ## stalloc_data_type) || len == 0) return 0;              \
    stalloc_data_type* (stalloc_pointer_ ## stalloc_data_type ## _data)          \
       = & (stalloc_data_ ## stalloc_data_type)                                  \
            [stalloc_idx_## stalloc_data_type];                                  \
    (stalloc_idx_ ## stalloc_data_type) += len;                                  \
    return (stalloc_pointer_ ## stalloc_data_type ## _data);                     \
    }

#define STATIC_MALLOC_DFN(stalloc_data_type)                                     \
     stalloc_data_type * STATIC_MALLOC(stalloc_data_type)(size_t len);           \
     STALLOC_DATA_DFN(stalloc_data_type);                                        \
     STALLOC_IDX_DFN(stalloc_data_type);                                         \
     S_ALLOC_DFN(stalloc_data_type)


#define STATIC_MALLOC(stalloc_data_type)                                         \
    static_malloc_##stalloc_data_type
#define STALLOC_ACTIVE_TYPE(stalloc_data_type)                                   \
    defined(static_malloc_len_##stalloc_data_type)                               \
        && (static_malloc_len_##stalloc_data_type) > 0

#if STALLOC_ACTIVE_TYPE(double)
    STATIC_MALLOC_DFN(double)
#endif

#if STALLOC_ACTIVE_TYPE(int)
    STATIC_MALLOC_DFN(int)
#endif

#if STALLOC_ACTIVE_TYPE(uint_t)
    STATIC_MALLOC_DFN(uint_t)
#endif

#if STALLOC_ACTIVE_TYPE(float)
    STATIC_MALLOC_DFN(float)
#endif



#ifdef __cplusplus
}
#endif

#endif /* STATIC_MALLOC_H */
