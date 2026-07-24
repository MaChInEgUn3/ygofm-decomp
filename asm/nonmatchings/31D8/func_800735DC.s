nonmatching func_800735DC, 0x48

glabel func_800735DC
    /* 63DDC 800735DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 63DE0 800735E0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 63DE4 800735E4 63C1010C */  jal        func_8007058C
    /* 63DE8 800735E8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 63DEC 800735EC 63C1010C */  jal        func_8007058C
    /* 63DF0 800735F0 21804000 */   addu      $s0, $v0, $zero
    /* 63DF4 800735F4 0F80033C */  lui        $v1, %hi(D_800F5B98)
    /* 63DF8 800735F8 985B6324 */  addiu      $v1, $v1, %lo(D_800F5B98)
    /* 63DFC 800735FC 80100200 */  sll        $v0, $v0, 2
    /* 63E00 80073600 80801000 */  sll        $s0, $s0, 2
    /* 63E04 80073604 21800302 */  addu       $s0, $s0, $v1
    /* 63E08 80073608 0000048E */  lw         $a0, 0x0($s0)
    /* 63E0C 8007360C 21104300 */  addu       $v0, $v0, $v1
    /* 63E10 80073610 000044AC */  sw         $a0, 0x0($v0)
    /* 63E14 80073614 1400BF8F */  lw         $ra, 0x14($sp)
    /* 63E18 80073618 1000B08F */  lw         $s0, 0x10($sp)
    /* 63E1C 8007361C 0800E003 */  jr         $ra
    /* 63E20 80073620 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800735DC
