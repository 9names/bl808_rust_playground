#ifndef __BL808_GLB_H__
#define __BL808_GLB_H__

#include "typedefs.h"

/** @addtogroup  BL808_Peripheral_Driver
 *  @{
 */

/** @addtogroup  GLB
 *  @{
 */

/** @defgroup  GLB_Public_Types
 *  @{
 */

/**
 *  @brief GLB AHB clock IP type definition
 */
typedef enum {
    GLB_AHB_CLOCK_IP_CPU,
    GLB_AHB_CLOCK_IP_SDU,
    GLB_AHB_CLOCK_IP_SEC,
    GLB_AHB_CLOCK_IP_DMA_0,
    GLB_AHB_CLOCK_IP_DMA_1,
    GLB_AHB_CLOCK_IP_DMA_2,
    GLB_AHB_CLOCK_IP_CCI,
    GLB_AHB_CLOCK_IP_RF_TOP,
    GLB_AHB_CLOCK_IP_GPIP,
    GLB_AHB_CLOCK_IP_TZC,
    GLB_AHB_CLOCK_IP_EF_CTRL,
    GLB_AHB_CLOCK_IP_SF_CTRL,
    GLB_AHB_CLOCK_IP_EMAC,
    GLB_AHB_CLOCK_IP_UART0,
    GLB_AHB_CLOCK_IP_UART1,
    GLB_AHB_CLOCK_IP_UART2,
    GLB_AHB_CLOCK_IP_UART3,
    GLB_AHB_CLOCK_IP_SPI,
    GLB_AHB_CLOCK_IP_I2C,
    GLB_AHB_CLOCK_IP_PWM,
    GLB_AHB_CLOCK_IP_TIMER,
    GLB_AHB_CLOCK_IP_IR,
    GLB_AHB_CLOCK_IP_CHECKSUM,
    GLB_AHB_CLOCK_IP_QDEC,
    GLB_AHB_CLOCK_IP_KYS,
    GLB_AHB_CLOCK_IP_I2S,
    GLB_AHB_CLOCK_IP_USB11,
    GLB_AHB_CLOCK_IP_CAM,
    GLB_AHB_CLOCK_IP_MJPEG,
    GLB_AHB_CLOCK_IP_BT_BLE_NORMAL,
    GLB_AHB_CLOCK_IP_BT_BLE_LP,
    GLB_AHB_CLOCK_IP_ZB_NORMAL,
    GLB_AHB_CLOCK_IP_ZB_LP,
    GLB_AHB_CLOCK_IP_WIFI_NORMAL,
    GLB_AHB_CLOCK_IP_WIFI_LP,
    GLB_AHB_CLOCK_IP_BT_BLE_2_NORMAL,
    GLB_AHB_CLOCK_IP_BT_BLE_2_LP,
    GLB_AHB_CLOCK_IP_EMI_MISC,
    GLB_AHB_CLOCK_IP_PSRAM0_CTRL,
    GLB_AHB_CLOCK_IP_PSRAM1_CTRL,
    GLB_AHB_CLOCK_IP_USB20,
    GLB_AHB_CLOCK_IP_MIX2,
    GLB_AHB_CLOCK_IP_AUDIO,
    GLB_AHB_CLOCK_IP_SDH,
    GLB_AHB_CLOCK_IP_ZB2_NORMAL,
    GLB_AHB_CLOCK_IP_ZB2_LP,
    GLB_AHB_CLOCK_IP_I2C1,
    GLB_AHB_CLOCK_IP_WIFI_PHY,
    GLB_AHB_CLOCK_IP_WIFI_MAC_PHY,
    GLB_AHB_CLOCK_IP_WIFI_PLATFORM,
    GLB_AHB_CLOCK_IP_LZ4,
    GLB_AHB_CLOCK_IP_AUPDM,
    GLB_AHB_CLOCK_IP_GAUGE,
} GLB_AHB_CLOCK_IP_Type;

/**
 *  @brief GLB core ID type definition
 */
typedef enum {
    GLB_CORE_ID_M0,      /*!< M0 */
    GLB_CORE_ID_D0,      /*!< D0 */
    GLB_CORE_ID_LP,      /*!< LP */
    GLB_CORE_ID_MAX,     /*!< ID max */
    GLB_CORE_ID_INVALID, /*!< ID invalid */
} GLB_CORE_ID_Type;

/**
 *  @brief cci ID type definition
 */
typedef enum {
    CCI0_ID,    /*!< CCI0 port define */
    CCI_ID_MAX, /*!< CCI MAX ID define */
} CCI_ID_Type;

/**
 *  @brief GLB DSP all interrupt type definition
 */
typedef enum {
    GLB_DSP_ALL_INT_BUS_DEC_ERR_INT = 0,      /*!< bus_dec_err_int */
    GLB_DSP_ALL_INT_SPP_RSV0_INT = 1,         /*!< spp_rsv0_int */
    GLB_DSP_ALL_INT_IPC2_NP2AP_IRQ = 2,       /*!< ipc2_np2ap_irq */
    GLB_DSP_ALL_INT_RSV3 = 3,                 /*!< rsv3 */
    GLB_DSP_ALL_INT_UART0_INT = 4,            /*!< uart0_int */
    GLB_DSP_ALL_INT_I2C0_INT = 5,             /*!< i2c0_int */
    GLB_DSP_ALL_INT_I2C1_INT = 6,             /*!< i2c1_int */
    GLB_DSP_ALL_INT_SPI_INT = 7,              /*!< spi_int */
    GLB_DSP_ALL_INT_SPP_RSV1_INT = 8,         /*!< spp_rsv1_int */
    GLB_DSP_ALL_INT_SPP_RSV2_INT = 9,         /*!< spp_rsv2_int */
    GLB_DSP_ALL_INT_SEOF1_INT = 10,           /*!< seof1_int */
    GLB_DSP_ALL_INT_SEOF2_INT = 11,           /*!< seof2_int */
    GLB_DSP_ALL_INT_SEOF3_INT = 12,           /*!< seof3_int */
    GLB_DSP_ALL_INT_DVP2BUS_INT_0 = 13,       /*!< dvp2bus_int[0] */
    GLB_DSP_ALL_INT_DVP2BUS_INT_1 = 14,       /*!< dvp2bus_int[1] */
    GLB_DSP_ALL_INT_DVP2BUS_INT_2 = 15,       /*!< dvp2bus_int[2] */
    GLB_DSP_ALL_INT_DVP2BUS_INT_3 = 16,       /*!< dvp2bus_int[3] */
    GLB_DSP_ALL_INT_H264_BS_IRQ = 17,         /*!< h264_bs_irq */
    GLB_DSP_ALL_INT_H264_FRAME_IRQ = 18,      /*!< h264_frame_irq */
    GLB_DSP_ALL_INT_H264_SEQ_DONE_INT = 19,   /*!< h264_seq_done_int */
    GLB_DSP_ALL_INT_MJPEG_INT = 20,           /*!< mjpeg_int */
    GLB_DSP_ALL_INT_H264_S_BS_IRQ = 21,       /*!< h264_s_bs_irq */
    GLB_DSP_ALL_INT_H264_S_FRAME_IRQ = 22,    /*!< h264_s_frame_irq */
    GLB_DSP_ALL_INT_H264_S_SEQ_DONE_INT = 23, /*!< h264_s_seq_done_int */
    GLB_DSP_ALL_INT_DMA_INTR_0 = 24,          /*!< DMA_INTR[0] */
    GLB_DSP_ALL_INT_DMA_INTR_1 = 25,          /*!< DMA_INTR[1] */
    GLB_DSP_ALL_INT_DMA_INTR_2 = 26,          /*!< DMA_INTR[2] */
    GLB_DSP_ALL_INT_DMA_INTR_3 = 27,          /*!< DMA_INTR[3] */
    GLB_DSP_ALL_INT_DMA_INTR_4 = 28,          /*!< DMA_INTR[4] */
    GLB_DSP_ALL_INT_DMA_INTR_5 = 29,          /*!< DMA_INTR[5] */
    GLB_DSP_ALL_INT_DMA_INTR_6 = 30,          /*!< DMA_INTR[6] */
    GLB_DSP_ALL_INT_DMA_INTR_7 = 31,          /*!< DMA_INTR[7] */
    GLB_DSP_ALL_INT_RSV32 = 32,               /*!< rsv32 */
    GLB_DSP_ALL_INT_RSV33 = 33,               /*!< rsv33 */
    GLB_DSP_ALL_INT_RSV34 = 34,               /*!< rsv34 */
    GLB_DSP_ALL_INT_RSV35 = 35,               /*!< rsv35 */
    GLB_DSP_ALL_INT_RSV36 = 36,               /*!< rsv36 */
    GLB_DSP_ALL_INT_MIPI_CSI_INT = 37,        /*!< mipi_csi_int */
    GLB_DSP_ALL_INT_IPC2_AP2NP_IRQ = 38,      /*!< ipc2_ap2np_irq */
    GLB_DSP_ALL_INT_RSV39 = 39,               /*!< rsv39 */
    GLB_DSP_ALL_INT_MJDEC_INT = 40,           /*!< mjdec_int */
    GLB_DSP_ALL_INT_DVP2BUS_IN_4 = 41,        /*!< dvp2bus_int[4] */
    GLB_DSP_ALL_INT_DVP2BUS_IN_5 = 42,        /*!< dvp2bus_int[5] */
    GLB_DSP_ALL_INT_DVP2BUS_IN_6 = 43,        /*!< dvp2bus_int[6] */
    GLB_DSP_ALL_INT_DVP2BUS_IN_7 = 44,        /*!< dvp2bus_int[7] */
    GLB_DSP_ALL_INT_DMA2D_INT_0 = 45,         /*!< dma2d_int[0] */
    GLB_DSP_ALL_INT_DMA2D_INT_1 = 46,         /*!< dma2d_int[1] */
    GLB_DSP_ALL_INT_DP_SOEF0_INT = 47,        /*!< dp_soef0_int */
    GLB_DSP_ALL_INT_RSV48 = 48,               /*!< rsv48 */
    GLB_DSP_ALL_INT_RSV49 = 49,               /*!< rsv49 */
    GLB_DSP_ALL_INT_RSV50 = 50,               /*!< rsv50 */
    GLB_DSP_ALL_INT_RSV51 = 51,               /*!< rsv51 */
    GLB_DSP_ALL_INT_OSDDP_INT = 52,           /*!< osdDP_int */
    GLB_DSP_ALL_INT_DBI_INT = 53,             /*!< dbi_int */
    GLB_DSP_ALL_INT_SPP_RSV3_INT = 54,        /*!< spp_rsv3_int */
    GLB_DSP_ALL_INT_OSDA_INT = 55,            /*!< osdA_int */
    GLB_DSP_ALL_INT_OSDB_INT = 56,            /*!< osdB_int */
    GLB_DSP_ALL_INT_OSD_PB_INT = 57,          /*!< osd_pb_int */
    GLB_DSP_ALL_INT_SPP_RSV4_INT = 58,        /*!< spp_rsv4_int */
    GLB_DSP_ALL_INT_MIPI_DSI_INT = 59,        /*!< mipi_dsi_int */
    GLB_DSP_ALL_INT_SPP_RSV5_HIST_INT = 60,   /*!< spp_rsv5_hist_int */
    GLB_DSP_ALL_INT_MM_TIMER_IRQ2 = 61,       /*!< mm_timer_irq2 */
    GLB_DSP_ALL_INT_MM_TIMER_IRQ3 = 62,       /*!< mm_timer_irq3 */
    GLB_DSP_ALL_INT_MM_WDT_IRQ = 63,          /*!< mm_wdt_irq */
} GLB_DSP_ALL_INT_Type;

