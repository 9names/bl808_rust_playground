#ifndef __BL808_GLB_GPIO_H__
#define __BL808_GLB_GPIO_H__

#include "typedefs.h"
#include "bl808_gpio.h"

/**
 *  @brief GLB GPIO interrupt control mode type definition
 */
typedef enum {
    GLB_GPIO_INT_TRIG_SYNC_FALLING_EDGE = 0,        /*!< GPIO interrupt sync mode, GPIO falling edge trigger interrupt */
    GLB_GPIO_INT_TRIG_SYNC_RISING_EDGE = 1,         /*!< GPIO interrupt sync mode, GPIO rising edge trigger interrupt */
    GLB_GPIO_INT_TRIG_SYNC_LOW_LEVEL = 2,           /*!< GPIO interrupt sync mode, GPIO low level trigger interrupt (32k 3T) */
    GLB_GPIO_INT_TRIG_SYNC_HIGH_LEVEL = 3,          /*!< GPIO interrupt sync mode, GPIO high level trigger interrupt (32k 3T) */
    GLB_GPIO_INT_TRIG_SYNC_FALLING_RISING_EDGE = 4, /*!< GPIO interrupt sync mode, GPIO falling and rising edge trigger interrupt */
    GLB_GPIO_INT_TRIG_ASYNC_FALLING_EDGE = 8,       /*!< GPIO interrupt async mode, GPIO falling edge trigger interrupt */
    GLB_GPIO_INT_TRIG_ASYNC_RISING_EDGE = 9,        /*!< GPIO interrupt async mode, GPIO rising edge trigger interrupt */
    GLB_GPIO_INT_TRIG_ASYNC_LOW_LEVEL = 10,         /*!< GPIO interrupt async mode, GPIO low level trigger interrupt (32k 3T) */
    GLB_GPIO_INT_TRIG_ASYNC_HIGH_LEVEL = 11,        /*!< GPIO interrupt async mode, GPIO high level trigger interrupt (32k 3T) */
} GLB_GPIO_INT_TRIG_Type;

/**
 *  @brief GLB GPIO FIFO interrupt type definition
 */
typedef enum {
    GLB_GPIO_FIFO_INT_FER,  /*!< GLB GPIO FIFO Underflow or Overflow interrupt */
    GLB_GPIO_FIFO_INT_FIFO, /*!< GLB GPIO FIFO ready (tx_fifo_cnt > tx_fifo_th) interrupt */
    GLB_GPIO_FIFO_INT_END,  /*!< GLB GPIO FIFO Empty interrupt */
    GLB_GPIO_FIFO_INT_ALL,  /*!< All the interrupt */
} GLB_GPIO_FIFO_INT_Type;

/**
 *  @brief GLB GPIO FIFO Timing Phase type definition
 */
typedef enum {
    GPIO_FIFO_PHASE_FIRST_HIGH, /*!< GPIO first send high level */
    GPIO_FIFO_PHASE_FIRST_LOW,  /*!< GPIO first send low level */
} GLB_GPIO_FIFO_PHASE_Type;

/**
 *  @brief GLB GPIO FIFO Idle State type definition
 */
typedef enum {
    GPIO_FIFO_IDLE_LOW,
    GPIO_FIFO_IDLE_HIGH,
} GLB_GPIO_FIFO_IDLE_Type;

/**
 *  @brief GLB GPIO FIFO Latch Mode type definition
 */
typedef enum {
    GPIO_FIFO_LATCH_WRITE,    /*!< GPIO FIFO direct write I/O */
    GPIO_FIFO_LATCH_SETCLEAR, /*!< GPIO FIFO set/clr I/O */
} GLB_GPIO_FIFO_LATCH_Type;

/**
 *  @brief GPIO interrupt configuration structure type definition
 */
typedef struct
{
    GLB_GPIO_Type gpioPin;       /*!< GPIO pin num */
    GLB_GPIO_INT_TRIG_Type trig; /*!< GPIO interrupt trig mode */
    BL_Mask_Type intMask;        /*!< GPIO interrupt mask config */
} GLB_GPIO_INT_Cfg_Type;

/**
 *  @brief UART configuration structure type definition
 */
typedef struct
{
    uint8_t code0FirstTime;              /*!< The clock num of code0 first send */
    uint8_t code1FirstTime;              /*!< The clock num of code1 first send */
    uint16_t codeTotalTime;              /*!< The total clock num of code0/1(high + low */
    GLB_GPIO_FIFO_PHASE_Type code0Phase; /*!< low or high level of code0 first send */
    GLB_GPIO_FIFO_PHASE_Type code1Phase; /*!< low or high level of code1 first send */
    GLB_GPIO_FIFO_IDLE_Type idle;        /*!< the I/O idle level */
    uint8_t fifoDmaThreshold;            /*!< FIFO threshold */
    BL_Fun_Type fifoDmaEnable;           /*!< Enable or disable DMA of GPIO */
    GLB_GPIO_FIFO_LATCH_Type latch;      /*!< Write or set/clr GPIO level */
} GLB_GPIO_FIFO_CFG_Type;

#endif