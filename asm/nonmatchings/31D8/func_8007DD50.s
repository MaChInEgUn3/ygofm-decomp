nonmatching func_8007DD50, 0x84

glabel func_8007DD50
    /* 6E550 8007DD50 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6E554 8007DD54 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6E558 8007DD58 0980103C */  lui        $s0, %hi(D_80093A38)
    /* 6E55C 8007DD5C 383A1026 */  addiu      $s0, $s0, %lo(D_80093A38)
    /* 6E560 8007DD60 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6E564 8007DD64 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6E568 8007DD68 0000028E */  lw         $v0, 0x0($s0)
    /* 6E56C 8007DD6C 01001124 */  addiu      $s1, $zero, 0x1
    /* 6E570 8007DD70 12005110 */  beq        $v0, $s1, .L8007DDBC
    /* 6E574 8007DD74 21188000 */   addu      $v1, $a0, $zero
    /* 6E578 8007DD78 0880043C */  lui        $a0, %hi(func_8007DE4C)
    /* 6E57C 8007DD7C 4CDE8424 */  addiu      $a0, $a0, %lo(func_8007DE4C)
    /* 6E580 8007DD80 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 6E584 8007DD84 E0FF02AE */  sw         $v0, -0x20($s0)
    /* 6E588 8007DD88 E4FF00AE */  sw         $zero, -0x1C($s0)
    /* 6E58C 8007DD8C ECFF00AE */  sw         $zero, -0x14($s0)
    /* 6E590 8007DD90 E8FF03AE */  sw         $v1, -0x18($s0)
    /* 6E594 8007DD94 18FA010C */  jal        func_8007E860
    /* 6E598 8007DD98 F0FF05AE */   sw        $a1, -0x10($s0)
    /* 6E59C 8007DD9C 0880043C */  lui        $a0, %hi(func_8007E128)
    /* 6E5A0 8007DDA0 28E18424 */  addiu      $a0, $a0, %lo(func_8007E128)
    /* 6E5A4 8007DDA4 20FA010C */  jal        func_8007E880
    /* 6E5A8 8007DDA8 F4FF02AE */   sw        $v0, -0xC($s0)
    /* 6E5AC 8007DDAC F8FF02AE */  sw         $v0, -0x8($s0)
    /* 6E5B0 8007DDB0 01000224 */  addiu      $v0, $zero, 0x1
    /* 6E5B4 8007DDB4 70F70108 */  j          .L8007DDC0
    /* 6E5B8 8007DDB8 000011AE */   sw        $s1, 0x0($s0)
  .L8007DDBC:
    /* 6E5BC 8007DDBC 21100000 */  addu       $v0, $zero, $zero
  .L8007DDC0:
    /* 6E5C0 8007DDC0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6E5C4 8007DDC4 1400B18F */  lw         $s1, 0x14($sp)
    /* 6E5C8 8007DDC8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6E5CC 8007DDCC 0800E003 */  jr         $ra
    /* 6E5D0 8007DDD0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007DD50
