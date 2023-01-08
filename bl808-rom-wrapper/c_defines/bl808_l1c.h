#ifndef __BL808_L1C_H__
#define __BL808_L1C_H__

#include "typedefs.h"
#include "misc.h"

/**
 *  @brief L1C configuration structure type definition
 */
typedef struct {
    uint8_t cacheEn;
    uint8_t wayDis;
    uint8_t wa;
    uint8_t wb;
    uint8_t wt;
    uint8_t rsvd[3];
    uint32_t cacheRangeL;
    uint32_t cacheRangeH;
}L1C_CACHE_Cfg_Type;

/**
 *  @brief L1C BMX arb mode type definition
 */
typedef enum {
    L1C_BMX_ARB_FIX,                        /*!< 0->fix */
    L1C_BMX_ARB_ROUND_ROBIN,                /*!< 2->round-robin */
    L1C_BMX_ARB_RANDOM,                     /*!< 3->random */
}L1C_BMX_ARB_Type;

/**
 *  @brief L1C BMX configuration structure type definition
 */
typedef struct {
    uint8_t timeoutEn;                      /*!< Bus timeout enable: detect slave no reaponse in 1024 cycles */
    BL_Fun_Type errEn;                      /*!< Bus error response enable */
    L1C_BMX_ARB_Type arbMod;                /*!< 0->fix, 2->round-robin, 3->random */
}L1C_BMX_Cfg_Type;

/**
 *  @brief L1C BMX bus err type definition
 */
typedef enum {
    L1C_BMX_BUS_ERR_TRUSTZONE_DECODE,       /*!< Bus trustzone decode error */
    L1C_BMX_BUS_ERR_ADDR_DECODE,            /*!< Bus addr decode error */
}L1C_BMX_BUS_ERR_Type;

/**
 *  @brief L1C BMX bus err interrupt type definition
 */
typedef enum {
    L1C_BMX_ERR_INT_ERR,                    /*!< L1C BMX bus err interrupt */
    L1C_BMX_ERR_INT_ALL,                    /*!< L1C BMX bus err interrupt max num */
}L1C_BMX_ERR_INT_Type;

/**
 *  @brief L1C BMX time out interrupt type definition
 */
typedef enum {
    L1C_BMX_TO_INT_TIMEOUT,                 /*!< L1C_BMX timeout interrupt */
    L1C_BMX_TO_INT_ALL,                     /*!< L1C_BMX timeout interrupt max num */
}L1C_BMX_TO_INT_Type;

#endif