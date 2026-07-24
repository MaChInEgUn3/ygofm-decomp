nonmatching func_80015DB8, 0x44

glabel func_80015DB8
    /* 65B8 80015DB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 65BC 80015DBC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 65C0 80015DC0 6A008390 */  lbu        $v1, 0x6A($a0)
    /* 65C4 80015DC4 00000000 */  nop
    /* 65C8 80015DC8 C0100300 */  sll        $v0, $v1, 3
    /* 65CC 80015DCC 23104300 */  subu       $v0, $v0, $v1
    /* 65D0 80015DD0 00110200 */  sll        $v0, $v0, 4
    /* 65D4 80015DD4 0F80033C */  lui        $v1, %hi(D_800EFE48)
    /* 65D8 80015DD8 48FE6324 */  addiu      $v1, $v1, %lo(D_800EFE48)
    /* 65DC 80015DDC 21104300 */  addu       $v0, $v0, $v1
    /* 65E0 80015DE0 2800428C */  lw         $v0, 0x28($v0)
    /* 65E4 80015DE4 4657000C */  jal        func_80015D18
    /* 65E8 80015DE8 280082AC */   sw        $v0, 0x28($a0)
    /* 65EC 80015DEC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 65F0 80015DF0 00000000 */  nop
    /* 65F4 80015DF4 0800E003 */  jr         $ra
    /* 65F8 80015DF8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015DB8
