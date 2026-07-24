nonmatching func_8005B054, 0x60

glabel func_8005B054
    /* 4B854 8005B054 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4B858 8005B058 21188000 */  addu       $v1, $a0, $zero
    /* 4B85C 8005B05C 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 4B860 8005B060 1000A2AF */  sw         $v0, 0x10($sp)
    /* 4B864 8005B064 FFFFA230 */  andi       $v0, $a1, 0xFFFF
    /* 4B868 8005B068 FFFFC730 */  andi       $a3, $a2, 0xFFFF
    /* 4B86C 8005B06C 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4B870 8005B070 21286000 */  addu       $a1, $v1, $zero
    /* 4B874 8005B074 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4B878 8005B078 E86A010C */  jal        func_8005ABA0
    /* 4B87C 8005B07C 21304000 */   addu      $a2, $v0, $zero
    /* 4B880 8005B080 1800A493 */  lbu        $a0, 0x18($sp)
    /* 4B884 8005B084 1900A393 */  lbu        $v1, 0x19($sp)
    /* 4B888 8005B088 1A00A293 */  lbu        $v0, 0x1A($sp)
    /* 4B88C 8005B08C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4B890 8005B090 1F008430 */  andi       $a0, $a0, 0x1F
    /* 4B894 8005B094 1F006330 */  andi       $v1, $v1, 0x1F
    /* 4B898 8005B098 40190300 */  sll        $v1, $v1, 5
    /* 4B89C 8005B09C 25208300 */  or         $a0, $a0, $v1
    /* 4B8A0 8005B0A0 1F004230 */  andi       $v0, $v0, 0x1F
    /* 4B8A4 8005B0A4 80120200 */  sll        $v0, $v0, 10
    /* 4B8A8 8005B0A8 25108200 */  or         $v0, $a0, $v0
    /* 4B8AC 8005B0AC 0800E003 */  jr         $ra
    /* 4B8B0 8005B0B0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8005B054
