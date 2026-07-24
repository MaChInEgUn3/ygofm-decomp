nonmatching func_80043DA0, 0x90

glabel func_80043DA0
    /* 345A0 80043DA0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 345A4 80043DA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 345A8 80043DA8 21808000 */  addu       $s0, $a0, $zero
    /* 345AC 80043DAC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 345B0 80043DB0 2190A000 */  addu       $s2, $a1, $zero
    /* 345B4 80043DB4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 345B8 80043DB8 01001124 */  addiu      $s1, $zero, 0x1
    /* 345BC 80043DBC 1C00BFAF */  sw         $ra, 0x1C($sp)
  .L80043DC0:
    /* 345C0 80043DC0 0000048E */  lw         $a0, 0x0($s0)
    /* 345C4 80043DC4 20CE010C */  jal        func_80073880
    /* 345C8 80043DC8 00000000 */   nop
    /* 345CC 80043DCC 12005110 */  beq        $v0, $s1, .L80043E18
    /* 345D0 80043DD0 21100000 */   addu      $v0, $zero, $zero
    /* 345D4 80043DD4 0400048E */  lw         $a0, 0x4($s0)
    /* 345D8 80043DD8 20CE010C */  jal        func_80073880
    /* 345DC 80043DDC 00000000 */   nop
    /* 345E0 80043DE0 0D005110 */  beq        $v0, $s1, .L80043E18
    /* 345E4 80043DE4 01000224 */   addiu     $v0, $zero, 0x1
    /* 345E8 80043DE8 0800048E */  lw         $a0, 0x8($s0)
    /* 345EC 80043DEC 20CE010C */  jal        func_80073880
    /* 345F0 80043DF0 00000000 */   nop
    /* 345F4 80043DF4 08005110 */  beq        $v0, $s1, .L80043E18
    /* 345F8 80043DF8 02000224 */   addiu     $v0, $zero, 0x2
    /* 345FC 80043DFC 0C00048E */  lw         $a0, 0xC($s0)
    /* 34600 80043E00 20CE010C */  jal        func_80073880
    /* 34604 80043E04 00000000 */   nop
    /* 34608 80043E08 03005110 */  beq        $v0, $s1, .L80043E18
    /* 3460C 80043E0C 03000224 */   addiu     $v0, $zero, 0x3
    /* 34610 80043E10 EBFF4012 */  beqz       $s2, .L80043DC0
    /* 34614 80043E14 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80043E18:
    /* 34618 80043E18 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3461C 80043E1C 1800B28F */  lw         $s2, 0x18($sp)
    /* 34620 80043E20 1400B18F */  lw         $s1, 0x14($sp)
    /* 34624 80043E24 1000B08F */  lw         $s0, 0x10($sp)
    /* 34628 80043E28 0800E003 */  jr         $ra
    /* 3462C 80043E2C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80043DA0
