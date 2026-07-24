nonmatching func_8008E740, 0x34

glabel func_8008E740
    /* 7EF40 8008E740 21180000 */  addu       $v1, $zero, $zero
    /* 7EF44 8008E744 09008010 */  beqz       $a0, .L8008E76C
    /* 7EF48 8008E748 21100000 */   addu      $v0, $zero, $zero
    /* 7EF4C 8008E74C D6390208 */  j          .L8008E758
    /* 7EF50 8008E750 00000000 */   nop
  .L8008E754:
    /* 7EF54 8008E754 01006324 */  addiu      $v1, $v1, 0x1
  .L8008E758:
    /* 7EF58 8008E758 00008280 */  lb         $v0, 0x0($a0)
    /* 7EF5C 8008E75C 00000000 */  nop
    /* 7EF60 8008E760 FCFF4014 */  bnez       $v0, .L8008E754
    /* 7EF64 8008E764 01008424 */   addiu     $a0, $a0, 0x1
    /* 7EF68 8008E768 21106000 */  addu       $v0, $v1, $zero
  .L8008E76C:
    /* 7EF6C 8008E76C 0800E003 */  jr         $ra
    /* 7EF70 8008E770 00000000 */   nop
endlabel func_8008E740
    /* 7EF74 8008E774 00000000 */  nop
    /* 7EF78 8008E778 00000000 */  nop
    /* 7EF7C 8008E77C 00000000 */  nop
