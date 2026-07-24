nonmatching func_8003D2B8, 0x48

glabel func_8003D2B8
    /* 2DAB8 8003D2B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DABC 8003D2BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2DAC0 8003D2C0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2DAC4 8003D2C4 A2F4000C */  jal        func_8003D288
    /* 2DAC8 8003D2C8 2180A000 */   addu      $s0, $a1, $zero
    /* 2DACC 8003D2CC 07004010 */  beqz       $v0, .L8003D2EC
    /* 2DAD0 8003D2D0 00000000 */   nop
    /* 2DAD4 8003D2D4 B004828F */  lw         $v0, %gp_rel(D_8009B3B8)($gp)
    /* 2DAD8 8003D2D8 0404038E */  lw         $v1, 0x404($s0)
    /* 2DADC 8003D2DC 00000000 */  nop
    /* 2DAE0 8003D2E0 26104300 */  xor        $v0, $v0, $v1
    /* 2DAE4 8003D2E4 BCF40008 */  j          .L8003D2F0
    /* 2DAE8 8003D2E8 0100422C */   sltiu     $v0, $v0, 0x1
  .L8003D2EC:
    /* 2DAEC 8003D2EC 21100000 */  addu       $v0, $zero, $zero
  .L8003D2F0:
    /* 2DAF0 8003D2F0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2DAF4 8003D2F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DAF8 8003D2F8 0800E003 */  jr         $ra
    /* 2DAFC 8003D2FC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003D2B8