/**
 *  @brief GLB MCU all interrupt type definition
 */
typedef enum {
    GLB_MCU_ALL_INT_BMX_ERR_INT = 0,                       /*!< bmx_err_intmcu_dec_err_int */
    GLB_MCU_ALL_INT_BMX_TIMEOUT_INT_MCU_TIMEOUT_INT = 1,   /*!< bmx_timeout_intmcu_timeout_int */
    GLB_MCU_ALL_INT_IPC0_NP2AP_IRQ = 2,                    /*!< ipc0_np2ap_irq */
    GLB_MCU_ALL_INT_IPC0_AP2NP_IRQ = 3,                    /*!< ipc0_ap2np_irq */
    GLB_MCU_ALL_INT_AUDIO_INT = 4,                         /*!< audio_int */
    GLB_MCU_ALL_INT_RF_TOP_INT_0 = 5,                      /*!< rf_top_int[0] */
    GLB_MCU_ALL_INT_RF_TOP_INT_1 = 6,                      /*!< rf_top_int[1] */
    GLB_MCU_ALL_INT_LZ4_INT = 7,                           /*!< lz4_int */
    GLB_MCU_ALL_INT_RSV8 = 8,                              /*!< rsv8 */
    GLB_MCU_ALL_INT_SEC_ENG_ID0_GMAC_INT = 9,              /*!< sec_eng_id0_gmac_int */
    GLB_MCU_ALL_INT_SEC_ENG_ID0_CDET_INT = 10,             /*!< sec_eng_id0_cdet_int */
    GLB_MCU_ALL_INT_SEC_ENG_ID0_PKA_INT = 11,              /*!< sec_eng_id0_pka_int */
    GLB_MCU_ALL_INT_SEC_ENG_ID0_TRNG_INT = 12,             /*!< sec_eng_id0_trng_int */
    GLB_MCU_ALL_INT_SEC_ENG_ID0_AES_INT = 13,              /*!< sec_eng_id0_aes_int */
    GLB_MCU_ALL_INT_SEC_ENG_ID0_SHA_INT = 14,              /*!< sec_eng_id0_sha_int */
    GLB_MCU_ALL_INT_DMA_INTR_ALL = 15,                     /*!< DMA_INTR_ALL */
    GLB_MCU_ALL_INT_DMA2_INTR_ALL = 16,                    /*!< DMA2_INTR_ALL */
    GLB_MCU_ALL_INT_SDH_MMC1_INT_SDH2PMU_WAKEUP_INT1 = 17, /*!< sdh_mmc1_intsdh2pmu_wakeup_int1 */
    GLB_MCU_ALL_INT_MM_IRQ_ALL = 18,                       /*!< mm_irq_all */
    GLB_MCU_ALL_INT_IRTX_INT = 19,                         /*!< irtx_int */
    GLB_MCU_ALL_INT_IRRX_INT = 20,                         /*!< irrx_int */
    GLB_MCU_ALL_INT_USB_INT = 21,                          /*!< usb_int */
    GLB_MCU_ALL_INT_AUPDM_INT = 22,                        /*!< aupdm_int */
    GLB_MCU_ALL_INT_SF_CTRL_ID0_INT = 23,                  /*!< sf_ctrl_id0_int */
    GLB_MCU_ALL_INT_EMAC_INT = 24,                         /*!< emac_int */
    GLB_MCU_ALL_INT_GPADC_DMA_INT = 25,                    /*!< gpadc_dma_int */
    GLB_MCU_ALL_INT_EFUSE_INT = 26,                        /*!< efuse_int */
    GLB_MCU_ALL_INT_SPI_0_INT = 27,                        /*!< spi_0_int */
    GLB_MCU_ALL_INT_UART_IRQ = 28,                         /*!< uart_irq */
    GLB_MCU_ALL_INT_UART1_IRQ = 29,                        /*!< uart1_irq */
    GLB_MCU_ALL_INT_UART2_IRQ = 30,                        /*!< uart2_irq */
    GLB_MCU_ALL_INT_GPIO_DMA_INT = 31,                     /*!< gpio_dma_int */
    GLB_MCU_ALL_INT_I2C_0_INT = 32,                        /*!< i2c_0_int */
    GLB_MCU_ALL_INT_PWM_INT = 33,                          /*!< pwm_int */
    GLB_MCU_ALL_INT_IPC1_NP2AP_IRQ = 34,                   /*!< ipc1_np2ap_irq */
    GLB_MCU_ALL_INT_IPC1_AP2NP_IRQ = 35,                   /*!< ipc1_ap2np_irq */
    GLB_MCU_ALL_INT_TIMER0_2_IRQ = 36,                     /*!< timer0_2_irq */
    GLB_MCU_ALL_INT_TIMER0_3_IRQ = 37,                     /*!< timer0_3_irq */
    GLB_MCU_ALL_INT_WDT0_IRQ = 38,                         /*!< wdt0_irq */
    GLB_MCU_ALL_INT_I2C_1_INT = 39,                        /*!< i2c_1_int */
    GLB_MCU_ALL_INT_I2S0_INT = 40,                         /*!< i2s0_int */
    GLB_MCU_ALL_INT_RSV41 = 41,                            /*!< rsv41 */
    GLB_MCU_ALL_INT_RSV42 = 42,                            /*!< rsv42 */
    GLB_MCU_ALL_INT_ANA_OCP_OUT_TO_CPU_IRQ = 43,           /*!< ana_ocp_out_to_cpu_irq[2:0] */
    GLB_MCU_ALL_INT_GPIO_IRQ = 44,                         /*!< gpio_irq */
    GLB_MCU_ALL_INT_DM_IRQ = 45,                           /*!< dm_irq */
    GLB_MCU_ALL_INT_BT_IRQ = 46,                           /*!< bt_irq */
    GLB_MCU_ALL_INT_M154_REQ_ENH_ACK_INT = 47,             /*!< m154_req_enh_ack_int */
    GLB_MCU_ALL_INT_M154_INT = 48,                         /*!< m154_int */
    GLB_MCU_ALL_INT_M154_AES_INT = 49,                     /*!< m154_aes_int */
    GLB_MCU_ALL_INT_PDS_INT = 50,                          /*!< pds_int */
    GLB_MCU_ALL_INT_HBN_IRQ_OUT_0 = 51,                    /*!< hbn_irq_out[0] */
    GLB_MCU_ALL_INT_HBN_IRQ_OUT_1 = 52,                    /*!< hbn_irq_out[1] */
    GLB_MCU_ALL_INT_BOR_OUT = 53,                          /*!< bor_out */
    GLB_MCU_ALL_INT_WIFI_TO_CPU_IRQ_N = 54,                /*!< wifi_to_cpu_irq_n */
    GLB_MCU_ALL_INT_BZ_PHY_INT = 55,                       /*!< bz_phy_int */
    GLB_MCU_ALL_INT_BLE_INT = 56,                          /*!< ble_int */
    GLB_MCU_ALL_INT_MAC_INT_TX_RX_TIMER = 57,              /*!< mac_int_tx_rx_timer */
    GLB_MCU_ALL_INT_MAC_INT_TX_RX_MISC = 58,               /*!< mac_int_tx_rx_misc */
    GLB_MCU_ALL_INT_MAC_INT_RX_TRIGGER = 59,               /*!< mac_int_rx_trigger */
    GLB_MCU_ALL_INT_MAC_INT_TX_TRIGGER = 60,               /*!< mac_int_tx_trigger */
    GLB_MCU_ALL_INT_MAC_INT_GEN = 61,                      /*!< mac_int_gen */
    GLB_MCU_ALL_INT_MAC_INT_PROT_TRIGGER = 62,             /*!< mac_int_prot_trigger */
    GLB_MCU_ALL_INT_WIFI_IPC = 63,                         /*!< wifi_ipc */
} GLB_MCU_ALL_INT_Type;

/**
 *  @brief GLB LP all interrupt type definition
 */
