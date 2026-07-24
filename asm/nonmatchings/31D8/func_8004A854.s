nonmatching func_8004A854, 0x90

glabel func_8004A854
    /* 3B054 8004A854 FFFF0924 */  addiu      $t1, $zero, -0x1
    /* 3B058 8004A858 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B05C 8004A85C 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B060 8004A860 FFFF0834 */  ori        $t0, $zero, 0xFFFF
    /* 3B064 8004A864 10056284 */  lh         $v0, 0x510($v1)
    /* 3B068 8004A868 00000000 */  nop
    /* 3B06C 8004A86C 1B004018 */  blez       $v0, .L8004A8DC
    /* 3B070 8004A870 21280000 */   addu      $a1, $zero, $zero
    /* 3B074 8004A874 FF008430 */  andi       $a0, $a0, 0xFF
    /* 3B078 8004A878 2138A000 */  addu       $a3, $a1, $zero
  .L8004A87C:
    /* 3B07C 8004A87C 21186700 */  addu       $v1, $v1, $a3
    /* 3B080 8004A880 9E016694 */  lhu        $a2, 0x19E($v1)
    /* 3B084 8004A884 FFFF0231 */  andi       $v0, $t0, 0xFFFF
    /* 3B088 8004A888 2B104600 */  sltu       $v0, $v0, $a2
    /* 3B08C 8004A88C 0B004014 */  bnez       $v0, .L8004A8BC
    /* 3B090 8004A890 00000000 */   nop
    /* 3B094 8004A894 83016290 */  lbu        $v0, 0x183($v1)
    /* 3B098 8004A898 00000000 */  nop
    /* 3B09C 8004A89C 07004414 */  bne        $v0, $a0, .L8004A8BC
    /* 3B0A0 8004A8A0 00000000 */   nop
    /* 3B0A4 8004A8A4 8D016290 */  lbu        $v0, 0x18D($v1)
    /* 3B0A8 8004A8A8 00000000 */  nop
    /* 3B0AC 8004A8AC 03004010 */  beqz       $v0, .L8004A8BC
    /* 3B0B0 8004A8B0 00000000 */   nop
    /* 3B0B4 8004A8B4 2140C000 */  addu       $t0, $a2, $zero
    /* 3B0B8 8004A8B8 2148A000 */  addu       $t1, $a1, $zero
  .L8004A8BC:
    /* 3B0BC 8004A8BC 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B0C0 8004A8C0 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B0C4 8004A8C4 00000000 */  nop
    /* 3B0C8 8004A8C8 10056284 */  lh         $v0, 0x510($v1)
    /* 3B0CC 8004A8CC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3B0D0 8004A8D0 2A10A200 */  slt        $v0, $a1, $v0
    /* 3B0D4 8004A8D4 E9FF4014 */  bnez       $v0, .L8004A87C
    /* 3B0D8 8004A8D8 2800E724 */   addiu     $a3, $a3, 0x28
  .L8004A8DC:
    /* 3B0DC 8004A8DC 0800E003 */  jr         $ra
    /* 3B0E0 8004A8E0 21102001 */   addu      $v0, $t1, $zero
endlabel func_8004A854
