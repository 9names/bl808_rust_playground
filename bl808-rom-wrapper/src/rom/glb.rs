use crate::{
    rom_table::{constants::RomIndex, rom_lookup::rom_lookup},
    types::{bl808_glb::*, misc::BL_Err_Type},
};

pub fn halt_cpu(coreID: GLB_CORE_ID_Type) -> BL_Err_Type {
    let func = unsafe {
        core::mem::transmute::<*const (), extern "C" fn(GLB_CORE_ID_Type) -> BL_Err_Type>(
            rom_lookup(RomIndex::ROM_API_INDEX_GLB_Halt_CPU),
        )
    };
    func(coreID)
}

pub fn release_cpu(coreID: GLB_CORE_ID_Type) -> BL_Err_Type {
    let func = unsafe {
        core::mem::transmute::<*const (), extern "C" fn(GLB_CORE_ID_Type) -> BL_Err_Type>(
            rom_lookup(RomIndex::ROM_API_INDEX_GLB_Release_CPU),
        )
    };
    func(coreID)
}

pub fn set_cpu_reset_address(coreID: GLB_CORE_ID_Type, addr: u32) -> BL_Err_Type {
    let func = unsafe {
        core::mem::transmute::<*const (), extern "C" fn(GLB_CORE_ID_Type, u32) -> BL_Err_Type>(
            rom_lookup(RomIndex::ROM_API_INDEX_GLB_Set_CPU_Reset_Address),
        )
    };
    func(coreID, addr)
}

pub fn power_on_xtal_and_pll_clk(xtalType: GLB_XTAL_Type, pllType: GLB_PLL_Type) -> BL_Err_Type {
    let func = unsafe {
        core::mem::transmute::<*const (), extern "C" fn(GLB_XTAL_Type, GLB_PLL_Type) -> BL_Err_Type>(
            rom_lookup(RomIndex::ROM_API_INDEX_GLB_Power_On_XTAL_And_PLL_CLK),
        )
    };
    func(xtalType, pllType)
}

pub fn set_mcu_system_clk(clkFreq: GLB_MCU_SYS_CLK_Type) -> BL_Err_Type {
    let func = unsafe {
        core::mem::transmute::<*const (), extern "C" fn(GLB_MCU_SYS_CLK_Type) -> BL_Err_Type>(
            rom_lookup(RomIndex::ROM_API_INDEX_GLB_Set_MCU_System_CLK),
        )
    };
    func(clkFreq)
}

pub fn set_mcu_system_clk_div(mcuClkDiv: u8, mcuPBclkDiv: u8, lpClkDiv: u8) -> BL_Err_Type {
    let func = unsafe {
        core::mem::transmute::<*const (), extern "C" fn(u8, u8, u8) -> BL_Err_Type>(rom_lookup(
            RomIndex::ROM_API_INDEX_GLB_Set_MCU_System_CLK_Div,
        ))
    };
    func(mcuClkDiv, mcuPBclkDiv, lpClkDiv)
}

pub fn set_mcu_muxpll_160m_sel(clkSel: GLB_MCU_MUXPLL_160M_CLK_SEL_Type) -> BL_Err_Type {
    let func = unsafe {
        core::mem::transmute::<
            *const (),
            extern "C" fn(GLB_MCU_MUXPLL_160M_CLK_SEL_Type) -> BL_Err_Type,
        >(rom_lookup(
            RomIndex::ROM_API_INDEX_GLB_Set_MCU_Muxpll_160M_Sel,
        ))
    };
    func(clkSel)
}

pub fn set_mcu_muxpll_80m_sel(clkSel: GLB_MCU_MUXPLL_80M_CLK_SEL_Type) -> BL_Err_Type {
    let func = unsafe {
        core::mem::transmute::<
            *const (),
            extern "C" fn(GLB_MCU_MUXPLL_80M_CLK_SEL_Type) -> BL_Err_Type,
        >(rom_lookup(
            RomIndex::ROM_API_INDEX_GLB_Set_MCU_Muxpll_80M_Sel,
        ))
    };
    func(clkSel)
}

pub fn set_dsp_system_clk(clkFreq: GLB_DSP_SYS_CLK_Type) -> BL_Err_Type {
    let func = unsafe {
        core::mem::transmute::<*const (), extern "C" fn(GLB_DSP_SYS_CLK_Type) -> BL_Err_Type>(
            rom_lookup(RomIndex::ROM_API_INDEX_GLB_Set_DSP_System_CLK),
        )
    };
    func(clkFreq)
}
