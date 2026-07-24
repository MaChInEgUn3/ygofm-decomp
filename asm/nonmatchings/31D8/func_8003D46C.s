nonmatching func_8003D46C, 0xAC

glabel func_8003D46C
    /* 2DC6C 8003D46C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2DC70 8003D470 2000B2AF */  sw         $s2, 0x20($sp)
    /* 2DC74 8003D474 21908000 */  addu       $s2, $a0, $zero
    /* 2DC78 8003D478 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2DC7C 8003D47C 2180A000 */  addu       $s0, $a1, $zero
    /* 2DC80 8003D480 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2DC84 8003D484 0A80013C */  lui        $at, %hi(D_8009B34D)
    /* 2DC88 8003D488 4DB322A0 */  sb         $v0, %lo(D_8009B34D)($at)
    /* 2DC8C 8003D48C 00010224 */  addiu      $v0, $zero, 0x100
    /* 2DC90 8003D490 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2DC94 8003D494 0F80023C */  lui        $v0, %hi(D_800EF6EA)
    /* 2DC98 8003D498 EAF64490 */  lbu        $a0, %lo(D_800EF6EA)($v0)
    /* 2DC9C 8003D49C 40000224 */  addiu      $v0, $zero, 0x40
    /* 2DCA0 8003D4A0 FF7F4532 */  andi       $a1, $s2, 0x7FFF
    /* 2DCA4 8003D4A4 20000624 */  addiu      $a2, $zero, 0x20
    /* 2DCA8 8003D4A8 50000724 */  addiu      $a3, $zero, 0x50
    /* 2DCAC 8003D4AC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 2DCB0 8003D4B0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2DCB4 8003D4B4 F9D6000C */  jal        func_80035BE4
    /* 2DCB8 8003D4B8 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2DCBC 8003D4BC 0A80033C */  lui        $v1, %hi(D_8009AF76)
    /* 2DCC0 8003D4C0 76AF6390 */  lbu        $v1, %lo(D_8009AF76)($v1)
    /* 2DCC4 8003D4C4 21884000 */  addu       $s1, $v0, $zero
    /* 2DCC8 8003D4C8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2DCCC 8003D4CC 06000012 */  beqz       $s0, .L8003D4E8
    /* 2DCD0 8003D4D0 590023A2 */   sb        $v1, 0x59($s1)
    /* 2DCD4 8003D4D4 34002296 */  lhu        $v0, 0x34($s1)
    /* 2DCD8 8003D4D8 00000000 */  nop
    /* 2DCDC 8003D4DC 08104234 */  ori        $v0, $v0, 0x1008
    /* 2DCE0 8003D4E0 3FF50008 */  j          .L8003D4FC
    /* 2DCE4 8003D4E4 340022A6 */   sh        $v0, 0x34($s1)
  .L8003D4E8:
    /* 2DCE8 8003D4E8 00804232 */  andi       $v0, $s2, 0x8000
    /* 2DCEC 8003D4EC 04004010 */  beqz       $v0, .L8003D500
    /* 2DCF0 8003D4F0 21102002 */   addu      $v0, $s1, $zero
    /* 2DCF4 8003D4F4 85E6000C */  jal        func_80039A14
    /* 2DCF8 8003D4F8 21202002 */   addu      $a0, $s1, $zero
  .L8003D4FC:
    /* 2DCFC 8003D4FC 21102002 */  addu       $v0, $s1, $zero
  .L8003D500:
    /* 2DD00 8003D500 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2DD04 8003D504 2000B28F */  lw         $s2, 0x20($sp)
    /* 2DD08 8003D508 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2DD0C 8003D50C 1800B08F */  lw         $s0, 0x18($sp)
    /* 2DD10 8003D510 0800E003 */  jr         $ra
    /* 2DD14 8003D514 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003D46C
