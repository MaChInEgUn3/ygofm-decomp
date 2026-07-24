nonmatching func_8003BC40, 0xD4

glabel func_8003BC40
    /* 2C440 8003BC40 FFFFC824 */  addiu      $t0, $a2, -0x1
    /* 2C444 8003BC44 0B000005 */  bltz       $t0, .L8003BC74
    /* 2C448 8003BC48 40100800 */   sll       $v0, $t0, 1
    /* 2C44C 8003BC4C 21184500 */  addu       $v1, $v0, $a1
  .L8003BC50:
    /* 2C450 8003BC50 00006294 */  lhu        $v0, 0x0($v1)
    /* 2C454 8003BC54 00000000 */  nop
    /* 2C458 8003BC58 03004010 */  beqz       $v0, .L8003BC68
    /* 2C45C 8003BC5C 00000000 */   nop
    /* 2C460 8003BC60 1DEF0008 */  j          .L8003BC74
    /* 2C464 8003BC64 01000625 */   addiu     $a2, $t0, 0x1
  .L8003BC68:
    /* 2C468 8003BC68 FFFF0825 */  addiu      $t0, $t0, -0x1
    /* 2C46C 8003BC6C F8FF0105 */  bgez       $t0, .L8003BC50
    /* 2C470 8003BC70 FEFF6324 */   addiu     $v1, $v1, -0x2
  .L8003BC74:
    /* 2C474 8003BC74 2400C018 */  blez       $a2, .L8003BD08
    /* 2C478 8003BC78 21400000 */   addu      $t0, $zero, $zero
    /* 2C47C 8003BC7C 1E80023C */  lui        $v0, %hi(D_801D9000)
    /* 2C480 8003BC80 00904B24 */  addiu      $t3, $v0, %lo(D_801D9000)
    /* 2C484 8003BC84 F0FF0A24 */  addiu      $t2, $zero, -0x10
  .L8003BC88:
    /* 2C488 8003BC88 0000A994 */  lhu        $t1, 0x0($a1)
    /* 2C48C 8003BC8C 00000000 */  nop
    /* 2C490 8003BC90 2B380900 */  sltu       $a3, $zero, $t1
    /* 2C494 8003BC94 80100700 */  sll        $v0, $a3, 2
    /* 2C498 8003BC98 21184B00 */  addu       $v1, $v0, $t3
    /* 2C49C 8003BC9C 0000628C */  lw         $v0, 0x0($v1)
    /* 2C4A0 8003BCA0 3AEF0008 */  j          .L8003BCE8
    /* 2C4A4 8003BCA4 00000000 */   nop
  .L8003BCA8:
    /* 2C4A8 8003BCA8 25104A00 */  or         $v0, $v0, $t2
    /* 2C4AC 8003BCAC 000082A0 */  sb         $v0, 0x0($a0)
    /* 2C4B0 8003BCB0 010087A0 */  sb         $a3, 0x1($a0)
    /* 2C4B4 8003BCB4 3EEF0008 */  j          .L8003BCF8
    /* 2C4B8 8003BCB8 02008424 */   addiu     $a0, $a0, 0x2
  .L8003BCBC:
    /* 2C4BC 8003BCBC 00006294 */  lhu        $v0, 0x0($v1)
    /* 2C4C0 8003BCC0 00000000 */  nop
    /* 2C4C4 8003BCC4 05004914 */  bne        $v0, $t1, .L8003BCDC
    /* 2C4C8 8003BCC8 F000E228 */   slti      $v0, $a3, 0xF0
    /* 2C4CC 8003BCCC F6FF4010 */  beqz       $v0, .L8003BCA8
    /* 2C4D0 8003BCD0 03120700 */   sra       $v0, $a3, 8
    /* 2C4D4 8003BCD4 3DEF0008 */  j          .L8003BCF4
    /* 2C4D8 8003BCD8 000087A0 */   sb        $a3, 0x0($a0)
  .L8003BCDC:
    /* 2C4DC 8003BCDC 04006324 */  addiu      $v1, $v1, 0x4
    /* 2C4E0 8003BCE0 0000628C */  lw         $v0, 0x0($v1)
    /* 2C4E4 8003BCE4 0100E724 */  addiu      $a3, $a3, 0x1
  .L8003BCE8:
    /* 2C4E8 8003BCE8 F4FF4014 */  bnez       $v0, .L8003BCBC
    /* 2C4EC 8003BCEC 00000000 */   nop
    /* 2C4F0 8003BCF0 000080A0 */  sb         $zero, 0x0($a0)
  .L8003BCF4:
    /* 2C4F4 8003BCF4 01008424 */  addiu      $a0, $a0, 0x1
  .L8003BCF8:
    /* 2C4F8 8003BCF8 01000825 */  addiu      $t0, $t0, 0x1
    /* 2C4FC 8003BCFC 2A100601 */  slt        $v0, $t0, $a2
    /* 2C500 8003BD00 E1FF4014 */  bnez       $v0, .L8003BC88
    /* 2C504 8003BD04 0200A524 */   addiu     $a1, $a1, 0x2
  .L8003BD08:
    /* 2C508 8003BD08 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 2C50C 8003BD0C 0800E003 */  jr         $ra
    /* 2C510 8003BD10 000082A0 */   sb        $v0, 0x0($a0)
endlabel func_8003BC40