typedef enum {
    GLB_LP_ALL_INT_BMX_ERR_INT = 0,                       /*!< bmx_err_int */
    GLB_LP_ALL_INT_BMX_TIMEOUT_INT_MCU_TIMEOUT_INT = 1,   /*!< bmx_timeout_intmcu_timeout_int */
    GLB_LP_ALL_INT_IPC0_NP2AP_IRQ = 2,                    /*!< ipc0_np2ap_irq */
    GLB_LP_ALL_INT_IPC0_AP2NP_IRQ = 3,                    /*!< ipc0_ap2np_irq */
    GLB_LP_ALL_INT_AUDIO_INT = 4,                         /*!< audio_int */
    GLB_LP_ALL_INT_RF_TOP_INT_0 = 5,                      /*!< rf_top_int[0] */
    GLB_LP_ALL_INT_RF_TOP_INT_1 = 6,                      /*!< rf_top_int[1] */
    GLB_LP_ALL_INT_LZ4_INT = 7,                           /*!< lz4_int */
    GLB_LP_ALL_INT_RSV8 = 8,                              /*!< rsv8 */
    GLB_LP_ALL_INT_SEC_ENG_ID0_GMAC_INT = 9,              /*!< sec_eng_id0_gmac_int */
    GLB_LP_ALL_INT_SEC_ENG_ID0_CDET_INT = 10,             /*!< sec_eng_id0_cdet_int */
    GLB_LP_ALL_INT_SEC_ENG_ID0_PKA_INT = 11,              /*!< sec_eng_id0_pka_int */
    GLB_LP_ALL_INT_SEC_ENG_ID0_TRNG_INT = 12,             /*!< sec_eng_id0_trng_int */
    GLB_LP_ALL_INT_SEC_ENG_ID0_AES_INT = 13,              /*!< sec_eng_id0_aes_int */
    GLB_LP_ALL_INT_SEC_ENG_ID0_SHA_INT = 14,              /*!< sec_eng_id0_sha_int */
    GLB_LP_ALL_INT_DMA_INTR_ALL = 15,                     /*!< DMA_INTR_ALL */
    GLB_LP_ALL_INT_DMA2_INTR_ALL = 16,                    /*!< DMA2_INTR_ALL */
    GLB_LP_ALL_INT_SDH_MMC1_INT_SDH2PMU_WAKEUP_INT1 = 17, /*!< sdh_mmc1_intsdh2pmu_wakeup_int1 */
    GLB_LP_ALL_INT_MM_IRQ_ALL = 18,                       /*!< mm_irq_all */
    GLB_LP_ALL_INT_IRTX_INT = 19,                         /*!< irtx_int */
    GLB_LP_ALL_INT_IRRX_INT = 20,                         /*!< irrx_int */
    GLB_LP_ALL_INT_USB_INT = 21,                          /*!< usb_int */
    GLB_LP_ALL_INT_AUPDM_INT = 22,                        /*!< aupdm_int */
    GLB_LP_ALL_INT_SF_CTRL_ID0_INT = 23,                  /*!< sf_ctrl_id0_int */
    GLB_LP_ALL_INT_EMAC_INT = 24,                         /*!< emac_int */
    GLB_LP_ALL_INT_GPADC_DMA_INT = 25,                    /*!< gpadc_dma_int */
    GLB_LP_ALL_INT_EFUSE_INT = 26,                        /*!< efuse_int */
    GLB_LP_ALL_INT_SPI_0_INT = 27,                        /*!< spi_0_int */
    GLB_LP_ALL_INT_UART_IRQ = 28,                         /*!< uart_irq */
    GLB_LP_ALL_INT_UART1_IRQ = 29,                        /*!< uart1_irq */
    GLB_LP_ALL_INT_UART2_IRQ = 30,                        /*!< uart2_irq */
    GLB_LP_ALL_INT_GPIO_DMA_INT = 31,                     /*!< gpio_dma_int */
    GLB_LP_ALL_INT_I2C_0_INT = 32,                        /*!< i2c_0_int */
    GLB_LP_ALL_INT_PWM_INT = 33,                          /*!< pwm_int */
    GLB_LP_ALL_INT_IPC1_NP2AP_IRQ = 34,                   /*!< ipc1_np2ap_irq */
    GLB_LP_ALL_INT_IPC1_AP2NP_IRQ = 35,                   /*!< ipc1_ap2np_irq */
    GLB_LP_ALL_INT_TIMER0_2_IRQ = 36,                     /*!< timer0_2_irq */
    GLB_LP_ALL_INT_TIMER0_3_IRQ = 37,                     /*!< timer0_3_irq */
    GLB_LP_ALL_INT_WDT0_IRQ = 38,                         /*!< wdt0_irq */
    GLB_LP_ALL_INT_I2C_1_INT = 39,                        /*!< i2c_1_int */
    GLB_LP_ALL_INT_I2S0_INT = 40,                         /*!< i2s0_int */
    GLB_LP_ALL_INT_RSV41 = 41,                            /*!< rsv41 */
    GLB_LP_ALL_INT_RSV42 = 42,                            /*!< rsv42 */
    GLB_LP_ALL_INT_ANA_OCP_OUT_TO_CPU_IRQ = 43,           /*!< ana_ocp_out_to_cpu_irq[2:0] */
    GLB_LP_ALL_INT_GPIO_IRQ = 44,                         /*!< gpio_irq */
    GLB_LP_ALL_INT_DM_IRQ = 45,                           /*!< dm_irq */
    GLB_LP_ALL_INT_BT_IRQ = 46,                           /*!< bt_irq */
    GLB_LP_ALL_INT_M154_REQ_ENH_ACK_INT = 47,             /*!< m154_req_enh_ack_int */
    GLB_LP_ALL_INT_M154_INT = 48,                         /*!< m154_int */
    GLB_LP_ALL_INT_M154_AES_INT = 49,                     /*!< m154_aes_int */
    GLB_LP_ALL_INT_PDS_INT = 50,                          /*!< pds_int */
    GLB_LP_ALL_INT_HBN_IRQ_OUT_0 = 51,                    /*!< hbn_irq_out[0] */
    GLB_LP_ALL_INT_HBN_IRQ_OUT_1 = 52,                    /*!< hbn_irq_out[1] */
    GLB_LP_ALL_INT_BOR_OUT = 53,                          /*!< bor_out */
    GLB_LP_ALL_INT_WIFI_TO_CPU_IRQ_N = 54,                /*!< wifi_to_cpu_irq_n */
    GLB_LP_ALL_INT_BZ_PHY_INT = 55,                       /*!< bz_phy_int */
    GLB_LP_ALL_INT_BLE_INT = 56,                          /*!< ble_int */
    GLB_LP_ALL_INT_MAC_INT_TX_RX_TIMER = 57,              /*!< mac_int_tx_rx_timer */
    GLB_LP_ALL_INT_MAC_INT_TX_RX_MISC = 58,               /*!< mac_int_tx_rx_misc */
    GLB_LP_ALL_INT_MAC_INT_RX_TRIGGER = 59,               /*!< mac_int_rx_trigger */
    GLB_LP_ALL_INT_MAC_INT_TX_TRIGGER = 60,               /*!< mac_int_tx_trigger */
    GLB_LP_ALL_INT_MAC_INT_GEN = 61,                      /*!< mac_int_gen */
    GLB_LP_ALL_INT_MAC_INT_PROT_TRIGGER = 62,             /*!< mac_int_prot_trigger */
    GLB_LP_ALL_INT_WIFI_IPC = 63,                         /*!< wifi_ipc */
} GLB_LP_ALL_INT_Type;

/**
 *  @brief GLB dsp muxpll 320M clock type definition
 */
typedef enum {
    GLB_DSP_MUXPLL_SEL_WIFIPLL_320M, /*!< dsp muxpll select wifipll 320M */
    GLB_DSP_MUXPLL_SEL_AUPLL_DIV1,   /*!< dsp muxpll select aupll div1 */
} GLB_DSP_MUXPLL_320M_CLK_SEL_Type;

/**
 *  @brief GLB dsp muxpll 240M clock type definition
 */
typedef enum {
    GLB_DSP_MUXPLL_SEL_WIFIPLL_240M, /*!< dsp muxpll select wifipll 240M */
    GLB_DSP_MUXPLL_SEL_AUPLL_DIV2,   /*!< dsp muxpll select aupll div2 */
} GLB_DSP_MUXPLL_240M_CLK_SEL_Type;

/**
 *  @brief GLB dsp muxpll 160M clock type definition
 */
typedef enum {
    GLB_DSP_MUXPLL_SEL_WIFIPLL_160M, /*!< dsp muxpll select wifipll 160M */
    GLB_DSP_MUXPLL_SEL_CPUPLL_160M,  /*!< dsp muxpll select cpupll 160M */
} GLB_DSP_MUXPLL_160M_CLK_SEL_Type;

/**
 *  @brief GLB mcu muxpll 160M clock type definition
 */
typedef enum {
    GLB_MCU_MUXPLL_SEL_WIFIPLL_160M,    /*!< mcu muxpll select wifipll 160M */
    GLB_MCU_MUXPLL_SEL_TOP_CPUPLL_160M, /*!< mcu muxpll select top cpupll 160M */
    GLB_MCU_MUXPLL_SEL_TOP_AUPLL_DIV2,  /*!< mcu muxpll select top aupll div2 */
    GLB_MCU_MUXPLL_SEL_AUPLL_DIV2P5,    /*!< mcu muxpll select aupll div2p5 */
} GLB_MCU_MUXPLL_160M_CLK_SEL_Type;

/**
 *  @brief GLB mcu muxpll 80M clock type definition
 */
