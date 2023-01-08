#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use crate::rom_table::constants::RomIndex;
use crate::rom_table::constants::ROM_APITABLE_ADDR;

// use num_enum::IntoPrimitive;
// #[allow(dead_code)]
// pub type ROM_API_INDEX_e = usize;

/// Lookup the address of ROM function offset in the ROM table
///
/// This doesn't do the actual lookup, since that needs to be done at runtime
/// using the actual table in flash.
/// Dereferenceing the returned pointer will yield the function pointer address
pub const fn rom_lookup_addr(index: RomIndex) -> *mut usize {
    let rom_function_table_index = ROM_APITABLE_ADDR + (index as usize * 4);
    rom_function_table_index as *mut usize
}

pub const fn rom_lookup_addr_u32(index: RomIndex) -> *const u32 {
    let rom_function_table_index = ROM_APITABLE_ADDR + (index as usize * 4);
    rom_function_table_index as *const u32
}

/// Return the function pointer to the specified ROM function
///
/// This function pointer still needs to be cast to the correct function signature
#[inline(always)]
pub fn rom_lookup(index: RomIndex) -> *const () {
    unsafe { rom_lookup_addr(index).read_volatile() as *const () }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn rom_address_offset() {
        assert_eq!(
            ROM_APITABLE_ADDR as *mut usize,
            rom_lookup_addr(RomIndex::ROM_API_INDEX_VERSION)
        );
        assert_eq!(
            (ROM_APITABLE_ADDR + 4) as *mut usize,
            rom_lookup_addr(RomIndex::ROM_API_INDEX_RSVD_0)
        );
        assert_eq!(
            (ROM_APITABLE_ADDR + 8) as *mut usize,
            rom_lookup_addr(RomIndex::ROM_API_INDEX_RSVD_1)
        );
    }
    // fn glb_get_core_type(xtal_src: u32) -> usize {
    //     let romdriver_glb_get_core_type = unsafe {
    //         core::mem::transmute::<*const (), extern "C" fn() -> usize>(rom_lookup(
    //             RomIndex::ROM_API_INDEX_GLB_Get_Core_Type,
    //         ))
    //     };

    //     romdriver_glb_get_core_type()
    // }
}
