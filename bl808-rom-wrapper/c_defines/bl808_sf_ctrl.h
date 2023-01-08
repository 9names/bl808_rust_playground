#ifndef __BL808_SF_CTRL_H__
#define __BL808_SF_CTRL_H__

#include "misc.h"
#include "typedefs.h"
/**
 *  @brief Serial flash pad type definition
 */
typedef enum {
    SF_CTRL_PAD1,                           /*!< SF Ctrl pad 1 */
    SF_CTRL_PAD2,                           /*!< SF Ctrl pad 2 */
    SF_CTRL_PAD3,                           /*!< SF Ctrl pad 3 */
}SF_Ctrl_Pad_Type;

/**
 *  @brief Serial flash config pin select type definition
 */
typedef enum {
    SF_IO_EMB_SWAP_IO0_IO3=0x0,             /*!< SF select embedded flash swap io0 with io3 */
    SF_IO_EMB_SWAP_DUAL_IO0_IO3=0x1,        /*!< SF select embedded flash swap dual io0 with io3 */
    SF_IO_EMB_SWAP_NONE=0x2,                /*!< SF select embedded flash no swap */
    SF_IO_EMB_SWAP_NONE_DUAL_IO0=0x3,       /*!< SF select embedded flash no swap and use dual io0 */
    SF_IO_EXT_SF2=0x4,                      /*!< SF select external flash SF2 use gpio27-32 */
    SF_IO_EXT_SF3=0x8,                      /*!< SF select external flash SF3 use gpio33-38 */
    SF_IO_EMB_SWAP_IO0_IO3_AND_EXT_SF2=0x14,    /*!< SF select embedded flash swap io0 with io3 and external SF2 use gpio27-32 */
    SF_IO_EMB_SWAP_DUAL_IO0_IO3_AND_EXT_SF2=0x15,    /*!< SF select embedded flash swap dual io0 with io3 and external SF2 use gpio27-32 */
    SF_IO_EMB_SWAP_NONE_AND_EXT_SF2=0x16,   /*!< SF select embedded flash no swap and external SF2 use gpio27-32 */
    SF_IO_EMB_SWAP_NONE_DUAL_IO0_AND_EXT_SF2=0x17,    /*!< SF select embedded flash no swap, use dual io0 and external SF2 use gpio27-32 */
    SF_IO_EMB_SWAP_IO0_IO3_AND_EXT_SF3=0x18,    /*!< SF select embedded flash swap io0 with io3 and external SF3 use gpio33-38 */
    SF_IO_EMB_SWAP_DUAL_IO0_IO3_AND_EXT_SF3=0x19,    /*!< SF select embedded flash swap dual io0 with io3 and external SF3 use gpio33-38 */
    SF_IO_EMB_SWAP_NONE_AND_EXT_SF3=0x1A,   /*!< SF select embedded flash no swap and external SF3 use gpio33-38 */
    SF_IO_EMB_SWAP_NONE_DUAL_IO0_AND_EXT_SF3=0x1B,    /*!< SF select embedded flash no swap, use dual io0 and external SF3 use gpio33-38 */
}SF_Ctrl_Pin_Select;

/**
 *  @brief Serial flash select bank control type definition
 */
typedef enum {
    SF_CTRL_FLASH_BANK0,                    /*!< SF Ctrl select flash bank0 */
    SF_CTRL_FLASH_BANK1,                    /*!< SF Ctrl select flash bank1 */
}SF_Ctrl_Bank_Select;

/**
 *  @brief Serial flash controller wrap mode type definition
 */
typedef enum {
    SF_CTRL_WRAP_MODE_0,                    /*!< Cmds bypass wrap commands to macro, original mode */
    SF_CTRL_WRAP_MODE_1,                    /*!< Cmds handle wrap commands, original mode */
    SF_CTRL_WRAP_MODE_2,                    /*!< Cmds bypass wrap commands to macro, cmds force wrap16*4 splitted into two wrap8*4 */
    SF_CTRL_WRAP_MODE_3,                    /*!< Cmds handle wrap commands, cmds force wrap16*4 splitted into two wrap8*4 */
}SF_Ctrl_Wrap_Mode;

/**
 *  @brief Serail flash controller wrap mode len type definition
 */