typedef enum {
    GLB_MCU_MUXPLL_SEL_WIFIPLL_80M,    /*!< mcu muxpll select wifipll 80M */
    GLB_MCU_MUXPLL_SEL_TOP_CPUPLL_80M, /*!< mcu muxpll select top cpupll 80M */
    GLB_MCU_MUXPLL_SEL_AUPLL_DIV5,     /*!< mcu muxpll select aupll div5 */
    GLB_MCU_MUXPLL_SEL_AUPLL_DIV6,     /*!< mcu muxpll select aupll div6 */
} GLB_MCU_MUXPLL_80M_CLK_SEL_Type;

/**
 *  @brief GLB pll clock gate type definition
 */
typedef enum {
    GLB_PLL_CGEN_MM_WIFIPLL_160M,  /*!< pll cgen mm wifipll 160m */
    GLB_PLL_CGEN_MM_WIFIPLL_240M,  /*!< pll cgen mm wifipll 240m */
    GLB_PLL_CGEN_MM_WIFIPLL_320M,  /*!< pll cgen mm wifipll 320m */
    GLB_PLL_CGEN_MM_AUPLL_DIV1,    /*!< pll cgen mm aupll div1 */
    GLB_PLL_CGEN_MM_AUPLL_DIV2,    /*!< pll cgen mm aupll div2 */
    GLB_PLL_CGEN_EMI_CPUPLL_400M,  /*!< pll cgen emi cpupll 400m */
    GLB_PLL_CGEN_EMI_CPUPLL_200M,  /*!< pll cgen emi cpupll 200m */
    GLB_PLL_CGEN_EMI_WIFIPLL_320M, /*!< pll cgen emi wifipll 320m */
    GLB_PLL_CGEN_EMI_AUPLL_DIV1,   /*!< pll cgen emi aupll div1 */
    GLB_PLL_CGEN_TOP_CPUPLL_80M,   /*!< pll cgen top cpupll 80m */
    GLB_PLL_CGEN_TOP_CPUPLL_100M,  /*!< pll cgen top cpupll 100m */
    GLB_PLL_CGEN_TOP_CPUPLL_160M,  /*!< pll cgen top cpupll 160m */
    GLB_PLL_CGEN_TOP_CPUPLL_400M,  /*!< pll cgen top cpupll 400m */
    GLB_PLL_CGEN_TOP_WIFIPLL_240M, /*!< pll cgen top wifipll 240m */
    GLB_PLL_CGEN_TOP_WIFIPLL_320M, /*!< pll cgen top wifipll 320m */
    GLB_PLL_CGEN_TOP_AUPLL_DIV2,   /*!< pll cgen top aupll div2 */
    GLB_PLL_CGEN_TOP_AUPLL_DIV1,   /*!< pll cgen top aupll div1 */
} GLB_PLL_CGEN_Type;

/**
 *  @brief GLB mcu system clock type definition
 */
typedef enum {
    GLB_MCU_SYS_CLK_RC32M,        /*!< use RC32M as system clock frequency */
    GLB_MCU_SYS_CLK_XTAL,         /*!< use XTAL as system clock */
    GLB_MCU_SYS_CLK_CPUPLL_400M,  /*!< use CPUPLL output 400M as system clock */
    GLB_MCU_SYS_CLK_WIFIPLL_240M, /*!< use WIFIPLL output 240M as system clock */
    GLB_MCU_SYS_CLK_WIFIPLL_320M, /*!< use WIFIPLL output 320M as system clock */
} GLB_MCU_SYS_CLK_Type;

/**
 *  @brief GLB dsp system clock type definition
 */
typedef enum {
    GLB_DSP_SYS_CLK_RC32M,           /*!< use RC32M as system clock frequency */
    GLB_DSP_SYS_CLK_XTAL,            /*!< use XTAL as system clock */
    GLB_DSP_SYS_CLK_MM_WIFIPLL_240M, /*!< use WIFIPLL 240M as system clock */
    GLB_DSP_SYS_CLK_MM_WIFIPLL_320M, /*!< use WIFIPLL 320M as system clock */
    GLB_DSP_SYS_CLK_CPUPLL_400M,     /*!< use CPUPLL output 400M as system clock */
} GLB_DSP_SYS_CLK_Type;

/**
 *  @brief GLB dsp pbus clock type definition
 */
typedef enum {
    GLB_DSP_SYS_PBCLK_RC32M,           /*!< use rc32m as pbus clock */
    GLB_DSP_SYS_PBCLK_XTAL,            /*!< use xtal as pbus clock */
    GLB_DSP_SYS_PBCLK_MM_WIFIPLL_160M, /*!< use mm_wifipll_160m_clk as pbus clock */
    GLB_DSP_SYS_PBCLK_CPUPLL_160M,     /*!< use cpupll_160m_clk as pbus clock */
    GLB_DSP_SYS_PBCLK_MM_WIFIPLL_240M, /*!< use mm_wifipll_240m_clk as pbus clock */
} GLB_DSP_SYS_PBCLK_Type;

/**
 *  @brief GLB dsp system clock type definition
 */
typedef enum {
    GLB_PLL_REFCLK_XTAL = 0,  /*!< use XTAL as pll ref clock */
    GLB_PLL_REFCLK_RC32M = 3, /*!< use RC32M as pll ref clock */
} GLB_PLL_REF_CLK_Type;

typedef struct {
    uint8_t clkpllRefdivRatio;  /*!< xxx pll_refdiv_ratio */
    uint8_t clkpllIntFracSw;    /*!< xxx pll_int_frac_sw */
    uint8_t clkpllIcp1u;        /*!< xxx pll_icp_1u */
    uint8_t clkpllIcp5u;        /*!< xxx pll_icp_5u */
    uint8_t clkpllRz;           /*!< xxx pll_rz */
    uint8_t clkpllCz;           /*!< xxx pll_cz */
    uint8_t clkpllC3;           /*!< xxx pll_c3 */
    uint8_t clkpllR4Short;      /*!< xxx pll_r4_short */
    uint8_t clkpllC4En;         /*!< xxx pll_r4_en */
    uint8_t clkpllSelSampleClk; /*!< xxx pll_sel_sample_clk */
    uint8_t clkpllVcoSpeed;     /*!< xxx pll_vco_speed */
    uint8_t clkpllSdmCtrlHw;    /*!< xxx pll_sdm_ctrl_hw */
    uint8_t clkpllSdmBypass;    /*!< xxx pll_sdm_bypass */
} GLB_WAC_PLL_CFG_BASIC_Type;

typedef struct {
    const GLB_WAC_PLL_CFG_BASIC_Type *const basicCfg; /*!< pll basic configuration */
    uint32_t clkpllSdmin;                             /*!< pll sdmin value */
} GLB_WAC_PLL_Cfg_Type;

typedef struct {
    uint8_t clkpllRefdivRatio;  /*!< xxx pll_refdiv_ratio */
    uint8_t clkpllSelSampleClk; /*!< xxx pll_sel_sample_clk */
    uint8_t clkpllVcoSpeed;     /*!< xxx pll_vco_speed */
    uint8_t clkpllEvenDivEn;    /*!< xxx pll_even_div_en */
    uint8_t clkpllEvenDivRatio; /*!< xxx pll_even_div_ratio */
} GLB_MU_PLL_CFG_BASIC_Type;

typedef struct {
    const GLB_MU_PLL_CFG_BASIC_Type *const basicCfg; /*!< pll basic configuration */
    uint32_t clkpllSdmin;                            /*!< pll sdmin value */
} GLB_MU_PLL_Cfg_Type;

/**
 *  @brief GLB CAM clock type definition
 */
typedef enum {
    GLB_CAM_CLK_XCLK,        /*!< Select XCLK as CAM clock */
    GLB_CAM_CLK_WIFIPLL_96M, /*!< Select WIFIPLL_96M as CAM clock */
    GLB_CAM_CLK_CPUPLL_100M, /*!< Select CPUPLL_96M as CAM clock */
} GLB_CAM_CLK_Type;

/**
 *  @brief GLB SDH clock type definition
 */
typedef enum {
    GLB_SDH_CLK_WIFIPLL_96M, /*!< Select WIFIPLL_96M as SDH clock */
    GLB_SDH_CLK_CPUPLL_100M, /*!< Select CPUPLL_100M as SDH clock */
} GLB_SDH_CLK_Type;

/**
 *  @brief GLB UART sig swap group type definition
 */
typedef enum {
    GLB_UART_SIG_SWAP_GRP_GPIO0_GPIO11,  /*!< SWAP UART SIG GROUP GPIO0  -  GPIO11 */
    GLB_UART_SIG_SWAP_GRP_GPIO12_GPIO23, /*!< SWAP UART SIG GROUP GPIO12 -  GPIO23 */
    GLB_UART_SIG_SWAP_GRP_GPIO24_GPIO35, /*!< SWAP UART SIG GROUP GPIO24 -  GPIO35 */
    GLB_UART_SIG_SWAP_GRP_GPIO36_GPIO45, /*!< SWAP UART SIG GROUP GPIO36 -  GPIO45 */
} GLB_UART_SIG_SWAP_GRP_Type;

/**
 *  @brief GLB I2S output ref clock type definition
 */
typedef enum {
    GLB_I2S_OUT_REF_CLK_NONE, /*!< no output reference clock on I2S_0 ref_clock port */
    GLB_I2S_OUT_REF_CLK_SRC,  /*!< output reference clock on I2S_0 ref_clock port */
} GLB_I2S_OUT_REF_CLK_Type;

/**
 *  @brief GLB DMA clock ID type definition
 */
