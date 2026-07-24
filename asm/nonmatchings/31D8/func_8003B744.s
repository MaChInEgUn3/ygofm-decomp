nonmatching func_8003B744, 0x9C

glabel func_8003B744
    /* 2BF44 8003B744 2130A000 */  addu       $a2, $a1, $zero
    /* 2BF48 8003B748 FFCF0234 */  ori        $v0, $zero, 0xCFFF
    /* 2BF4C 8003B74C 2A104600 */  slt        $v0, $v0, $a2
    /* 2BF50 8003B750 0C004010 */  beqz       $v0, .L8003B784
    /* 2BF54 8003B754 FFFF033C */   lui       $v1, (0xFFFF3000 >> 16)
    /* 2BF58 8003B758 00306334 */  ori        $v1, $v1, (0xFFFF3000 & 0xFFFF)
    /* 2BF5C 8003B75C 1C80023C */  lui        $v0, %hi(D_801C0000)
    /* 2BF60 8003B760 00004224 */  addiu      $v0, $v0, %lo(D_801C0000)
    /* 2BF64 8003B764 FFFF043C */  lui        $a0, (0xFFFF0000 >> 16)
  .L8003B768:
    /* 2BF68 8003B768 2118C300 */  addu       $v1, $a2, $v1
    /* 2BF6C 8003B76C 40180300 */  sll        $v1, $v1, 1
    /* 2BF70 8003B770 21186200 */  addu       $v1, $v1, $v0
    /* 2BF74 8003B774 00006394 */  lhu        $v1, 0x0($v1)
    /* 2BF78 8003B778 24104400 */  and        $v0, $v0, $a0
    /* 2BF7C 8003B77C 0800E003 */  jr         $ra
    /* 2BF80 8003B780 25104300 */   or        $v0, $v0, $v1
  .L8003B784:
    /* 2BF84 8003B784 FF7F0224 */  addiu      $v0, $zero, 0x7FFF
    /* 2BF88 8003B788 2A104600 */  slt        $v0, $v0, $a2
    /* 2BF8C 8003B78C 05004010 */  beqz       $v0, .L8003B7A4
    /* 2BF90 8003B790 1D80023C */   lui       $v0, %hi(D_801D5800)
    /* 2BF94 8003B794 00584224 */  addiu      $v0, $v0, %lo(D_801D5800)
    /* 2BF98 8003B798 FFFF043C */  lui        $a0, (0xFFFF0000 >> 16)
    /* 2BF9C 8003B79C DAED0008 */  j          .L8003B768
    /* 2BFA0 8003B7A0 00800324 */   addiu     $v1, $zero, -0x8000
  .L8003B7A4:
    /* 2BFA4 8003B7A4 0005C228 */  slti       $v0, $a2, 0x500
    /* 2BFA8 8003B7A8 02004014 */  bnez       $v0, .L8003B7B4
    /* 2BFAC 8003B7AC 00000000 */   nop
    /* 2BFB0 8003B7B0 00FFC624 */  addiu      $a2, $a2, -0x100
  .L8003B7B4:
    /* 2BFB4 8003B7B4 1B80023C */  lui        $v0, %hi(D_801B0000)
    /* 2BFB8 8003B7B8 00004224 */  addiu      $v0, $v0, %lo(D_801B0000)
    /* 2BFBC 8003B7BC FFFF053C */  lui        $a1, (0xFFFF0000 >> 16)
    /* 2BFC0 8003B7C0 1C80043C */  lui        $a0, %hi(D_801C0000)
    /* 2BFC4 8003B7C4 00008424 */  addiu      $a0, $a0, %lo(D_801C0000)
    /* 2BFC8 8003B7C8 40180600 */  sll        $v1, $a2, 1
    /* 2BFCC 8003B7CC 21186400 */  addu       $v1, $v1, $a0
    /* 2BFD0 8003B7D0 00006394 */  lhu        $v1, 0x0($v1)
    /* 2BFD4 8003B7D4 24104500 */  and        $v0, $v0, $a1
    /* 2BFD8 8003B7D8 0800E003 */  jr         $ra
    /* 2BFDC 8003B7DC 25104300 */   or        $v0, $v0, $v1
endlabel func_8003B744
