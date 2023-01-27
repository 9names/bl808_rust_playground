MEMORY
{
    FLASH     : ORIGIN = 0xA0000000, LENGTH = 64M
    RAM       : ORIGIN = 0x62FC0000, LENGTH = 320K
}

REGION_ALIAS("REGION_TEXT", FLASH);
REGION_ALIAS("REGION_RODATA", FLASH);
REGION_ALIAS("REGION_DATA", RAM);
REGION_ALIAS("REGION_BSS", RAM);
REGION_ALIAS("REGION_HEAP", RAM);
REGION_ALIAS("REGION_STACK", RAM);