nonmatching func_8008BC90, 0x68

glabel func_8008BC90
    /* 7C490 8008BC90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C494 8008BC94 1080033C */  lui        $v1, %hi(D_800FE348)
    /* 7C498 8008BC98 48E36324 */  addiu      $v1, $v1, %lo(D_800FE348)
    /* 7C49C 8008BC9C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7C4A0 8008BCA0 0000628C */  lw         $v0, 0x0($v1)
    /* 7C4A4 8008BCA4 00000000 */  nop
    /* 7C4A8 8008BCA8 0B00401C */  bgtz       $v0, .L8008BCD8
    /* 7C4AC 8008BCAC 21288000 */   addu      $a1, $a0, $zero
    /* 7C4B0 8008BCB0 0980043C */  lui        $a0, %hi(func_8008BCF8)
    /* 7C4B4 8008BCB4 F8BC8424 */  addiu      $a0, $a0, %lo(func_8008BCF8)
    /* 7C4B8 8008BCB8 02000224 */  addiu      $v0, $zero, 0x2
    /* 7C4BC 8008BCBC 000062AC */  sw         $v0, 0x0($v1)
    /* 7C4C0 8008BCC0 040060AC */  sw         $zero, 0x4($v1)
    /* 7C4C4 8008BCC4 080060AC */  sw         $zero, 0x8($v1)
    /* 7C4C8 8008BCC8 3834020C */  jal        func_8008D0E0
    /* 7C4CC 8008BCCC 100065AC */   sw        $a1, 0x10($v1)
    /* 7C4D0 8008BCD0 3A2F0208 */  j          .L8008BCE8
    /* 7C4D4 8008BCD4 01000224 */   addiu     $v0, $zero, 0x1
  .L8008BCD8:
    /* 7C4D8 8008BCD8 0180043C */  lui        $a0, %hi(D_80012478)
    /* 7C4DC 8008BCDC 1C3A020C */  jal        func_8008E870
    /* 7C4E0 8008BCE0 78248424 */   addiu     $a0, $a0, %lo(D_80012478)
    /* 7C4E4 8008BCE4 21100000 */  addu       $v0, $zero, $zero
  .L8008BCE8:
    /* 7C4E8 8008BCE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7C4EC 8008BCEC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7C4F0 8008BCF0 0800E003 */  jr         $ra
    /* 7C4F4 8008BCF4 00000000 */   nop
endlabel func_8008BC90
