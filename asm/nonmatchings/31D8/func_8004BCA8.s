nonmatching func_8004BCA8, 0x40

glabel func_8004BCA8
    /* 3C4A8 8004BCA8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3C4AC 8004BCAC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C4B0 8004BCB0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3C4B4 8004BCB4 B92E010C */  jal        func_8004BAE4
    /* 3C4B8 8004BCB8 21808000 */   addu      $s0, $a0, $zero
    /* 3C4BC 8004BCBC 21200002 */  addu       $a0, $s0, $zero
    /* 3C4C0 8004BCC0 B92E010C */  jal        func_8004BAE4
    /* 3C4C4 8004BCC4 21804000 */   addu      $s0, $v0, $zero
    /* 3C4C8 8004BCC8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 3C4CC 8004BCCC FF001032 */  andi       $s0, $s0, 0xFF
    /* 3C4D0 8004BCD0 00821000 */  sll        $s0, $s0, 8
    /* 3C4D4 8004BCD4 25105000 */  or         $v0, $v0, $s0
    /* 3C4D8 8004BCD8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3C4DC 8004BCDC 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C4E0 8004BCE0 0800E003 */  jr         $ra
    /* 3C4E4 8004BCE4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004BCA8
