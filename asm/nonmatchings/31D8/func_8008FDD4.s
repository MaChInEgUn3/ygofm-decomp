nonmatching func_8008FDD4, 0x3C

glabel func_8008FDD4
    /* 805D4 8008FDD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 805D8 8008FDD8 05008014 */  bnez       $a0, .L8008FDF0
    /* 805DC 8008FDDC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 805E0 8008FDE0 2B40020C */  jal        func_800900AC
    /* 805E4 8008FDE4 00000000 */   nop
    /* 805E8 8008FDE8 803F0208 */  j          .L8008FE00
    /* 805EC 8008FDEC 00000000 */   nop
  .L8008FDF0:
    /* 805F0 8008FDF0 7540020C */  jal        func_800901D4
    /* 805F4 8008FDF4 00000000 */   nop
    /* 805F8 8008FDF8 42170200 */  srl        $v0, $v0, 29
    /* 805FC 8008FDFC 01004230 */  andi       $v0, $v0, 0x1
  .L8008FE00:
    /* 80600 8008FE00 1000BF8F */  lw         $ra, 0x10($sp)
    /* 80604 8008FE04 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 80608 8008FE08 0800E003 */  jr         $ra
    /* 8060C 8008FE0C 00000000 */   nop
endlabel func_8008FDD4
