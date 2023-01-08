#ifndef __BL808_HBN_H__
#define __BL808_HBN_H__

#include "bl808_gpio.h"
#include "bl808_sflash.h"
#include "typedefs.h"
#include "misc.h"

/**
 *  @brief HBN PIR interrupt configuration type definition
 */
typedef struct
{
    BL_Fun_Type lowIntEn;  /*!< Low will trigger interrupt */
    BL_Fun_Type highIntEn; /*!< High will trigger interrupt */
} HBN_PIR_INT_CFG_Type;

/**
 *  @brief HBN PIR low pass filter type definition
 */
typedef enum {
    HBN_PIR_LPF_DIV1, /*!< HBN PIR lpf div 1 */
    HBN_PIR_LPF_DIV2, /*!< HBN PIR lpf div 2 */
} HBN_PIR_LPF_Type;

/**
 *  @brief HBN PIR high pass filter type definition
 */
typedef enum {
    HBN_PIR_HPF_METHOD0, /*!< HBN PIR hpf calc method 0, 1-z^-1 */
    HBN_PIR_HPF_METHOD1, /*!< HBN PIR hpf calc method 1, 1-z^-2 */
    HBN_PIR_HPF_METHOD2, /*!< HBN PIR hpf calc method 2, 1-z^-3 */
} HBN_PIR_HPF_Type;

/**
 *  @brief HBN flash pad pu pd type
 */
typedef enum {
    HBN_FLASH_PAD_PULL_NONE, /*!< flash pad pull none when Flash at Deep Power Down Mode */
    HBN_FLASH_PAD_PULL_UP,   /*!< flash pad pull up when Flash at Deep Power Down Mode */
    HBN_FLASH_PAD_PULL_DOWN, /*!< flash pad pull down when Flash at Deep Power Down Mode */
} HBN_FLASH_PAD_PULL_Type;

/**
 *  @brief HBN BOD threshold type definition
 */
typedef enum {
    HBN_BOD_THRES_2P05V, /*!< BOD threshold 2.05V */
    HBN_BOD_THRES_2P10V, /*!< BOD threshold 2.10V */
    HBN_BOD_THRES_2P15V, /*!< BOD threshold 2.15V */
    HBN_BOD_THRES_2P20V, /*!< BOD threshold 2.20V */
    HBN_BOD_THRES_2P25V, /*!< BOD threshold 2.25V */
    HBN_BOD_THRES_2P30V, /*!< BOD threshold 2.30V */
    HBN_BOD_THRES_2P35V, /*!< BOD threshold 2.35V */
    HBN_BOD_THRES_2P40V, /*!< BOD threshold 2.40V */
} HBN_BOD_THRES_Type;

/**
 *  @brief HBN BOD mode type definition
 */
typedef enum {
    HBN_BOD_MODE_POR_INDEPENDENT, /*!< POR is independent of BOD */
    HBN_BOD_MODE_POR_RELEVANT,    /*!< POR is relevant to BOD */
} HBN_BOD_MODE_Type;

/**
 *  @brief HBN 32K clock type definition
 */
typedef enum {
    HBN_32K_RC = 0,  /*!< HBN use rc 32k */
    HBN_32K_XTAL,    /*!< HBN use xtal 32k */
    HBN_32K_DIG = 3, /*!< HBN use dig 32k */
} HBN_32K_CLK_Type;

/**
 *  @brief HBN xclk clock type definition
 */
typedef enum {
    HBN_MCU_XCLK_RC32M, /*!< use RC32M as xclk clock */
    HBN_MCU_XCLK_XTAL,  /*!< use XTAL as xclk clock */
} HBN_MCU_XCLK_Type;

/**
 *  @brief HBN root clock type definition
 */
typedef enum {
    HBN_MCU_ROOT_CLK_XCLK, /*!< use XCLK as root clock */
    HBN_MCU_ROOT_CLK_PLL,  /*!< use PLL as root clock */
} HBN_MCU_ROOT_CLK_Type;

/**
 *  @brief HBN UART clock type definition
 */
typedef enum {
    HBN_UART_CLK_MCU_PBCLK = 0, /*!< Select mcu_pbclk as UART clock */
    HBN_UART_CLK_160M,          /*!< Select 160M as UART clock */
    HBN_UART_CLK_XCLK,          /*!< Select XCLK as UART clock */
} HBN_UART_CLK_Type;

