nonmatching func_8008FEA0, 0xF0

glabel func_8008FEA0
    /* 806A0 8008FEA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 806A4 8008FEA4 21288000 */  addu       $a1, $a0, $zero
    /* 806A8 8008FEA8 0600A010 */  beqz       $a1, .L8008FEC4
    /* 806AC 8008FEAC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 806B0 8008FEB0 01000224 */  addiu      $v0, $zero, 0x1
    /* 806B4 8008FEB4 1B00A210 */  beq        $a1, $v0, .L8008FF24
    /* 806B8 8008FEB8 0080023C */   lui       $v0, (0x80000000 >> 16)
    /* 806BC 8008FEBC DD3F0208 */  j          .L8008FF74
    /* 806C0 8008FEC0 00000000 */   nop
  .L8008FEC4:
    /* 806C4 8008FEC4 0A80033C */  lui        $v1, %hi(D_8009A0BC)
    /* 806C8 8008FEC8 BCA0638C */  lw         $v1, %lo(D_8009A0BC)($v1)
    /* 806CC 8008FECC 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 806D0 8008FED0 000062AC */  sw         $v0, 0x0($v1)
    /* 806D4 8008FED4 0A80023C */  lui        $v0, %hi(D_8009A090)
    /* 806D8 8008FED8 90A0428C */  lw         $v0, %lo(D_8009A090)($v0)
    /* 806DC 8008FEDC 0A80043C */  lui        $a0, %hi(D_80099F78)
    /* 806E0 8008FEE0 789F8424 */  addiu      $a0, $a0, %lo(D_80099F78)
    /* 806E4 8008FEE4 000040AC */  sw         $zero, 0x0($v0)
    /* 806E8 8008FEE8 0A80023C */  lui        $v0, %hi(D_8009A09C)
    /* 806EC 8008FEEC 9CA0428C */  lw         $v0, %lo(D_8009A09C)($v0)
    /* 806F0 8008FEF0 20000524 */  addiu      $a1, $zero, 0x20
    /* 806F4 8008FEF4 000040AC */  sw         $zero, 0x0($v0)
    /* 806F8 8008FEF8 0A80033C */  lui        $v1, %hi(D_8009A0BC)
    /* 806FC 8008FEFC BCA0638C */  lw         $v1, %lo(D_8009A0BC)($v1)
    /* 80700 8008FF00 0060023C */  lui        $v0, (0x60000000 >> 16)
    /* 80704 8008FF04 E43F020C */  jal        func_8008FF90
    /* 80708 8008FF08 000062AC */   sw        $v0, 0x0($v1)
    /* 8070C 8008FF0C 0A80043C */  lui        $a0, %hi(D_80099FFC)
    /* 80710 8008FF10 FC9F8424 */  addiu      $a0, $a0, %lo(D_80099FFC)
    /* 80714 8008FF14 E43F020C */  jal        func_8008FF90
    /* 80718 8008FF18 20000524 */   addiu     $a1, $zero, 0x20
    /* 8071C 8008FF1C E03F0208 */  j          .L8008FF80
    /* 80720 8008FF20 00000000 */   nop
  .L8008FF24:
    /* 80724 8008FF24 0A80033C */  lui        $v1, %hi(D_8009A0BC)
    /* 80728 8008FF28 BCA0638C */  lw         $v1, %lo(D_8009A0BC)($v1)
    /* 8072C 8008FF2C 00000000 */  nop
    /* 80730 8008FF30 000062AC */  sw         $v0, 0x0($v1)
    /* 80734 8008FF34 0A80023C */  lui        $v0, %hi(D_8009A090)
    /* 80738 8008FF38 90A0428C */  lw         $v0, %lo(D_8009A090)($v0)
    /* 8073C 8008FF3C 00000000 */  nop
    /* 80740 8008FF40 000040AC */  sw         $zero, 0x0($v0)
    /* 80744 8008FF44 0A80023C */  lui        $v0, %hi(D_8009A09C)
    /* 80748 8008FF48 9CA0428C */  lw         $v0, %lo(D_8009A09C)($v0)
    /* 8074C 8008FF4C 00000000 */  nop
    /* 80750 8008FF50 000040AC */  sw         $zero, 0x0($v0)
    /* 80754 8008FF54 0A80023C */  lui        $v0, %hi(D_8009A09C)
    /* 80758 8008FF58 9CA0428C */  lw         $v0, %lo(D_8009A09C)($v0)
    /* 8075C 8008FF5C 0A80033C */  lui        $v1, %hi(D_8009A0BC)
    /* 80760 8008FF60 BCA0638C */  lw         $v1, %lo(D_8009A0BC)($v1)
    /* 80764 8008FF64 0000428C */  lw         $v0, 0x0($v0)
    /* 80768 8008FF68 0060023C */  lui        $v0, (0x60000000 >> 16)
    /* 8076C 8008FF6C E03F0208 */  j          .L8008FF80
    /* 80770 8008FF70 000062AC */   sw        $v0, 0x0($v1)
  .L8008FF74:
    /* 80774 8008FF74 0180043C */  lui        $a0, %hi(D_80012988)
    /* 80778 8008FF78 1C3A020C */  jal        func_8008E870
    /* 8077C 8008FF7C 88298424 */   addiu     $a0, $a0, %lo(D_80012988)
  .L8008FF80:
    /* 80780 8008FF80 1000BF8F */  lw         $ra, 0x10($sp)
    /* 80784 8008FF84 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 80788 8008FF88 0800E003 */  jr         $ra
    /* 8078C 8008FF8C 00000000 */   nop
endlabel func_8008FEA0
