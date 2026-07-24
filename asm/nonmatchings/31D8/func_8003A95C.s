nonmatching func_8003A95C, 0x34

glabel func_8003A95C
    /* 2B15C 8003A95C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2B160 8003A960 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2B164 8003A964 340085A4 */  sh         $a1, 0x34($a0)
    /* 2B168 8003A968 002C0500 */  sll        $a1, $a1, 16
    /* 2B16C 8003A96C 360086A4 */  sh         $a2, 0x36($a0)
    /* 2B170 8003A970 00340600 */  sll        $a2, $a2, 16
    /* 2B174 8003A974 032C0500 */  sra        $a1, $a1, 16
    /* 2B178 8003A978 48EA000C */  jal        func_8003A920
    /* 2B17C 8003A97C 03340600 */   sra       $a2, $a2, 16
    /* 2B180 8003A980 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2B184 8003A984 00000000 */  nop
    /* 2B188 8003A988 0800E003 */  jr         $ra
    /* 2B18C 8003A98C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003A95C
