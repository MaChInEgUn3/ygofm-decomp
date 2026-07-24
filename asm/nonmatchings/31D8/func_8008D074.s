nonmatching func_8008D074, 0x5C

glabel func_8008D074
    /* 7D874 8008D074 21308000 */  addu       $a2, $a0, $zero
    /* 7D878 8008D078 2138A000 */  addu       $a3, $a1, $zero
    /* 7D87C 8008D07C 0180053C */  lui        $a1, %hi(D_8001263C)
    /* 7D880 8008D080 3C26A524 */  addiu      $a1, $a1, %lo(D_8001263C)
    /* 7D884 8008D084 0300A288 */  lwl        $v0, 0x3($a1)
    /* 7D888 8008D088 0000A298 */  lwr        $v0, 0x0($a1)
    /* 7D88C 8008D08C 0400A380 */  lb         $v1, 0x4($a1)
    /* 7D890 8008D090 0500A480 */  lb         $a0, 0x5($a1)
    /* 7D894 8008D094 0300E2A8 */  swl        $v0, 0x3($a3)
    /* 7D898 8008D098 0000E2B8 */  swr        $v0, 0x0($a3)
    /* 7D89C 8008D09C 0400E3A0 */  sb         $v1, 0x4($a3)
    /* 7D8A0 8008D0A0 0500E4A0 */  sb         $a0, 0x5($a3)
    /* 7D8A4 8008D0A4 0200C104 */  bgez       $a2, .L8008D0B0
    /* 7D8A8 8008D0A8 2110C000 */   addu      $v0, $a2, $zero
    /* 7D8AC 8008D0AC 0F00C224 */  addiu      $v0, $a2, 0xF
  .L8008D0B0:
    /* 7D8B0 8008D0B0 03110200 */  sra        $v0, $v0, 4
    /* 7D8B4 8008D0B4 30004324 */  addiu      $v1, $v0, 0x30
    /* 7D8B8 8008D0B8 00110200 */  sll        $v0, $v0, 4
    /* 7D8BC 8008D0BC 2310C200 */  subu       $v0, $a2, $v0
    /* 7D8C0 8008D0C0 30004224 */  addiu      $v0, $v0, 0x30
    /* 7D8C4 8008D0C4 0200E3A0 */  sb         $v1, 0x2($a3)
    /* 7D8C8 8008D0C8 0800E003 */  jr         $ra
    /* 7D8CC 8008D0CC 0300E2A0 */   sb        $v0, 0x3($a3)
endlabel func_8008D074
