#ifndef __BL808_EF_CTRL_H__
#define __BL808_EF_CTRL_H__

#include "typedefs.h"

/**
 *  @brief Efuse Ctrl key slot type definition
 */
typedef enum {
    EF_CTRL_KEY_SLOT0, /*!< key slot 0 */
    EF_CTRL_KEY_SLOT1, /*!< key slot 1 */
    EF_CTRL_KEY_SLOT2, /*!< key slot 2 */
    EF_CTRL_KEY_SLOT3, /*!< key slot 3 */
    EF_CTRL_KEY_SLOT4, /*!< key slot 4 */
    EF_CTRL_KEY_SLOT5, /*!< key slot 5 */
    EF_CTRL_KEY_MAX,   /*!<  */
} EF_Ctrl_Key_Type;

/**
 *  @brief Efuse Ctrl sign type definition
 */
typedef enum {
    EF_CTRL_SIGN_NONE, /*!< no sign */
    EF_CTRL_SIGN_RSA,  /*!< use RSA to sign */
    EF_CTRL_SIGN_ECC,  /*!< use ECC to sign */
} EF_Ctrl_Sign_Type;

/**
 *  @brief Efuse Ctrl flash AES type definition
 */
typedef enum {
    EF_CTRL_SF_AES_NONE, /*!< No AES */
    EF_CTRL_SF_AES_128,  /*!< AES 128 */
    EF_CTRL_SF_AES_192,  /*!< AES 192 */
    EF_CTRL_SF_AES_256,  /*!< AES 256 */
} EF_Ctrl_SF_AES_Type;

/**
 *  @brief Efuse Ctrl Dbg type definition
 */
typedef enum {
    EF_CTRL_DBG_OPEN = 0,  /*!< Open debug */
    EF_CTRL_DBG_PASSWORD,  /*!< Open debug with password */
    EF_CTRL_DBG_CLOSE = 4, /*!< Close debug */
} EF_Ctrl_Dbg_Mode_Type;

/**
 *  @brief Efuse Ctrl clock type definition
 */
typedef enum {
    EF_CTRL_EF_CLK,   /*!< Select efuse clock */
    EF_CTRL_SAHB_CLK, /*!< Select SAHB clock */
} EF_Ctrl_CLK_Type;

/**
 *  @brief Efuse Ctrl clock type definition
 */
typedef enum {
    EF_CTRL_PARA_DFT,    /*!< Select default cyc parameter */
    EF_CTRL_PARA_MANUAL, /*!< Select manual cyc parameter */
} EF_Ctrl_CYC_PARA_Type;

/**
 *  @brief Efuse Ctrl clock type definition
 */
typedef enum {
    EF_CTRL_OP_MODE_AUTO,   /*!< Select efuse program auto mode */
    EF_CTRL_OP_MODE_MANUAL, /*!< Select efuse program manual mode */
} EF_Ctrl_OP_MODE_Type;

/**
 *  @brief Efuse Ctrl secure configuration structure type definition
 */
typedef struct
{
    EF_Ctrl_Dbg_Mode_Type ef_dbg_mode; /*!< Efuse debug mode */
    uint8_t ef_dbg_jtag_0_dis;         /*!< Jtag debug disable config value */
    uint8_t ef_dbg_jtag_1_dis;         /*!< Jtag debug disable config value */
    uint8_t ef_sboot_en;               /*!< Secure boot enable config value */
} EF_Ctrl_Sec_Param_Type;

/**
 *  @brief Efuse analog dcdc11 trim type definition
 */
typedef struct
{
    uint32_t trimDcdc11VoutAon       : 4;  /*!< Efuse analog trim:dcdc11_vout_trim_aon */
    uint32_t trimDcdc11VoutAonParity : 1;  /*!< Efuse analog trim:dcdc11_vout_trim_aon_parity */
    uint32_t trimDcdc11VoutAonEn     : 1;  /*!< Efuse analog trim:dcdc11_vout_trim_aon_en */
    uint32_t reserved                : 26; /*!< Efuse analog trim:reserved */
} Efuse_Ana_DCDC11_Trim_Type;

/**
 *  @brief Efuse analog dcdc18 trim type definition
 */
typedef struct
{
    uint32_t trimDcdc18VoutAon       : 4;  /*!< Efuse analog trim:dcdc18_vout_trim_aon */
    uint32_t trimDcdc18VoutAonParity : 1;  /*!< Efuse analog trim:dcdc18_vout_trim_aon_parity */
    uint32_t trimDcdc18VoutAonEn     : 1;  /*!< Efuse analog trim:dcdc18_vout_trim_aon_en */
    uint32_t reserved                : 26; /*!< Efuse analog trim:reserved */
} Efuse_Ana_DCDC18_Trim_Type;

/**
 *  @brief Efuse analog ldo18flash trim type definition
 */
