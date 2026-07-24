nonmatching func_8007FC64, 0x5C

glabel func_8007FC64
    /* 70464 8007FC64 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 70468 8007FC68 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7046C 8007FC6C 21808000 */  addu       $s0, $a0, $zero
    /* 70470 8007FC70 0980023C */  lui        $v0, %hi(D_80094660)
    /* 70474 8007FC74 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 70478 8007FC78 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7047C 8007FC7C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 70480 8007FC80 3C00428C */  lw         $v0, 0x3C($v0)
    /* 70484 8007FC84 03001192 */  lbu        $s1, 0x3($s0)
    /* 70488 8007FC88 09F84000 */  jalr       $v0
    /* 7048C 8007FC8C 21200000 */   addu      $a0, $zero, $zero
    /* 70490 8007FC90 0980023C */  lui        $v0, %hi(D_80094660)
    /* 70494 8007FC94 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 70498 8007FC98 04000426 */  addiu      $a0, $s0, 0x4
    /* 7049C 8007FC9C 1400428C */  lw         $v0, 0x14($v0)
    /* 704A0 8007FCA0 00000000 */  nop
    /* 704A4 8007FCA4 09F84000 */  jalr       $v0
    /* 704A8 8007FCA8 21282002 */   addu      $a1, $s1, $zero
    /* 704AC 8007FCAC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 704B0 8007FCB0 1400B18F */  lw         $s1, 0x14($sp)
    /* 704B4 8007FCB4 1000B08F */  lw         $s0, 0x10($sp)
    /* 704B8 8007FCB8 0800E003 */  jr         $ra
    /* 704BC 8007FCBC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007FC64
