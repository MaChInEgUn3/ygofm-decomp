nonmatching func_8002CD8C, 0x5C

glabel func_8002CD8C
    /* 1D58C 8002CD8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D590 8002CD90 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1D594 8002CD94 0A80013C */  lui        $at, %hi(D_8009B0C0)
    /* 1D598 8002CD98 C0B020A0 */  sb         $zero, %lo(D_8009B0C0)($at)
    /* 1D59C 8002CD9C FC00010C */  jal        func_800403F0
    /* 1D5A0 8002CDA0 00000000 */   nop
    /* 1D5A4 8002CDA4 99D6000C */  jal        func_80035A64
    /* 1D5A8 8002CDA8 00000000 */   nop
    /* 1D5AC 8002CDAC A7E7000C */  jal        func_80039E9C
    /* 1D5B0 8002CDB0 00000000 */   nop
    /* 1D5B4 8002CDB4 2D4D000C */  jal        func_800134B4
    /* 1D5B8 8002CDB8 00000000 */   nop
    /* 1D5BC 8002CDBC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D5C0 8002CDC0 18000224 */  addiu      $v0, $zero, 0x18
    /* 1D5C4 8002CDC4 0A80013C */  lui        $at, %hi(D_8009B39C)
    /* 1D5C8 8002CDC8 9CB322A0 */  sb         $v0, %lo(D_8009B39C)($at)
    /* 1D5CC 8002CDCC 14000224 */  addiu      $v0, $zero, 0x14
    /* 1D5D0 8002CDD0 0A80013C */  lui        $at, %hi(D_8009B254)
    /* 1D5D4 8002CDD4 54B220A0 */  sb         $zero, %lo(D_8009B254)($at)
    /* 1D5D8 8002CDD8 0A80013C */  lui        $at, %hi(D_8009B3A2)
    /* 1D5DC 8002CDDC A2B322A0 */  sb         $v0, %lo(D_8009B3A2)($at)
    /* 1D5E0 8002CDE0 0800E003 */  jr         $ra
    /* 1D5E4 8002CDE4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002CD8C
