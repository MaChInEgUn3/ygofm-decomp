nonmatching func_80035668, 0x18

glabel func_80035668
    /* 25E68 80035668 8000023C */  lui        $v0, (0x808080 >> 16)
    /* 25E6C 8003566C 80804234 */  ori        $v0, $v0, (0x808080 & 0xFFFF)
    /* 25E70 80035670 040484AF */  sw         $a0, %gp_rel(D_8009B30C)($gp)
    /* 25E74 80035674 F80382AF */  sw         $v0, %gp_rel(D_8009B300)($gp)
    /* 25E78 80035678 0800E003 */  jr         $ra
    /* 25E7C 8003567C 00000000 */   nop
endlabel func_80035668
