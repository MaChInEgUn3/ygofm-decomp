nonmatching func_8001798C, 0x68

glabel func_8001798C
    /* 818C 8001798C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 8190 80017990 0180023C */  lui        $v0, %hi(func_800171A8)
    /* 8194 80017994 A8714224 */  addiu      $v0, $v0, %lo(func_800171A8)
    /* 8198 80017998 21200000 */  addu       $a0, $zero, $zero
    /* 819C 8001799C 21288000 */  addu       $a1, $a0, $zero
    /* 81A0 800179A0 0A80033C */  lui        $v1, %hi(D_8009B364)
    /* 81A4 800179A4 64B36390 */  lbu        $v1, %lo(D_8009B364)($v1)
    /* 81A8 800179A8 EB000724 */  addiu      $a3, $zero, 0xEB
    /* 81AC 800179AC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 81B0 800179B0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 81B4 800179B4 1400A0AF */  sw         $zero, 0x14($sp)
    /* 81B8 800179B8 1800A0AF */  sw         $zero, 0x18($sp)
    /* 81BC 800179BC 00310300 */  sll        $a2, $v1, 4
    /* 81C0 800179C0 2330C300 */  subu       $a2, $a2, $v1
    /* 81C4 800179C4 80300600 */  sll        $a2, $a2, 2
    /* 81C8 800179C8 2330C300 */  subu       $a2, $a2, $v1
    /* 81CC 800179CC 80300600 */  sll        $a2, $a2, 2
    /* 81D0 800179D0 2330C300 */  subu       $a2, $a2, $v1
    /* 81D4 800179D4 8753000C */  jal        func_80014E1C
    /* 81D8 800179D8 C616C624 */   addiu     $a2, $a2, 0x16C6
    /* 81DC 800179DC F94D000C */  jal        func_800137E4
    /* 81E0 800179E0 00000000 */   nop
    /* 81E4 800179E4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 81E8 800179E8 00000000 */  nop
    /* 81EC 800179EC 0800E003 */  jr         $ra
    /* 81F0 800179F0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8001798C
