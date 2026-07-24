nonmatching func_800492D8, 0x30

glabel func_800492D8
    /* 39AD8 800492D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 39ADC 800492DC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 39AE0 800492E0 A518010C */  jal        func_80046294
    /* 39AE4 800492E4 00000000 */   nop
    /* 39AE8 800492E8 0424010C */  jal        func_80049010
    /* 39AEC 800492EC 00000000 */   nop
    /* 39AF0 800492F0 FCDF010C */  jal        func_80077FF0
    /* 39AF4 800492F4 21200000 */   addu      $a0, $zero, $zero
    /* 39AF8 800492F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 39AFC 800492FC 00000000 */  nop
    /* 39B00 80049300 0800E003 */  jr         $ra
    /* 39B04 80049304 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800492D8
