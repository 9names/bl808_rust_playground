struct glb_reg {
    /* 0x0 : soc_info0 */
    union {
        struct {
            uint32_t reserved_0_26 : 27; /* [26: 0],       rsvd,        0x0 */
            uint32_t chip_rdy      : 1;  /* [   27],          r,        0x0 */
            uint32_t glb_id        : 4;  /* [31:28],          r,        0x6 */
        } BF;
        uint32_t WORD;
    } soc_info0;

    /* 0x4  reserved */
    uint8_t RESERVED0x4[76];

    /* 0x50 : core_cfg16 */
    union {
        struct {
            uint32_t np_int_sta0 : 32; /* [31: 0],          r,        0x0 */
        } BF;
        uint32_t WORD;
    } core_cfg16;
};

typedef volatile struct glb_reg glb_reg_t;
