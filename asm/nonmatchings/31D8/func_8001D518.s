nonmatching func_8001D518, 0x9C

glabel func_8001D518
    /* DD18 8001D518 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* DD1C 8001D51C 1800B0AF */  sw         $s0, 0x18($sp)
    /* DD20 8001D520 F002908F */  lw         $s0, %gp_rel(D_8009B1F8)($gp)
    /* DD24 8001D524 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* DD28 8001D528 21888000 */  addu       $s1, $a0, $zero
    /* DD2C 8001D52C 1B000016 */  bnez       $s0, .L8001D59C
    /* DD30 8001D530 2000BFAF */   sw        $ra, 0x20($sp)
    /* DD34 8001D534 0B00010C */  jal        func_8004002C
    /* DD38 8001D538 00000000 */   nop
    /* DD3C 8001D53C 21204000 */  addu       $a0, $v0, $zero
    /* DD40 8001D540 2B00010C */  jal        func_800400AC
    /* DD44 8001D544 02000524 */   addiu     $a1, $zero, 0x2
    /* DD48 8001D548 21804000 */  addu       $s0, $v0, $zero
    /* DD4C 8001D54C 21200002 */  addu       $a0, $s0, $zero
    /* DD50 8001D550 04000524 */  addiu      $a1, $zero, 0x4
    /* DD54 8001D554 0B000224 */  addiu      $v0, $zero, 0xB
    /* DD58 8001D558 1000A2AF */  sw         $v0, 0x10($sp)
    /* DD5C 8001D55C F0010224 */  addiu      $v0, $zero, 0x1F0
    /* DD60 8001D560 03000624 */  addiu      $a2, $zero, 0x3
    /* DD64 8001D564 08000724 */  addiu      $a3, $zero, 0x8
    /* DD68 8001D568 1A01010C */  jal        func_80040468
    /* DD6C 8001D56C 1400A2AF */   sw        $v0, 0x14($sp)
    /* DD70 8001D570 21200002 */  addu       $a0, $s0, $zero
    /* DD74 8001D574 0A002292 */  lbu        $v0, 0xA($s1)
    /* DD78 8001D578 01000524 */  addiu      $a1, $zero, 0x1
    /* DD7C 8001D57C 3B0A010C */  jal        func_800428EC
    /* DD80 8001D580 6A0002A2 */   sb        $v0, 0x6A($s0)
    /* DD84 8001D584 0180023C */  lui        $v0, %hi(func_80015DB8)
    /* DD88 8001D588 08000396 */  lhu        $v1, 0x8($s0)
    /* DD8C 8001D58C B85D4224 */  addiu      $v0, $v0, %lo(func_80015DB8)
    /* DD90 8001D590 240002AE */  sw         $v0, 0x24($s0)
    /* DD94 8001D594 08006334 */  ori        $v1, $v1, 0x8
    /* DD98 8001D598 080003A6 */  sh         $v1, 0x8($s0)
  .L8001D59C:
    /* DD9C 8001D59C 21100002 */  addu       $v0, $s0, $zero
    /* DDA0 8001D5A0 2000BF8F */  lw         $ra, 0x20($sp)
    /* DDA4 8001D5A4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* DDA8 8001D5A8 1800B08F */  lw         $s0, 0x18($sp)
    /* DDAC 8001D5AC 0800E003 */  jr         $ra
    /* DDB0 8001D5B0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8001D518
