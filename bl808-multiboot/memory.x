MEMORY
{
    FLASH     : ORIGIN = 0x58000000, LENGTH = 8K
    FLASH_LP     : ORIGIN = 0x58002000, LENGTH = 8K
    FLASH_D0     : ORIGIN = 0x58004000, LENGTH = 8K
    RAM       : ORIGIN = 0x22024000, LENGTH = 4K
}

EXTERN(D0_FIRMWARE)

SECTIONS {
    /* d0 firmware */
    .d0 ORIGIN(FLASH_D0) :
    {
        KEEP(*(.d0));
    } > FLASH_D0
};

REGION_ALIAS("REGION_TEXT", FLASH);
REGION_ALIAS("REGION_RODATA", FLASH);
REGION_ALIAS("REGION_DATA", RAM);
REGION_ALIAS("REGION_BSS", RAM);
REGION_ALIAS("REGION_HEAP", RAM);
REGION_ALIAS("REGION_STACK", RAM);
