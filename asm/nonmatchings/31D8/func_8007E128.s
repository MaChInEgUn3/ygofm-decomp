nonmatching func_8007E128, 0xB8

glabel func_8007E128
    /* 6E928 8007E128 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6E92C 8007E12C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6E930 8007E130 0980103C */  lui        $s0, %hi(D_80093A34)
    /* 6E934 8007E134 343A1026 */  addiu      $s0, $s0, %lo(D_80093A34)
    /* 6E938 8007E138 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6E93C 8007E13C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6E940 8007E140 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6E944 8007E144 0000028E */  lw         $v0, 0x0($s0)
    /* 6E948 8007E148 00000000 */  nop
    /* 6E94C 8007E14C 1E004010 */  beqz       $v0, .L8007E1C8
    /* 6E950 8007E150 2190A000 */   addu      $s2, $a1, $zero
    /* 6E954 8007E154 0400028E */  lw         $v0, 0x4($s0)
    /* 6E958 8007E158 00000000 */  nop
    /* 6E95C 8007E15C 1A004010 */  beqz       $v0, .L8007E1C8
    /* 6E960 8007E160 FF009130 */   andi      $s1, $a0, 0xFF
    /* 6E964 8007E164 02000224 */  addiu      $v0, $zero, 0x2
    /* 6E968 8007E168 09002216 */  bne        $s1, $v0, .L8007E190
    /* 6E96C 8007E16C 00000000 */   nop
    /* 6E970 8007E170 B0EE010C */  jal        func_8007BAC0
    /* 6E974 8007E174 00000000 */   nop
    /* 6E978 8007E178 13004014 */  bnez       $v0, .L8007E1C8
    /* 6E97C 8007E17C 00000000 */   nop
    /* 6E980 8007E180 78F8010C */  jal        func_8007E1E0
    /* 6E984 8007E184 00000000 */   nop
    /* 6E988 8007E188 72F80108 */  j          .L8007E1C8
    /* 6E98C 8007E18C 00000000 */   nop
  .L8007E190:
    /* 6E990 8007E190 F8FF048E */  lw         $a0, -0x8($s0)
    /* 6E994 8007E194 18FA010C */  jal        func_8007E860
    /* 6E998 8007E198 00000000 */   nop
    /* 6E99C 8007E19C FCFF048E */  lw         $a0, -0x4($s0)
    /* 6E9A0 8007E1A0 20FA010C */  jal        func_8007E880
    /* 6E9A4 8007E1A4 00000000 */   nop
    /* 6E9A8 8007E1A8 ECFF028E */  lw         $v0, -0x14($s0)
    /* 6E9AC 8007E1AC 00000000 */  nop
    /* 6E9B0 8007E1B0 05004010 */  beqz       $v0, .L8007E1C8
    /* 6E9B4 8007E1B4 040000AE */   sw        $zero, 0x4($s0)
    /* 6E9B8 8007E1B8 21202002 */  addu       $a0, $s1, $zero
    /* 6E9BC 8007E1BC 21284002 */  addu       $a1, $s2, $zero
    /* 6E9C0 8007E1C0 09F84000 */  jalr       $v0
    /* 6E9C4 8007E1C4 21300000 */   addu      $a2, $zero, $zero
  .L8007E1C8:
    /* 6E9C8 8007E1C8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6E9CC 8007E1CC 1800B28F */  lw         $s2, 0x18($sp)
    /* 6E9D0 8007E1D0 1400B18F */  lw         $s1, 0x14($sp)
    /* 6E9D4 8007E1D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6E9D8 8007E1D8 0800E003 */  jr         $ra
    /* 6E9DC 8007E1DC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007E128
