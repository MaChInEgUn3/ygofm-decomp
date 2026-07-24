nonmatching func_8002E060, 0xC8

glabel func_8002E060
    /* 1E860 8002E060 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 1E864 8002E064 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 1E868 8002E068 21988000 */  addu       $s3, $a0, $zero
    /* 1E86C 8002E06C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1E870 8002E070 2188A000 */  addu       $s1, $a1, $zero
    /* 1E874 8002E074 2000B0AF */  sw         $s0, 0x20($sp)
    /* 1E878 8002E078 2180C000 */  addu       $s0, $a2, $zero
    /* 1E87C 8002E07C 3000BFAF */  sw         $ra, 0x30($sp)
    /* 1E880 8002E080 0B00010C */  jal        func_8004002C
    /* 1E884 8002E084 2800B2AF */   sw        $s2, 0x28($sp)
    /* 1E888 8002E088 21204000 */  addu       $a0, $v0, $zero
    /* 1E88C 8002E08C 2B00010C */  jal        func_800400AC
    /* 1E890 8002E090 02000524 */   addiu     $a1, $zero, 0x2
    /* 1E894 8002E094 21904000 */  addu       $s2, $v0, $zero
    /* 1E898 8002E098 21204002 */  addu       $a0, $s2, $zero
    /* 1E89C 8002E09C 21280000 */  addu       $a1, $zero, $zero
    /* 1E8A0 8002E0A0 2130A000 */  addu       $a2, $a1, $zero
    /* 1E8A4 8002E0A4 02000724 */  addiu      $a3, $zero, 0x2
    /* 1E8A8 8002E0A8 1000A0AF */  sw         $zero, 0x10($sp)
    /* 1E8AC 8002E0AC 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1E8B0 8002E0B0 1800B1AF */  sw         $s1, 0x18($sp)
    /* 1E8B4 8002E0B4 3301010C */  jal        func_800404CC
    /* 1E8B8 8002E0B8 1C00B0AF */   sw        $s0, 0x1C($sp)
    /* 1E8BC 8002E0BC 21204002 */  addu       $a0, $s2, $zero
    /* 1E8C0 8002E0C0 002E1000 */  sll        $a1, $s0, 24
    /* 1E8C4 8002E0C4 3B0A010C */  jal        func_800428EC
    /* 1E8C8 8002E0C8 032E0500 */   sra       $a1, $a1, 24
    /* 1E8CC 8002E0CC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1E8D0 8002E0D0 100062A2 */  sb         $v0, 0x10($s3)
    /* 1E8D4 8002E0D4 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E8D8 8002E0D8 06000216 */  bne        $s0, $v0, .L8002E0F4
    /* 1E8DC 8002E0DC 0001033C */   lui       $v1, (0x1000000 >> 16)
    /* 1E8E0 8002E0E0 01000224 */  addiu      $v0, $zero, 0x1
    /* 1E8E4 8002E0E4 040062A6 */  sh         $v0, 0x4($s3)
    /* 1E8E8 8002E0E8 0400428E */  lw         $v0, 0x4($s2)
    /* 1E8EC 8002E0EC 3FB80008 */  j          .L8002E0FC
    /* 1E8F0 8002E0F0 0050033C */   lui       $v1, (0x50000000 >> 16)
  .L8002E0F4:
    /* 1E8F4 8002E0F4 040060A6 */  sh         $zero, 0x4($s3)
    /* 1E8F8 8002E0F8 0400428E */  lw         $v0, 0x4($s2)
  .L8002E0FC:
    /* 1E8FC 8002E0FC 00000000 */  nop
    /* 1E900 8002E100 25104300 */  or         $v0, $v0, $v1
    /* 1E904 8002E104 040042AE */  sw         $v0, 0x4($s2)
    /* 1E908 8002E108 000072AE */  sw         $s2, 0x0($s3)
    /* 1E90C 8002E10C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 1E910 8002E110 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 1E914 8002E114 2800B28F */  lw         $s2, 0x28($sp)
    /* 1E918 8002E118 2400B18F */  lw         $s1, 0x24($sp)
    /* 1E91C 8002E11C 2000B08F */  lw         $s0, 0x20($sp)
    /* 1E920 8002E120 0800E003 */  jr         $ra
    /* 1E924 8002E124 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8002E060
