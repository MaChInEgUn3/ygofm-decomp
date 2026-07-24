nonmatching func_80070EB4, 0x68

glabel func_80070EB4
    /* 616B4 80070EB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 616B8 80070EB8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 616BC 80070EBC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 616C0 80070EC0 63C1010C */  jal        func_8007058C
    /* 616C4 80070EC4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 616C8 80070EC8 63C1010C */  jal        func_8007058C
    /* 616CC 80070ECC 21884000 */   addu      $s1, $v0, $zero
    /* 616D0 80070ED0 63C1010C */  jal        func_8007058C
    /* 616D4 80070ED4 21804000 */   addu      $s0, $v0, $zero
    /* 616D8 80070ED8 0F80043C */  lui        $a0, %hi(D_800F5B98)
    /* 616DC 80070EDC 985B8424 */  addiu      $a0, $a0, %lo(D_800F5B98)
    /* 616E0 80070EE0 80100200 */  sll        $v0, $v0, 2
    /* 616E4 80070EE4 80881100 */  sll        $s1, $s1, 2
    /* 616E8 80070EE8 21882402 */  addu       $s1, $s1, $a0
    /* 616EC 80070EEC 80801000 */  sll        $s0, $s0, 2
    /* 616F0 80070EF0 21800402 */  addu       $s0, $s0, $a0
    /* 616F4 80070EF4 0000238E */  lw         $v1, 0x0($s1)
    /* 616F8 80070EF8 0000058E */  lw         $a1, 0x0($s0)
    /* 616FC 80070EFC 21104400 */  addu       $v0, $v0, $a0
    /* 61700 80070F00 23186500 */  subu       $v1, $v1, $a1
    /* 61704 80070F04 000043AC */  sw         $v1, 0x0($v0)
    /* 61708 80070F08 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6170C 80070F0C 1400B18F */  lw         $s1, 0x14($sp)
    /* 61710 80070F10 1000B08F */  lw         $s0, 0x10($sp)
    /* 61714 80070F14 0800E003 */  jr         $ra
    /* 61718 80070F18 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80070EB4
