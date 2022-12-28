#include "typedefs.h"

#ifndef _MISC_H
#define _MISC_H

#ifdef BIT
#undef BIT
#define BIT(n) (1UL << (n))
#else
#define BIT(n) (1UL << (n))
#endif

/**
 * @brief Null Type definition
 */
#ifndef NULL
#define NULL 0
#endif

/**
 * @brief Error type definition
 */
typedef enum {
    SUCCESS = 0,
    ERROR = 1,
    TIMEOUT = 2,
    INVALID = 3, /* invalid arguments */
    NORESC = 4   /* no resource or resource temperary unavailable */
} BL_Err_Type;

/**
 * @brief Functional type definition
 */
typedef enum {
    DISABLE = 0,
    ENABLE = 1,
} BL_Fun_Type;

/**
 * @brief Status type definition
 */
typedef enum {
    RESET = 0,
    SET = 1,
} BL_Sts_Type;

/**
 * @brief Mask type definition
 */
typedef enum {
    UNMASK = 0,
    MASK = 1
} BL_Mask_Type;

/**
 * @brief Logical status Type definition
 */
typedef enum {
    LOGIC_LO = 0,
    LOGIC_HI = !LOGIC_LO
} LogicalStatus;

/**
 * @brief Active status Type definition
 */
typedef enum {
    DEACTIVE = 0,
    ACTIVE = !DEACTIVE
} ActiveStatus;

/**
 *  @brief Interrupt callback function type
 */
typedef void(intCallback_Type)(void);
typedef void (*pFunc)(void);

#define ARCH_MemCpy      arch_memcpy
#define ARCH_MemSet      arch_memset
#define ARCH_MemCmp      arch_memcmp
#define ARCH_MemCpy4     arch_memcpy4
#define ARCH_MemCpy_Fast arch_memcpy_fast
#define ARCH_MemSet4     arch_memset4

#ifdef DEBUG
void check_failed(uint8_t *file, uint32_t line);
#define CHECK_PARAM(expr) ((expr) ? (void)0 : check_failed((uint8_t *)__FILE__, __LINE__))
#else
#define CHECK_PARAM(expr) ((void)0)
#endif /* DEBUG */

void *arch_memcpy(void *dst, const void *src, uint32_t n);
void *arch_memset(void *s, uint8_t c, uint32_t n);
int arch_memcmp(const void *s1, const void *s2, uint32_t n);
uint32_t *arch_memcpy4(uint32_t *dst, const uint32_t *src, uint32_t n);
void *arch_memcpy_fast(void *pdst, const void *psrc, uint32_t n);
uint32_t *arch_memset4(uint32_t *dst, const uint32_t val, uint32_t n);
void memcopy_to_fifo(void *fifo_addr, uint8_t *data, uint32_t length);
void fifocopy_to_mem(void *fifo_addr, uint8_t *data, uint32_t length);
int arch_ctzll(uint64_t *val, uint32_t *bit);
int arch_clzll(uint64_t *val, uint32_t *bit);
int arch_ffsll(uint64_t *val, uint32_t *bit);
#endif
