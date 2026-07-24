nonmatching func_8007F9D8, 0x60

glabel func_8007F9D8
    /* 701D8 8007F9D8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 701DC 8007F9DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 701E0 8007F9E0 21808000 */  addu       $s0, $a0, $zero
    /* 701E4 8007F9E4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 701E8 8007F9E8 2188A000 */  addu       $s1, $a1, $zero
    /* 701EC 8007F9EC 0180043C */  lui        $a0, %hi(D_80012280)
    /* 701F0 8007F9F0 80228424 */  addiu      $a0, $a0, %lo(D_80012280)
    /* 701F4 8007F9F4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 701F8 8007F9F8 CDFD010C */  jal        func_8007F734
    /* 701FC 8007F9FC 21280002 */   addu      $a1, $s0, $zero
    /* 70200 8007FA00 21280002 */  addu       $a1, $s0, $zero
    /* 70204 8007FA04 0980023C */  lui        $v0, %hi(D_80094660)
    /* 70208 8007FA08 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 7020C 8007FA0C 08000624 */  addiu      $a2, $zero, 0x8
    /* 70210 8007FA10 1C00448C */  lw         $a0, 0x1C($v0)
    /* 70214 8007FA14 0800428C */  lw         $v0, 0x8($v0)
    /* 70218 8007FA18 00000000 */  nop
    /* 7021C 8007FA1C 09F84000 */  jalr       $v0
    /* 70220 8007FA20 21382002 */   addu      $a3, $s1, $zero
    /* 70224 8007FA24 1800BF8F */  lw         $ra, 0x18($sp)
    /* 70228 8007FA28 1400B18F */  lw         $s1, 0x14($sp)
    /* 7022C 8007FA2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 70230 8007FA30 0800E003 */  jr         $ra
    /* 70234 8007FA34 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007F9D8
