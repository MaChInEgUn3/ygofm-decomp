nonmatching func_8008FF90, 0x90

glabel func_8008FF90
    /* 80790 8008FF90 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 80794 8008FF94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 80798 8008FF98 21888000 */  addu       $s1, $a0, $zero
    /* 8079C 8008FF9C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 807A0 8008FFA0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 807A4 8008FFA4 2B40020C */  jal        func_800900AC
    /* 807A8 8008FFA8 2180A000 */   addu      $s0, $a1, $zero
    /* 807AC 8008FFAC 0A80033C */  lui        $v1, %hi(D_8009A0C0)
    /* 807B0 8008FFB0 C0A0638C */  lw         $v1, %lo(D_8009A0C0)($v1)
    /* 807B4 8008FFB4 42811000 */  srl        $s0, $s0, 5
    /* 807B8 8008FFB8 0000628C */  lw         $v0, 0x0($v1)
    /* 807BC 8008FFBC 00841000 */  sll        $s0, $s0, 16
    /* 807C0 8008FFC0 88004234 */  ori        $v0, $v0, 0x88
    /* 807C4 8008FFC4 000062AC */  sw         $v0, 0x0($v1)
    /* 807C8 8008FFC8 0A80033C */  lui        $v1, %hi(D_8009A088)
    /* 807CC 8008FFCC 88A0638C */  lw         $v1, %lo(D_8009A088)($v1)
    /* 807D0 8008FFD0 04002226 */  addiu      $v0, $s1, 0x4
    /* 807D4 8008FFD4 000062AC */  sw         $v0, 0x0($v1)
    /* 807D8 8008FFD8 0A80023C */  lui        $v0, %hi(D_8009A08C)
    /* 807DC 8008FFDC 8CA0428C */  lw         $v0, %lo(D_8009A08C)($v0)
    /* 807E0 8008FFE0 20001036 */  ori        $s0, $s0, 0x20
    /* 807E4 8008FFE4 000050AC */  sw         $s0, 0x0($v0)
    /* 807E8 8008FFE8 0A80033C */  lui        $v1, %hi(D_8009A0B8)
    /* 807EC 8008FFEC B8A0638C */  lw         $v1, %lo(D_8009A0B8)($v1)
    /* 807F0 8008FFF0 0000228E */  lw         $v0, 0x0($s1)
    /* 807F4 8008FFF4 0001043C */  lui        $a0, (0x1000201 >> 16)
    /* 807F8 8008FFF8 000062AC */  sw         $v0, 0x0($v1)
    /* 807FC 8008FFFC 0A80023C */  lui        $v0, %hi(D_8009A090)
    /* 80800 80090000 90A0428C */  lw         $v0, %lo(D_8009A090)($v0)
    /* 80804 80090004 01028434 */  ori        $a0, $a0, (0x1000201 & 0xFFFF)
    /* 80808 80090008 000044AC */  sw         $a0, 0x0($v0)
    /* 8080C 8009000C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 80810 80090010 1400B18F */  lw         $s1, 0x14($sp)
    /* 80814 80090014 1000B08F */  lw         $s0, 0x10($sp)
    /* 80818 80090018 0800E003 */  jr         $ra
    /* 8081C 8009001C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008FF90
