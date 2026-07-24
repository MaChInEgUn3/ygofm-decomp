nonmatching func_8008CF74, 0x54

glabel func_8008CF74
    /* 7D774 8008CF74 01000224 */  addiu      $v0, $zero, 0x1
    /* 7D778 8008CF78 10008210 */  beq        $a0, $v0, .L8008CFBC
    /* 7D77C 8008CF7C 21180000 */   addu      $v1, $zero, $zero
    /* 7D780 8008CF80 02008228 */  slti       $v0, $a0, 0x2
    /* 7D784 8008CF84 05004010 */  beqz       $v0, .L8008CF9C
    /* 7D788 8008CF88 00000000 */   nop
    /* 7D78C 8008CF8C 0C008010 */  beqz       $a0, .L8008CFC0
    /* 7D790 8008CF90 00000000 */   nop
    /* 7D794 8008CF94 F0330208 */  j          .L8008CFC0
    /* 7D798 8008CF98 00808334 */   ori       $v1, $a0, 0x8000
  .L8008CF9C:
    /* 7D79C 8008CF9C 02000224 */  addiu      $v0, $zero, 0x2
    /* 7D7A0 8008CFA0 07008210 */  beq        $a0, $v0, .L8008CFC0
    /* 7D7A4 8008CFA4 01000324 */   addiu     $v1, $zero, 0x1
    /* 7D7A8 8008CFA8 04000224 */  addiu      $v0, $zero, 0x4
    /* 7D7AC 8008CFAC 04008214 */  bne        $a0, $v0, .L8008CFC0
    /* 7D7B0 8008CFB0 00808334 */   ori       $v1, $a0, 0x8000
    /* 7D7B4 8008CFB4 F0330208 */  j          .L8008CFC0
    /* 7D7B8 8008CFB8 03000324 */   addiu     $v1, $zero, 0x3
  .L8008CFBC:
    /* 7D7BC 8008CFBC 02000324 */  addiu      $v1, $zero, 0x2
  .L8008CFC0:
    /* 7D7C0 8008CFC0 0800E003 */  jr         $ra
    /* 7D7C4 8008CFC4 21106000 */   addu      $v0, $v1, $zero
endlabel func_8008CF74