typedef enum {
    SF_CTRL_WRAP_LEN_8,                     /*!< SF Ctrl wrap length: 8 */
    SF_CTRL_WRAP_LEN_16,                    /*!< SF Ctrl wrap length: 16 */
    SF_CTRL_WRAP_LEN_32,                    /*!< SF Ctrl wrap length: 32 */
    SF_CTRL_WRAP_LEN_64,                    /*!< SF Ctrl wrap length: 64 */
    SF_CTRL_WRAP_LEN_128,                   /*!< SF Ctrl wrap length: 128 */
    SF_CTRL_WRAP_LEN_256,                   /*!< SF Ctrl wrap length: 256 */
    SF_CTRL_WRAP_LEN_512,                   /*!< SF Ctrl wrap length: 512 */
    SF_CTRL_WRAP_LEN_1024,                  /*!< SF Ctrl wrap length: 1024 */
    SF_CTRL_WRAP_LEN_2048,                  /*!< SF Ctrl wrap length: 2048 */
    SF_CTRL_WRAP_LEN_4096,                  /*!< SF Ctrl wrap length: 4096 */
}SF_Ctrl_Wrap_Len_Type;

/**
 *  @brief Serail flash controller memory remap type define
 */
typedef enum {
    SF_CTRL_ORIGINAL_MEMORY_MAP,            /*!< Remap none, use two addr map when use dual flash */
    SF_CTRL_REMAP_16MB,                     /*!< Remap HADDR>16MB region to psram port HADDR[24] -> HADDR[28] */
    SF_CTRL_REMAP_8MB,                      /*!< Remap HADDR>8MB region to psram port HADDR[23] -> HADDR[28] */
    SF_CTRL_REMAP_4MB,                      /*!< Remap HADDR>4MB region to psram port HADDR[22] -> HADDR[28] */
}SF_Ctrl_Remap_Type;

/**
 *  @brief Serial flash controller owner type definition
 */
typedef enum {
    SF_CTRL_OWNER_SAHB,                     /*!< System AHB bus control serial flash controller */
    SF_CTRL_OWNER_IAHB,                     /*!< I-Code AHB bus control serial flash controller */
}SF_Ctrl_Owner_Type;

/**
 *  @brief Read and write type definition
 */
typedef enum {
    SF_CTRL_READ,                           /*!< Serail flash read command flag */
    SF_CTRL_WRITE,                          /*!< Serail flash write command flag */
}SF_Ctrl_RW_Type;

/**
 *  @brief Serail flash interface IO type definition
 */
typedef enum {
    SF_CTRL_NIO_MODE,                       /*!< Normal IO mode define */
    SF_CTRL_DO_MODE,                        /*!< Dual Output mode define */
    SF_CTRL_QO_MODE,                        /*!< Quad Output mode define */
    SF_CTRL_DIO_MODE,                       /*!< Dual IO mode define */
    SF_CTRL_QIO_MODE,                       /*!< Quad IO mode define */
}SF_Ctrl_IO_Type;

/**
 *  @brief Serail flash controller interface mode type definition
 */
typedef enum {
    SF_CTRL_SPI_MODE,                       /*!< SPI mode define */
    SF_CTRL_QPI_MODE,                       /*!< QPI mode define */
}SF_Ctrl_Mode_Type;

/**
 *  @brief Serail flash controller command mode type definition
 */
typedef enum {
    SF_CTRL_CMD_1_LINE,                     /*!< Command in one line mode */
    SF_CTRL_CMD_4_LINES,                    /*!< Command in four lines mode */
}SF_Ctrl_Cmd_Mode_Type;

/**
 *  @brief Serail flash controller address mode type definition
 */
typedef enum {
    SF_CTRL_ADDR_1_LINE,                    /*!< Address in one line mode */
    SF_CTRL_ADDR_2_LINES,                   /*!< Address in two lines mode */
    SF_CTRL_ADDR_4_LINES,                   /*!< Address in four lines mode */
}SF_Ctrl_Addr_Mode_Type;

/**
 *  @brief Serail flash controller dummy mode type definition
 */
typedef enum {
    SF_CTRL_DUMMY_1_LINE,                   /*!< Dummy in one line mode */
    SF_CTRL_DUMMY_2_LINES,                  /*!< Dummy in two lines mode */
    SF_CTRL_DUMMY_4_LINES,                  /*!< Dummy in four lines mode */
}SF_Ctrl_Dmy_Mode_Type;

/**
 *  @brief Serail flash controller data mode type definition
 */
typedef enum {
    SF_CTRL_DATA_1_LINE,                    /*!< Data in one line mode */
    SF_CTRL_DATA_2_LINES,                   /*!< Data in two lines mode */
    SF_CTRL_DATA_4_LINES,                   /*!< Data in four lines mode */
}SF_Ctrl_Data_Mode_Type;

/**
 *  @brief Serail flash controller AES mode type definition
 */
typedef enum {
    SF_CTRL_AES_CTR_MODE,                   /*!< Serail flash AES CTR mode */
    SF_CTRL_AES_XTS_MODE,                   /*!< Serail flash AES XTS mode */
}SF_Ctrl_AES_Mode_Type;

