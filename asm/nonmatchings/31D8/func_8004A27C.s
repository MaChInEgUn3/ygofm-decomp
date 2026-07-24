nonmatching func_8004A27C, 0x7C

glabel func_8004A27C
    /* 3AA7C 8004A27C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3AA80 8004A280 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3AA84 8004A284 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3AA88 8004A288 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3AA8C 8004A28C 14056294 */  lhu        $v0, 0x514($v1)
    /* 3AA90 8004A290 00000000 */  nop
    /* 3AA94 8004A294 1800A200 */  mult       $a1, $v0
    /* 3AA98 8004A298 16056594 */  lhu        $a1, 0x516($v1)
    /* 3AA9C 8004A29C 12380000 */  mflo       $a3
    /* 3AAA0 8004A2A0 80200400 */  sll        $a0, $a0, 2
    /* 3AAA4 8004A2A4 CC0460A4 */  sh         $zero, 0x4CC($v1)
    /* 3AAA8 8004A2A8 1800C500 */  mult       $a2, $a1
    /* 3AAAC 8004A2AC CE0460A4 */  sh         $zero, 0x4CE($v1)
    /* 3AAB0 8004A2B0 0180023C */  lui        $v0, %hi(D_80011434)
    /* 3AAB4 8004A2B4 34144224 */  addiu      $v0, $v0, %lo(D_80011434)
    /* 3AAB8 8004A2B8 21208200 */  addu       $a0, $a0, $v0
    /* 3AABC 8004A2BC 0000848C */  lw         $a0, 0x0($a0)
    /* 3AAC0 8004A2C0 0F000224 */  addiu      $v0, $zero, 0xF
    /* 3AAC4 8004A2C4 C40462AC */  sw         $v0, 0x4C4($v1)
    /* 3AAC8 8004A2C8 C00464AC */  sw         $a0, 0x4C0($v1)
    /* 3AACC 8004A2CC C0046424 */  addiu      $a0, $v1, 0x4C0
    /* 3AAD0 8004A2D0 C3110700 */  sra        $v0, $a3, 7
    /* 3AAD4 8004A2D4 C80462A4 */  sh         $v0, 0x4C8($v1)
    /* 3AAD8 8004A2D8 12480000 */  mflo       $t1
    /* 3AADC 8004A2DC C3110900 */  sra        $v0, $t1, 7
    /* 3AAE0 8004A2E0 14DD010C */  jal        func_80077450
    /* 3AAE4 8004A2E4 CA0462A4 */   sh        $v0, 0x4CA($v1)
    /* 3AAE8 8004A2E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3AAEC 8004A2EC 00000000 */  nop
    /* 3AAF0 8004A2F0 0800E003 */  jr         $ra
    /* 3AAF4 8004A2F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004A27C