/**
 *  @brief HBN RTC interrupt delay type definition
 */
typedef enum {
    HBN_RTC_INT_DELAY_32T = 0, /*!< HBN RTC interrupt delay 32T */
    HBN_RTC_INT_DELAY_0T = 1,  /*!< HBN RTC interrupt delay 0T */
} HBN_RTC_INT_Delay_Type;

/**
 *  @brief HBN interrupt type definition
 */
typedef enum {
    HBN_INT_GPIO9 = 0,   /*!< HBN interrupt type: GPIO9 */
    HBN_INT_GPIO10 = 1,  /*!< HBN interrupt type: GPIO10 */
    HBN_INT_GPIO11 = 2,  /*!< HBN interrupt type: GPIO11 */
    HBN_INT_GPIO12 = 3,  /*!< HBN interrupt type: GPIO12 */
    HBN_INT_GPIO13 = 4,  /*!< HBN interrupt type: GPIO13 */
    HBN_INT_GPIO14 = 5,  /*!< HBN interrupt type: GPIO14 */
    HBN_INT_GPIO15 = 6,  /*!< HBN interrupt type: GPIO15 */
    HBN_INT_GPIO40 = 7,  /*!< HBN interrupt type: GPIO40 */
    HBN_INT_GPIO41 = 8,  /*!< HBN interrupt type: GPIO41 */
    HBN_INT_RTC = 16,    /*!< HBN interrupt type: RTC */
    HBN_INT_PIR = 17,    /*!< HBN interrupt type: PIR */
    HBN_INT_BOD = 18,    /*!< HBN interrupt type: BOD */
    HBN_INT_ACOMP0 = 20, /*!< HBN interrupt type: ACOMP0 */
    HBN_INT_ACOMP1 = 22, /*!< HBN interrupt type: ACOMP1 */
} HBN_INT_Type;

/**
 *  @brief HBN aon pad type definition
 */
typedef enum {
    HBN_AON_PAD_GPIO9 = 0,  /*!< HBN aon pad type: GPIO9 */
    HBN_AON_PAD_GPIO10 = 1, /*!< HBN aon pad type: GPIO10 */
    HBN_AON_PAD_GPIO11 = 2, /*!< HBN aon pad type: GPIO11 */
    HBN_AON_PAD_GPIO12 = 3, /*!< HBN aon pad type: GPIO12 */
    HBN_AON_PAD_GPIO13 = 4, /*!< HBN aon pad type: GPIO13 */
    HBN_AON_PAD_GPIO14 = 5, /*!< HBN aon pad type: GPIO14 */
    HBN_AON_PAD_GPIO15 = 6, /*!< HBN aon pad type: GPIO15 */
    HBN_AON_PAD_GPIO40 = 7, /*!< HBN aon pad type: GPIO40 */
    HBN_AON_PAD_GPIO41 = 8, /*!< HBN aon pad type: GPIO41 */
} HBN_AON_PAD_Type;

/**
 *  @brief HBN acomp interrupt type definition
 */
typedef enum {
    HBN_ACOMP_INT_EDGE_POSEDGE = 0, /*!< HBN acomp interrupt edge posedge */
    HBN_ACOMP_INT_EDGE_NEGEDGE = 1, /*!< HBN acomp interrupt edge negedge */
} HBN_ACOMP_INT_EDGE_Type;

/**
 *  @brief HBN GPIO pad pu pd type
 */
typedef enum {
    HBN_GPIO_PAD_PULL_NONE = 0, /*!< gpio pad pull none at hbn */
    HBN_GPIO_PAD_PULL_DOWN = 1, /*!< gpio pad pull down at hbn */
    HBN_GPIO_PAD_PULL_UP = 2,   /*!< gpio pad pull up at hbn */
    HBN_GPIO_PAD_ACTIVE_IE = 3, /*!< gpio pad active ie at hbn */
} HBN_GPIO_PAD_PULL_Type;

/**
 *  @brief HBN AON PAD configuration type definition
 */
