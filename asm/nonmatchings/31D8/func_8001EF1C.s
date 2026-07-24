nonmatching func_8001EF1C, 0x5C

glabel func_8001EF1C
    /* F71C 8001EF1C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* F720 8001EF20 1000B0AF */  sw         $s0, 0x10($sp)
    /* F724 8001EF24 21808000 */  addu       $s0, $a0, $zero
    /* F728 8001EF28 1400B1AF */  sw         $s1, 0x14($sp)
    /* F72C 8001EF2C 1800BFAF */  sw         $ra, 0x18($sp)
    /* F730 8001EF30 325C000C */  jal        func_800170C8
    /* F734 8001EF34 2188A000 */   addu      $s1, $a1, $zero
    /* F738 8001EF38 21200002 */  addu       $a0, $s0, $zero
    /* F73C 8001EF3C 21804000 */  addu       $s0, $v0, $zero
    /* F740 8001EF40 917B000C */  jal        func_8001EE44
    /* F744 8001EF44 21282002 */   addu      $a1, $s1, $zero
    /* F748 8001EF48 FFFF1032 */  andi       $s0, $s0, 0xFFFF
    /* F74C 8001EF4C 21800202 */  addu       $s0, $s0, $v0
    /* F750 8001EF50 1027022A */  slti       $v0, $s0, 0x2710
    /* F754 8001EF54 03004014 */  bnez       $v0, .L8001EF64
    /* F758 8001EF58 21100002 */   addu      $v0, $s0, $zero
    /* F75C 8001EF5C 0F271024 */  addiu      $s0, $zero, 0x270F
    /* F760 8001EF60 21100002 */  addu       $v0, $s0, $zero
  .L8001EF64:
    /* F764 8001EF64 1800BF8F */  lw         $ra, 0x18($sp)
    /* F768 8001EF68 1400B18F */  lw         $s1, 0x14($sp)
    /* F76C 8001EF6C 1000B08F */  lw         $s0, 0x10($sp)
    /* F770 8001EF70 0800E003 */  jr         $ra
    /* F774 8001EF74 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001EF1C
