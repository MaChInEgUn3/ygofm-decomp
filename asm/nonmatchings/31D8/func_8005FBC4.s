nonmatching func_8005FBC4, 0x58

glabel func_8005FBC4
    /* 503C4 8005FBC4 1400A38F */  lw         $v1, 0x14($sp)
    /* 503C8 8005FBC8 2310A600 */  subu       $v0, $a1, $a2
    /* 503CC 8005FBCC 18004300 */  mult       $v0, $v1
    /* 503D0 8005FBD0 21308600 */  addu       $a2, $a0, $a2
    /* 503D4 8005FBD4 12400000 */  mflo       $t0
    /* 503D8 8005FBD8 40100500 */  sll        $v0, $a1, 1
    /* 503DC 8005FBDC 2330C200 */  subu       $a2, $a2, $v0
    /* 503E0 8005FBE0 1800C300 */  mult       $a2, $v1
    /* 503E4 8005FBE4 12300000 */  mflo       $a2
    /* 503E8 8005FBE8 2328A400 */  subu       $a1, $a1, $a0
    /* 503EC 8005FBEC 00000000 */  nop
    /* 503F0 8005FBF0 1800A300 */  mult       $a1, $v1
    /* 503F4 8005FBF4 1000A28F */  lw         $v0, 0x10($sp)
    /* 503F8 8005FBF8 00000000 */  nop
    /* 503FC 8005FBFC 060044A4 */  sh         $a0, 0x6($v0)
    /* 50400 8005FC00 23200401 */  subu       $a0, $t0, $a0
    /* 50404 8005FC04 21208700 */  addu       $a0, $a0, $a3
    /* 50408 8005FC08 000044A4 */  sh         $a0, 0x0($v0)
    /* 5040C 8005FC0C 020046A4 */  sh         $a2, 0x2($v0)
    /* 50410 8005FC10 12180000 */  mflo       $v1
    /* 50414 8005FC14 0800E003 */  jr         $ra
    /* 50418 8005FC18 040043A4 */   sh        $v1, 0x4($v0)
endlabel func_8005FBC4
