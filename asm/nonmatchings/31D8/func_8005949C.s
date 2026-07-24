nonmatching func_8005949C, 0x24

glabel func_8005949C
    /* 49C9C 8005949C C0100400 */  sll        $v0, $a0, 3
    /* 49CA0 800594A0 23104400 */  subu       $v0, $v0, $a0
    /* 49CA4 800594A4 00110200 */  sll        $v0, $v0, 4
    /* 49CA8 800594A8 21104400 */  addu       $v0, $v0, $a0
    /* 49CAC 800594AC 40110200 */  sll        $v0, $v0, 5
    /* 49CB0 800594B0 0F80033C */  lui        $v1, %hi(D_800F39F0)
    /* 49CB4 800594B4 F0396324 */  addiu      $v1, $v1, %lo(D_800F39F0)
    /* 49CB8 800594B8 0800E003 */  jr         $ra
    /* 49CBC 800594BC 21104300 */   addu      $v0, $v0, $v1
endlabel func_8005949C