typedef enum {
    GLB_DMA0_CLK_CH0, /*!< DMA0 clock ID:channel 0 */
    GLB_DMA0_CLK_CH1, /*!< DMA0 clock ID:channel 1 */
    GLB_DMA0_CLK_CH2, /*!< DMA0 clock ID:channel 2 */
    GLB_DMA0_CLK_CH3, /*!< DMA0 clock ID:channel 3 */
    GLB_DMA0_CLK_CH4, /*!< DMA0 clock ID:channel 4 */
    GLB_DMA0_CLK_CH5, /*!< DMA0 clock ID:channel 5 */
    GLB_DMA0_CLK_CH6, /*!< DMA0 clock ID:channel 6 */
    GLB_DMA0_CLK_CH7, /*!< DMA0 clock ID:channel 7 */
    GLB_DMA1_CLK_CH0, /*!< DMA1 clock ID:channel 0 */
    GLB_DMA1_CLK_CH1, /*!< DMA1 clock ID:channel 1 */
    GLB_DMA1_CLK_CH2, /*!< DMA1 clock ID:channel 2 */
    GLB_DMA1_CLK_CH3, /*!< DMA1 clock ID:channel 3 */
} GLB_DMA_CLK_ID_Type;

/**
 *  @brief GLB peripheral DMA type definition
 */
typedef enum {
    GLB_PERI_DMA_UART0_RX = 0,  /*!< uart_rx  */
    GLB_PERI_DMA_UART0_TX = 1,  /*!< uart_tx  */
    GLB_PERI_DMA_UART1_RX = 2,  /*!< uart1_rx */
    GLB_PERI_DMA_UART1_TX = 3,  /*!< uart1_tx */
    GLB_PERI_DMA_UART2_RX = 4,  /*!< uart2_rx */
    GLB_PERI_DMA_UART2_TX = 5,  /*!< uart2_tx */
    GLB_PERI_DMA_I2C_0_RX = 6,  /*!< i2c_0_rx */
    GLB_PERI_DMA_I2C_0_TX = 7,  /*!< i2c_0_tx */
    GLB_PERI_DMA_IRTX_TX = 8,   /*!< irtx_tx  */
    GLB_PERI_DMA_GPIO_TX = 9,   /*!< gpio_tx  */
    GLB_PERI_DMA_SPI_RX = 10,   /*!< spi_rx   */
    GLB_PERI_DMA_SPI_TX = 11,   /*!< spi_tx   */
    GLB_PERI_DMA_AUDIO_RX = 12, /*!< audio_rx */
    GLB_PERI_DMA_AUDIO_TX = 13, /*!< audio_tx */
    GLB_PERI_DMA_I2C_1_RX = 14, /*!< i2c_1_rx */
    GLB_PERI_DMA_I2C_1_TX = 15, /*!< i2c_1_tx */
    GLB_PERI_DMA_I2S_0_RX = 16, /*!< i2s_0_rx */
    GLB_PERI_DMA_I2S_0_TX = 17, /*!< i2s_0_tx */
    GLB_PERI_DMA_PDM_RX = 18,   /*!< pdm_rx   */
    GLB_PERI_DMA_PADC = 19,     /*!< padc     */
    GLB_PERI_DMA_GAUGE = 20,    /*!< gauge    */
    GLB_PERI_DMA_GPADC = 22,    /*!< gpadc    */
    GLB_PERI_DMA_GPDAC_TX = 23, /*!< gpdac_tx */
} GLB_PERI_DMA_Type;

/**
 *  @brief GLB DMA CN selection type definition
 */
typedef enum {
    GLB_PERI_DMA_CN_SEL_DMA0 = 0, /*!< peripheral DMA channel select DMA0 */
    GLB_PERI_DMA_CN_SEL_DMA1 = 1, /*!< peripheral DMA channel select DMA1 */
} GLB_PERI_DMA_CN_SEL_Type;

/**
 *  @brief GLB clock source type definition
 */
typedef enum {
    GLB_IR_CLK_SRC_XCLK, /*!< IR clock source select XCLK */
} GLB_IR_CLK_SRC_Type;

/**
 *  @brief GLB flash clock type definition
 */
typedef enum {
    GLB_SFLASH_CLK_120M_WIFIPLL, /*!< Select WIFIPLL 120M as flash clock */
    GLB_SFLASH_CLK_XTAL,         /*!< Select XTAL as flash clock */
    GLB_SFLASH_CLK_100M_CPUPLL,  /*!< Select CPUPLL 100M as flash clock */
    GLB_SFLASH_CLK_80M_MUXPLL,   /*!< Select MUXPLL 80M as flash clock */
    GLB_SFLASH_CLK_BCLK,         /*!< Select BCLK as flash clock */
    GLB_SFLASH_CLK_96M_WIFIPLL,  /*!< Select WIFIPLL 96M as flash clock */
} GLB_SFLASH_CLK_Type;

/**
 *  @brief GLB I2C clock type definition
 */
typedef enum {
    GLB_I2C_CLK_BCLK, /*!< Select bus clk as I2C clock */
    GLB_I2C_CLK_XCLK, /*!< Select xclk as I2C clock */
} GLB_I2C_CLK_Type;

/**
 *  @brief GLB SPI clock type definition
 */
typedef enum {
    GLB_SPI_CLK_MCU_MUXPLL_160M, /*!< Select MCU MUXPLL 160M as SPI clock */
    GLB_SPI_CLK_XCLK,            /*!< Select xclk as SPI clock */
} GLB_SPI_CLK_Type;

/**
 *  @brief GLB PWM1 io type definition
 */
typedef enum {
    GLB_PWM1_IO_SINGLE_END, /*!< Select pwm1 io single end */
    GLB_PWM1_IO_DIFF_END,   /*!< Select pwm1 io differential end for BLDC */
} GLB_PWM1_IO_SEL_Type;

/**
 *  @brief GLB PWM2 io type definition
 */
typedef enum {
    GLB_PWM2_IO_SINGLE_END,      /*!< Select pwm2 io single end */
    GLB_PWM2_IO_SINGLE_END_BLDC, /*!< Select pwm2 io single end BLDC */
} GLB_PWM2_IO_SEL_Type;

/**
 *  @brief GLB PDM io type definition
 */
typedef enum {
    GLB_PDM_IO_SEL_AUDIO_TOP, /*!< Select audio_top PDM */
    GLB_PDM_IO_SEL_AUPDM_TOP, /*!< Select aupdm_top PDM */
} GLB_PDM_IO_SEL_Type;

/**
 *  @brief GLB SPI pad action type definition
 */
typedef enum {
    GLB_SPI_PAD_ACT_AS_SLAVE,  /*!< SPI pad act as slave */
    GLB_SPI_PAD_ACT_AS_MASTER, /*!< SPI pad act as master */
} GLB_SPI_PAD_ACT_AS_Type;

/**
 *  @brief GLB AHB software type definition
 */
typedef enum {
    GLB_AHB_MCU_SW_RSV0 = 0,
    GLB_AHB_MCU_SW_RSV1 = 1,
    GLB_AHB_MCU_SW_WIFI = 4,
    GLB_AHB_MCU_SW_BTDM = 8,
    GLB_AHB_MCU_SW_ZIGBEE = 9,
    GLB_AHB_MCU_SW_BLE2 = 10,
    GLB_AHB_MCU_SW_ZIGBEE2 = 11,
    GLB_AHB_MCU_SW_EMI_MISC = 16,
    GLB_AHB_MCU_SW_PSRAM0_CTRL = 17,
    GLB_AHB_MCU_SW_PSRAM1_CTRL = 18,
    GLB_AHB_MCU_SW_USB_EMAC = 19,
    GLB_AHB_MCU_SW_RSV20 = 20,
    GLB_AHB_MCU_SW_AUDIO = 21,
    GLB_AHB_MCU_SW_SDH = 22,
    GLB_AHB_MCU_SW_RSV23 = 23,
    GLB_AHB_MCU_SW_DMA2 = 24,
    GLB_AHB_MCU_SW_GLB = 32,
    GLB_AHB_MCU_SW_MIX = 33,
    GLB_AHB_MCU_SW_GPIP = 34,
    GLB_AHB_MCU_SW_SEC_DBG = 35,
    GLB_AHB_MCU_SW_SEC_ENG = 36,
    GLB_AHB_MCU_SW_TZ1 = 37,
    GLB_AHB_MCU_SW_TZ2 = 38,
    GLB_AHB_MCU_SW_EFUSE = 39,
    GLB_AHB_MCU_SW_CCI = 40,
    GLB_AHB_MCU_SW_MCU_PERI_BUS = 41,
    GLB_AHB_MCU_SW_RSV42 = 42,
    GLB_AHB_MCU_SW_SF = 43,
    GLB_AHB_MCU_SW_DMA = 44,
    GLB_AHB_MCU_SW_SDU = 45,
    GLB_AHB_MCU_SW_PDS = 46,
    GLB_AHB_MCU_SW_RSV47 = 47,
    GLB_AHB_MCU_SW_UART0 = 48,
    GLB_AHB_MCU_SW_UART1 = 49,
    GLB_AHB_MCU_SW_SPI = 50,
    GLB_AHB_MCU_SW_I2C = 51,
    GLB_AHB_MCU_SW_PWM = 52,
    GLB_AHB_MCU_SW_TIMER = 53,
    GLB_AHB_MCU_SW_IR_REMOTE = 54,
    GLB_AHB_MCU_SW_CHECKSUM = 55,
    GLB_AHB_MCU_SW_IPC = 56,
    GLB_AHB_MCU_SW_I2C1 = 57,
    GLB_AHB_MCU_SW_UART2 = 58,
    GLB_AHB_MCU_SW_I2S = 59,
    GLB_AHB_MCU_SW_AUPDM = 60,
    GLB_AHB_MCU_SW_LZ4 = 61,
    GLB_AHB_MCU_SW_RSV62 = 62,
    GLB_AHB_MCU_SW_RSV63 = 63,
    GLB_AHB_MCU_SW_PWRON_RST = 64,
    GLB_AHB_MCU_SW_CPU_RESET = 65,
    GLB_AHB_MCU_SW_SYS_RESET = 66,
    GLB_AHB_MCU_SW_PICO_RESET = 67,
    GLB_AHB_MCU_SW_CPU2_RESET = 68,
    GLB_AHB_MCU_SW_CHIP_RESET = 69,
    GLB_AHB_MCU_SW_WL_WDT_RESET_MM_EN = 70,
    GLB_AHB_MCU_SW_MMWDT2WL_RST_MSK = 71,
} GLB_AHB_MCU_SW_Type;

