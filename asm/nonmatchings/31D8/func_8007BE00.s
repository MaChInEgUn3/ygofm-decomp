nonmatching func_8007BE00, 0x40

glabel func_8007BE00
    /* 6C600 8007BE00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C604 8007BE04 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C608 8007BE08 0980013C */  lui        $at, %hi(D_80093880)
    /* 6C60C 8007BE0C 34E8010C */  jal        func_8007A0D0
    /* 6C610 8007BE10 803820AC */   sw        $zero, %lo(D_80093880)($at)
    /* 6C614 8007BE14 21200000 */  addu       $a0, $zero, $zero
    /* 6C618 8007BE18 0980013C */  lui        $at, %hi(D_800934E0)
    /* 6C61C 8007BE1C E03420AC */  sw         $zero, %lo(D_800934E0)($at)
    /* 6C620 8007BE20 0980013C */  lui        $at, %hi(D_800934E4)
    /* 6C624 8007BE24 E43420AC */  sw         $zero, %lo(D_800934E4)($at)
    /* 6C628 8007BE28 15D1010C */  jal        func_80074454
    /* 6C62C 8007BE2C 21280000 */   addu      $a1, $zero, $zero
    /* 6C630 8007BE30 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C634 8007BE34 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6C638 8007BE38 0800E003 */  jr         $ra
    /* 6C63C 8007BE3C 00000000 */   nop
endlabel func_8007BE00
