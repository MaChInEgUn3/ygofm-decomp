nonmatching func_800599FC, 0x54

glabel func_800599FC
    /* 4A1FC 800599FC B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 4A200 80059A00 21408000 */  addu       $t0, $a0, $zero
    /* 4A204 80059A04 2148A000 */  addu       $t1, $a1, $zero
    /* 4A208 80059A08 2150C000 */  addu       $t2, $a2, $zero
    /* 4A20C 80059A0C 21280001 */  addu       $a1, $t0, $zero
    /* 4A210 80059A10 5800A28F */  lw         $v0, 0x58($sp)
    /* 4A214 80059A14 5C00A38F */  lw         $v1, 0x5C($sp)
    /* 4A218 80059A18 6000A48F */  lw         $a0, 0x60($sp)
    /* 4A21C 80059A1C 21302001 */  addu       $a2, $t1, $zero
    /* 4A220 80059A20 1000A7AF */  sw         $a3, 0x10($sp)
    /* 4A224 80059A24 21384001 */  addu       $a3, $t2, $zero
    /* 4A228 80059A28 4000BFAF */  sw         $ra, 0x40($sp)
    /* 4A22C 80059A2C 1C00A4AF */  sw         $a0, 0x1C($sp)
    /* 4A230 80059A30 2000A427 */  addiu      $a0, $sp, 0x20
    /* 4A234 80059A34 1400A2AF */  sw         $v0, 0x14($sp)
    /* 4A238 80059A38 D362010C */  jal        func_80058B4C
    /* 4A23C 80059A3C 1800A3AF */   sw        $v1, 0x18($sp)
    /* 4A240 80059A40 4000BF8F */  lw         $ra, 0x40($sp)
    /* 4A244 80059A44 00000000 */  nop
    /* 4A248 80059A48 0800E003 */  jr         $ra
    /* 4A24C 80059A4C 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_800599FC
