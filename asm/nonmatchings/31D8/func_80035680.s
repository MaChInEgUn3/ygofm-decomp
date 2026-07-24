nonmatching func_80035680, 0x20

glabel func_80035680
    /* 25E80 80035680 0404828F */  lw         $v0, %gp_rel(D_8009B30C)($gp)
    /* 25E84 80035684 0C0480AF */  sw         $zero, %gp_rel(D_8009B314)($gp)
    /* 25E88 80035688 080484AF */  sw         $a0, %gp_rel(D_8009B310)($gp)
    /* 25E8C 8003568C FC0384AF */  sw         $a0, %gp_rel(D_8009B304)($gp)
    /* 25E90 80035690 04004234 */  ori        $v0, $v0, 0x4
    /* 25E94 80035694 040482AF */  sw         $v0, %gp_rel(D_8009B30C)($gp)
    /* 25E98 80035698 0800E003 */  jr         $ra
    /* 25E9C 8003569C 00000000 */   nop
endlabel func_80035680