typedef struct
{
    uint8_t ctrlEn;                 /*!< AON GPIO41/40/15~9  Control by AON HW */
    uint8_t inputEn;                /*!< Always on PAD IE/SMT (if corresponding  AON GPIO controlled by AON HW) */
    uint8_t outputEn;               /*!< Always on PAD OE (if corresponding  AON GPIO controlled by AON HW) */
    HBN_GPIO_PAD_PULL_Type pullCfg; /*!< Always on PAD PU/PD (if corresponding  AON GPIO controlled by AON HW) */
} HBN_AON_PAD_CFG_Type;

/**
 *  @brief HBN GPIO interrupt trigger type definition
 */
typedef enum {
    HBN_GPIO_INT_TRIGGER_SYNC_FALLING_EDGE = 0x0,        /*!< HBN GPIO INT trigger type: sync falling edge trigger */
    HBN_GPIO_INT_TRIGGER_SYNC_RISING_EDGE = 0x1,         /*!< HBN GPIO INT trigger type: sync rising edge trigger */
    HBN_GPIO_INT_TRIGGER_SYNC_LOW_LEVEL = 0x2,           /*!< HBN GPIO INT trigger type: sync low level trigger */
    HBN_GPIO_INT_TRIGGER_SYNC_HIGH_LEVEL = 0x3,          /*!< HBN GPIO INT trigger type: sync high level trigger */
    HBN_GPIO_INT_TRIGGER_SYNC_RISING_FALLING_EDGE = 0x4, /*!< HBN GPIO INT trigger type: sync rising falling edge trigger */
    HBN_GPIO_INT_TRIGGER_ASYNC_FALLING_EDGE = 0x8,       /*!< HBN GPIO INT trigger type: async falling edge trigger */
    HBN_GPIO_INT_TRIGGER_ASYNC_RISING_EDGE = 0x9,        /*!< HBN GPIO INT trigger type: async rising edge trigger */
    HBN_GPIO_INT_TRIGGER_ASYNC_LOW_LEVEL = 0xA,          /*!< HBN GPIO INT trigger type: async low level trigger */
    HBN_GPIO_INT_TRIGGER_ASYNC_HIGH_LEVEL = 0xB,         /*!< HBN GPIO INT trigger type: async high level trigger */
} HBN_GPIO_INT_Trigger_Type;

/**
 *  @brief HBN OUT0 interrupt type definition
 */
typedef enum {
    HBN_OUT0_INT_GPIO9 = 0,  /*!< HBN out 0 interrupt type: GPIO9 */
    HBN_OUT0_INT_GPIO10 = 1, /*!< HBN out 0 interrupt type: GPIO10 */
    HBN_OUT0_INT_GPIO11 = 2, /*!< HBN out 0 interrupt type: GPIO11 */
    HBN_OUT0_INT_GPIO12 = 3, /*!< HBN out 0 interrupt type: GPIO12 */
    HBN_OUT0_INT_GPIO13 = 4, /*!< HBN out 0 interrupt type: GPIO13 */
    HBN_OUT0_INT_GPIO14 = 5, /*!< HBN out 0 interrupt type: GPIO14 */
    HBN_OUT0_INT_GPIO15 = 6, /*!< HBN out 0 interrupt type: GPIO15 */
    HBN_OUT0_INT_GPIO40 = 7, /*!< HBN out 0 interrupt type: GPIO40 */
    HBN_OUT0_INT_GPIO41 = 8, /*!< HBN out 0 interrupt type: GPIO41 */
    HBN_OUT0_INT_RTC,        /*!< HBN out 0 interrupt type: RTC */
    HBN_OUT0_INT_MAX,        /*!< MAX */
} HBN_OUT0_INT_Type;

/**
 *  @brief HBN OUT0 interrupt type definition
 */
typedef enum {
    HBN_OUT1_INT_PIR,    /*!< HBN out 1 interrupt type: PIR */
    HBN_OUT1_INT_BOD,    /*!< HBN out 1 interrupt type: BOD */
    HBN_OUT1_INT_ACOMP0, /*!< HBN out 1 interrupt type: ACOMP0 */
    HBN_OUT1_INT_ACOMP1, /*!< HBN out 1 interrupt type: ACOMP1 */
    HBN_OUT1_INT_MAX,    /*!< MAX */
} HBN_OUT1_INT_Type;

