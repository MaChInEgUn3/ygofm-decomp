nonmatching func_8003C568, 0xC0

glabel func_8003C568
    /* 2CD68 8003C568 F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* 2CD6C 8003C56C 0A80023C */  lui        $v0, %hi(D_8009AF5C)
    /* 2CD70 8003C570 5CAF4A24 */  addiu      $t2, $v0, %lo(D_8009AF5C)
    /* 2CD74 8003C574 03004789 */  lwl        $a3, 0x3($t2)
    /* 2CD78 8003C578 00004799 */  lwr        $a3, 0x0($t2)
    /* 2CD7C 8003C57C 04004885 */  lh         $t0, 0x4($t2)
    /* 2CD80 8003C580 0300A7AB */  swl        $a3, 0x3($sp)
    /* 2CD84 8003C584 0000A7BB */  swr        $a3, 0x0($sp)
    /* 2CD88 8003C588 0400A8A7 */  sh         $t0, 0x4($sp)
    /* 2CD8C 8003C58C 68000224 */  addiu      $v0, $zero, 0x68
    /* 2CD90 8003C590 0800A2A7 */  sh         $v0, 0x8($sp)
    /* 2CD94 8003C594 75048283 */  lb         $v0, %gp_rel(D_8009B37D)($gp)
    /* 2CD98 8003C598 7804858F */  lw         $a1, %gp_rel(D_8009B380)($gp)
    /* 2CD9C 8003C59C 8004868F */  lw         $a2, %gp_rel(D_8009B388)($gp)
    /* 2CDA0 8003C5A0 C8000324 */  addiu      $v1, $zero, 0xC8
    /* 2CDA4 8003C5A4 0A00A3A7 */  sh         $v1, 0xA($sp)
    /* 2CDA8 8003C5A8 40100200 */  sll        $v0, $v0, 1
    /* 2CDAC 8003C5AC 2110A203 */  addu       $v0, $sp, $v0
    /* 2CDB0 8003C5B0 08004394 */  lhu        $v1, 0x8($v0)
    /* 2CDB4 8003C5B4 48000224 */  addiu      $v0, $zero, 0x48
    /* 2CDB8 8003C5B8 3200A2A4 */  sh         $v0, 0x32($a1)
    /* 2CDBC 8003C5BC 20000224 */  addiu      $v0, $zero, 0x20
    /* 2CDC0 8003C5C0 3000A3A4 */  sh         $v1, 0x30($a1)
    /* 2CDC4 8003C5C4 3000C2A4 */  sh         $v0, 0x30($a2)
    /* 2CDC8 8003C5C8 40100400 */  sll        $v0, $a0, 1
    /* 2CDCC 8003C5CC 2110A203 */  addu       $v0, $sp, $v0
    /* 2CDD0 8003C5D0 00004294 */  lhu        $v0, 0x0($v0)
    /* 2CDD4 8003C5D4 00000000 */  nop
    /* 2CDD8 8003C5D8 08004224 */  addiu      $v0, $v0, 0x8
    /* 2CDDC 8003C5DC 0C008014 */  bnez       $a0, .L8003C610
    /* 2CDE0 8003C5E0 3200C2A4 */   sh        $v0, 0x32($a2)
    /* 2CDE4 8003C5E4 0800A294 */  lhu        $v0, 0x8($a1)
    /* 2CDE8 8003C5E8 3000A394 */  lhu        $v1, 0x30($a1)
    /* 2CDEC 8003C5EC BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* 2CDF0 8003C5F0 08006324 */  addiu      $v1, $v1, 0x8
    /* 2CDF4 8003C5F4 0800A2A4 */  sh         $v0, 0x8($a1)
    /* 2CDF8 8003C5F8 3000C3A4 */  sh         $v1, 0x30($a2)
    /* 2CDFC 8003C5FC 3200A294 */  lhu        $v0, 0x32($a1)
    /* 2CE00 8003C600 00000000 */  nop
    /* 2CE04 8003C604 08004224 */  addiu      $v0, $v0, 0x8
    /* 2CE08 8003C608 88F10008 */  j          .L8003C620
    /* 2CE0C 8003C60C 3200C2A4 */   sh        $v0, 0x32($a2)
  .L8003C610:
    /* 2CE10 8003C610 0800A294 */  lhu        $v0, 0x8($a1)
    /* 2CE14 8003C614 00000000 */  nop
    /* 2CE18 8003C618 40004234 */  ori        $v0, $v0, 0x40
    /* 2CE1C 8003C61C 0800A2A4 */  sh         $v0, 0x8($a1)
  .L8003C620:
    /* 2CE20 8003C620 0800E003 */  jr         $ra
    /* 2CE24 8003C624 1000BD27 */   addiu     $sp, $sp, 0x10
endlabel func_8003C568
