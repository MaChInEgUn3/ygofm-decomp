nonmatching func_8001EF78, 0x5C

glabel func_8001EF78
    /* F778 8001EF78 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* F77C 8001EF7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* F780 8001EF80 21808000 */  addu       $s0, $a0, $zero
    /* F784 8001EF84 1400B1AF */  sw         $s1, 0x14($sp)
    /* F788 8001EF88 1800BFAF */  sw         $ra, 0x18($sp)
    /* F78C 8001EF8C 325C000C */  jal        func_800170C8
    /* F790 8001EF90 2188A000 */   addu      $s1, $a1, $zero
    /* F794 8001EF94 21200002 */  addu       $a0, $s0, $zero
    /* F798 8001EF98 21804000 */  addu       $s0, $v0, $zero
    /* F79C 8001EF9C 917B000C */  jal        func_8001EE44
    /* F7A0 8001EFA0 21282002 */   addu      $a1, $s1, $zero
    /* F7A4 8001EFA4 03841000 */  sra        $s0, $s0, 16
    /* F7A8 8001EFA8 21800202 */  addu       $s0, $s0, $v0
    /* F7AC 8001EFAC 1027022A */  slti       $v0, $s0, 0x2710
    /* F7B0 8001EFB0 03004014 */  bnez       $v0, .L8001EFC0
    /* F7B4 8001EFB4 21100002 */   addu      $v0, $s0, $zero
    /* F7B8 8001EFB8 0F271024 */  addiu      $s0, $zero, 0x270F
    /* F7BC 8001EFBC 21100002 */  addu       $v0, $s0, $zero
  .L8001EFC0:
    /* F7C0 8001EFC0 1800BF8F */  lw         $ra, 0x18($sp)
    /* F7C4 8001EFC4 1400B18F */  lw         $s1, 0x14($sp)
    /* F7C8 8001EFC8 1000B08F */  lw         $s0, 0x10($sp)
    /* F7CC 8001EFCC 0800E003 */  jr         $ra
    /* F7D0 8001EFD0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001EF78
