nonmatching func_800771B0, 0x5C

glabel func_800771B0
    /* 679B0 800771B0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 679B4 800771B4 21288000 */  addu       $a1, $a0, $zero
    /* 679B8 800771B8 0700023C */  lui        $v0, (0x7EFE8 >> 16)
    /* 679BC 800771BC E8EF4234 */  ori        $v0, $v0, (0x7EFE8 & 0xFFFF)
    /* 679C0 800771C0 F0EFA324 */  addiu      $v1, $a1, -0x1010
    /* 679C4 800771C4 2B104300 */  sltu       $v0, $v0, $v1
    /* 679C8 800771C8 0B004014 */  bnez       $v0, .L800771F8
    /* 679CC 800771CC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 679D0 800771D0 4CD6010C */  jal        func_80075930
    /* 679D4 800771D4 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 679D8 800771D8 0980013C */  lui        $at, %hi(D_80092BA0)
    /* 679DC 800771DC A02B22A4 */  sh         $v0, %lo(D_80092BA0)($at)
    /* 679E0 800771E0 0980033C */  lui        $v1, %hi(D_80092BA0)
    /* 679E4 800771E4 A02B6394 */  lhu        $v1, %lo(D_80092BA0)($v1)
    /* 679E8 800771E8 0980023C */  lui        $v0, %hi(D_80092BB0)
    /* 679EC 800771EC B02B428C */  lw         $v0, %lo(D_80092BB0)($v0)
    /* 679F0 800771F0 7FDC0108 */  j          .L800771FC
    /* 679F4 800771F4 04104300 */   sllv      $v0, $v1, $v0
  .L800771F8:
    /* 679F8 800771F8 21100000 */  addu       $v0, $zero, $zero
  .L800771FC:
    /* 679FC 800771FC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 67A00 80077200 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 67A04 80077204 0800E003 */  jr         $ra
    /* 67A08 80077208 00000000 */   nop
endlabel func_800771B0
    /* 67A0C 8007720C 00000000 */  nop
