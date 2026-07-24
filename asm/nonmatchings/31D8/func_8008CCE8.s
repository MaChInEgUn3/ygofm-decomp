nonmatching func_8008CCE8, 0x11C

glabel func_8008CCE8
    /* 7D4E8 8008CCE8 1080033C */  lui        $v1, %hi(D_800FE348)
    /* 7D4EC 8008CCEC 48E36324 */  addiu      $v1, $v1, %lo(D_800FE348)
    /* 7D4F0 8008CCF0 0000628C */  lw         $v0, 0x0($v1)
    /* 7D4F4 8008CCF4 00000000 */  nop
    /* 7D4F8 8008CCF8 05004014 */  bnez       $v0, .L8008CD10
    /* 7D4FC 8008CCFC 00000000 */   nop
    /* 7D500 8008CD00 0800628C */  lw         $v0, 0x8($v1)
    /* 7D504 8008CD04 00000000 */  nop
    /* 7D508 8008CD08 3C004010 */  beqz       $v0, .L8008CDFC
    /* 7D50C 8008CD0C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8008CD10:
    /* 7D510 8008CD10 0000688C */  lw         $t0, 0x0($v1)
    /* 7D514 8008CD14 0400678C */  lw         $a3, 0x4($v1)
    /* 7D518 8008CD18 1D008014 */  bnez       $a0, .L8008CD90
    /* 7D51C 8008CD1C 00000000 */   nop
    /* 7D520 8008CD20 0800628C */  lw         $v0, 0x8($v1)
    /* 7D524 8008CD24 00000000 */  nop
    /* 7D528 8008CD28 06004014 */  bnez       $v0, .L8008CD44
    /* 7D52C 8008CD2C 00000000 */   nop
    /* 7D530 8008CD30 08006324 */  addiu      $v1, $v1, 0x8
  .L8008CD34:
    /* 7D534 8008CD34 0000628C */  lw         $v0, 0x0($v1)
    /* 7D538 8008CD38 00000000 */  nop
    /* 7D53C 8008CD3C FDFF4010 */  beqz       $v0, .L8008CD34
    /* 7D540 8008CD40 00000000 */   nop
  .L8008CD44:
    /* 7D544 8008CD44 0600C010 */  beqz       $a2, .L8008CD60
    /* 7D548 8008CD48 00000000 */   nop
    /* 7D54C 8008CD4C 1080023C */  lui        $v0, %hi(D_800FE33C)
    /* 7D550 8008CD50 3CE34224 */  addiu      $v0, $v0, %lo(D_800FE33C)
    /* 7D554 8008CD54 0000428C */  lw         $v0, 0x0($v0)
    /* 7D558 8008CD58 00000000 */  nop
    /* 7D55C 8008CD5C 0000C2AC */  sw         $v0, 0x0($a2)
  .L8008CD60:
    /* 7D560 8008CD60 0600A010 */  beqz       $a1, .L8008CD7C
    /* 7D564 8008CD64 00000000 */   nop
    /* 7D568 8008CD68 1080023C */  lui        $v0, %hi(D_800FE338)
    /* 7D56C 8008CD6C 38E34224 */  addiu      $v0, $v0, %lo(D_800FE338)
    /* 7D570 8008CD70 0000428C */  lw         $v0, 0x0($v0)
    /* 7D574 8008CD74 00000000 */  nop
    /* 7D578 8008CD78 0000A2AC */  sw         $v0, 0x0($a1)
  .L8008CD7C:
    /* 7D57C 8008CD7C 1080023C */  lui        $v0, %hi(D_800FE348)
    /* 7D580 8008CD80 48E34224 */  addiu      $v0, $v0, %lo(D_800FE348)
    /* 7D584 8008CD84 080040AC */  sw         $zero, 0x8($v0)
    /* 7D588 8008CD88 7F330208 */  j          .L8008CDFC
    /* 7D58C 8008CD8C 01000224 */   addiu     $v0, $zero, 0x1
  .L8008CD90:
    /* 7D590 8008CD90 0800628C */  lw         $v0, 0x8($v1)
    /* 7D594 8008CD94 00000000 */  nop
    /* 7D598 8008CD98 08004014 */  bnez       $v0, .L8008CDBC
    /* 7D59C 8008CD9C 00000000 */   nop
    /* 7D5A0 8008CDA0 0200C010 */  beqz       $a2, .L8008CDAC
    /* 7D5A4 8008CDA4 00000000 */   nop
    /* 7D5A8 8008CDA8 0000C7AC */  sw         $a3, 0x0($a2)
  .L8008CDAC:
    /* 7D5AC 8008CDAC 1300A010 */  beqz       $a1, .L8008CDFC
    /* 7D5B0 8008CDB0 21100000 */   addu      $v0, $zero, $zero
    /* 7D5B4 8008CDB4 7F330208 */  j          .L8008CDFC
    /* 7D5B8 8008CDB8 0000A8AC */   sw        $t0, 0x0($a1)
  .L8008CDBC:
    /* 7D5BC 8008CDBC 0600C010 */  beqz       $a2, .L8008CDD8
    /* 7D5C0 8008CDC0 00000000 */   nop
    /* 7D5C4 8008CDC4 1080023C */  lui        $v0, %hi(D_800FE33C)
    /* 7D5C8 8008CDC8 3CE34224 */  addiu      $v0, $v0, %lo(D_800FE33C)
    /* 7D5CC 8008CDCC 0000428C */  lw         $v0, 0x0($v0)
    /* 7D5D0 8008CDD0 00000000 */  nop
    /* 7D5D4 8008CDD4 0000C2AC */  sw         $v0, 0x0($a2)
  .L8008CDD8:
    /* 7D5D8 8008CDD8 0600A010 */  beqz       $a1, .L8008CDF4
    /* 7D5DC 8008CDDC 00000000 */   nop
    /* 7D5E0 8008CDE0 1080023C */  lui        $v0, %hi(D_800FE338)
    /* 7D5E4 8008CDE4 38E34224 */  addiu      $v0, $v0, %lo(D_800FE338)
    /* 7D5E8 8008CDE8 0000428C */  lw         $v0, 0x0($v0)
    /* 7D5EC 8008CDEC 00000000 */  nop
    /* 7D5F0 8008CDF0 0000A2AC */  sw         $v0, 0x0($a1)
  .L8008CDF4:
    /* 7D5F4 8008CDF4 080060AC */  sw         $zero, 0x8($v1)
    /* 7D5F8 8008CDF8 01000224 */  addiu      $v0, $zero, 0x1
  .L8008CDFC:
    /* 7D5FC 8008CDFC 0800E003 */  jr         $ra
    /* 7D600 8008CE00 00000000 */   nop
endlabel func_8008CCE8