/**
 *  @brief Serail flash controller AES key len type definition
 */
typedef enum {
    SF_CTRL_AES_128BITS,                    /*!< Serail flash AES key 128 bits length */
    SF_CTRL_AES_256BITS,                    /*!< Serail flash AES key 256 bits length */
    SF_CTRL_AES_192BITS,                    /*!< Serail flash AES key 192 bits length */
    SF_CTRL_AES_128BITS_DOUBLE_KEY,         /*!< Serail flash AES key 128 bits length double key */
}SF_Ctrl_AES_Key_Type;

/**
 *  @brief Serail flash controller configuration structure type definition
 */
typedef struct {
    SF_Ctrl_Owner_Type owner;               /*!< Sflash interface bus owner */
    BL_Fun_Type en32bAddr;                  /*!< Sflash enable 32-bits address */
    uint8_t  clkDelay;                      /*!< Clock count for read due to pad delay */
    uint8_t  clkInvert;                     /*!< Clock invert */
    uint8_t  rxClkInvert;                   /*!< RX clock invert */
    uint8_t  doDelay;                       /*!< Data out delay */
    uint8_t  diDelay;                       /*!< Data in delay */
    uint8_t  oeDelay;                       /*!< Output enable delay */
}SF_Ctrl_Cfg_Type;

/**
 *  @brief SF Ctrl bank2 controller configuration structure type definition
 */
typedef struct {
    BL_Fun_Type sbus2Select;                /*!< Select sbus2 as 2nd flash controller */
    BL_Fun_Type bank2RxClkInvertSrc;        /*!< Select bank2 rx clock invert source */
    BL_Fun_Type bank2RxClkInvertSel;        /*!< Select inveted bank2 rx clock */
    BL_Fun_Type bank2DelaySrc;              /*!< Select bank2 read delay source */
    uint8_t bank2ClkDelay;                  /*!< Bank2 read delay cycle = n + 1 */
    uint8_t doDelay;                        /*!< Data out delay */
    uint8_t diDelay;                        /*!< Data in delay */
    uint8_t oeDelay;                        /*!< Output enable delay */
}SF_Ctrl_Bank2_Cfg;

/**
 *  @brief SF Ctrl cmds configuration structure type definition
 */
typedef struct {
    BL_Fun_Type ackLatency;                 /*!< SF Ctrl ack latency cycles */
    BL_Fun_Type cmdsCoreEn;                 /*!< SF Ctrl cmds core enable */
    BL_Fun_Type cmds1En;                    /*!< SF Ctrl cmds 1 enable */
    SF_Ctrl_Wrap_Mode cmds1WrapMode;        /*!< SF Ctrl cmds 1 wrap mode */
    SF_Ctrl_Wrap_Len_Type cmds1WrapLen;     /*!< SF Ctrl cmds 1 wrap length */
    BL_Fun_Type cmds2En;                    /*!< SF Ctrl cmds 2 enable */
    SF_Ctrl_Wrap_Mode cmds2WrapMode;        /*!< SF Ctrl cmds 2 wrap mode */
    SF_Ctrl_Wrap_Len_Type cmds2WrapLen;     /*!< SF Ctrl cmds 2 wrap length */
    BL_Fun_Type cmds2WrapQueueInitVal;      /*!< SF Ctrl cmds 2 wrap queue initial value */
    BL_Fun_Type cmds2BurstToggleEn;         /*!< SF Ctrl cmds 2 burst toggle mode enable */
    uint8_t cmds2BurstToggleDelay;          /*!< SF Ctrl cmds 2 dummy delay cycle after burst toggle command */
}SF_Ctrl_Cmds_Cfg;

/**
 *  @brief Serail flash command configuration structure type definition
 */
typedef struct {
    uint8_t  rwFlag;                        /*!< Read write flag */
    SF_Ctrl_Cmd_Mode_Type  cmdMode;         /*!< Command mode */
    SF_Ctrl_Addr_Mode_Type  addrMode;       /*!< Address mode */
    uint8_t  addrSize;                      /*!< Address size */
    uint8_t  dummyClks;                     /*!< Dummy clocks */
    SF_Ctrl_Dmy_Mode_Type  dummyMode;       /*!< Dummy mode */
    SF_Ctrl_Data_Mode_Type  dataMode;       /*!< Data mode */
    uint8_t  rsv[1];                        /*!<  */
    uint32_t nbData;                        /*!< Transfer number of bytes */
    uint32_t cmdBuf[2];                     /*!< Command buffer */
}SF_Ctrl_Cmd_Cfg_Type;

#endif