/// Fragments of SVD taken from bl808-pac
/// Want to parse these but need to map them to scrape data first
/// so it's more expedient to encode them here.

pub const HEADER: &str = r#"<?xml version="1.0" encoding="utf-8"?>
<device schemaVersion="1.3" xmlns:xs="http://www.w3.org/2001/XMLSchema-instance" xs:noNamespaceSchemaLocation="CMSIS-SVD.xsd">
  <vendor>Bouffalo Lab</vendor>
  <vendorID>bouffalolab</vendorID>
  <name>BL808</name>
  <series></series> <!-- todo -->
  <version>1.0</version>
  <description>Bouffalo BL808 chip</description>
  <licenseText>
Copyright (c) 2022 Bouffalo Lab
bl808-pac is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details.
  </licenseText>
  <addressUnitBits>8</addressUnitBits>
  <width>64</width>
  <size>32</size>
  <access>read-write</access>
  <resetValue>0x00000000</resetValue>
  <resetMask>0xFFFFFFFF</resetMask>
  
  <peripherals>
"#;

pub const FOOTER: &str = r#"
</peripherals>
</device>"#;

// #define MIX_BASE         ((uint32_t)0x20001000)
// #define EF_CTRL_BASE     ((uint32_t)0x20056000)
// #define SF_CTRL_BUF_BASE ((uint32_t)0x2000b600)

// #define GLB_BASE         ((uint32_t)0x20000000)
pub const GLB: &str = r#"<name>GLB</name>
<description>Global configuration register</description>
<baseAddress>0x20000000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define GPIP_BASE        ((uint32_t)0x20002000)
pub const GPIP: &str = r#"<name>GPIP</name>
<description>Generic DAC, ADC and ACOMP interface control</description>
<baseAddress>0x20002000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x400</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define PHY_BASE         ((uint32_t)0x20002800)
pub const PHY: &str = r#""#;
// #define AGC_BASE         ((uint32_t)0x20002c00)
pub const AGC: &str = r#"<name>AGC</name>
<description>Automatic Gain Control</description>
<baseAddress>0x20002C00</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size> <!-- todo -->
  <usage>registers</usage>
</addressBlock>"#;

// #define SEC_DBG_BASE     ((uint32_t)0x20003000)
pub const SEC_DBG: &str = r#""#;

pub const DEBUG: &str = r#"<name>DEBUG</name>
<description>Secure debug configuration</description>
<baseAddress>0x20003000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;

// #define SEC_ENG_BASE     ((uint32_t)0x20004000)
pub const SEC_ENG: &str = r#"<name>SEC</name>
<description>Secure Engine</description>
<baseAddress>0x20004000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define TZ1_BASE         ((uint32_t)0x20005000)
pub const TZ1: &str = r#""#;
// #define TZC_SEC_BASE     ((uint32_t)0x20005000)
pub const TZC_SEC: &str = r#""#;
// #define TZ2_BASE         ((uint32_t)0x20006000)
pub const TZ2: &str = r#""#;
// #define TZC_NSEC_BASE    ((uint32_t)0x20006000)
pub const TZC_NSEC: &str = r#""#;
// #define EFUSE_BASE       ((uint32_t)0x20056000)
pub const EFUSE: &str = r#"      <name>EFUSE</name>
<description>eFuse memory control</description>
<baseAddress>0x20056000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;

// #define EF_DATA_BASE     ((uint32_t)0x20056000)
pub const EF_DATA: &str = r#""#;
// #define CCI_BASE         ((uint32_t)0x20008000)
pub const CCI: &str = r#"      <name>CCI</name>
<description>Camera Control Interface</description> <!-- todo verify -->
<baseAddress>0x20008000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define MCU_MISC_BASE    ((uint32_t)0x20009000)
pub const MCU_MISC: &str = r#"<name>MISC</name>
<description>Chip Miscellaneous control</description>
<baseAddress>0x20009000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define L1C_BASE         ((uint32_t)0x20009000)
pub const L1C: &str = r#""#;
// #define UART0_BASE       ((uint32_t)0x2000a000)
pub const UART0: &str = r#"<name>UART[%s]</name>
<dim>2</dim>
<dimIncrement>0x100</dimIncrement>
<description>Universal Asynchronous Receiver Transmitter</description>
<baseAddress>0x2000A000</baseAddress>
<access>read-write</access>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define UART1_BASE       ((uint32_t)0x2000a100)
pub const UART1: &str = r#""#;
// #define SPI0_BASE        ((uint32_t)0x2000a200)
pub const SPI0: &str = r#"<name>SPI[%s]</name>
<dim>1</dim>
<dimIncrement>0x100</dimIncrement>
<description>Serial Peripheral Interface</description>
<baseAddress>0x2000A200</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define I2C0_BASE        ((uint32_t)0x2000a300)
pub const I2C0: &str = r#"<name>I2C[%s]</name>
<dim>2</dim>
<dimIncrement>0x600</dimIncrement>
<description>Inter-Integrated Circuit bus</description>
<baseAddress>0x2000A300</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define PWM_BASE         ((uint32_t)0x2000a400)
pub const PWM: &str = r#"<name>PWM</name>
<description>Pulse-Width Modulation module</description>
<baseAddress>0x2000A400</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define TIMER0_BASE      ((uint32_t)0x2000a500)
pub const TIMER0: &str = r#"<name>TIMER</name>
<description>Timer control</description>
<baseAddress>0x2000A500</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define IR_BASE          ((uint32_t)0x2000a600)
pub const IR: &str = r#"      <name>IR</name>
<description>Infrared Remote module</description>
<baseAddress>0x2000A600</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define CKS_BASE         ((uint32_t)0x2000a700)
pub const CKS: &str = r#""#;
// #define IPC0_BASE        ((uint32_t)0x2000a800)
pub const IPC0: &str = r#"<name>IPC</name>
<description>Inter-processor Channel</description>
<baseAddress>0x2000A800</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define IPC1_BASE        ((uint32_t)0x2000a840)
pub const IPC1: &str = r#""#;
// #define I2C1_BASE        ((uint32_t)0x2000a900)
pub const I2C1: &str = r#""#;
// #define UART2_BASE       ((uint32_t)0x2000aa00)
pub const UART2: &str = r#""#;
// #define ISO11898_BASE    ((uint32_t)0x2000aa00)
pub const ISO11898: &str = r#"      <name>ISO11898</name>
<description>ISO 11898 communication protocol</description>
<baseAddress>0x2000AA00</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;

