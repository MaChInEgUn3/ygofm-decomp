nonmatching func_800713B8, 0x6C

glabel func_800713B8
    /* 61BB8 800713B8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 61BBC 800713BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 61BC0 800713C0 0F80103C */  lui        $s0, %hi(D_800F5B98)
    /* 61BC4 800713C4 985B1026 */  addiu      $s0, $s0, %lo(D_800F5B98)
    /* 61BC8 800713C8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 61BCC 800713CC 63C1010C */  jal        func_8007058C
    /* 61BD0 800713D0 1400B1AF */   sw        $s1, 0x14($sp)
    /* 61BD4 800713D4 80100200 */  sll        $v0, $v0, 2
    /* 61BD8 800713D8 21105000 */  addu       $v0, $v0, $s0
    /* 61BDC 800713DC 0000518C */  lw         $s1, 0x0($v0)
    /* 61BE0 800713E0 63C1010C */  jal        func_8007058C
    /* 61BE4 800713E4 00000000 */   nop
    /* 61BE8 800713E8 80100200 */  sll        $v0, $v0, 2
    /* 61BEC 800713EC 0F80043C */  lui        $a0, %hi(D_800E9FF0)
    /* 61BF0 800713F0 F09F8424 */  addiu      $a0, $a0, %lo(D_800E9FF0)
    /* 61BF4 800713F4 01000324 */  addiu      $v1, $zero, 0x1
    /* 61BF8 800713F8 23187100 */  subu       $v1, $v1, $s1
    /* 61BFC 800713FC 40190300 */  sll        $v1, $v1, 5
    /* 61C00 80071400 21186400 */  addu       $v1, $v1, $a0
    /* 61C04 80071404 14006384 */  lh         $v1, 0x14($v1)
    /* 61C08 80071408 21105000 */  addu       $v0, $v0, $s0
    /* 61C0C 8007140C 000043AC */  sw         $v1, 0x0($v0)
    /* 61C10 80071410 1800BF8F */  lw         $ra, 0x18($sp)
    /* 61C14 80071414 1400B18F */  lw         $s1, 0x14($sp)
    /* 61C18 80071418 1000B08F */  lw         $s0, 0x10($sp)
    /* 61C1C 8007141C 0800E003 */  jr         $ra
    /* 61C20 80071420 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800713B8
