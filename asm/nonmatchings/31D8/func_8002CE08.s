nonmatching func_8002CE08, 0x5C

glabel func_8002CE08
    /* 1D608 8002CE08 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1D60C 8002CE0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D610 8002CE10 40006230 */  andi       $v0, $v1, 0x40
    /* 1D614 8002CE14 07004014 */  bnez       $v0, .L8002CE34
    /* 1D618 8002CE18 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1D61C 8002CE1C 40006234 */  ori        $v0, $v1, 0x40
    /* 1D620 8002CE20 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D624 8002CE24 66C0000C */  jal        func_80030198
    /* 1D628 8002CE28 00000000 */   nop
    /* 1D62C 8002CE2C 95B30008 */  j          .L8002CE54
    /* 1D630 8002CE30 00000000 */   nop
  .L8002CE34:
    /* 1D634 8002CE34 21C4000C */  jal        func_80031084
    /* 1D638 8002CE38 00000000 */   nop
    /* 1D63C 8002CE3C 64038293 */  lbu        $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D640 8002CE40 00000000 */  nop
    /* 1D644 8002CE44 40004230 */  andi       $v0, $v0, 0x40
    /* 1D648 8002CE48 02004014 */  bnez       $v0, .L8002CE54
    /* 1D64C 8002CE4C 00000000 */   nop
    /* 1D650 8002CE50 610380A3 */  sb         $zero, %gp_rel(D_8009B269)($gp)
  .L8002CE54:
    /* 1D654 8002CE54 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D658 8002CE58 00000000 */  nop
    /* 1D65C 8002CE5C 0800E003 */  jr         $ra
    /* 1D660 8002CE60 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002CE08