/**
 *  @brief GLB AHB software type definition
 */
typedef enum {
    GLB_AHB_DSP_SW_REG_CTRL_SYS_RESET = 0,
    GLB_AHB_DSP_SW_REG_CTRL_PWRON_RST = 2,
    GLB_AHB_DSP_SW_REG_CTRL_MMCPU0_RESET = 8,
    GLB_AHB_DSP_SW_SWRST_MM_MISC = 32,
    GLB_AHB_DSP_SW_SWRST_DMA = 33,
    GLB_AHB_DSP_SW_SWRST_UART0 = 34,
    GLB_AHB_DSP_SW_SWRST_I2C0 = 35,
    GLB_AHB_DSP_SW_SWRST_I2C1 = 36,
    GLB_AHB_DSP_SW_SWRST_IPC = 37,
    GLB_AHB_DSP_SW_SWRST_DMA2D = 38,
    GLB_AHB_DSP_SW_SWRST_SPI = 40,
    GLB_AHB_DSP_SW_SWRST_TIMER = 41,
    GLB_AHB_DSP_SW_SWRST_I2S0 = 42,
    GLB_AHB_DSP_SW_SWRST_I2S1 = 43,
    GLB_AHB_DSP_SW_SWRST_PDM0 = 44,
    GLB_AHB_DSP_SW_SWRST_PDM1 = 45,
    GLB_AHB_DSP_SW_SWRST_PUHS = 47,
    GLB_AHB_DSP_SW_SWRST_SPP_MISC = 64,
    GLB_AHB_DSP_SW_SWRST_SPP_MAIN = 65,
    GLB_AHB_DSP_SW_SWRST_SPP_TSRC = 66,
    GLB_AHB_DSP_SW_SWRST_DP_TSRC = 67,
    GLB_AHB_DSP_SW_SWRST_NR3D_CTRL = 68,
    GLB_AHB_DSP_SW_SWRST_DVP2BUSA = 69,
    GLB_AHB_DSP_SW_SWRST_DVP2BUSB = 70,
    GLB_AHB_DSP_SW_SWRST_DVP2BUSC = 71,
    GLB_AHB_DSP_SW_SWRST_DVP2BUSD = 72,
    GLB_AHB_DSP_SW_SWRST_MIPI = 73,
    GLB_AHB_DSP_SW_SWRST_SPP_REG = 80,
    GLB_AHB_DSP_SW_SWRST_DVP2BUSE = 81,
    GLB_AHB_DSP_SW_SWRST_DVP2BUSF = 82,
    GLB_AHB_DSP_SW_SWRST_DVP2BUSG = 83,
    GLB_AHB_DSP_SW_SWRST_DVP2BUSH = 84,
    GLB_AHB_DSP_SW_SWRST_CODEC_MISC = 96,
    GLB_AHB_DSP_SW_SWRST_MJPEG = 97,
    GLB_AHB_DSP_SW_SWRST_H264 = 98,
    GLB_AHB_DSP_SW_SWRST_MJPEG_DEC = 99,
    GLB_AHB_DSP_SW_SWRST_CNN = 100,
    GLB_AHB_DSP_SW_SWRST_VRAM = 112,
    GLB_AHB_DSP_SW_RG_IS_RST_N = 128,
} GLB_AHB_DSP_SW_Type;

/**
 *  @brief GLB dis reset type definition
 */
typedef enum {
    GLB_DISRST_GPIP = 2,
    GLB_DISRST_SEC_ENG = 4,
    GLB_DISRST_CCI = 8,
    GLB_DISRST_SF = 11,
    GLB_DISRST_UART0 = 16,
    GLB_DISRST_UART1 = 17,
    GLB_DISRST_SPI = 18,
    GLB_DISRST_I2C0 = 19,
    GLB_DISRST_PWM = 20,
    GLB_DISRST_TIMER = 21,
    GLB_DISRST_IR_REMOTE = 22,
    GLB_DISRST_CHECKSUM = 23,
    GLB_DISRST_IPC = 24,
    GLB_DISRST_I2C1 = 25,
    GLB_DISRST_UART2 = 26,
} GLB_DISRST_Type;

/**
 *  @brief GLB PKA clock type definition
 */
typedef enum {
    GLB_PKA_CLK_MCU_BCLK,        /*!< Select MCU_BCLK as PKA clock */
    GLB_PKA_CLK_MCU_MUXPLL_160M, /*!< Select MCU MUXPLL 160M as PKA clock */
} GLB_PKA_CLK_Type;

/**
 *  @brief GLB MCU software system reset type definition
 */
typedef enum {
    GLB_MCU_SW_SYSTEM_CTRL_MCU = 1, /*!< mcu reset */
    GLB_MCU_SW_SYSTEM_CTRL_LP = 3,  /*!< lp reset */
} GLB_MCU_SW_SYSTEM_Type;

/**
 *  @brief BMX arb mode type definition
 */
typedef enum {
    BMX_ARB_ROUND_ROBIN = 0, /*!< 0->round-robin */
    BMX_ARB_FIX = 1,         /*!< 1->fix */
} BMX_ARB_Type;

/**
 *  @brief BMX latch type definition
 */
typedef enum {
    BMX_LATCH_FIRST_ERROR = 0, /*!< 0->Latch first error */
    BMX_LATCH_LAST_ERROR = 1,  /*!< 1->Latch last error */
} BMX_LATCH_Type;

/**
 *  @brief BMX configuration structure type definition
 */
typedef struct {
    BMX_ARB_Type arbMod; /*!< 0->fix, 2->round-robin, 3->random */
    uint8_t timeoutEn;   /*!< Bus timeout enable: detect slave no reaponse in 1024 cycles */
} BMX_TO_Cfg_Type;

/**
 *  @brief BMX bus err type definition
 */
typedef enum {
    BMX_BUS_ERR_TRUSTZONE_DECODE, /*!< Bus trustzone decode error */
    BMX_BUS_ERR_ADDR_DECODE,      /*!< Bus addr decode error */
} BMX_BUS_ERR_Type;

/**
 *  @brief BMX bus err interrupt type definition
 */
typedef enum {
    BMX_ERR_INT_ERR, /*!< BMX bus err interrupt */
    BMX_ERR_INT_ALL, /*!< BMX bus err interrupt max num */
} BMX_ERR_INT_Type;

/**
 *  @brief BMX time out interrupt type definition
 */
typedef enum {
    BMX_TO_INT_TIMEOUT, /*!< BMX timeout interrupt */
    BMX_TO_INT_ALL,     /*!< BMX timeout interrupt max num */
} BMX_TO_INT_Type;

/**
 *  @brief GLB eth ref clock out type definition
 */
typedef enum {
    GLB_ETH_REF_CLK_OUT_OUTSIDE_50M, /*!< select outside 50MHz RMII ref clock */
    GLB_ETH_REF_CLK_OUT_INSIDE_50M,  /*!< select inside 50MHz RMII ref clock */
} GLB_ETH_REF_CLK_OUT_Type;

/**
 *  @brief GLB EM type definition
 */
typedef enum {
    GLB_WRAM160KB_EM0KB,  /*!< WRAM_160KB EM_0KB */
    GLB_WRAM144KB_EM16KB, /*!< WRAM_144KB EM_16KB */
    GLB_WRAM128KB_EM32KB, /*!< WRAM_128KB EM_32KB */
    GLB_WRAM112KB_EM48KB, /*!< WRAM_112KB EM_48KB */
    GLB_WRAM96KB_EM64KB,  /*!< WRAM_96KB EM_64KB */
} GLB_EM_Type;

/**
 *  @brief GLB ADC clock type definition
 */
typedef enum {
    GLB_ADC_CLK_AUPLL, /*!< use AUPLL as ADC clock */
    GLB_ADC_CLK_XCLK,  /*!< use XCLK as ADC clock */
} GLB_ADC_CLK_Type;

/**
 *  @brief GLB DAC clock type definition
 */
typedef enum {
    GLB_DAC_CLK_32M,  /*!< use 32M as DAC clock */
    GLB_DAC_CLK_XCLK, /*!< use XCLK as DAC clock */
} GLB_DAC_CLK_Type;

/**
 *  @brief GLB chip clock input output type definition
 */
/**
 *  @brief GLB chip clock out 0 type definition
 */
typedef enum {
    GLB_CHIP_CLK_OUT_0_CAM_REF_CLK = 0,   /*!< cam_ref_clk */
    GLB_CHIP_CLK_OUT_0_I2S_REF_CLK = 1,   /*!< i2s_ref_clk out */
    GLB_CHIP_CLK_OUT_0_CLK_AUDIO_ADC = 2, /*!< clk_adc */
    GLB_CHIP_CLK_OUT_0_CLK_AUDIO_DAC = 3, /*!< clk_dac */
} GLB_CHIP_CLK_OUT_0_Type;

/**
 *  @brief GLB chip clock out 1 type definition
 */
typedef enum {
    GLB_CHIP_CLK_OUT_1_CAM_REF_CLK = 0,   /*!< no chip clock out */
    GLB_CHIP_CLK_OUT_1_I2S_REF_CLK = 1,   /*!< i2s_ref_clk out */
    GLB_CHIP_CLK_OUT_1_CLK_AUDIO_ADC = 2, /*!< clk_adc_in_128fs */
    GLB_CHIP_CLK_OUT_1_CLK_AUDIO_DAC = 3, /*!< clk_dac_in_128fs */
} GLB_CHIP_CLK_OUT_1_Type;

/**
 *  @brief GLB chip clock out 2 type definition
 */
