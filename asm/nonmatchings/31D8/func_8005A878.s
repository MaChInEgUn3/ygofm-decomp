nonmatching func_8005A878, 0x4C

glabel func_8005A878
    /* 4B078 8005A878 0F80053C */  lui        $a1, %hi(D_800F2B20)
    /* 4B07C 8005A87C 202BA624 */  addiu      $a2, $a1, %lo(D_800F2B20)
    /* 4B080 8005A880 0100C290 */  lbu        $v0, 0x1($a2)
    /* 4B084 8005A884 00000000 */  nop
    /* 4B088 8005A888 0C004014 */  bnez       $v0, .L8005A8BC
    /* 4B08C 8005A88C 21180000 */   addu      $v1, $zero, $zero
    /* 4B090 8005A890 09008014 */  bnez       $a0, .L8005A8B8
    /* 4B094 8005A894 00000000 */   nop
    /* 4B098 8005A898 202BA290 */  lbu        $v0, %lo(D_800F2B20)($a1)
    /* 4B09C 8005A89C 00000000 */  nop
    /* 4B0A0 8005A8A0 05004010 */  beqz       $v0, .L8005A8B8
    /* 4B0A4 8005A8A4 00000000 */   nop
    /* 4B0A8 8005A8A8 0200C294 */  lhu        $v0, 0x2($a2)
    /* 4B0AC 8005A8AC 00000000 */  nop
    /* 4B0B0 8005A8B0 02004014 */  bnez       $v0, .L8005A8BC
    /* 4B0B4 8005A8B4 00000000 */   nop
  .L8005A8B8:
    /* 4B0B8 8005A8B8 01000324 */  addiu      $v1, $zero, 0x1
  .L8005A8BC:
    /* 4B0BC 8005A8BC 0800E003 */  jr         $ra
    /* 4B0C0 8005A8C0 21106000 */   addu      $v0, $v1, $zero
endlabel func_8005A878
