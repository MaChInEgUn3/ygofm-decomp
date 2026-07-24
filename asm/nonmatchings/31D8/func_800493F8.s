nonmatching func_800493F8, 0x3C

glabel func_800493F8
    /* 39BF8 800493F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 39BFC 800493FC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 39C00 80049400 0424010C */  jal        func_80049010
    /* 39C04 80049404 00000000 */   nop
    /* 39C08 80049408 1E80033C */  lui        $v1, (0x801EA800 >> 16)
    /* 39C0C 8004940C 0A80023C */  lui        $v0, %hi(D_8009B45C)
    /* 39C10 80049410 5CB4428C */  lw         $v0, %lo(D_8009B45C)($v0)
    /* 39C14 80049414 00A86334 */  ori        $v1, $v1, (0x801EA800 & 0xFFFF)
    /* 39C18 80049418 641543AC */  sw         $v1, 0x1564($v0)
    /* 39C1C 8004941C FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 39C20 80049420 000062A4 */  sh         $v0, 0x0($v1)
    /* 39C24 80049424 1000BF8F */  lw         $ra, 0x10($sp)
    /* 39C28 80049428 00000000 */  nop
    /* 39C2C 8004942C 0800E003 */  jr         $ra
    /* 39C30 80049430 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800493F8
