nonmatching func_8003CCD8, 0x120

glabel func_8003CCD8
    /* 2D4D8 8003CCD8 21280000 */  addu       $a1, $zero, $zero
    /* 2D4DC 8003CCDC 1F000824 */  addiu      $t0, $zero, 0x1F
    /* 2D4E0 8003CCE0 0F80023C */  lui        $v0, %hi(D_800EF6B0)
    /* 2D4E4 8003CCE4 B0F64224 */  addiu      $v0, $v0, %lo(D_800EF6B0)
    /* 2D4E8 8003CCE8 21204800 */  addu       $a0, $v0, $t0
    /* 2D4EC 8003CCEC A0048A8F */  lw         $t2, %gp_rel(D_8009B3A8)($gp)
    /* 2D4F0 8003CCF0 8804828F */  lw         $v0, %gp_rel(D_8009B390)($gp)
    /* 2D4F4 8003CCF4 00800B3C */  lui        $t3, (0x80000000 >> 16)
    /* 2D4F8 8003CCF8 A00480AF */  sw         $zero, %gp_rel(D_8009B3A8)($gp)
    /* 2D4FC 8003CCFC 21384001 */  addu       $a3, $t2, $zero
    /* 2D500 8003CD00 26104A00 */  xor        $v0, $v0, $t2
    /* 2D504 8003CD04 24484A00 */  and        $t1, $v0, $t2
    /* 2D508 8003CD08 21302001 */  addu       $a2, $t1, $zero
    /* 2D50C 8003CD0C 88048AAF */  sw         $t2, %gp_rel(D_8009B390)($gp)
  .L8003CD10:
    /* 2D510 8003CD10 2410EB00 */  and        $v0, $a3, $t3
    /* 2D514 8003CD14 14004010 */  beqz       $v0, .L8003CD68
    /* 2D518 8003CD18 40280500 */   sll       $a1, $a1, 1
    /* 2D51C 8003CD1C 2410CB00 */  and        $v0, $a2, $t3
    /* 2D520 8003CD20 02004010 */  beqz       $v0, .L8003CD2C
    /* 2D524 8003CD24 00000000 */   nop
    /* 2D528 8003CD28 0100A534 */  ori        $a1, $a1, 0x1
  .L8003CD2C:
    /* 2D52C 8003CD2C 00008290 */  lbu        $v0, 0x0($a0)
    /* 2D530 8003CD30 0A80033C */  lui        $v1, %hi(D_8009B0D8)
    /* 2D534 8003CD34 D8B06390 */  lbu        $v1, %lo(D_8009B0D8)($v1)
    /* 2D538 8003CD38 00000000 */  nop
    /* 2D53C 8003CD3C 21104300 */  addu       $v0, $v0, $v1
    /* 2D540 8003CD40 000082A0 */  sb         $v0, 0x0($a0)
    /* 2D544 8003CD44 94048393 */  lbu        $v1, %gp_rel(D_8009B39C)($gp)
    /* 2D548 8003CD48 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2D54C 8003CD4C 2B104300 */  sltu       $v0, $v0, $v1
    /* 2D550 8003CD50 06004014 */  bnez       $v0, .L8003CD6C
    /* 2D554 8003CD54 00000000 */   nop
    /* 2D558 8003CD58 9A048293 */  lbu        $v0, %gp_rel(D_8009B3A2)($gp)
    /* 2D55C 8003CD5C 0100A534 */  ori        $a1, $a1, 0x1
    /* 2D560 8003CD60 5BF30008 */  j          .L8003CD6C
    /* 2D564 8003CD64 000082A0 */   sb        $v0, 0x0($a0)
  .L8003CD68:
    /* 2D568 8003CD68 000080A0 */  sb         $zero, 0x0($a0)
  .L8003CD6C:
    /* 2D56C 8003CD6C 40380700 */  sll        $a3, $a3, 1
    /* 2D570 8003CD70 40300600 */  sll        $a2, $a2, 1
    /* 2D574 8003CD74 FFFF0825 */  addiu      $t0, $t0, -0x1
    /* 2D578 8003CD78 E5FF0105 */  bgez       $t0, .L8003CD10
    /* 2D57C 8003CD7C FFFF8424 */   addiu     $a0, $a0, -0x1
    /* 2D580 8003CD80 0A80023C */  lui        $v0, %hi(D_8009B0C8)
    /* 2D584 8003CD84 C8B0428C */  lw         $v0, %lo(D_8009B0C8)($v0)
    /* 2D588 8003CD88 00000000 */  nop
    /* 2D58C 8003CD8C 09004010 */  beqz       $v0, .L8003CDB4
    /* 2D590 8003CD90 00000000 */   nop
    /* 2D594 8003CD94 A804828F */  lw         $v0, %gp_rel(D_8009B3B0)($gp)
    /* 2D598 8003CD98 AC04838F */  lw         $v1, %gp_rel(D_8009B3B4)($gp)
    /* 2D59C 8003CD9C 25104500 */  or         $v0, $v0, $a1
    /* 2D5A0 8003CDA0 25186900 */  or         $v1, $v1, $t1
    /* 2D5A4 8003CDA4 A80482AF */  sw         $v0, %gp_rel(D_8009B3B0)($gp)
    /* 2D5A8 8003CDA8 AC0483AF */  sw         $v1, %gp_rel(D_8009B3B4)($gp)
    /* 2D5AC 8003CDAC 74F30008 */  j          .L8003CDD0
    /* 2D5B0 8003CDB0 02140A00 */   srl       $v0, $t2, 16
  .L8003CDB4:
    /* 2D5B4 8003CDB4 AC04828F */  lw         $v0, %gp_rel(D_8009B3B4)($gp)
    /* 2D5B8 8003CDB8 A804838F */  lw         $v1, %gp_rel(D_8009B3B0)($gp)
    /* 2D5BC 8003CDBC A80480AF */  sw         $zero, %gp_rel(D_8009B3B0)($gp)
    /* 2D5C0 8003CDC0 AC0480AF */  sw         $zero, %gp_rel(D_8009B3B4)($gp)
    /* 2D5C4 8003CDC4 25482201 */  or         $t1, $t1, $v0
    /* 2D5C8 8003CDC8 2528A300 */  or         $a1, $a1, $v1
    /* 2D5CC 8003CDCC 02140A00 */  srl        $v0, $t2, 16
  .L8003CDD0:
    /* 2D5D0 8003CDD0 9C048AA7 */  sh         $t2, %gp_rel(D_8009B3A4)($gp)
    /* 2D5D4 8003CDD4 9E0482A7 */  sh         $v0, %gp_rel(D_8009B3A6)($gp)
    /* 2D5D8 8003CDD8 02140900 */  srl        $v0, $t1, 16
    /* 2D5DC 8003CDDC 900489A7 */  sh         $t1, %gp_rel(D_8009B398)($gp)
    /* 2D5E0 8003CDE0 920482A7 */  sh         $v0, %gp_rel(D_8009B39A)($gp)
    /* 2D5E4 8003CDE4 02140500 */  srl        $v0, $a1, 16
    /* 2D5E8 8003CDE8 8C0485A7 */  sh         $a1, %gp_rel(D_8009B394)($gp)
    /* 2D5EC 8003CDEC 8E0482A7 */  sh         $v0, %gp_rel(D_8009B396)($gp)
    /* 2D5F0 8003CDF0 0800E003 */  jr         $ra
    /* 2D5F4 8003CDF4 00000000 */   nop
endlabel func_8003CCD8
