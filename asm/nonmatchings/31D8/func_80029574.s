nonmatching func_80029574, 0x1C

glabel func_80029574
    /* 19D74 80029574 80210400 */  sll        $a0, $a0, 6
    /* 19D78 80029578 0F80023C */  lui        $v0, %hi(D_800EA0E8)
    /* 19D7C 8002957C E8A04224 */  addiu      $v0, $v0, %lo(D_800EA0E8)
    /* 19D80 80029580 21208200 */  addu       $a0, $a0, $v0
    /* 19D84 80029584 040080AC */  sw         $zero, 0x4($a0)
    /* 19D88 80029588 0800E003 */  jr         $ra
    /* 19D8C 8002958C 000080AC */   sw        $zero, 0x0($a0)
endlabel func_80029574
