nonmatching func_80058E94, 0x2C

glabel func_80058E94
    /* 49694 80058E94 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 49698 80058E98 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 4969C 80058E9C C0100400 */  sll        $v0, $a0, 3
    /* 496A0 80058EA0 23104400 */  subu       $v0, $v0, $a0
    /* 496A4 80058EA4 00110200 */  sll        $v0, $v0, 4
    /* 496A8 80058EA8 21104400 */  addu       $v0, $v0, $a0
    /* 496AC 80058EAC 40110200 */  sll        $v0, $v0, 5
    /* 496B0 80058EB0 21104300 */  addu       $v0, $v0, $v1
    /* 496B4 80058EB4 060E4294 */  lhu        $v0, 0xE06($v0)
    /* 496B8 80058EB8 0800E003 */  jr         $ra
    /* 496BC 80058EBC 02110200 */   srl       $v0, $v0, 4
endlabel func_80058E94
