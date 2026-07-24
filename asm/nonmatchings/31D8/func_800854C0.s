nonmatching func_800854C0, 0x38

glabel func_800854C0
    /* 75CC0 800854C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 75CC4 800854C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 75CC8 800854C8 00F2043C */  lui        $a0, (0xF2000001 >> 16)
    /* 75CCC 800854CC 01008434 */  ori        $a0, $a0, (0xF2000001 & 0xFFFF)
    /* 75CD0 800854D0 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 75CD4 800854D4 54CE010C */  jal        func_80073950
    /* 75CD8 800854D8 00200624 */   addiu     $a2, $zero, 0x2000
    /* 75CDC 800854DC 00F2043C */  lui        $a0, (0xF2000001 >> 16)
    /* 75CE0 800854E0 89CE010C */  jal        func_80073A24
    /* 75CE4 800854E4 01008434 */   ori       $a0, $a0, (0xF2000001 & 0xFFFF)
    /* 75CE8 800854E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 75CEC 800854EC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 75CF0 800854F0 0800E003 */  jr         $ra
    /* 75CF4 800854F4 00000000 */   nop
endlabel func_800854C0
    /* 75CF8 800854F8 00000000 */  nop
    /* 75CFC 800854FC 00000000 */  nop
