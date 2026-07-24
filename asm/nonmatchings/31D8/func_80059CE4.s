nonmatching func_80059CE4, 0xF4

glabel func_80059CE4
    /* 4A4E4 80059CE4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4A4E8 80059CE8 0F80023C */  lui        $v0, %hi(D_800F56F0)
    /* 4A4EC 80059CEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4A4F0 80059CF0 F0565024 */  addiu      $s0, $v0, %lo(D_800F56F0)
    /* 4A4F4 80059CF4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4A4F8 80059CF8 542B020C */  jal        func_8008AD50
    /* 4A4FC 80059CFC 21200002 */   addu      $a0, $s0, $zero
    /* 4A500 80059D00 8C008393 */  lbu        $v1, %gp_rel(D_8009AF94)($gp)
    /* 4A504 80059D04 0F000224 */  addiu      $v0, $zero, 0xF
    /* 4A508 80059D08 05006214 */  bne        $v1, $v0, .L80059D20
    /* 4A50C 80059D0C 13000224 */   addiu     $v0, $zero, 0x13
    /* 4A510 80059D10 C03A010C */  jal        func_8004EB00
    /* 4A514 80059D14 00000000 */   nop
    /* 4A518 80059D18 8C008393 */  lbu        $v1, %gp_rel(D_8009AF94)($gp)
    /* 4A51C 80059D1C 13000224 */  addiu      $v0, $zero, 0x13
  .L80059D20:
    /* 4A520 80059D20 03006214 */  bne        $v1, $v0, .L80059D30
    /* 4A524 80059D24 00000000 */   nop
    /* 4A528 80059D28 8B3F010C */  jal        func_8004FE2C
    /* 4A52C 80059D2C 00000000 */   nop
  .L80059D30:
    /* 4A530 80059D30 8C008393 */  lbu        $v1, %gp_rel(D_8009AF94)($gp)
    /* 4A534 80059D34 14000224 */  addiu      $v0, $zero, 0x14
    /* 4A538 80059D38 03006214 */  bne        $v1, $v0, .L80059D48
    /* 4A53C 80059D3C 00000000 */   nop
    /* 4A540 80059D40 F441010C */  jal        func_800507D0
    /* 4A544 80059D44 00000000 */   nop
  .L80059D48:
    /* 4A548 80059D48 542B020C */  jal        func_8008AD50
    /* 4A54C 80059D4C 21200002 */   addu      $a0, $s0, $zero
    /* 4A550 80059D50 2D50010C */  jal        func_800540B4
    /* 4A554 80059D54 21200000 */   addu      $a0, $zero, $zero
    /* 4A558 80059D58 2D50010C */  jal        func_800540B4
    /* 4A55C 80059D5C 01000424 */   addiu     $a0, $zero, 0x1
    /* 4A560 80059D60 2D50010C */  jal        func_800540B4
    /* 4A564 80059D64 02000424 */   addiu     $a0, $zero, 0x2
    /* 4A568 80059D68 7556010C */  jal        func_800559D4
    /* 4A56C 80059D6C 21200000 */   addu      $a0, $zero, $zero
    /* 4A570 80059D70 7556010C */  jal        func_800559D4
    /* 4A574 80059D74 01000424 */   addiu     $a0, $zero, 0x1
    /* 4A578 80059D78 8937010C */  jal        func_8004DE24
    /* 4A57C 80059D7C 00000000 */   nop
    /* 4A580 80059D80 683A010C */  jal        func_8004E9A0
    /* 4A584 80059D84 00000000 */   nop
    /* 4A588 80059D88 2B4A010C */  jal        func_800528AC
    /* 4A58C 80059D8C 00000000 */   nop
    /* 4A590 80059D90 BA55010C */  jal        func_800556E8
    /* 4A594 80059D94 21200000 */   addu      $a0, $zero, $zero
    /* 4A598 80059D98 BA55010C */  jal        func_800556E8
    /* 4A59C 80059D9C 01000424 */   addiu     $a0, $zero, 0x1
    /* 4A5A0 80059DA0 BA55010C */  jal        func_800556E8
    /* 4A5A4 80059DA4 02000424 */   addiu     $a0, $zero, 0x2
    /* 4A5A8 80059DA8 C27E010C */  jal        func_8005FB08
    /* 4A5AC 80059DAC 00000000 */   nop
    /* 4A5B0 80059DB0 03004014 */  bnez       $v0, .L80059DC0
    /* 4A5B4 80059DB4 00000000 */   nop
    /* 4A5B8 80059DB8 E976010C */  jal        func_8005DBA4
    /* 4A5BC 80059DBC 00000000 */   nop
  .L80059DC0:
    /* 4A5C0 80059DC0 9246010C */  jal        func_80051A48
    /* 4A5C4 80059DC4 00000000 */   nop
    /* 4A5C8 80059DC8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4A5CC 80059DCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A5D0 80059DD0 0800E003 */  jr         $ra
    /* 4A5D4 80059DD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80059CE4
