nonmatching func_8008E3D0, 0x30

glabel func_8008E3D0
    /* 7EBD0 8008E3D0 09008010 */  beqz       $a0, .L8008E3F8
    /* 7EBD4 8008E3D4 21100000 */   addu      $v0, $zero, $zero
    /* 7EBD8 8008E3D8 0300C01C */  bgtz       $a2, .L8008E3E8
    /* 7EBDC 8008E3DC 21108000 */   addu      $v0, $a0, $zero
    /* 7EBE0 8008E3E0 FE380208 */  j          .L8008E3F8
    /* 7EBE4 8008E3E4 21100000 */   addu      $v0, $zero, $zero
  .L8008E3E8:
    /* 7EBE8 8008E3E8 000085A0 */  sb         $a1, 0x0($a0)
    /* 7EBEC 8008E3EC FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 7EBF0 8008E3F0 FDFFC01C */  bgtz       $a2, .L8008E3E8
    /* 7EBF4 8008E3F4 01008424 */   addiu     $a0, $a0, 0x1
  .L8008E3F8:
    /* 7EBF8 8008E3F8 0800E003 */  jr         $ra
    /* 7EBFC 8008E3FC 00000000 */   nop
endlabel func_8008E3D0
