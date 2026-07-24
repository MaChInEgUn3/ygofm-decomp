nonmatching func_8002CCE4, 0x64

glabel func_8002CCE4
    /* 1D4E4 8002CCE4 FF078230 */  andi       $v0, $a0, 0x7FF
    /* 1D4E8 8002CCE8 C3300200 */  sra        $a2, $v0, 3
    /* 1D4EC 8002CCEC 00808230 */  andi       $v0, $a0, 0x8000
    /* 1D4F0 8002CCF0 0C004010 */  beqz       $v0, .L8002CD24
    /* 1D4F4 8002CCF4 07008530 */   andi      $a1, $a0, 0x7
    /* 1D4F8 8002CCF8 07008330 */  andi       $v1, $a0, 0x7
    /* 1D4FC 8002CCFC 80000224 */  addiu      $v0, $zero, 0x80
    /* 1D500 8002CD00 07206200 */  srav       $a0, $v0, $v1
    /* 1D504 8002CD04 1D80033C */  lui        $v1, %hi(D_801D0000)
    /* 1D508 8002CD08 00006324 */  addiu      $v1, $v1, %lo(D_801D0000)
    /* 1D50C 8002CD0C 2118C300 */  addu       $v1, $a2, $v1
    /* 1D510 8002CD10 18066290 */  lbu        $v0, 0x618($v1)
    /* 1D514 8002CD14 27200400 */  nor        $a0, $zero, $a0
    /* 1D518 8002CD18 24104400 */  and        $v0, $v0, $a0
    /* 1D51C 8002CD1C 0800E003 */  jr         $ra
    /* 1D520 8002CD20 180662A0 */   sb        $v0, 0x618($v1)
  .L8002CD24:
    /* 1D524 8002CD24 80000424 */  addiu      $a0, $zero, 0x80
    /* 1D528 8002CD28 1D80033C */  lui        $v1, %hi(D_801D0000)
    /* 1D52C 8002CD2C 00006324 */  addiu      $v1, $v1, %lo(D_801D0000)
    /* 1D530 8002CD30 2118C300 */  addu       $v1, $a2, $v1
    /* 1D534 8002CD34 18066290 */  lbu        $v0, 0x618($v1)
    /* 1D538 8002CD38 0720A400 */  srav       $a0, $a0, $a1
    /* 1D53C 8002CD3C 25104400 */  or         $v0, $v0, $a0
    /* 1D540 8002CD40 0800E003 */  jr         $ra
    /* 1D544 8002CD44 180662A0 */   sb        $v0, 0x618($v1)
endlabel func_8002CCE4
