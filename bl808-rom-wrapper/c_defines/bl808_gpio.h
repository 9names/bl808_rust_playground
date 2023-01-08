#ifndef  __BL808_GPIO_H__
#define  __BL808_GPIO_H__

#include "typedefs.h"
#include "misc.h"

typedef enum
{
    GLB_GPIO_PIN_0 = 0,
    GLB_GPIO_PIN_1,
    GLB_GPIO_PIN_2,
    GLB_GPIO_PIN_3,
    GLB_GPIO_PIN_4,
    GLB_GPIO_PIN_5,
    GLB_GPIO_PIN_6,
    GLB_GPIO_PIN_7,
    GLB_GPIO_PIN_8,
    GLB_GPIO_PIN_9,
    GLB_GPIO_PIN_10,
    GLB_GPIO_PIN_11,
    GLB_GPIO_PIN_12,
    GLB_GPIO_PIN_13,
    GLB_GPIO_PIN_14,
    GLB_GPIO_PIN_15,
    GLB_GPIO_PIN_16,
    GLB_GPIO_PIN_17,
    GLB_GPIO_PIN_18,
    GLB_GPIO_PIN_19,
    GLB_GPIO_PIN_20,
    GLB_GPIO_PIN_21,
    GLB_GPIO_PIN_22,
    GLB_GPIO_PIN_23,
    GLB_GPIO_PIN_24,
    GLB_GPIO_PIN_25,
    GLB_GPIO_PIN_26,
    GLB_GPIO_PIN_27,
    GLB_GPIO_PIN_28,
    GLB_GPIO_PIN_29,
    GLB_GPIO_PIN_30,
    GLB_GPIO_PIN_31,
    GLB_GPIO_PIN_32,
    GLB_GPIO_PIN_33,
    GLB_GPIO_PIN_34,
    GLB_GPIO_PIN_35,
    GLB_GPIO_PIN_36,
    GLB_GPIO_PIN_37,
    GLB_GPIO_PIN_38,
    GLB_GPIO_PIN_39,
    GLB_GPIO_PIN_40,
    GLB_GPIO_PIN_41,
    GLB_GPIO_PIN_42,
    GLB_GPIO_PIN_43,
    GLB_GPIO_PIN_44,
    GLB_GPIO_PIN_45,
    GLB_GPIO_PIN_46,
    GLB_GPIO_PIN_47,
    GLB_GPIO_PIN_48,
    GLB_GPIO_PIN_49,
    GLB_GPIO_PIN_50,
    GLB_GPIO_PIN_51,
    GLB_GPIO_PIN_MAX,
}GLB_GPIO_Type;

#define  GPIO_MODE_INPUT                                        ((uint32_t)0x00000000U)   /*!< Input Floating Mode                   */
#define  GPIO_MODE_OUTPUT                                       ((uint32_t)0x00000001U)   /*!< Output Push Pull Mode                 */
#define  GPIO_MODE_AF                                           ((uint32_t)0x00000002U)   /*!< Alternate function                    */
#define  GPIO_MODE_ANALOG                                       ((uint32_t)0x00000003U)   /*!< Analog function                       */
#define  GPIO_PULL_UP                                           ((uint32_t)0x00000000U)   /*!< GPIO pull up                          */
#define  GPIO_PULL_DOWN                                         ((uint32_t)0x00000001U)   /*!< GPIO pull down                        */
#define  GPIO_PULL_NONE                                         ((uint32_t)0x00000002U)   /*!< GPIO no pull up or down               */
#define  GPIO_OUTPUT_VALUE_MODE                                 ((uint8_t)0x00U)          /*!< GPIO Output by reg_gpio_x_o Value                             */
#define  GPIO_SET_CLR_MODE                                      ((uint8_t)0x01U)          /*!< GPIO Output set by reg_gpio_x_set and clear by reg_gpio_x_clr */
#define  GPIO_DMA_OUTPUT_VALUE_MODE                             ((uint8_t)0x02U)          /*!< GPIO Output value by gpio_dma_o                               */
#define  GPIO_DMA_SET_CLR_MODE                                  ((uint8_t)0x03U)          /*!< GPIO Outout value by gpio_dma_set/gpio_dma_clr                */

typedef enum {
    GPIO_FUN_SDH = 0,
    GPIO_FUN_SPI0 = 1,
    GPIO_FUN_FLASH = 2,
    GPIO_FUN_I2S = 3,
    GPIO_FUN_PDM = 4,
    GPIO_FUN_I2C0 = 5,
    GPIO_FUN_I2C1 = 6,
    GPIO_FUN_UART = 7,
    GPIO_FUN_ETHER_MAC = 8,
    GPIO_FUN_CAM = 9,
    GPIO_FUN_ANALOG = 10,
    GPIO_FUN_GPIO = 11,
    GPIO_FUN_PWM0 = 16,
    GPIO_FUN_PWM1 = 17,
    GPIO_FUN_SPI1 = 18,
    GPIO_FUN_I2C2 = 19,
    GPIO_FUN_I2C3 = 20,
    GPIO_FUN_MM_UART = 21,
    GPIO_FUN_DBI_B = 22,
    GPIO_FUN_DBI_C = 23,
    GPIO_FUN_DPI = 24,
    GPIO_FUN_JTAG_LP = 25,
    GPIO_FUN_JTAG_M0 = 26,
    GPIO_FUN_JTAG_D0 = 27,
    GPIO_FUN_CLOCK_OUT = 31,
} GLB_GPIO_FUNC_Type;

typedef struct
{
    uint8_t gpioPin;
    uint8_t gpioFun;
    uint8_t gpioMode;
    uint8_t pullType;
    uint8_t drive;
    uint8_t smtCtrl;
    uint8_t outputMode;
}GLB_GPIO_Cfg_Type;

#endif