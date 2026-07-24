nonmatching func_8008D15C, 0x6C

glabel func_8008D15C
    /* 7D95C 8008D15C 0A80033C */  lui        $v1, %hi(D_80099EA8)
    /* 7D960 8008D160 A89E638C */  lw         $v1, %lo(D_80099EA8)($v1)
    /* 7D964 8008D164 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7D968 8008D168 13006004 */  bltz       $v1, .L8008D1B8
    /* 7D96C 8008D16C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 7D970 8008D170 80100300 */  sll        $v0, $v1, 2
    /* 7D974 8008D174 00190300 */  sll        $v1, $v1, 4
    /* 7D978 8008D178 1080043C */  lui        $a0, %hi(D_800FE3A8)
    /* 7D97C 8008D17C A8E38424 */  addiu      $a0, $a0, %lo(D_800FE3A8)
    /* 7D980 8008D180 1080013C */  lui        $at, %hi(D_800FE3E8)
    /* 7D984 8008D184 21082200 */  addu       $at, $at, $v0
    /* 7D988 8008D188 E8E3228C */  lw         $v0, %lo(D_800FE3E8)($at)
    /* 7D98C 8008D18C 00000000 */  nop
    /* 7D990 8008D190 09F84000 */  jalr       $v0
    /* 7D994 8008D194 21206400 */   addu      $a0, $v1, $a0
    /* 7D998 8008D198 07004010 */  beqz       $v0, .L8008D1B8
    /* 7D99C 8008D19C 00000000 */   nop
    /* 7D9A0 8008D1A0 0A80023C */  lui        $v0, %hi(D_80099EA8)
    /* 7D9A4 8008D1A4 A89E428C */  lw         $v0, %lo(D_80099EA8)($v0)
    /* 7D9A8 8008D1A8 00000000 */  nop
    /* 7D9AC 8008D1AC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 7D9B0 8008D1B0 0A80013C */  lui        $at, %hi(D_80099EA8)
    /* 7D9B4 8008D1B4 A89E22AC */  sw         $v0, %lo(D_80099EA8)($at)
  .L8008D1B8:
    /* 7D9B8 8008D1B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7D9BC 8008D1BC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7D9C0 8008D1C0 0800E003 */  jr         $ra
    /* 7D9C4 8008D1C4 00000000 */   nop
endlabel func_8008D15C
