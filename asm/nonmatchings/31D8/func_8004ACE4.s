nonmatching func_8004ACE4, 0x104

glabel func_8004ACE4
    /* 3B4E4 8004ACE4 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 3B4E8 8004ACE8 2800B0AF */  sw         $s0, 0x28($sp)
    /* 3B4EC 8004ACEC 21808000 */  addu       $s0, $a0, $zero
    /* 3B4F0 8004ACF0 3000BFAF */  sw         $ra, 0x30($sp)
    /* 3B4F4 8004ACF4 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 3B4F8 8004ACF8 11000392 */  lbu        $v1, 0x11($s0)
    /* 3B4FC 8004ACFC 0F000224 */  addiu      $v0, $zero, 0xF
    /* 3B500 8004AD00 05006210 */  beq        $v1, $v0, .L8004AD18
    /* 3B504 8004AD04 10000224 */   addiu     $v0, $zero, 0x10
    /* 3B508 8004AD08 21006210 */  beq        $v1, $v0, .L8004AD90
    /* 3B50C 8004AD0C 06000224 */   addiu     $v0, $zero, 0x6
    /* 3B510 8004AD10 752B0108 */  j          .L8004ADD4
    /* 3B514 8004AD14 00000000 */   nop
  .L8004AD18:
    /* 3B518 8004AD18 70D7010C */  jal        func_80075DC0
    /* 3B51C 8004AD1C 01001124 */   addiu     $s1, $zero, 0x1
    /* 3B520 8004AD20 03005114 */  bne        $v0, $s1, .L8004AD30
    /* 3B524 8004AD24 00000000 */   nop
    /* 3B528 8004AD28 F8D6010C */  jal        func_80075BE0
    /* 3B52C 8004AD2C 21200000 */   addu      $a0, $zero, $zero
  .L8004AD30:
    /* 3B530 8004AD30 F8D9010C */  jal        func_800767E0
    /* 3B534 8004AD34 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 3B538 8004AD38 03004010 */  beqz       $v0, .L8004AD48
    /* 3B53C 8004AD3C 00000000 */   nop
    /* 3B540 8004AD40 E4D9010C */  jal        func_80076790
    /* 3B544 8004AD44 21200000 */   addu      $a0, $zero, $zero
  .L8004AD48:
    /* 3B548 8004AD48 1000B1AF */  sw         $s1, 0x10($sp)
    /* 3B54C 8004AD4C 13000292 */  lbu        $v0, 0x13($s0)
    /* 3B550 8004AD50 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3B554 8004AD54 78D7010C */  jal        func_80075DE0
    /* 3B558 8004AD58 1400A2AF */   sw        $v0, 0x14($sp)
    /* 3B55C 8004AD5C F8D9010C */  jal        func_800767E0
    /* 3B560 8004AD60 FEFF0424 */   addiu     $a0, $zero, -0x2
    /* 3B564 8004AD64 03004010 */  beqz       $v0, .L8004AD74
    /* 3B568 8004AD68 00000000 */   nop
    /* 3B56C 8004AD6C E4D9010C */  jal        func_80076790
    /* 3B570 8004AD70 01000424 */   addiu     $a0, $zero, 0x1
  .L8004AD74:
    /* 3B574 8004AD74 F8D6010C */  jal        func_80075BE0
    /* 3B578 8004AD78 01000424 */   addiu     $a0, $zero, 0x1
    /* 3B57C 8004AD7C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B580 8004AD80 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B584 8004AD84 13000292 */  lbu        $v0, 0x13($s0)
    /* 3B588 8004AD88 752B0108 */  j          .L8004ADD4
    /* 3B58C 8004AD8C 440862A0 */   sb        $v0, 0x844($v1)
  .L8004AD90:
    /* 3B590 8004AD90 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3B594 8004AD94 13000292 */  lbu        $v0, 0x13($s0)
    /* 3B598 8004AD98 00000000 */  nop
    /* 3B59C 8004AD9C 00120200 */  sll        $v0, $v0, 8
    /* 3B5A0 8004ADA0 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 3B5A4 8004ADA4 13000292 */  lbu        $v0, 0x13($s0)
    /* 3B5A8 8004ADA8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3B5AC 8004ADAC 00120200 */  sll        $v0, $v0, 8
    /* 3B5B0 8004ADB0 78D7010C */  jal        func_80075DE0
    /* 3B5B4 8004ADB4 1A00A2A7 */   sh        $v0, 0x1A($sp)
    /* 3B5B8 8004ADB8 F8D6010C */  jal        func_80075BE0
    /* 3B5BC 8004ADBC 01000424 */   addiu     $a0, $zero, 0x1
    /* 3B5C0 8004ADC0 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B5C4 8004ADC4 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B5C8 8004ADC8 13000292 */  lbu        $v0, 0x13($s0)
    /* 3B5CC 8004ADCC 00000000 */  nop
    /* 3B5D0 8004ADD0 450862A0 */  sb         $v0, 0x845($v1)
  .L8004ADD4:
    /* 3B5D4 8004ADD4 3000BF8F */  lw         $ra, 0x30($sp)
    /* 3B5D8 8004ADD8 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 3B5DC 8004ADDC 2800B08F */  lw         $s0, 0x28($sp)
    /* 3B5E0 8004ADE0 0800E003 */  jr         $ra
    /* 3B5E4 8004ADE4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8004ACE4
