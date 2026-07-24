nonmatching func_8005F7B0, 0x78

glabel func_8005F7B0
    /* 4FFB0 8005F7B0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4FFB4 8005F7B4 2138A000 */  addu       $a3, $a1, $zero
    /* 4FFB8 8005F7B8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4FFBC 8005F7BC 73018393 */  lbu        $v1, %gp_rel(D_8009B07B)($gp)
    /* 4FFC0 8005F7C0 05000224 */  addiu      $v0, $zero, 0x5
    /* 4FFC4 8005F7C4 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 4FFC8 8005F7C8 01000224 */  addiu      $v0, $zero, 0x1
    /* 4FFCC 8005F7CC 1000A4A7 */  sh         $a0, 0x10($sp)
    /* 4FFD0 8005F7D0 1200A0A7 */  sh         $zero, 0x12($sp)
    /* 4FFD4 8005F7D4 05006214 */  bne        $v1, $v0, .L8005F7EC
    /* 4FFD8 8005F7D8 1400A0A7 */   sh        $zero, 0x14($sp)
    /* 4FFDC 8005F7DC 74018293 */  lbu        $v0, %gp_rel(D_8009B07C)($gp)
    /* 4FFE0 8005F7E0 00000000 */  nop
    /* 4FFE4 8005F7E4 0C004310 */  beq        $v0, $v1, .L8005F818
    /* 4FFE8 8005F7E8 00000000 */   nop
  .L8005F7EC:
    /* 4FFEC 8005F7EC 72018483 */  lb         $a0, %gp_rel(D_8009B07A)($gp)
    /* 4FFF0 8005F7F0 72018293 */  lbu        $v0, %gp_rel(D_8009B07A)($gp)
    /* 4FFF4 8005F7F4 03008104 */  bgez       $a0, .L8005F804
    /* 4FFF8 8005F7F8 01004224 */   addiu     $v0, $v0, 0x1
    /* 4FFFC 8005F7FC 037E0108 */  j          .L8005F80C
    /* 50000 8005F800 21200000 */   addu      $a0, $zero, $zero
  .L8005F804:
    /* 50004 8005F804 720182A3 */  sb         $v0, %gp_rel(D_8009B07A)($gp)
    /* 50008 8005F808 2A200400 */  slt        $a0, $zero, $a0
  .L8005F80C:
    /* 5000C 8005F80C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 50010 8005F810 477E010C */  jal        func_8005F91C
    /* 50014 8005F814 2130A000 */   addu      $a2, $a1, $zero
  .L8005F818:
    /* 50018 8005F818 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5001C 8005F81C 00000000 */  nop
    /* 50020 8005F820 0800E003 */  jr         $ra
    /* 50024 8005F824 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8005F7B0
