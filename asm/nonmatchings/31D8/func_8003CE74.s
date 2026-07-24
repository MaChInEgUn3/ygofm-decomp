nonmatching func_8003CE74, 0x44

glabel func_8003CE74
    /* 2D674 8003CE74 5C008627 */  addiu      $a2, $gp, %gp_rel(D_8009AF64)
    /* 2D678 8003CE78 0400C58C */  lw         $a1, 0x4($a2)
    /* 2D67C 8003CE7C 5C00838F */  lw         $v1, %gp_rel(D_8009AF64)($gp)
    /* 2D680 8003CE80 C0170500 */  sll        $v0, $a1, 31
    /* 2D684 8003CE84 42200300 */  srl        $a0, $v1, 1
    /* 2D688 8003CE88 25104400 */  or         $v0, $v0, $a0
    /* 2D68C 8003CE8C 00230300 */  sll        $a0, $v1, 12
    /* 2D690 8003CE90 26104400 */  xor        $v0, $v0, $a0
    /* 2D694 8003CE94 01006330 */  andi       $v1, $v1, 0x1
    /* 2D698 8003CE98 2118A300 */  addu       $v1, $a1, $v1
    /* 2D69C 8003CE9C 2128A300 */  addu       $a1, $a1, $v1
    /* 2D6A0 8003CEA0 021D0200 */  srl        $v1, $v0, 20
    /* 2D6A4 8003CEA4 26104300 */  xor        $v0, $v0, $v1
    /* 2D6A8 8003CEA8 0400C5AC */  sw         $a1, 0x4($a2)
    /* 2D6AC 8003CEAC 5C0082AF */  sw         $v0, %gp_rel(D_8009AF64)($gp)
    /* 2D6B0 8003CEB0 0800E003 */  jr         $ra
    /* 2D6B4 8003CEB4 00000000 */   nop
endlabel func_8003CE74
