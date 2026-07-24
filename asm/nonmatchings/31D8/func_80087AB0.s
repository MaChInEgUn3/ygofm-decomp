/* Handwritten function */
nonmatching func_80087AB0, 0x7C

glabel func_80087AB0
    /* 782B0 80087AB0 000080C8 */  lwc2       $0, 0x0($a0)
    /* 782B4 80087AB4 040081C8 */  lwc2       $1, 0x4($a0)
    /* 782B8 80087AB8 0000A2C8 */  lwc2       $2, 0x0($a1)
    /* 782BC 80087ABC 0400A3C8 */  lwc2       $3, 0x4($a1)
    /* 782C0 80087AC0 0000C4C8 */  lwc2       $4, 0x0($a2)
    /* 782C4 80087AC4 0400C5C8 */  lwc2       $5, 0x4($a2)
    /* 782C8 80087AC8 00000000 */  nop
    /* 782CC 80087ACC 3000284A */  rtpt
    /* 782D0 80087AD0 1000A88F */  lw         $t0, 0x10($sp)
    /* 782D4 80087AD4 1400A98F */  lw         $t1, 0x14($sp)
    /* 782D8 80087AD8 1800AA8F */  lw         $t2, 0x18($sp)
    /* 782DC 80087ADC 00000CE9 */  swc2       $12, 0x0($t0)
    /* 782E0 80087AE0 00002DE9 */  swc2       $13, 0x0($t1)
    /* 782E4 80087AE4 00004EE9 */  swc2       $14, 0x0($t2)
    /* 782E8 80087AE8 00F84348 */  cfc2       $v1, $31 /* handwritten instruction */
    /* 782EC 80087AEC 0000E0C8 */  lwc2       $0, 0x0($a3)
    /* 782F0 80087AF0 0400E1C8 */  lwc2       $1, 0x4($a3)
    /* 782F4 80087AF4 00000000 */  nop
    /* 782F8 80087AF8 0100184A */  rtps
    /* 782FC 80087AFC 1C00A88F */  lw         $t0, 0x1C($sp)
    /* 78300 80087B00 2000A98F */  lw         $t1, 0x20($sp)
    /* 78304 80087B04 2400AA8F */  lw         $t2, 0x24($sp)
    /* 78308 80087B08 00000EE9 */  swc2       $14, 0x0($t0)
    /* 7830C 80087B0C 00F84848 */  cfc2       $t0, $31 /* handwritten instruction */
    /* 78310 80087B10 000028E9 */  swc2       $8, 0x0($t1)
    /* 78314 80087B14 25400301 */  or         $t0, $t0, $v1
    /* 78318 80087B18 000048AD */  sw         $t0, 0x0($t2)
    /* 7831C 80087B1C 2E00684B */  avsz4
    /* 78320 80087B20 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 78324 80087B24 0800E003 */  jr         $ra
    /* 78328 80087B28 00000000 */   nop
endlabel func_80087AB0
    /* 7832C 80087B2C 00000000 */  nop
