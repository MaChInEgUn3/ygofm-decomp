nonmatching func_8007A4C0, 0x168

glabel func_8007A4C0
    /* 6ACC0 8007A4C0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6ACC4 8007A4C4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6ACC8 8007A4C8 21908000 */  addu       $s2, $a0, $zero
    /* 6ACCC 8007A4CC FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 6ACD0 8007A4D0 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 6ACD4 8007A4D4 2800B4AF */  sw         $s4, 0x28($sp)
    /* 6ACD8 8007A4D8 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6ACDC 8007A4DC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6ACE0 8007A4E0 5CD0010C */  jal        func_80074170
    /* 6ACE4 8007A4E4 1800B0AF */   sw        $s0, 0x18($sp)
    /* 6ACE8 8007A4E8 3C00143C */  lui        $s4, (0x3C0000 >> 16)
    /* 6ACEC 8007A4EC 0980133C */  lui        $s3, %hi(D_80093504)
    /* 6ACF0 8007A4F0 04357326 */  addiu      $s3, $s3, %lo(D_80093504)
    /* 6ACF4 8007A4F4 0980113C */  lui        $s1, %hi(D_800937BC)
    /* 6ACF8 8007A4F8 BC373126 */  addiu      $s1, $s1, %lo(D_800937BC)
    /* 6ACFC 8007A4FC 0980103C */  lui        $s0, %hi(D_80093584)
    /* 6AD00 8007A500 84351026 */  addiu      $s0, $s0, %lo(D_80093584)
    /* 6AD04 8007A504 C0034224 */  addiu      $v0, $v0, 0x3C0
    /* 6AD08 8007A508 0F80013C */  lui        $at, %hi(D_800F5DC0)
    /* 6AD0C 8007A50C C05D22AC */  sw         $v0, %lo(D_800F5DC0)($at)
    /* 6AD10 8007A510 0180023C */  lui        $v0, %hi(D_80011DC0)
    /* 6AD14 8007A514 C01D4224 */  addiu      $v0, $v0, %lo(D_80011DC0)
    /* 6AD18 8007A518 0F80013C */  lui        $at, %hi(D_800F5DC4)
    /* 6AD1C 8007A51C C45D20AC */  sw         $zero, %lo(D_800F5DC4)($at)
    /* 6AD20 8007A520 0F80013C */  lui        $at, %hi(D_800F5DC8)
    /* 6AD24 8007A524 C85D22AC */  sw         $v0, %lo(D_800F5DC8)($at)
  .L8007A528:
    /* 6AD28 8007A528 5CD0010C */  jal        func_80074170
    /* 6AD2C 8007A52C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 6AD30 8007A530 0F80033C */  lui        $v1, %hi(D_800F5DC0)
    /* 6AD34 8007A534 C05D638C */  lw         $v1, %lo(D_800F5DC0)($v1)
    /* 6AD38 8007A538 00000000 */  nop
    /* 6AD3C 8007A53C 2A186200 */  slt        $v1, $v1, $v0
    /* 6AD40 8007A540 0A006014 */  bnez       $v1, .L8007A56C
    /* 6AD44 8007A544 00000000 */   nop
    /* 6AD48 8007A548 0F80023C */  lui        $v0, %hi(D_800F5DC4)
    /* 6AD4C 8007A54C C45D428C */  lw         $v0, %lo(D_800F5DC4)($v0)
    /* 6AD50 8007A550 00000000 */  nop
    /* 6AD54 8007A554 21184000 */  addu       $v1, $v0, $zero
    /* 6AD58 8007A558 01004224 */  addiu      $v0, $v0, 0x1
    /* 6AD5C 8007A55C 2A188302 */  slt        $v1, $s4, $v1
    /* 6AD60 8007A560 0F80013C */  lui        $at, %hi(D_800F5DC4)
    /* 6AD64 8007A564 1B006010 */  beqz       $v1, .L8007A5D4
    /* 6AD68 8007A568 C45D22AC */   sw        $v0, %lo(D_800F5DC4)($at)
  .L8007A56C:
    /* 6AD6C 8007A56C 0180043C */  lui        $a0, %hi(D_80011CB4)
    /* 6AD70 8007A570 BC3E020C */  jal        func_8008FAF0
    /* 6AD74 8007A574 B41C8424 */   addiu     $a0, $a0, %lo(D_80011CB4)
    /* 6AD78 8007A578 00002492 */  lbu        $a0, 0x0($s1)
    /* 6AD7C 8007A57C 01002292 */  lbu        $v0, 0x1($s1)
    /* 6AD80 8007A580 0F80053C */  lui        $a1, %hi(D_800F5DC8)
    /* 6AD84 8007A584 C85DA58C */  lw         $a1, %lo(D_800F5DC8)($a1)
    /* 6AD88 8007A588 80100200 */  sll        $v0, $v0, 2
    /* 6AD8C 8007A58C 21105000 */  addu       $v0, $v0, $s0
    /* 6AD90 8007A590 80200400 */  sll        $a0, $a0, 2
    /* 6AD94 8007A594 0000438C */  lw         $v1, 0x0($v0)
    /* 6AD98 8007A598 0980023C */  lui        $v0, %hi(D_800934FD)
    /* 6AD9C 8007A59C FD344290 */  lbu        $v0, %lo(D_800934FD)($v0)
    /* 6ADA0 8007A5A0 21209000 */  addu       $a0, $a0, $s0
    /* 6ADA4 8007A5A4 80100200 */  sll        $v0, $v0, 2
    /* 6ADA8 8007A5A8 21105300 */  addu       $v0, $v0, $s3
    /* 6ADAC 8007A5AC 1000A3AF */  sw         $v1, 0x10($sp)
    /* 6ADB0 8007A5B0 0000468C */  lw         $a2, 0x0($v0)
    /* 6ADB4 8007A5B4 0000878C */  lw         $a3, 0x0($a0)
    /* 6ADB8 8007A5B8 0180043C */  lui        $a0, %hi(D_80011CC4)
    /* 6ADBC 8007A5BC 1C3A020C */  jal        func_8008E870
    /* 6ADC0 8007A5C0 C41C8424 */   addiu     $a0, $a0, %lo(D_80011CC4)
    /* 6ADC4 8007A5C4 34E8010C */  jal        func_8007A0D0
    /* 6ADC8 8007A5C8 00000000 */   nop
    /* 6ADCC 8007A5CC 76E90108 */  j          .L8007A5D8
    /* 6ADD0 8007A5D0 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8007A5D4:
    /* 6ADD4 8007A5D4 21100000 */  addu       $v0, $zero, $zero
  .L8007A5D8:
    /* 6ADD8 8007A5D8 0B004014 */  bnez       $v0, .L8007A608
    /* 6ADDC 8007A5DC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6ADE0 8007A5E0 0980023C */  lui        $v0, %hi(D_800937D8)
    /* 6ADE4 8007A5E4 D837428C */  lw         $v0, %lo(D_800937D8)($v0)
    /* 6ADE8 8007A5E8 00000000 */  nop
    /* 6ADEC 8007A5EC 0000428C */  lw         $v0, 0x0($v0)
    /* 6ADF0 8007A5F0 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 6ADF4 8007A5F4 24104300 */  and        $v0, $v0, $v1
    /* 6ADF8 8007A5F8 03004010 */  beqz       $v0, .L8007A608
    /* 6ADFC 8007A5FC 21100000 */   addu      $v0, $zero, $zero
    /* 6AE00 8007A600 C9FF4012 */  beqz       $s2, .L8007A528
    /* 6AE04 8007A604 01000224 */   addiu     $v0, $zero, 0x1
  .L8007A608:
    /* 6AE08 8007A608 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 6AE0C 8007A60C 2800B48F */  lw         $s4, 0x28($sp)
    /* 6AE10 8007A610 2400B38F */  lw         $s3, 0x24($sp)
    /* 6AE14 8007A614 2000B28F */  lw         $s2, 0x20($sp)
    /* 6AE18 8007A618 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6AE1C 8007A61C 1800B08F */  lw         $s0, 0x18($sp)
    /* 6AE20 8007A620 0800E003 */  jr         $ra
    /* 6AE24 8007A624 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8007A4C0
