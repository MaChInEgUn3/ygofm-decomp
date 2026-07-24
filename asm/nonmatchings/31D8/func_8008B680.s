nonmatching func_8008B680, 0x70

glabel func_8008B680
    /* 7BE80 8008B680 1080013C */  lui        $at, %hi(D_800FE2F8)
    /* 7BE84 8008B684 F8E23FAC */  sw         $ra, %lo(D_800FE2F8)($at)
    /* 7BE88 8008B688 2CCE010C */  jal        func_800738B0
    /* 7BE8C 8008B68C 00000000 */   nop
    /* 7BE90 8008B690 57000924 */  addiu      $t1, $zero, 0x57
    /* 7BE94 8008B694 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 7BE98 8008B698 09F84001 */  jalr       $t2
    /* 7BE9C 8008B69C 00000000 */   nop
    /* 7BEA0 8008B6A0 6C01428C */  lw         $v0, 0x16C($v0)
    /* 7BEA4 8008B6A4 00000000 */  nop
    /* 7BEA8 8008B6A8 C809438C */  lw         $v1, 0x9C8($v0)
    /* 7BEAC 8008B6AC 09800A3C */  lui        $t2, %hi(func_8008B5C4 + 0x14)
    /* 7BEB0 8008B6B0 D8B54A25 */  addiu      $t2, $t2, %lo(func_8008B5C4 + 0x14)
    /* 7BEB4 8008B6B4 0980093C */  lui        $t1, %hi(func_8008B5EC)
    /* 7BEB8 8008B6B8 ECB52925 */  addiu      $t1, $t1, %lo(func_8008B5EC)
  .L8008B6BC:
    /* 7BEBC 8008B6BC 0000488D */  lw         $t0, 0x0($t2)
    /* 7BEC0 8008B6C0 00000000 */  nop
    /* 7BEC4 8008B6C4 C80948AC */  sw         $t0, 0x9C8($v0)
    /* 7BEC8 8008B6C8 04004A25 */  addiu      $t2, $t2, 0x4
    /* 7BECC 8008B6CC FBFF4915 */  bne        $t2, $t1, .L8008B6BC
    /* 7BED0 8008B6D0 04004224 */   addiu     $v0, $v0, 0x4
    /* 7BED4 8008B6D4 3CD0010C */  jal        func_800740F0
    /* 7BED8 8008B6D8 00000000 */   nop
    /* 7BEDC 8008B6DC 10801F3C */  lui        $ra, %hi(D_800FE2F8)
    /* 7BEE0 8008B6E0 F8E2FF8F */  lw         $ra, %lo(D_800FE2F8)($ra)
    /* 7BEE4 8008B6E4 00000000 */  nop
    /* 7BEE8 8008B6E8 0800E003 */  jr         $ra
    /* 7BEEC 8008B6EC 00000000 */   nop
endlabel func_8008B680