typedef struct
{
    uint32_t trimLdo18flashVoutAon       : 4;  /*!< Efuse analog trim:ldo18flash_vout_trim */
    uint32_t trimLdo18flashVoutAonParity : 1;  /*!< Efuse analog trim:ldo18flash_vout_trim_parity */
    uint32_t trimLdo18flashVoutAonEn     : 1;  /*!< Efuse analog trim:ldo18flash_vout_trim_en */
    uint32_t reserved                    : 26; /*!< Efuse analog trim:reserved */
} Efuse_Ana_LDO18FLASH_Trim_Type;

/**
 *  @brief Efuse analog usb20rcal trim type definition
 */
typedef struct
{
    uint32_t trimUsb20rcalAon       : 6;  /*!< Efuse analog trim:usb20_rcal_code_aon */
    uint32_t trimUsb20rcalAonParity : 1;  /*!< Efuse analog trim:usb20_rcal_code_aon_parity */
    uint32_t trimUsb20rcalAonEn     : 1;  /*!< Efuse analog trim:usb20_rcal_code_aon_en */
    uint32_t reserved               : 24; /*!< Efuse analog trim:reserved */
} Efuse_Ana_USB20RCAL_Trim_Type;

/**
 *  @brief Efuse analog RC32M trim type definition
 */
typedef struct
{
    uint32_t trimRc32mCodeFrExt       : 8;  /*!< Efuse analog trim:trim_rc32m_code_fr_ext */
    uint32_t trimRc32mCodeFrExtParity : 1;  /*!< Efuse analog trim:trim_rc32m_ext_code_en_parity */
    uint32_t trimRc32mExtCodeEn       : 1;  /*!< Efuse analog trim:trim_rc32m_ext_code_en */
    uint32_t reserved                 : 22; /*!< Efuse analog trim:reserved */
} Efuse_Ana_RC32M_Trim_Type;

/**
 *  @brief Efuse analog RC32K trim type definition
 */
typedef struct
{
    uint32_t trimRc32kCodeFrExt       : 10; /*!< Efuse analog trim:trim_rc32k_code_fr_ext */
    uint32_t trimRc32kCodeFrExtParity : 1;  /*!< Efuse analog trim:trim_rc32k_code_fr_ext_parity */
    uint32_t trimRc32kExtCodeEn       : 1;  /*!< Efuse analog trim:trim_rc32k_ext_code_en */
    uint32_t reserved                 : 20; /*!< Efuse analog trim:reserved */
} Efuse_Ana_RC32K_Trim_Type;

typedef struct
{
    uint32_t trimLdo18ioVoutVal    : 4;  /*!< Efuse analog trim:trim_ldo18io_vout_val */
    uint32_t trimLdo18ioVoutParity : 1;  /*!< Efuse analog trim:trim_ldo18io_vout_parity */
    uint32_t trimLdo18ioVoutEn     : 1;  /*!< Efuse analog trim:trim_ldo18io_vout_en */
    uint32_t reserved              : 26; /*!< Efuse analog trim:reserved */
} Efuse_Ana_LDO18IO_VOUT_Trim_Type;

/**
 *  @brief Efuse analog TSEN trim type definition
 */
typedef struct
{
    uint32_t tsenRefcodeCorner        : 12; /*!< TSEN refcode */
    uint32_t tsenRefcodeCornerParity  : 1;  /*!< TSEN refcode parity */
    uint32_t tsenRefcodeCornerEn      : 1;  /*!< TSEN refcode enable */
    uint32_t tsenRefcodeCornerVersion : 1;  /*!< TSEN refcode version */
    uint32_t reserved                 : 17; /*!< TSEN analog trim:reserved */
} Efuse_TSEN_Refcode_Corner_Type;

/**
 *  @brief Efuse analog ADC Gain trim type definition
 */
typedef struct
{
    uint32_t adcGainCoeff       : 12; /*!< ADC gain coeff */
    uint32_t adcGainCoeffParity : 1;  /*!< ADC gain coeff parity */
    uint32_t adcGainCoeffEn     : 1;  /*!< ADC gain coeff enable */
    uint32_t reserved           : 18; /*!< ADC gain coeff:reserved */
} Efuse_ADC_Gain_Coeff_Type;

/**
 *  @brief Efuse analog device info type definition
 */
typedef struct
{
    uint32_t rsvd       : 22; /*!< Reserved */
    uint32_t deviceInfo : 3;  /*!< Efuse device information */
    uint32_t psramInfo  : 2;  /*!< Efuse psram info 0:no psram, 1:BW 4MB, 2:UHS 64MB */
    uint32_t memoryInfo : 2;  /*!< Efuse memory info 0:no memory, 8:1MB flash */
    uint32_t chipInfo   : 3;  /*!< Efuse chip revision */
} Efuse_Device_Info_Type;

/**
 *  @brief Efuse Capcode type definition
 */
typedef struct
{
    uint32_t capCode : 6;  /*!< Cap code value */
    uint32_t parity  : 1;  /*!< Parity of capcode */
    uint32_t en      : 1;  /*!< Enable status */
    uint32_t rsvd    : 24; /*!< Reserved */
} Efuse_Capcode_Info_Type;

#endif