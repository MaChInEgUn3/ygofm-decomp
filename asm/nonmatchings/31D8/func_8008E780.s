nonmatching func_8008E780, 0x80

glabel func_8008E780
    /* 7EF80 8008E780 03008010 */  beqz       $a0, .L8008E790
    /* 7EF84 8008E784 00000000 */   nop
    /* 7EF88 8008E788 0700A014 */  bnez       $a1, .L8008E7A8
    /* 7EF8C 8008E78C 00000000 */   nop
  .L8008E790:
    /* 7EF90 8008E790 19008510 */  beq        $a0, $a1, .L8008E7F8
    /* 7EF94 8008E794 21100000 */   addu      $v0, $zero, $zero
    /* 7EF98 8008E798 17008010 */  beqz       $a0, .L8008E7F8
    /* 7EF9C 8008E79C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 7EFA0 8008E7A0 FE390208 */  j          .L8008E7F8
    /* 7EFA4 8008E7A4 01000224 */   addiu     $v0, $zero, 0x1
  .L8008E7A8:
    /* 7EFA8 8008E7A8 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 7EFAC 8008E7AC 1200C004 */  bltz       $a2, .L8008E7F8
    /* 7EFB0 8008E7B0 21100000 */   addu      $v0, $zero, $zero
  .L8008E7B4:
    /* 7EFB4 8008E7B4 00008380 */  lb         $v1, 0x0($a0)
    /* 7EFB8 8008E7B8 0000A280 */  lb         $v0, 0x0($a1)
    /* 7EFBC 8008E7BC 00000000 */  nop
    /* 7EFC0 8008E7C0 06006214 */  bne        $v1, $v0, .L8008E7DC
    /* 7EFC4 8008E7C4 0100A524 */   addiu     $a1, $a1, 0x1
    /* 7EFC8 8008E7C8 0A006010 */  beqz       $v1, .L8008E7F4
    /* 7EFCC 8008E7CC 01008424 */   addiu     $a0, $a0, 0x1
    /* 7EFD0 8008E7D0 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 7EFD4 8008E7D4 F7FFC104 */  bgez       $a2, .L8008E7B4
    /* 7EFD8 8008E7D8 00000000 */   nop
  .L8008E7DC:
    /* 7EFDC 8008E7DC 0500C004 */  bltz       $a2, .L8008E7F4
    /* 7EFE0 8008E7E0 00000000 */   nop
    /* 7EFE4 8008E7E4 00008380 */  lb         $v1, 0x0($a0)
    /* 7EFE8 8008E7E8 FFFFA280 */  lb         $v0, -0x1($a1)
    /* 7EFEC 8008E7EC FE390208 */  j          .L8008E7F8
    /* 7EFF0 8008E7F0 23106200 */   subu      $v0, $v1, $v0
  .L8008E7F4:
    /* 7EFF4 8008E7F4 21100000 */  addu       $v0, $zero, $zero
  .L8008E7F8:
    /* 7EFF8 8008E7F8 0800E003 */  jr         $ra
    /* 7EFFC 8008E7FC 00000000 */   nop
endlabel func_8008E780
