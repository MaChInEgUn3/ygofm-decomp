nonmatching func_80024060, 0x28

glabel func_80024060
    /* 14860 80024060 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14864 80024064 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14868 80024068 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1486C 8002406C EF8F000C */  jal        func_80023FBC
    /* 14870 80024070 21808000 */   addu      $s0, $a0, $zero
    /* 14874 80024074 19000292 */  lbu        $v0, 0x19($s0)
    /* 14878 80024078 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1487C 8002407C 1000B08F */  lw         $s0, 0x10($sp)
    /* 14880 80024080 0800E003 */  jr         $ra
    /* 14884 80024084 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80024060