typedef enum {
    GLB_CHIP_CLK_OUT_2_CAM_REF_CLK = 0,  /*!< cam_ref_clk */
    GLB_CHIP_CLK_OUT_2_I2S_REF_CLK = 1,  /*!< i2s_ref_clk */
    GLB_CHIP_CLK_OUT_2_ANA_XTAL_CLK = 2, /*!< ana_xtal_clk */
    GLB_CHIP_CLK_OUT_2_PLL_32M_CLK = 3,  /*!< pll_32m_clk */
} GLB_CHIP_CLK_OUT_2_Type;

/**
 *  @brief GLB chip clock out 3 type definition
 */
typedef enum {
    GLB_CHIP_CLK_OUT_3_CAM_REF_CLK = 0, /*!< no chip clock out */
    GLB_CHIP_CLK_OUT_3_I2S_REF_CLK = 1, /*!< i2s_ref_clk out */
    GLB_CHIP_CLK_OUT_3_NONE = 2,        /*!< no clock out */
    GLB_CHIP_CLK_OUT_3_PLL_48M_CLK = 3, /*!< pll_48m_clk */
} GLB_CHIP_CLK_OUT_3_Type;

/**
 *  @brief GLB CSI DSI clock source select type definition
 */
typedef enum {
    GLB_CSI_DSI_CLK_SEL_XTAL_CLK,     /*!< xtal_clk */
    GLB_CSI_DSI_CLK_SEL_CPUPLL_DIV10, /*!< cpupll_div10 */
} GLB_CSI_DSI_CLK_SEL_Type;

/**
 *  @brief GLB DIG clock source select type definition
 */
typedef enum {
    GLB_DIG_CLK_WIFIPLL_32M, /*!< select WIFIPLL 32M as DIG clock source */
    GLB_DIG_CLK_XCLK,        /*!< select XCLK as DIG clock source */
    GLB_DIG_CLK_AUPLL,       /*!< select AUPLL as DIG clock source */
} GLB_DIG_CLK_Type;

/**
 *  @brief GLB 512K clock out select type definition
 */
typedef enum {
    GLB_512K_CLK_OUT_512K, /*!< select 512K clock out */
    GLB_512K_CLK_OUT_256K, /*!< select 256K clock out */
    GLB_512K_CLK_OUT_128K, /*!< select 128K clock out */
} GLB_512K_CLK_OUT_Type;

/**
 *  @brief GLB BT bandwidth type definition
 */
typedef enum {
    GLB_BT_BANDWIDTH_1M, /*!< BT bandwidth 1MHz */
    GLB_BT_BANDWIDTH_2M, /*!< BT bandwidth 2MHz */
} GLB_BT_BANDWIDTH_Type;

/**
 *  @brief GLB UART2 IO selection type definition
 */
typedef enum {
    GLB_UART2_IO_SEL_UART2,    /*!< Select UART2 function */
    GLB_UART2_IO_SEL_ISO11898, /*!< Select ISO11898 function */
} GLB_UART2_IO_SEL_Type;

/**
 *  @brief GLB UART signal type definition
 */
typedef enum {
    GLB_UART_SIG_0,  /*!< UART signal 0 */
    GLB_UART_SIG_1,  /*!< UART signal 1 */
    GLB_UART_SIG_2,  /*!< UART signal 2 */
    GLB_UART_SIG_3,  /*!< UART signal 3 */
    GLB_UART_SIG_4,  /*!< UART signal 4 */
    GLB_UART_SIG_5,  /*!< UART signal 5 */
    GLB_UART_SIG_6,  /*!< UART signal 6 */
    GLB_UART_SIG_7,  /*!< UART signal 7 */
    GLB_UART_SIG_8,  /*!< UART signal 8 */
    GLB_UART_SIG_9,  /*!< UART signal 9 */
    GLB_UART_SIG_10, /*!< UART signal 10 */
    GLB_UART_SIG_11, /*!< UART signal 11 */
} GLB_UART_SIG_Type;

/**
 *  @brief GLB UART signal  function type definition
 */
typedef enum {
    GLB_UART_SIG_FUN_UART0_RTS, /*!< UART funtion: UART 0 RTS */
    GLB_UART_SIG_FUN_UART0_CTS, /*!< UART funtion: UART 0 CTS */
    GLB_UART_SIG_FUN_UART0_TXD, /*!< UART funtion: UART 0 TXD */
    GLB_UART_SIG_FUN_UART0_RXD, /*!< UART funtion: UART 0 RXD */
    GLB_UART_SIG_FUN_UART1_RTS, /*!< UART funtion: UART 1 RTS */
    GLB_UART_SIG_FUN_UART1_CTS, /*!< UART funtion: UART 1 CTS */
    GLB_UART_SIG_FUN_UART1_TXD, /*!< UART funtion: UART 1 TXD */
    GLB_UART_SIG_FUN_UART1_RXD, /*!< UART funtion: UART 1 RXD */
    GLB_UART_SIG_FUN_UART2_RTS, /*!< UART funtion: UART 2 RTS */
    GLB_UART_SIG_FUN_UART2_CTS, /*!< UART funtion: UART 2 CTS */
    GLB_UART_SIG_FUN_UART2_TXD, /*!< UART funtion: UART 2 TXD */
    GLB_UART_SIG_FUN_UART2_RXD, /*!< UART funtion: UART 2 RXD */
} GLB_UART_SIG_FUN_Type;

/**
 *  @brief XTAL type definition
 */
typedef enum {
    GLB_XTAL_NONE,  /*!< XTAL is none */
    GLB_XTAL_24M,   /*!< XTAL is 24M */
    GLB_XTAL_32M,   /*!< XTAL is 32M */
    GLB_XTAL_38P4M, /*!< XTAL is 38.4M */
    GLB_XTAL_40M,   /*!< XTAL is 40M */
    GLB_XTAL_26M,   /*!< XTAL is 26M */
    GLB_XTAL_RC32M, /*!< XTAL is RC32M */
    GLB_XTAL_MAX,   /*!< type max num */
} GLB_XTAL_Type;

/**
 *  @brief PLL power on type definition
 */
typedef enum {
    GLB_PLL_NONE = 0,    /*!< power on xtal and pll */
    GLB_PLL_WIFIPLL = 1, /*!< power on WIFIPLL */
    GLB_PLL_AUPLL = 2,   /*!< power on AUPLL */
    GLB_PLL_CPUPLL = 4,  /*!< power on CPUPLL */
    GLB_PLL_MIPIPLL = 8, /*!< power on ETHPLL */
    GLB_PLL_UHSPLL = 16, /*!< power on ETHPLL */
} GLB_PLL_Type;

/**
 *  @brief WAC PLL XTAL type definition
 */
typedef enum {
    GLB_WAC_PLL_WIFIPLL, /*!< wifi pll */
    GLB_WAC_PLL_AUPLL,   /*!< audio pll */
    GLB_WAC_PLL_CPUPLL,  /*!< cpu pll */
} GLB_WAC_PLL_Type;

/**
 *  @brief MU PLL XTAL type definition
 */
typedef enum {
    GLB_MU_PLL_MIPIPLL, /*!< mipi pll */
    GLB_MU_PLL_UHSPLL,  /*!< uhs pll */
} GLB_MU_PLL_Type;

/**
 *  @brief DISP clock type definition
 */
typedef enum {
    GLB_DISP_CLK_MIPIPLL_1500M, /*!< mipi pll 1500M */
} GLB_DISP_CLK_Type;

/**
 *  @brief PLL XTAL type definition
 */
typedef enum {
    GLB_PSRAM_EMI_CPUPLL_400M,  /*!< emi_cpupll_400m_clk */
    GLB_PSRAM_EMI_WIFIPLL_320M, /*!< emi_wifipll_320m_clk */
    GLB_PSRAM_EMI_AUPLL_DIV1,   /*!< emi_aupll_div1_clk */
} GLB_PSRAM_PLL_Type;

/**
 *  @brief GLB DSP xclk clock type definition
 */
typedef enum {
    GLB_DSP_XCLK_RC32M, /*!< use RC32M as xclk clock */
    GLB_DSP_XCLK_XTAL,  /*!< use XTAL as xclk clock */
} GLB_DSP_XCLK_Type;

/**
 *  @brief GLB DSP root clock type definition
 */
typedef enum {
    GLB_DSP_ROOT_CLK_XCLK, /*!< use XCLK as root clock */
    GLB_DSP_ROOT_CLK_PLL,  /*!< use PLL as root clock */
} GLB_DSP_ROOT_CLK_Type;

/**
 *  @brief GLB DSP pbroot clock type definition
 */
typedef enum {
    GLB_DSP_PBROOT_CLK_MM_XCLK,        /*!< use mm_xclk as pbroot clock */
    GLB_DSP_PBROOT_CLK_MM_MUXPLL_160M, /*!< use mm_muxpll_160m_clk as pbroot clock */
    GLB_DSP_PBROOT_CLK_MM_MUXPLL_240M, /*!< use mm_muxpll_240m_clk as pbroot clock */
} GLB_DSP_PBROOT_CLK_Type;

/**
 *  @brief GLB DSP PLL clock type definition
 */
typedef enum {
    GLB_DSP_PLL_CLK_MUXPLL_240M, /*!< select DSP PLL output muxpll 240m as cpu clock */
    GLB_DSP_PLL_CLK_MUXPLL_320M, /*!< select DSP PLL output muxpll 320m as cpu clock */
    GLB_DSP_PLL_CLK_CPUPLL_400M, /*!< select DSP PLL output cpupll 400m as cpu clock */
} GLB_DSP_PLL_CLK_Type;

/**
 *  @brief GLB DSP UART clock type definition
 */
typedef enum {
    GLB_DSP_UART_CLK_DSP_PBCLK,   /*!< Select dsp pbclk as UART clock */
    GLB_DSP_UART_CLK_MUXPLL_160M, /*!< Select muxpll 160m as UART clock */
    GLB_DSP_UART_CLK_DSP_XCLK,    /*!< Select xclk as UART clock */
} GLB_DSP_UART_CLK_Type;

