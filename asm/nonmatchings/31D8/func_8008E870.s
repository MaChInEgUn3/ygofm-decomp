nonmatching func_8008E870, 0x3C

glabel func_8008E870
    /* 7F070 8008E870 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7F074 8008E874 1C00A227 */  addiu      $v0, $sp, 0x1C
    /* 7F078 8008E878 1800A4AF */  sw         $a0, 0x18($sp)
    /* 7F07C 8008E87C 01000424 */  addiu      $a0, $zero, 0x1
    /* 7F080 8008E880 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7F084 8008E884 1C00A5AF */  sw         $a1, 0x1C($sp)
    /* 7F088 8008E888 040046AC */  sw         $a2, 0x4($v0)
    /* 7F08C 8008E88C 080047AC */  sw         $a3, 0x8($v0)
    /* 7F090 8008E890 1800A58F */  lw         $a1, 0x18($sp)
    /* 7F094 8008E894 2C3A020C */  jal        func_8008E8B0
    /* 7F098 8008E898 21304000 */   addu      $a2, $v0, $zero
    /* 7F09C 8008E89C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7F0A0 8008E8A0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7F0A4 8008E8A4 0800E003 */  jr         $ra
    /* 7F0A8 8008E8A8 00000000 */   nop
endlabel func_8008E870
    /* 7F0AC 8008E8AC 00000000 */  nop
