nonmatching func_8002CB80, 0x74

glabel func_8002CB80
    /* 1D380 8002CB80 F9FF8424 */  addiu      $a0, $a0, -0x7
    /* 1D384 8002CB84 06008004 */  bltz       $a0, .L8002CBA0
    /* 1D388 8002CB88 06000324 */   addiu     $v1, $zero, 0x6
    /* 1D38C 8002CB8C F9FFA524 */  addiu      $a1, $a1, -0x7
    /* 1D390 8002CB90 0700A104 */  bgez       $a1, .L8002CBB0
    /* 1D394 8002CB94 04000324 */   addiu     $v1, $zero, 0x4
  .L8002CB98:
    /* 1D398 8002CB98 0800E003 */  jr         $ra
    /* 1D39C 8002CB9C 21100000 */   addu      $v0, $zero, $zero
  .L8002CBA0:
    /* 1D3A0 8002CBA0 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 1D3A4 8002CBA4 2A10A300 */  slt        $v0, $a1, $v1
    /* 1D3A8 8002CBA8 FBFF4010 */  beqz       $v0, .L8002CB98
    /* 1D3AC 8002CBAC 21208300 */   addu      $a0, $a0, $v1
  .L8002CBB0:
    /* 1D3B0 8002CBB0 01008424 */  addiu      $a0, $a0, 0x1
    /* 1D3B4 8002CBB4 2A108300 */  slt        $v0, $a0, $v1
    /* 1D3B8 8002CBB8 02004014 */  bnez       $v0, .L8002CBC4
    /* 1D3BC 8002CBBC 00000000 */   nop
    /* 1D3C0 8002CBC0 21200000 */  addu       $a0, $zero, $zero
  .L8002CBC4:
    /* 1D3C4 8002CBC4 03008514 */  bne        $a0, $a1, .L8002CBD4
    /* 1D3C8 8002CBC8 FEFF8424 */   addiu     $a0, $a0, -0x2
    /* 1D3CC 8002CBCC 0800E003 */  jr         $ra
    /* 1D3D0 8002CBD0 F4010224 */   addiu     $v0, $zero, 0x1F4
  .L8002CBD4:
    /* 1D3D4 8002CBD4 02008104 */  bgez       $a0, .L8002CBE0
    /* 1D3D8 8002CBD8 00000000 */   nop
    /* 1D3DC 8002CBDC 21208300 */  addu       $a0, $a0, $v1
  .L8002CBE0:
    /* 1D3E0 8002CBE0 02008510 */  beq        $a0, $a1, .L8002CBEC
    /* 1D3E4 8002CBE4 0CFE0224 */   addiu     $v0, $zero, -0x1F4
    /* 1D3E8 8002CBE8 21100000 */  addu       $v0, $zero, $zero
  .L8002CBEC:
    /* 1D3EC 8002CBEC 0800E003 */  jr         $ra
    /* 1D3F0 8002CBF0 00000000 */   nop
endlabel func_8002CB80