// #define I2S_BASE         ((uint32_t)0x2000ab00)
pub const I2S: &str = r#"<name>I2S</name>
<description>Inter-IC Sound controller</description>
<baseAddress>0x2000AB00</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define PDM0_BASE        ((uint32_t)0x2000a000)
pub const PDM0: &str = r#"<name>PDM</name>
<description>Pulse Density Modulation</description>
<baseAddress>0x2000AC00</baseAddress> <!-- todo: verify -->
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define LZ4D_BASE        ((uint32_t)0x2000ad00)
pub const LZ4D: &str = r#"<name>LZ4D</name>
<description>Hardware LZ4 Decompressor</description>
<baseAddress>0x2000AD00</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define QSPI_BASE        ((uint32_t)0x2000b000)
pub const QSPI: &str = r#""#;
// #define SF_CTRL        ((uint32_t)0x2000b000)
pub const SF_CTRL: &str = r#"<name>FLASH</name>
<description>Quad Serial Flash control</description>
<baseAddress>0x2000B000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define SF_CTRL_BASE     ((uint32_t)0x2000b000)
pub const SF_CTRL_BUF: &str = r#""#;
// #define DMA0_BASE        ((uint32_t)0x2000c000)
pub const DMA0: &str = r#"<name>DMA%s</name>
<dim>2</dim>
<dimIncrement>0x65000</dimIncrement>
<description>Direct Memory Access</description>
<baseAddress>0x2000C000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define DMA1_BASE        ((uint32_t)0x20071000)
pub const DMA1: &str = r#""#;

// #define PDS_BASE         ((uint32_t)0x2000e000)
pub const PDS: &str = r#""#;
// #define HBN_BASE         ((uint32_t)0x2000f000)
pub const HBN: &str = r#"<name>HBN</name>
<description>Hibernate (Deep sleep) control</description>
<baseAddress>0x2000F000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x800</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define AON_BASE         ((uint32_t)0x2000f000)
pub const AON: &str = r#"<name>AON</name>
<description>Always-On function control</description>
<baseAddress>0x2000F800</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x800</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define EMI_MISC_BASE    ((uint32_t)0x20050000)
pub const EMI_MISC: &str = r#""#;
// #define PSRAM_CTRL_BASE  ((uint32_t)0x20052000)
pub const PSRAM_CTRL: &str = r#"<name>PSRAM</name>
<description>Pseudo Static Random Access Memory control</description>
<baseAddress>0x20052000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x100</size>
  <usage>registers</usage>
</addressBlock>"#;

// #define USB_BASE         ((uint32_t)0x20072000)
pub const USB: &str = r#"<name>USB</name>
<description>Universal Serial Bus host</description>
<baseAddress>0x20072000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define AUDIO_BASE       ((uint32_t)0x20055000)
pub const AUDIO: &str = r#"<name>AUDIO</name>
<description>Audio codec controller</description>
<baseAddress>0x20055000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define SDH_BASE         ((uint32_t)0x20060000)
pub const SDH: &str = r#"<name>SDH</name>
<description>Secure Digital host control</description>
<baseAddress>0x20060000</baseAddress>
<!-- todo: sdk shows this peripheral is written by 16-bit register, confirm this -->
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
// #define EMAC_BASE        ((uint32_t)0x20070000)
pub const EMAC: &str = r#"<name>EMAC</name>
<description>Ethernet Media Access Control</description>
<baseAddress>0x20070000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;

// These aren't listed in bl808.h

pub const WIFI: &str = r#"<name>WIFI</name>
<description>Wireless Fidelity control</description>
<baseAddress>0x24B00000</baseAddress> <!-- todo: ?? -->
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;

pub const PTA: &str = r#"<name>PTA</name>
<description>Packet Traffic Arbitration</description>
<baseAddress>0x24920000</baseAddress> <!-- todo: ?? -->
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;

// These are in the 0x3 space so probably not MCU?

pub const _: &str = r#"<name>MMGLB</name>
<description>Multimedia Global controller</description>
<baseAddress>0x30007000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
pub const _: &str = r#"<name>NPU</name>
<description>Bouffalo Convolutional Neural Network</description>
<baseAddress>0x30024000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
pub const _: &str = r#"<name>H264</name>
<description>H.264 video codec control</description>
<baseAddress>0x30022000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
pub const _: &str = r#"<name>CODEC</name>
<description>Codec miscellaneous control</description>
<baseAddress>0x30020000</baseAddress>
<addressBlock>
  <offset>0</offset>
  <size>0x1000</size>
  <usage>registers</usage>
</addressBlock>"#;
pub const _: &str = r#""#;
pub const _: &str = r#""#;
pub const _: &str = r#""#;
pub const _: &str = r#""#;
