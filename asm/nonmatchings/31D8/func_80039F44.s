nonmatching func_80039F44, 0x4C

glabel func_80039F44
    /* 2A744 80039F44 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A748 80039F48 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A74C 80039F4C 21808000 */  addu       $s0, $a0, $zero
    /* 2A750 80039F50 68000224 */  addiu      $v0, $zero, 0x68
    /* 2A754 80039F54 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2A758 80039F58 340002A6 */  sh         $v0, 0x34($s0)
    /* 2A75C 80039F5C B2000224 */  addiu      $v0, $zero, 0xB2
    /* 2A760 80039F60 320000A2 */  sb         $zero, 0x32($s0)
    /* 2A764 80039F64 330000A2 */  sb         $zero, 0x33($s0)
    /* 2A768 80039F68 310000A2 */  sb         $zero, 0x31($s0)
    /* 2A76C 80039F6C 6439020C */  jal        func_8008E590
    /* 2A770 80039F70 360002A6 */   sh        $v0, 0x36($s0)
    /* 2A774 80039F74 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2A778 80039F78 3C004224 */  addiu      $v0, $v0, 0x3C
    /* 2A77C 80039F7C 3E0002A6 */  sh         $v0, 0x3E($s0)
    /* 2A780 80039F80 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2A784 80039F84 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A788 80039F88 0800E003 */  jr         $ra
    /* 2A78C 80039F8C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80039F44