/**
 *  @brief GLB UART clock type definition
 */
typedef enum {
    GLB_UART_CLK_BCLK,     /*!< Select bclk clock as UART clock */
    GLB_UART_CLK_PLL_160M, /*!< Select PLL 160M as UART clock */
} GLB_UART_CLK_Type;

/**
 *  @brief GLB DSP CNN clock type definition
 */
typedef enum {
    GLB_DSP_CNN_CLK_160M, /*!< Select 160M as CNN clock */
    GLB_DSP_CNN_CLK_240M, /*!< Select 240M as CNN clock */
    GLB_DSP_CNN_CLK_320M, /*!< Select 320M as CNN clock */
} GLB_DSP_CNN_CLK_Type;

/**
 *  @brief GLB DSP DP clock type definition
 */
typedef enum {
    GLB_DSP_DP_CLK_DISPLAY_PLL, /*!< Select display pll as DP clock */
    GLB_DSP_DP_CLK_DSP_XCLK,    /*!< Select mm xclk as DP clock */
} GLB_DSP_DP_CLK_Type;

/**
 *  @brief GLB DSP SPP clock type definition
 */
typedef enum {
    GLB_DSP_SPP_CLK_MUXPLL_160M, /*!< Select muxpll 160M as SPP clock */
    GLB_DSP_SPP_CLK_MUXPLL_240M, /*!< Select muxpll 240M as SPP clock */
    GLB_DSP_SPP_CLK_CPUPLL_400M, /*!< Select cpupll 400M as SPP clock */
    GLB_DSP_SPP_CLK_DSP_XCLK,    /*!< Select dsp xclk as SPP clock */
} GLB_DSP_SPP_CLK_Type;

/**
 *  @brief GLB DSP H264 clock type definition
 */
typedef enum {
    GLB_DSP_H264_DSP_MUXPLL_160M, /*!< Select dsp muxpll 160M as SPP clock */
    GLB_DSP_H264_DSP_MUXPLL_240M, /*!< Select dsp muxpll 240M as SPP clock */
    GLB_DSP_H264_DSP_MUXPLL_320M, /*!< Select dsp muxpll 320M as SPP clock */
} GLB_DSP_H264_CLK_Type;

/**
 *  @brief GLB DSP SPI clock type definition
 */
typedef enum {
    GLB_DSP_SPI_CLK_DSP_MUXPLL_160M, /*!< Select muxpll 160M as SPI clock */
    GLB_DSP_SPI_CLK_DSP_XCLK,        /*!< Select xclk as SPI clock */
} GLB_DSP_SPI_CLK_Type;

/**
 *  @brief GLB DSP I2C clock type definition
 */
typedef enum {
    GLB_DSP_I2C_CLK_DSP_PBCLK, /*!< Select dsp pbclk as I2C clock */
    GLB_DSP_I2C_CLK_XCLK,      /*!< Select xclk as I2C clock */
} GLB_DSP_I2C_CLK_Type;

/**
 *  @brief GLB I2S di ref clock type definition
 */
typedef enum {
    GLB_I2S_DI_SEL_I2S_DI_INPUT,   /*!< Select i2s_di input */
    GLB_I2S_DI_SEL_I2S_REF_OUTPUT, /*!< Select i2s_ref_clk output */
} GLB_I2S_DI_REF_CLK_Type;

/**
 *  @brief GLB I2S do ref clock type definition
 */
typedef enum {
    GLB_I2S_DO_SEL_I2S_DO_OUTPT,   /*!< Select i2s_do output */
    GLB_I2S_DO_SEL_I2S_REF_OUTPUT, /*!< Select i2s_ref_clk output */
} GLB_I2S_DO_REF_CLK_Type;

/**
 *  @brief GLB EMI clock type definition
 */
typedef enum {
    GLB_EMI_CLK_MCU_PBCLK,        /*!< mcu_pbclk */
    GLB_EMI_CLK_CPUPLL_200M_CLK,  /*!< cpupll_200m_clk */
    GLB_EMI_CLK_WIFIPLL_320M_CLK, /*!< wifipll_320m_clk */
    GLB_EMI_CLK_CPUPLL_400M_CLK,  /*!< cpupll_400m_clk */
} GLB_EMI_CLK_Type;

/**
 *  @brief GLB DSP sw system type definition
 */
typedef enum {
    GLB_DSP_SW_SYSTEM_CTRL_SYS = 0,    /*!< SW system reset(pulse trigger) */
    GLB_DSP_SW_SYSTEM_CTRL_PWRON = 2,  /*!< SW power-on reset (pulse trigger) */
    GLB_DSP_SW_SYSTEM_CTRL_DSP0 = 8,   /*!< MMCPU0 reset(pulse trigger) */
    GLB_DSP_SW_SYSTEM_CTRL_DSP1 = 9,   /*!< MMCPU1 reset(pulse trigger) */
    GLB_DSP_SW_SYSTEM_CTRL_WL2MM = 15, /*!< wl2mm */
} GLB_DSP_SW_SYSTEM_Type;

/**
 *  @brief GLB DSP peripheral type definition
 */
typedef enum {
    GLB_DSP_PERIPHERAL_MM_MISC = 0, /*!< mm_misc */
    GLB_DSP_PERIPHERAL_DMA = 1,     /*!< dma */
    GLB_DSP_PERIPHERAL_UART0 = 2,   /*!< uart0 */
    GLB_DSP_PERIPHERAL_I2C0 = 3,    /*!< i2c0 */
    GLB_DSP_PERIPHERAL_IPC = 5,     /*!< ipc */
    GLB_DSP_PERIPHERAL_SPI = 8,     /*!< spi */
    GLB_DSP_PERIPHERAL_TIMER = 9,   /*!< timer */
    GLB_DSP_PERIPHERAL_I2S0 = 10,   /*!< i2s0 */
} GLB_DSP_PERIPHERAL_Type;

/**
 *  @brief GLB DSP spp sub type definition
 */
typedef enum {
    GLB_DSP_SPP_SUB_SPP_MISC = 0, /*!< spp_misc */
    GLB_DSP_SPP_SUB_DVP2BUSA = 1, /*!< dvp2busA */
    GLB_DSP_SPP_SUB_DVP2BUSB = 2, /*!< dvp2busB */
    GLB_DSP_SPP_SUB_DVP2BUSC = 3, /*!< dvp2busC */
    GLB_DSP_SPP_SUB_OSD_DRAW = 4, /*!< osd_draw */
    GLB_DSP_SPP_SUB_DP = 5,       /*!< dspplay */
    GLB_DSP_SPP_SUB_IMG_PR = 16,  /*!< img_pr scaler/yuv2rgb */
    GLB_DSP_SPP_SUB_SCLRA = 17,   /*!< ScalerA */
    GLB_DSP_SPP_SUB_SCLRB = 18,   /*!< ScalerB */
} GLB_DSP_SPP_SUB_Type;

/**
 *  @brief GLB DSP codec sub type definition
 */
typedef enum {
    GLB_DSP_CODEC_SUB_MJPEG = 1, /*!< mjpeg */
    GLB_DSP_CODEC_SUB_CNN = 2,   /*!< BLAI */
    GLB_DSP_CODEC_SUB_VRAM = 16, /*!< vram control logic(SRAM content would not be reset) */
} GLB_DSP_CODEC_SUB_Type;

/**
 *  @brief GLB DSP image sensor type definition
 */
typedef enum {
    GLB_DSP_IMAGE_SENSOR_RG_IS = 1, /*!< Image sensor */
} GLB_DSP_IMAGE_SENSOR_Type;

/**
 *  @brief GLB LDO15CIS level type definition
 */
typedef enum {
    GLB_LDO15CIS_LEVEL_1P00V = 0,  /*!< GLB LDO15CIS voltage 1.00V */
    GLB_LDO15CIS_LEVEL_1P05V = 1,  /*!< GLB LDO15CIS voltage 1.05V */
    GLB_LDO15CIS_LEVEL_1P10V = 2,  /*!< GLB LDO15CIS voltage 1.10V */
    GLB_LDO15CIS_LEVEL_1P15V = 3,  /*!< GLB LDO15CIS voltage 1.15V */
    GLB_LDO15CIS_LEVEL_1P20V = 4,  /*!< GLB LDO15CIS voltage 1.20V */
    GLB_LDO15CIS_LEVEL_1P30V = 5,  /*!< GLB LDO15CIS voltage 1.30V */
    GLB_LDO15CIS_LEVEL_1P40V = 6,  /*!< GLB LDO15CIS voltage 1.40V */
    GLB_LDO15CIS_LEVEL_1P45V = 7,  /*!< GLB LDO15CIS voltage 1.45V */
    GLB_LDO15CIS_LEVEL_1P50V = 8,  /*!< GLB LDO15CIS voltage 1.50V */
    GLB_LDO15CIS_LEVEL_1P55V = 9,  /*!< GLB LDO15CIS voltage 1.55V */
    GLB_LDO15CIS_LEVEL_1P60V = 10, /*!< GLB LDO15CIS voltage 1.60V */
    GLB_LDO15CIS_LEVEL_1P65V = 11, /*!< GLB LDO15CIS voltage 1.65V */
    GLB_LDO15CIS_LEVEL_1P70V = 12, /*!< GLB LDO15CIS voltage 1.70V */
    GLB_LDO15CIS_LEVEL_1P75V = 13, /*!< GLB LDO15CIS voltage 1.75V */
    GLB_LDO15CIS_LEVEL_1P80V = 14, /*!< GLB LDO15CIS voltage 1.80V */
    GLB_LDO15CIS_LEVEL_1P85V = 15, /*!< GLB LDO15CIS voltage 1.85V */
} GLB_LDO15CIS_LEVEL_Type;

#endif