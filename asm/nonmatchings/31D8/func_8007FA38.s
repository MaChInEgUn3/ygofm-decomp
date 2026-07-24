nonmatching func_8007FA38, 0xB8

glabel func_8007FA38
    /* 70238 8007FA38 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7023C 8007FA3C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 70240 8007FA40 21808000 */  addu       $s0, $a0, $zero
    /* 70244 8007FA44 1800B2AF */  sw         $s2, 0x18($sp)
    /* 70248 8007FA48 2190A000 */  addu       $s2, $a1, $zero
    /* 7024C 8007FA4C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 70250 8007FA50 2188C000 */  addu       $s1, $a2, $zero
    /* 70254 8007FA54 0180043C */  lui        $a0, %hi(D_8001228C)
    /* 70258 8007FA58 8C228424 */  addiu      $a0, $a0, %lo(D_8001228C)
    /* 7025C 8007FA5C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 70260 8007FA60 CDFD010C */  jal        func_8007F734
    /* 70264 8007FA64 21280002 */   addu      $a1, $s0, $zero
    /* 70268 8007FA68 04000286 */  lh         $v0, 0x4($s0)
    /* 7026C 8007FA6C 00000000 */  nop
    /* 70270 8007FA70 19004010 */  beqz       $v0, .L8007FAD8
    /* 70274 8007FA74 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 70278 8007FA78 06000286 */  lh         $v0, 0x6($s0)
    /* 7027C 8007FA7C 00000000 */  nop
    /* 70280 8007FA80 03004014 */  bnez       $v0, .L8007FA90
    /* 70284 8007FA84 00141100 */   sll       $v0, $s1, 16
    /* 70288 8007FA88 B6FE0108 */  j          .L8007FAD8
    /* 7028C 8007FA8C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8007FA90:
    /* 70290 8007FA90 0980033C */  lui        $v1, %hi(D_80094708)
    /* 70294 8007FA94 08476324 */  addiu      $v1, $v1, %lo(D_80094708)
    /* 70298 8007FA98 FFFF4432 */  andi       $a0, $s2, 0xFFFF
    /* 7029C 8007FA9C 25104400 */  or         $v0, $v0, $a0
    /* 702A0 8007FAA0 0000058E */  lw         $a1, 0x0($s0)
    /* 702A4 8007FAA4 0980073C */  lui        $a3, %hi(D_80094660)
    /* 702A8 8007FAA8 6046E78C */  lw         $a3, %lo(D_80094660)($a3)
    /* 702AC 8007FAAC 14000624 */  addiu      $a2, $zero, 0x14
    /* 702B0 8007FAB0 040062AC */  sw         $v0, 0x4($v1)
    /* 702B4 8007FAB4 000065AC */  sw         $a1, 0x0($v1)
    /* 702B8 8007FAB8 0400028E */  lw         $v0, 0x4($s0)
    /* 702BC 8007FABC F8FF6524 */  addiu      $a1, $v1, -0x8
    /* 702C0 8007FAC0 080062AC */  sw         $v0, 0x8($v1)
    /* 702C4 8007FAC4 1800E48C */  lw         $a0, 0x18($a3)
    /* 702C8 8007FAC8 0800E28C */  lw         $v0, 0x8($a3)
    /* 702CC 8007FACC 00000000 */  nop
    /* 702D0 8007FAD0 09F84000 */  jalr       $v0
    /* 702D4 8007FAD4 21380000 */   addu      $a3, $zero, $zero
  .L8007FAD8:
    /* 702D8 8007FAD8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 702DC 8007FADC 1800B28F */  lw         $s2, 0x18($sp)
    /* 702E0 8007FAE0 1400B18F */  lw         $s1, 0x14($sp)
    /* 702E4 8007FAE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 702E8 8007FAE8 0800E003 */  jr         $ra
    /* 702EC 8007FAEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007FA38
