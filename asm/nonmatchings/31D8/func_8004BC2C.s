nonmatching func_8004BC2C, 0x7C

glabel func_8004BC2C
    /* 3C42C 8004BC2C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3C430 8004BC30 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C434 8004BC34 21808000 */  addu       $s0, $a0, $zero
    /* 3C438 8004BC38 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3C43C 8004BC3C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3C440 8004BC40 B92E010C */  jal        func_8004BAE4
    /* 3C444 8004BC44 1400B1AF */   sw        $s1, 0x14($sp)
    /* 3C448 8004BC48 21200002 */  addu       $a0, $s0, $zero
    /* 3C44C 8004BC4C B92E010C */  jal        func_8004BAE4
    /* 3C450 8004BC50 21904000 */   addu      $s2, $v0, $zero
    /* 3C454 8004BC54 21200002 */  addu       $a0, $s0, $zero
    /* 3C458 8004BC58 B92E010C */  jal        func_8004BAE4
    /* 3C45C 8004BC5C 21884000 */   addu      $s1, $v0, $zero
    /* 3C460 8004BC60 21200002 */  addu       $a0, $s0, $zero
    /* 3C464 8004BC64 B92E010C */  jal        func_8004BAE4
    /* 3C468 8004BC68 21804000 */   addu      $s0, $v0, $zero
    /* 3C46C 8004BC6C FF004230 */  andi       $v0, $v0, 0xFF
    /* 3C470 8004BC70 FF001032 */  andi       $s0, $s0, 0xFF
    /* 3C474 8004BC74 00821000 */  sll        $s0, $s0, 8
    /* 3C478 8004BC78 21105000 */  addu       $v0, $v0, $s0
    /* 3C47C 8004BC7C FF003132 */  andi       $s1, $s1, 0xFF
    /* 3C480 8004BC80 008C1100 */  sll        $s1, $s1, 16
    /* 3C484 8004BC84 21105100 */  addu       $v0, $v0, $s1
    /* 3C488 8004BC88 00961200 */  sll        $s2, $s2, 24
    /* 3C48C 8004BC8C 21105200 */  addu       $v0, $v0, $s2
    /* 3C490 8004BC90 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3C494 8004BC94 1800B28F */  lw         $s2, 0x18($sp)
    /* 3C498 8004BC98 1400B18F */  lw         $s1, 0x14($sp)
    /* 3C49C 8004BC9C 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C4A0 8004BCA0 0800E003 */  jr         $ra
    /* 3C4A4 8004BCA4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8004BC2C
