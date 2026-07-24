nonmatching func_80024088, 0x28

glabel func_80024088
    /* 14888 80024088 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1488C 8002408C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14890 80024090 1400BFAF */  sw         $ra, 0x14($sp)
    /* 14894 80024094 428F000C */  jal        func_80023D08
    /* 14898 80024098 21808000 */   addu      $s0, $a0, $zero
    /* 1489C 8002409C 19000292 */  lbu        $v0, 0x19($s0)
    /* 148A0 800240A0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 148A4 800240A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 148A8 800240A8 0800E003 */  jr         $ra
    /* 148AC 800240AC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80024088
