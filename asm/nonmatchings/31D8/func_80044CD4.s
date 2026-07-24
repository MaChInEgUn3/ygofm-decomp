nonmatching func_80044CD4, 0x28

glabel func_80044CD4
    /* 354D4 80044CD4 3C05858F */  lw         $a1, %gp_rel(D_8009B444)($gp)
    /* 354D8 80044CD8 3805868F */  lw         $a2, %gp_rel(D_8009B440)($gp)
    /* 354DC 80044CDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 354E0 80044CE0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 354E4 80044CE4 6611010C */  jal        func_80044598
    /* 354E8 80044CE8 00000000 */   nop
    /* 354EC 80044CEC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 354F0 80044CF0 00000000 */  nop
    /* 354F4 80044CF4 0800E003 */  jr         $ra
    /* 354F8 80044CF8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80044CD4
