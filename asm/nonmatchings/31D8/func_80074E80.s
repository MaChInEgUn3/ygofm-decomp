nonmatching func_80074E80, 0xE8

glabel func_80074E80
    /* 65680 80074E80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 65684 80074E84 1000B0AF */  sw         $s0, 0x10($sp)
    /* 65688 80074E88 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6568C 80074E8C E4D0010C */  jal        func_80074390
    /* 65690 80074E90 21808000 */   addu      $s0, $a0, $zero
    /* 65694 80074E94 F8D3010C */  jal        func_80074FE0
    /* 65698 80074E98 21200002 */   addu      $a0, $s0, $zero
    /* 6569C 80074E9C 08000016 */  bnez       $s0, .L80074EC0
    /* 656A0 80074EA0 00C00434 */   ori       $a0, $zero, 0xC000
    /* 656A4 80074EA4 17000324 */  addiu      $v1, $zero, 0x17
    /* 656A8 80074EA8 0980023C */  lui        $v0, %hi(D_80092B72)
    /* 656AC 80074EAC 722B4224 */  addiu      $v0, $v0, %lo(D_80092B72)
  .L80074EB0:
    /* 656B0 80074EB0 000044A4 */  sh         $a0, 0x0($v0)
    /* 656B4 80074EB4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 656B8 80074EB8 FDFF6104 */  bgez       $v1, .L80074EB0
    /* 656BC 80074EBC FEFF4224 */   addiu     $v0, $v0, -0x2
  .L80074EC0:
    /* 656C0 80074EC0 DAD3010C */  jal        func_80074F68
    /* 656C4 80074EC4 00000000 */   nop
    /* 656C8 80074EC8 D1000424 */  addiu      $a0, $zero, 0xD1
    /* 656CC 80074ECC 0980023C */  lui        $v0, %hi(D_80092B2C)
    /* 656D0 80074ED0 2C2B4224 */  addiu      $v0, $v0, %lo(D_80092B2C)
    /* 656D4 80074ED4 0980053C */  lui        $a1, %hi(D_80093118)
    /* 656D8 80074ED8 1831A58C */  lw         $a1, %lo(D_80093118)($a1)
    /* 656DC 80074EDC 0980013C */  lui        $at, %hi(D_80092B1C)
    /* 656E0 80074EE0 1C2B20AC */  sw         $zero, %lo(D_80092B1C)($at)
    /* 656E4 80074EE4 0980013C */  lui        $at, %hi(D_80092B20)
    /* 656E8 80074EE8 202B20AC */  sw         $zero, %lo(D_80092B20)($at)
    /* 656EC 80074EEC 000040AC */  sw         $zero, 0x0($v0)
    /* 656F0 80074EF0 040040A4 */  sh         $zero, 0x4($v0)
    /* 656F4 80074EF4 060040A4 */  sh         $zero, 0x6($v0)
    /* 656F8 80074EF8 080040AC */  sw         $zero, 0x8($v0)
    /* 656FC 80074EFC 0C0040AC */  sw         $zero, 0xC($v0)
    /* 65700 80074F00 0980013C */  lui        $at, %hi(D_80092B24)
    /* 65704 80074F04 242B25AC */  sw         $a1, %lo(D_80092B24)($at)
    /* 65708 80074F08 3BD6010C */  jal        func_800758EC
    /* 6570C 80074F0C 21300000 */   addu      $a2, $zero, $zero
    /* 65710 80074F10 0980013C */  lui        $at, %hi(D_80092BE8)
    /* 65714 80074F14 E82B20AC */  sw         $zero, %lo(D_80092BE8)($at)
    /* 65718 80074F18 0980013C */  lui        $at, %hi(D_80092BEC)
    /* 6571C 80074F1C EC2B20AC */  sw         $zero, %lo(D_80092BEC)($at)
    /* 65720 80074F20 0980013C */  lui        $at, %hi(D_80092BF0)
    /* 65724 80074F24 F02B20AC */  sw         $zero, %lo(D_80092BF0)($at)
    /* 65728 80074F28 0980013C */  lui        $at, %hi(D_80092B18)
    /* 6572C 80074F2C 182B20AC */  sw         $zero, %lo(D_80092B18)($at)
    /* 65730 80074F30 0980013C */  lui        $at, %hi(D_80092BA4)
    /* 65734 80074F34 A42B20AC */  sw         $zero, %lo(D_80092BA4)($at)
    /* 65738 80074F38 0980013C */  lui        $at, %hi(D_80092B14)
    /* 6573C 80074F3C 142B20AC */  sw         $zero, %lo(D_80092B14)($at)
    /* 65740 80074F40 0980013C */  lui        $at, %hi(D_80092B40)
    /* 65744 80074F44 402B20AC */  sw         $zero, %lo(D_80092B40)($at)
    /* 65748 80074F48 0980013C */  lui        $at, %hi(D_80092B3C)
    /* 6574C 80074F4C 3C2B20AC */  sw         $zero, %lo(D_80092B3C)($at)
    /* 65750 80074F50 0980013C */  lui        $at, %hi(D_80092B74)
    /* 65754 80074F54 742B20AC */  sw         $zero, %lo(D_80092B74)($at)
    /* 65758 80074F58 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6575C 80074F5C 1000B08F */  lw         $s0, 0x10($sp)
    /* 65760 80074F60 0800E003 */  jr         $ra
    /* 65764 80074F64 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80074E80
