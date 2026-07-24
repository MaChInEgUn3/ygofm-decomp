nonmatching func_80038DB8, 0x64

glabel func_80038DB8
    /* 295B8 80038DB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 295BC 80038DBC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 295C0 80038DC0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 295C4 80038DC4 4FDB000C */  jal        func_80036D3C
    /* 295C8 80038DC8 21808000 */   addu      $s0, $a0, $zero
    /* 295CC 80038DCC FFFF043C */  lui        $a0, (0xFFFF0000 >> 16)
    /* 295D0 80038DD0 58000382 */  lb         $v1, 0x58($s0)
    /* 295D4 80038DD4 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 295D8 80038DD8 01006524 */  addiu      $a1, $v1, 0x1
    /* 295DC 80038DDC 80280500 */  sll        $a1, $a1, 2
    /* 295E0 80038DE0 80180300 */  sll        $v1, $v1, 2
    /* 295E4 80038DE4 21180302 */  addu       $v1, $s0, $v1
    /* 295E8 80038DE8 0000638C */  lw         $v1, 0x0($v1)
    /* 295EC 80038DEC 21280502 */  addu       $a1, $s0, $a1
    /* 295F0 80038DF0 24186400 */  and        $v1, $v1, $a0
    /* 295F4 80038DF4 25186200 */  or         $v1, $v1, $v0
    /* 295F8 80038DF8 0000A3AC */  sw         $v1, 0x0($a1)
    /* 295FC 80038DFC 58000292 */  lbu        $v0, 0x58($s0)
    /* 29600 80038E00 00000000 */  nop
    /* 29604 80038E04 01004224 */  addiu      $v0, $v0, 0x1
    /* 29608 80038E08 580002A2 */  sb         $v0, 0x58($s0)
    /* 2960C 80038E0C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 29610 80038E10 1000B08F */  lw         $s0, 0x10($sp)
    /* 29614 80038E14 0800E003 */  jr         $ra
    /* 29618 80038E18 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80038DB8
