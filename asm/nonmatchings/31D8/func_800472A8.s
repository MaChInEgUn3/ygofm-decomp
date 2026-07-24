nonmatching func_800472A8, 0x6C

glabel func_800472A8
    /* 37AA8 800472A8 5405828F */  lw         $v0, %gp_rel(D_8009B45C)($gp)
    /* 37AAC 800472AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37AB0 800472B0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 37AB4 800472B4 4A004290 */  lbu        $v0, 0x4A($v0)
    /* 37AB8 800472B8 00000000 */  nop
    /* 37ABC 800472BC 02004230 */  andi       $v0, $v0, 0x2
    /* 37AC0 800472C0 10004010 */  beqz       $v0, .L80047304
    /* 37AC4 800472C4 21188000 */   addu      $v1, $a0, $zero
    /* 37AC8 800472C8 00808230 */  andi       $v0, $a0, 0x8000
    /* 37ACC 800472CC 05004010 */  beqz       $v0, .L800472E4
    /* 37AD0 800472D0 FFFF6230 */   andi      $v0, $v1, 0xFFFF
    /* 37AD4 800472D4 CD14010C */  jal        func_80045334
    /* 37AD8 800472D8 FFFF6430 */   andi      $a0, $v1, 0xFFFF
    /* 37ADC 800472DC C11C0108 */  j          .L80047304
    /* 37AE0 800472E0 00000000 */   nop
  .L800472E4:
    /* 37AE4 800472E4 0070422C */  sltiu      $v0, $v0, 0x7000
    /* 37AE8 800472E8 02004014 */  bnez       $v0, .L800472F4
    /* 37AEC 800472EC 00000000 */   nop
    /* 37AF0 800472F0 00908424 */  addiu      $a0, $a0, -0x7000
  .L800472F4:
    /* 37AF4 800472F4 00240400 */  sll        $a0, $a0, 16
    /* 37AF8 800472F8 03240400 */  sra        $a0, $a0, 16
    /* 37AFC 800472FC 4E24010C */  jal        func_80049138
    /* 37B00 80047300 01000524 */   addiu     $a1, $zero, 0x1
  .L80047304:
    /* 37B04 80047304 1000BF8F */  lw         $ra, 0x10($sp)
    /* 37B08 80047308 00000000 */  nop
    /* 37B0C 8004730C 0800E003 */  jr         $ra
    /* 37B10 80047310 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800472A8
