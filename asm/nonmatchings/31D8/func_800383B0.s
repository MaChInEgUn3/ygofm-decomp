nonmatching func_800383B0, 0x2C

glabel func_800383B0
    /* 28BB0 800383B0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28BB4 800383B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 28BB8 800383B8 21808000 */  addu       $s0, $a0, $zero
    /* 28BBC 800383BC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 28BC0 800383C0 4FDB000C */  jal        func_80036D3C
    /* 28BC4 800383C4 600000A2 */   sb        $zero, 0x60($s0)
    /* 28BC8 800383C8 610002A2 */  sb         $v0, 0x61($s0)
    /* 28BCC 800383CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 28BD0 800383D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 28BD4 800383D4 0800E003 */  jr         $ra
    /* 28BD8 800383D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800383B0
