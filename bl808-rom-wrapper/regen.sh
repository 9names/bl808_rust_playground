#!/bin/sh
bindgen c_defines/bl808_glb.h --use-core --default-enum-style rust -- --target=riscv32-unknown-none-elf > src/types/bl808_glb.rs
bindgen c_defines/bl808_pds.h --use-core --default-enum-style rust -- --target=riscv32-unknown-none-elf > src/types/bl808_pds.rs
bindgen c_defines/bl808_ef_ctrl.h --use-core --default-enum-style rust -- --target=riscv32-unknown-none-elf > src/types/bl808_ef_ctrl.rs
bindgen c_defines/bl808_aon.h --use-core --default-enum-style rust -- --target=riscv32-unknown-none-elf > src/types/bl808_aon.rs
bindgen c_defines/bl808_glb_gpio.h --use-core --default-enum-style rust -- --target=riscv32-unknown-none-elf > src/types/bl808_glb_gpio.rs
bindgen c_defines/misc.h --use-core --default-enum-style rust -- --target=riscv32-unknown-none-elf > src/types/misc.rs
# This is included through bl808_pds (PDS_APP_CFG_Type struct contains a pointer to SPI_Flash_Cfg_Type)
# bindgen c_defines/bl808_sflash.h --use-core --default-enum-style rust > src/types/bl808_sflash.rs