/**
 *  @brief HBN LDO level type definition
 */
typedef enum {
    HBN_LDO_LEVEL_0P70V = 2,  /*!< HBN LDO voltage 0.70V */
    HBN_LDO_LEVEL_0P75V = 3,  /*!< HBN LDO voltage 0.75V */
    HBN_LDO_LEVEL_0P80V = 4,  /*!< HBN LDO voltage 0.80V */
    HBN_LDO_LEVEL_0P85V = 5,  /*!< HBN LDO voltage 0.85V */
    HBN_LDO_LEVEL_0P90V = 6,  /*!< HBN LDO voltage 0.90V */
    HBN_LDO_LEVEL_0P95V = 7,  /*!< HBN LDO voltage 0.95V */
    HBN_LDO_LEVEL_1P00V = 8,  /*!< HBN LDO voltage 1.00V */
    HBN_LDO_LEVEL_1P05V = 9,  /*!< HBN LDO voltage 1.05V */
    HBN_LDO_LEVEL_1P10V = 10, /*!< HBN LDO voltage 1.10V */
    HBN_LDO_LEVEL_1P15V = 11, /*!< HBN LDO voltage 1.15V */
    HBN_LDO_LEVEL_1P20V = 12, /*!< HBN LDO voltage 1.20V */
    HBN_LDO_LEVEL_1P25V = 13, /*!< HBN LDO voltage 1.25V */
    HBN_LDO_LEVEL_1P30V = 14, /*!< HBN LDO voltage 1.30V */
    HBN_LDO_LEVEL_1P35V = 15, /*!< HBN LDO voltage 1.35V */
} HBN_LDO_LEVEL_Type;

/**
 *  @brief HBN level type definition
 */
typedef enum {
    HBN_LEVEL_0, /*!< HBN pd_core */
    HBN_LEVEL_1, /*!< HBN pd_aon_hbncore + pd_core */
} HBN_LEVEL_Type;

/**
 *  @brief HBN RTC misc configuration type definition
 */
typedef struct
{
    uint32_t rtcRstHoldCnt_rtc          :  3;   /*!< rtc_rst_hold_cnt_rtc */
    uint32_t rsvda                      :  1;   /*!< reserved */
    uint32_t rtcRstEnRtc                :  1;   /*!< rtc_rst_en_rtc */
    uint32_t rtcRstInvRtc               :  1;   /*!< rtc_rst_inv_rtc */
    uint32_t rtcRstClkSel_rtc           :  1;   /*!< rtc_rst_clk_sel_rtc */
    uint32_t rsvdb                      :  1;   /*!< reserved */
    uint32_t ldo11RtcVoutSelRtc         :  4;   /*!< ldo11_rtc_vout_sel_rtc */
    uint32_t rsvdc                      : 22;   /*!< reserved */
} HBN_RTC_MISC_Type;

/**
 *  @brief HBN BOD configuration type definition
 */
typedef struct
{
    uint8_t enableBod;      /*!< Enable BOD or not */
    uint8_t enableBodInt;   /*!< Enable BOD interrupt or not */
    uint8_t bodThreshold;   /*!< BOD threshold */
    uint8_t enablePorInBod; /*!< Enable POR when BOD occure or not */
} HBN_BOD_CFG_Type;

/**
 *  @brief HBN APP configuration type definition
 */
typedef struct
{
    uint8_t useXtal32k;                     /*!< Whether use xtal 32K as 32K clock source,otherwise use rc32k */
    uint32_t sleepTime;                     /*!< HBN sleep time */
    uint8_t gpioWakeupSrc;                  /*!< GPIO Wakeup source */
    HBN_GPIO_INT_Trigger_Type gpioTrigType; /*!< GPIO Triger type */
    SPI_Flash_Cfg_Type *flashCfg;           /*!< Flash config pointer, used when power down flash */
    HBN_LEVEL_Type hbnLevel;                /*!< HBN level */
    HBN_LDO_LEVEL_Type ldoLevel;            /*!< LDO level */
    uint8_t dcdcPuSeq;                      /*!< power on dcdc sequence */
} HBN_APP_CFG_Type;

#endif