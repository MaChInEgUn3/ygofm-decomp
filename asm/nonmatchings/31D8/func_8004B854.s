nonmatching func_8004B854, 0xBC

glabel func_8004B854
    /* 3C054 8004B854 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3C058 8004B858 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3C05C 8004B85C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3C060 8004B860 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3C064 8004B864 03056290 */  lbu        $v0, 0x503($v1)
    /* 3C068 8004B868 00000000 */  nop
    /* 3C06C 8004B86C 24004014 */  bnez       $v0, .L8004B900
    /* 3C070 8004B870 01000224 */   addiu     $v0, $zero, 0x1
    /* 3C074 8004B874 2CCE010C */  jal        func_800738B0
    /* 3C078 8004B878 030562A0 */   sb        $v0, 0x503($v1)
    /* 3C07C 8004B87C 00F2043C */  lui        $a0, (0xF2000002 >> 16)
    /* 3C080 8004B880 95CE010C */  jal        func_80073A54
    /* 3C084 8004B884 02008434 */   ori       $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 3C088 8004B888 00F2043C */  lui        $a0, (0xF2000002 >> 16)
    /* 3C08C 8004B88C 02008434 */  ori        $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 3C090 8004B890 02000524 */  addiu      $a1, $zero, 0x2
    /* 3C094 8004B894 00100624 */  addiu      $a2, $zero, 0x1000
    /* 3C098 8004B898 0580073C */  lui        $a3, %hi(func_8004B734)
    /* 3C09C 8004B89C 18CE010C */  jal        func_80073860
    /* 3C0A0 8004B8A0 34B7E724 */   addiu     $a3, $a3, %lo(func_8004B734)
    /* 3C0A4 8004B8A4 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3C0A8 8004B8A8 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3C0AC 8004B8AC 21204000 */  addu       $a0, $v0, $zero
    /* 3C0B0 8004B8B0 24CE010C */  jal        func_80073890
    /* 3C0B4 8004B8B4 040564AC */   sw        $a0, 0x504($v1)
    /* 3C0B8 8004B8B8 00F2043C */  lui        $a0, (0xF2000002 >> 16)
    /* 3C0BC 8004B8BC 02008434 */  ori        $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 3C0C0 8004B8C0 00E00534 */  ori        $a1, $zero, 0xE000
    /* 3C0C4 8004B8C4 54CE010C */  jal        func_80073950
    /* 3C0C8 8004B8C8 00100624 */   addiu     $a2, $zero, 0x1000
    /* 3C0CC 8004B8CC 00F2043C */  lui        $a0, (0xF2000002 >> 16)
    /* 3C0D0 8004B8D0 89CE010C */  jal        func_80073A24
    /* 3C0D4 8004B8D4 02008434 */   ori       $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 3C0D8 8004B8D8 30CE010C */  jal        func_800738C0
    /* 3C0DC 8004B8DC 00000000 */   nop
    /* 3C0E0 8004B8E0 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3C0E4 8004B8E4 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3C0E8 8004B8E8 00000000 */  nop
    /* 3C0EC 8004B8EC 000540A0 */  sb         $zero, 0x500($v0)
    /* 3C0F0 8004B8F0 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3C0F4 8004B8F4 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3C0F8 8004B8F8 00000000 */  nop
    /* 3C0FC 8004B8FC 030540A0 */  sb         $zero, 0x503($v0)
  .L8004B900:
    /* 3C100 8004B900 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3C104 8004B904 00000000 */  nop
    /* 3C108 8004B908 0800E003 */  jr         $ra
    /* 3C10C 8004B90C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004B854
