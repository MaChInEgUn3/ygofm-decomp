nonmatching func_800428A8, 0x44

glabel func_800428A8
    /* 330A8 800428A8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 330AC 800428AC 4800A28F */  lw         $v0, 0x48($sp)
    /* 330B0 800428B0 3800A38F */  lw         $v1, 0x38($sp)
    /* 330B4 800428B4 3C00A88F */  lw         $t0, 0x3C($sp)
    /* 330B8 800428B8 4000A98F */  lw         $t1, 0x40($sp)
    /* 330BC 800428BC 4400AA8F */  lw         $t2, 0x44($sp)
    /* 330C0 800428C0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 330C4 800428C4 540082AC */  sw         $v0, 0x54($a0)
    /* 330C8 800428C8 1000A3AF */  sw         $v1, 0x10($sp)
    /* 330CC 800428CC 1400A8AF */  sw         $t0, 0x14($sp)
    /* 330D0 800428D0 1800A9AF */  sw         $t1, 0x18($sp)
    /* 330D4 800428D4 3301010C */  jal        func_800404CC
    /* 330D8 800428D8 1C00AAAF */   sw        $t2, 0x1C($sp)
    /* 330DC 800428DC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 330E0 800428E0 00000000 */  nop
    /* 330E4 800428E4 0800E003 */  jr         $ra
    /* 330E8 800428E8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800428A8
