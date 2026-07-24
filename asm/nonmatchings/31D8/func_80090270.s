/* Handwritten function */
nonmatching func_80090270, 0x30

glabel func_80090270
    /* 80A70 80090270 0A80083C */  lui        $t0, %hi(D_8009A0C8)
    /* 80A74 80090274 C8A00825 */  addiu      $t0, $t0, %lo(D_8009A0C8)
    /* 80A78 80090278 FFFF8120 */  addi       $at, $a0, -0x1 /* handwritten instruction */
    /* 80A7C 8009027C 04002018 */  blez       $at, .L80090290
    /* 80A80 80090280 0000028D */   lw        $v0, 0x0($t0)
    /* 80A84 80090284 40080400 */  sll        $at, $a0, 1
    /* 80A88 80090288 0800E003 */  jr         $ra
    /* 80A8C 8009028C 000001AD */   sw        $at, 0x0($t0)
  .L80090290:
    /* 80A90 80090290 FF00013C */  lui        $at, (0xFFFFFF >> 16)
    /* 80A94 80090294 FFFF2134 */  ori        $at, $at, (0xFFFFFF & 0xFFFF)
    /* 80A98 80090298 0800E003 */  jr         $ra
    /* 80A9C 8009029C 000001AD */   sw        $at, 0x0($t0)
endlabel func_80090270
