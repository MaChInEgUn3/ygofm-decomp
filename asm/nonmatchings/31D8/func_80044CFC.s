nonmatching func_80044CFC, 0x10

glabel func_80044CFC
    /* 354FC 80044CFC 0A80023C */  lui        $v0, %hi(D_8009B450)
    /* 35500 80044D00 50B440AC */  sw         $zero, %lo(D_8009B450)($v0)
    /* 35504 80044D04 0800E003 */  jr         $ra
    /* 35508 80044D08 21100000 */   addu      $v0, $zero, $zero
endlabel func_80044CFC
