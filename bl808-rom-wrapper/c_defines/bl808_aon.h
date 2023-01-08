#ifndef __BL808_AON_H__
#define __BL808_AON_H__

#include "typedefs.h"

/** @defgroup  AON_Public_Types
 *  @{
 */

/**
 *  @brief AON DCDC level type definition
 */
typedef enum {
    AON_DCDC_LEVEL_0P900V = 0,  /*!< AON DCDC voltage 0.900V */
    AON_DCDC_LEVEL_1P075V = 7,  /*!< AON DCDC voltage 1.075V */
    AON_DCDC_LEVEL_1P100V = 8,  /*!< AON DCDC voltage 1.100V */
    AON_DCDC_LEVEL_1P125V = 9,  /*!< AON DCDC voltage 1.125V */
    AON_DCDC_LEVEL_1P900V = 31, /*!< AON DCDC voltage 1.900V */
} AON_DCDC_LEVEL_Type;

#endif