/* Handwritten function */
nonmatching func_8008B510, 0x44

glabel func_8008B510
    /* 7BD10 8008B510 1080013C */  lui        $at, %hi(D_800FE2F8)
    /* 7BD14 8008B514 F8E23FAC */  sw         $ra, %lo(D_800FE2F8)($at)
    /* 7BD18 8008B518 57000924 */  addiu      $t1, $zero, 0x57
    /* 7BD1C 8008B51C B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 7BD20 8008B520 09F84001 */  jalr       $t2
    /* 7BD24 8008B524 00000000 */   nop
    /* 7BD28 8008B528 09000A24 */  addiu      $t2, $zero, 0x9
    /* 7BD2C 8008B52C 6C01428C */  lw         $v0, 0x16C($v0)
    /* 7BD30 8008B530 00000000 */  nop
    /* 7BD34 8008B534 88194320 */  addi       $v1, $v0, 0x1988 /* handwritten instruction */
    /* 7BD38 8008B538 3CD0010C */  jal        func_800740F0
    /* 7BD3C 8008B53C 000060AC */   sw        $zero, 0x0($v1)
    /* 7BD40 8008B540 10801F3C */  lui        $ra, %hi(D_800FE2F8)
    /* 7BD44 8008B544 F8E2FF8F */  lw         $ra, %lo(D_800FE2F8)($ra)
    /* 7BD48 8008B548 00000000 */  nop
    /* 7BD4C 8008B54C 0800E003 */  jr         $ra
    /* 7BD50 8008B550 00000000 */   nop
endlabel func_8008B510
