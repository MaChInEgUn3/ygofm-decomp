nonmatching func_80038BA8, 0x48

glabel func_80038BA8
    /* 293A8 80038BA8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 293AC 80038BAC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 293B0 80038BB0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 293B4 80038BB4 4FDB000C */  jal        func_80036D3C
    /* 293B8 80038BB8 21808000 */   addu      $s0, $a0, $zero
    /* 293BC 80038BBC 58000382 */  lb         $v1, 0x58($s0)
    /* 293C0 80038BC0 FFFF043C */  lui        $a0, (0xFFFF0000 >> 16)
    /* 293C4 80038BC4 80180300 */  sll        $v1, $v1, 2
    /* 293C8 80038BC8 21800302 */  addu       $s0, $s0, $v1
    /* 293CC 80038BCC 0000038E */  lw         $v1, 0x0($s0)
    /* 293D0 80038BD0 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 293D4 80038BD4 24186400 */  and        $v1, $v1, $a0
    /* 293D8 80038BD8 25186200 */  or         $v1, $v1, $v0
    /* 293DC 80038BDC 000003AE */  sw         $v1, 0x0($s0)
    /* 293E0 80038BE0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 293E4 80038BE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 293E8 80038BE8 0800E003 */  jr         $ra
    /* 293EC 80038BEC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80038BA8
